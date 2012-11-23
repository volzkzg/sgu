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

const int maxn = 444,INF = 0x7FFFFFFF/2;
struct node
{
    int v,next,num;
}edge[maxn*maxn*2];
int n,m,s,t,crystalNum,edgeNum;
int g[maxn],dist[maxn],queue[maxn*8];
bool vis[maxn*maxn*2];
vector<int> vec[maxn];

void insert(int u,int v,int num)
{
    edgeNum++;
    edge[edgeNum].v = v,edge[edgeNum].num = num;
    edge[edgeNum].next = g[u],g[u] = edgeNum;
    edgeNum++;
    edge[edgeNum].v = u,edge[edgeNum].num = num;
    edge[edgeNum].next = g[v],g[v] = edgeNum;
}
void makeGraph()
{
    int u,v;
    cin >> n >> m >> s >> t;
    rep(i,1,m)
	{
	    cin >> u >> v;
	    insert(u,v,i);
	}
}
void spfa()
{
    memset(vis,false,sizeof(vis));vis[s] = true;
    rep(i,1,n) dist[i] = INF;dist[s] = 0;
    int l=0,r=1;queue[0] = s;
    
    while (l<r)
	{
	    int u = queue[l++];
	    for (int k = g[u];k;k=edge[k].next)
		{
		    int v = edge[k].v;
		    if (dist[u]+1<dist[v])
			{
			    dist[v] = dist[u]+1;
			    if (!vis[v])
				{
				    vis[v] = true;
				    queue[r++] = v;
				}
			}
		}
	    vis[u] = false;
	}
}
void theSolver()
{
    spfa();
    memset(vis,false,sizeof(vis));
    crystalNum = dist[t];
    rep(i,0,crystalNum-1) rep(j,1,n) 
	if (dist[j] == i)
	    {
		for (int k = g[j];k;k=edge[k].next)
		    if (dist[edge[k].v] == i+1 && !vis[edge[k].num])
			{
			    vis[edge[k].num] = true;
			    vec[i].push_back(edge[k].num);
			}
	    }
    rep(i,1,m) if (!vis[i]) vec[0].push_back(i);
}
void thePrinter()
{
    cout << crystalNum << endl;
    vector<int>::iterator it;
    rep(i,0,crystalNum-1)
	{
	    int num = vec[i].end()-vec[i].begin();
	    cout << num;
	    for (it=vec[i].begin();it<vec[i].end();it++)
		cout << " " << *it;
	    cout << endl;
	}
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);

    makeGraph();
    theSolver();
    thePrinter();
}
