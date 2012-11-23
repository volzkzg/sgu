#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)
#define mkp make_pair

using namespace std;

typedef set<pair<int,int> >::iterator iter;
const int maxn = 666,INF = 0x7FFFFFFF/2;
struct gNode
{
    int gum,teeNum;
}g[maxn][maxn];
set<pair<int,int> > s[maxn];
int b[maxn],f[maxn][maxn],thing[maxn][maxn],ans[maxn];
int n,k,p,ansNum;

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    cin >> n >> k >> p;
    rep(i,0,n) rep(j,1,n) f[i][j] = INF;
    rep(i,1,k) cin >> b[i],s[i].clear();
    rep(i,1,n)
	{
	    int a,c;
	    cin >> a >> c;
	    s[c].insert(mkp(a,i));
	}
    rep(i,1,k)
	{
	    int c = b[i];
	    int v = 0;
	    iter it;
	    for (it = s[i].begin();it!=s[i].end();++it)
		{
		    c+=(*it).first;v++;
		    thing[i][v] = c;
		}
	    rrep(ii,n,0) rep(iii,0,v) if (ii-iii>=0)
		{
		    int last = ii-iii;
		    if (f[i-1][last]+thing[i][iii]<f[i][ii])
			{
			    f[i][ii] = f[i-1][last]+thing[i][iii];
			    g[i][ii].gum = i,g[i][ii].teeNum = iii;
			}
		}
	}
    int t = k;
    while (f[k][n]==INF || f[k][n]>p) n--;
    if (n == 0){cout << 0 << endl;return 0;}
    cout << n << endl;int w = n;
    while (n!=0)
	{
	    int gum = g[t][n].gum;
	    int teeNum = g[t][n].teeNum;
	    iter it;
	    for (it = s[gum].begin();teeNum>=1;teeNum--,++it)
		{
		    cout << (*it).second;
		    w--;
		    if (w != 0) cout << " " ; else cout << endl;
		}
	    n = n-g[t][n].teeNum;
	    t--;
	}
    return 0;
}
