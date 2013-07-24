#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

int a,b,c,d,i,j,n,m,k;
int lp[301],fk[301];
map<int,int> q;
pii mas[301];
bool used[301];

bool dfs(int v)
{
    if (used[v]) return 0;
    used[v]=1;
    for (int k=fk[v];;++k)
	{
	    ll w=(ll)mas[v].x*k+mas[v].y;
	    if (w<1 || w>m) break;
	    if (q.count(w)==0 || dfs(q[w]))
		{
		    lp[v]=w;
		    q[w]=v;
		    return 1;
		}
	    if (!mas[v].x) break;
	}
    return 0;
}
int main()
{
    memset(lp,-1,sizeof(lp));
    scanf("%d%d",&n,&m);
    rept(i,n)
	{
	    scanf("%d%d",&mas[i].x,&mas[i].y);
	    if (mas[i].x==0) fk[i]=0; else
		if (mas[i].x<0) fk[i]=(m-mas[i].y)/mas[i].x; else
		    fk[i]=(1-mas[i].y)/mas[i].x;

	    if (fk[i]<0) fk[i]=0;
	    if (mas[i].x<0)	while ((ll)fk[i]*mas[i].x+mas[i].y>m) ++fk[i];
	    if (mas[i].x>0) while ((ll)fk[i]*mas[i].x+mas[i].y<1) ++fk[i];
	}

    b=-1,a=0;
    while (a!=b)
	{
	    b=a; C(used);
	    rept(i,n) if (lp[i]==-1 && dfs(i)) ++a;
	}
    a=1;
    rept(i,n)
	{
	    if (lp[i]==-1)
		{
		    while (q.count(a) && lp[q[a]]==a) ++a;
		    lp[i]=a++;
		}
	    if (i) printf(" ");
	    printf("%d",lp[i]);
	}
    printf("\n");
}
