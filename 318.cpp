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
#define pb push_back

using namespace std;

const int maxn = 111,maxm = 111;
typedef vector<int>::iterator iter;
struct node
{
    int u,v,next;
}edge[maxm*maxm];
bool vis[maxm];
int beAccess[maxm][maxm];
int n,m,edgeNum,g[maxm],ans;

void insert(int u,int v)
{
    edgeNum++;
    edge[edgeNum].u = u,edge[edgeNum].v = v;
    edge[edgeNum].next = g[u],g[u] = edgeNum;
    edgeNum++;
    edge[edgeNum].u = v,edge[edgeNum].v = u;
    edge[edgeNum].next = g[v],g[v] = edgeNum;
}

bool equal(int u,int v)
{
    if (beAccess[u][0]!=beAccess[v][0]) return false;
    rep(i,1,beAccess[u][0])
	if(beAccess[u][i]!=beAccess[v][i]) return false;
    return true;
}

void find(int x)
{
    vis[x] = true;
    for (int i = g[x];i;i=edge[i].next)
	{
	    int v = edge[i].v;
	    if (!vis[v]) find(v);
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i,1,m)
	{
	    int num,k;
	    cin >> num;
	    rep(j,1,num)
		{
		    cin >> k;
		    beAccess[k][0]++;
		    beAccess[k][beAccess[k][0]]=i;
		}
	}
    rep(i,1,n) rep(j,i+1,n)
	if (equal(i,j))
	    insert(i,j);
    rep(i,1,n) if (beAccess[i][0]==0) vis[i] = true;
    rep(i,1,n) if (!vis[i])
	find(i),ans++;
    cout << ans << endl;
    return 0;
}
