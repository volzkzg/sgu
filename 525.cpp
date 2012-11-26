#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

const int maxn = 1111,maxm = 22222,INF = 0x7FFFFFFF/2;
struct node
{
    int u,v,next;
}edge[maxm];
int g[maxn],dfn[maxn],low[maxn],num[maxn],ans[maxm],stk[maxn];
int n,m,edgeNum,index,scc,maxNum=1,tmp;
bool instack[maxn];

void insert(int u,int v)
{
    edgeNum++;
    edge[edgeNum].u = u,edge[edgeNum].v = v;
    edge[edgeNum].next = g[u],g[u] = edgeNum;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++index;
    stk[++stk[0]] = u;
    instack[u] = true;
    for (int t = g[u];t;t=edge[t].next)
	{
	    int v = edge[t].v;
	    if (!dfn[v])
		{
		    tarjan(v);
		    low[u] = min(low[u],low[v]);
		}
	    else if (instack[v]) low[u] = min(low[u],dfn[v]);
	}
    if (low[u] == dfn[u])
	{
	    ++scc;
	    do
		{
		    instack[stk[stk[0]]] = false;
		    stk[0]--;
		    num[scc]++;
		}
	    while (stk[stk[0]+1] != u);
	}
}

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i,1,m)
	{
	    int u,v;
	    cin >> u >> v;
	    insert(u,v);
	}
    
    rep(i,1,m)
	{
	    memset(low,0,sizeof(low));
	    memset(dfn,0,sizeof(dfn));
	    memset(num,0,sizeof(num));
	    memset(instack,false,sizeof(instack));
	    stk[0] = scc = tmp = index = 0;
	    
	    int u = edge[i].v,v = edge[i].u;
	    int tt = g[u];insert(u,v);
	    
	    rep(j,1,n) if (!dfn[j]) tarjan(j);
	    rep(j,1,scc) tmp = max(tmp,num[j]);
	    if (tmp>maxNum)
		{
		    maxNum = tmp;
		    ans[ans[0] = 1] = i;
		}
	    else if (tmp == maxNum)
		ans[++ans[0]] = i;
	    edgeNum--;g[u] = tt;
	}
    cout << maxNum << endl;
    cout << ans[0] << endl;
    rep(i,1,ans[0]) cout << ans[i] << " " ;
    cout << endl;
    return 0;
}
