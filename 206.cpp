#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)
#define init(a,b) memset(a,b,sizeof(a));

using namespace std;

const int INF = 0x7FFFFFFF/2,maxn = 61,maxm=401,maxsize=401;
int N,M,W[maxsize][maxsize],edgeNum,size;
int g[maxn],lx[maxsize],ly[maxsize],link[maxsize],slack[maxsize],ori[maxm];
bool visx[maxsize],visy[maxsize];
struct egdeNode{int v,w,next;}edge[maxn*maxm];

void insert(int u,int v,int w)
{
    edgeNum++;
    edge[edgeNum].v = v,edge[edgeNum].w = w;
    edge[edgeNum].next = g[u],g[u] = edgeNum;
}
bool dfs(int prev,int now,int goal,int w,int pos)
{
    if (now == goal) return true;
    for (int i = g[now];i;i=edge[i].next)
	if (edge[i].v != prev)
	    if (dfs(now,edge[i].v,goal,w,pos))
		{
		    int tmp = (i%2==1)?i/2+1:i/2;
		    W[tmp][pos] = edge[i].w-w;
		    return true;
		}
    return false;
}
void theIniter()
{
    int u,v,w;
    cin >> N >> M;size = max(N-1,M-N+1);
    rep(i,1,N-1) {cin >> u >> v >> w;insert(u,v,w);insert(v,u,w);ori[i] = w;}
    rep(i,N,M)
	{
	    cin >> u >> v >> w;
	    ori[i] = w;
	    dfs(-1,u,v,w,i-N+1);
	}
    rep(i,1,size) rep(j,1,size) lx[i] = max(lx[i],W[i][j]);
}
bool KMing(int x)
{
    visx[x] = true;
    rep(y,1,size)
	{
	    if (visy[y]) continue;
	    if (lx[x]+ly[y]==W[x][y])
		{
		    visy[y] = true;
		    if (link[y]==0 || KMing(link[y]))
			{
			    link[y] = x;
			    return true;
			}
		}
	    else 
		slack[y] = min(slack[y],lx[x]+ly[y]-W[x][y]);
	}
    return false;
}
void theKMer()
{
    rep(i,1,size)
	{
	    rep(j,1,size) slack[j] = INF;
	    for (;;)
		{
		    init(visx,false);init(visy,false);
		    if (KMing(i)) break;int d = INF;
		    rep(j,1,size) if (!visy[j]) d = min(d,slack[j]);
		    rep(j,1,size) if (visx[j]) lx[j]-=d;
		    rep(j,1,size) if (visy[j]) ly[j]+=d;else slack[j]-=d;
		}
	}
}
void thePrinter()
{
    rep(i,1,N-1) ori[i]-=lx[i];
    rep(i,N,M) ori[i]+=ly[i-N+1];
    rep(i,1,M) cout << ori[i] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    theIniter();
    theKMer();
    thePrinter();
    return 0;
}
