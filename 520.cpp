#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

const int maxn = 1111,maxm = 1111;
struct node
{
    int u,v,next;
}edge[maxm*2];
bool vis[maxn],poss[maxn];
int g[maxn],dep[maxn];
int n,m,edgeNum;
int q[maxn*8],l,r;

void insert(int u,int v)
{
    edgeNum++;
    edge[edgeNum].u = u,edge[edgeNum].v = v;
    edge[edgeNum].next = g[u],g[u] = edgeNum;
    edgeNum++;
    edge[edgeNum].u = v,edge[edgeNum].v = u;
    edge[edgeNum].next = g[v],g[v] = edgeNum;
}

void dfs(int u)
{
    bool child = false;
    for (int t = g[u];t;t=edge[t].next)
	{
	    int v = edge[t].v;
	    if (dep[v] == dep[u]+1)
		{
		    dfs(v);
		    if (poss[v] == 0) child = true;
		}
	}
    poss[u] = child;
}

int main()
{
    freopen("test.in","r",stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i,1,m)
	{
	    int u,v;
	    cin >> u >> v;
	    insert(u,v);
	}
    
    l = 0 , r = 0;
    q[r++] = dep[1] = 1;
    vis[1] = true;
    while (l<r)
	{
	    int u = q[l++];
	    for (int t = g[u];t;t=edge[t].next)
		{
		    int v = edge[t].v;
		    if (dep[v] == 0 || dep[u]+1<dep[v])
			{
			    dep[v] = dep[u]+1;
			    if (!vis[v])
				{
				    q[r++] = v;
				    vis[v] = true;
				}
			}
		}
	    vis[1] = false;
	}

    dfs(1);
    string s = (poss[1])?"Vladimir":"Nikolay";
    cout << s << endl;
    return 0;
}
