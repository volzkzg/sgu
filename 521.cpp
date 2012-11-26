#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

typedef vector<int>::iterator iter;
const int maxn = 111111,INF = 0x7FFFFFFF/2;
struct node
{
    int x,y,ind;
    bool operator < (const node & a) const
    {
	if (x == a.x) return y>a.y;
	return x<a.x;
    }
}p[maxn];
vector<int> v (maxn,INF),vv (maxn,-INF);
int f[maxn],g[maxn],mark[maxn];
int must[maxn],mustNum,might[maxn],mightNum;
int n,maxNum;
int check[maxn];//1 present must,2 present might

int bin(int x)
{
    int l = 1,r = n,ret;
    while (l<=r)
	{
	    int mid = (l+r)>>1;
	    if (vv[mid]>x) l = mid+1;
	    else ret = mid,r = mid-1;
	}
    return ret;
}

int main()
{
    freopen("test.in","r",stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i,1,n)
	{
	    cin >> p[i].x >> p[i].y;
	    p[i].ind = i;
	}
    sort(p+1,p+n+1);

    rep(i,1,n)
	{
	    iter it = lower_bound(v.begin()+1,v.end(),p[i].y);
	    *it = min(p[i].y,*it);
	    f[i] = it-v.begin();
	    maxNum = max(maxNum,it-v.begin());
	}
    
    rrep(i,n,1)
	{
	    int pos = bin(p[i].y);
	    vv[pos] = max(p[i].y,vv[pos]);
	    g[i] = pos;
	}

    rep(i,1,n)
	{
	    int len = f[i]+g[i]-1;
	    if (len<maxNum) continue;
	    if (mark[f[i]] == 0)
		{
		    check[i] = 1;
		    mark[f[i]] = i;
		}
	    else if (mark[f[i]] == -1)
		    check[i] = 2;
	    else if (mark[f[i]] > 0)
		{
		    check[i] = check[mark[f[i]]] = 2;
		    mark[f[i]] = -1;
		}
	}

    rep(i,1,n) 
	{
	    if (check[i] == 1) must[++mustNum] = p[i].ind;
	    if (check[i] >= 1) might[++mightNum] = p[i].ind;
	}sort(must+1,must+mustNum+1);sort(might+1,might+mightNum+1);

    cout << mightNum;
    rep(i,1,mightNum) cout << " " << might[i];cout << endl;
    cout << mustNum;
    rep(i,1,mustNum) cout << " " << must[i];cout << endl;

    return 0;
}
