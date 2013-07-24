#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)
#define pb push_back
#define mkp make_pair
#define MAX 21

using namespace std;

const int INF = 0x7FFFFFFF/2;
vector<pair<int,int> > mct_dtl;
struct node
{
    int v,c,next;
};
struct maxflow
{
    node edge[MAX*MAX*4];
    int n,s,t,edgeNum,sum;
    int c[MAX*MAX*2],d[MAX*MAX*2],g[MAX*MAX*2];
    void insert(int ,int ,int);
    void build();
    int flow(int ,int);
    void getans();
    int opp(int);
}dinic;
int w[MAX],r[MAX],a[MAX][MAX];
int team,match;

int main()
{
    ios::sync_with_stdio(false);
    cin >> team;
    rep(i,1,team) cin >> w[i];
    rep(i,1,team) cin >> r[i];
    rep(i,1,team) rep(j,1,team) 
	{
	    cin >> a[i][j];
	    if (i != 1 && j != 1 && a[i][j] && i < j)
		{
		    match++;
		    mct_dtl.pb(mkp(i,j));
		}
	}
    w[1] += r[1];
    
    dinic.build();
    dinic.getans();
    
    return 0;
}

void maxflow::insert(int u,int v,int c)
{
    //cout << u << " " << v << " " << c << endl;
    edgeNum++;
    edge[edgeNum].v = v,edge[edgeNum].c = c;
    edge[edgeNum].next = g[u],g[u] = edgeNum;
    edgeNum++;
    edge[edgeNum].v = u,edge[edgeNum].c = 0;
    edge[edgeNum].next = g[v],g[v] = edgeNum;
}
void maxflow::build()
{
    sum = 0;
    n = team + match + 1;
    s = 1,t = n;
    int tmp = team;
    rep(i,2,team) 
	{
	    if (w[1] >= w[i])
		insert(s,i,w[1] - w[i]);
	    else
		{
		    cout << "NO" << endl;
		    exit(0);
		}
	}
    for (vector<pair<int,int> >::iterator iter = mct_dtl.begin();
	 iter != mct_dtl.end(); ++iter)
	{
	    tmp++;
	    int u = iter->first;
	    int v = iter->second;
	    insert(u,tmp,a[u][v]);
	    insert(v,tmp,a[u][v]);
	    insert(tmp,t,a[u][v]);
	    sum += a[u][v];
	}
}
void maxflow::getans()
{
    int ans = 0;
    c[0] = n;
    while (d[s] < n) ans += flow(s,INF);
    if (sum == ans) 
	cout << "YES" << endl;
    else
	cout << "NO" << endl;
}
int maxflow::flow(int u,int lim)
{
    if (u == t) return lim;
    int max_flow,min_num,v,ret,j;
    max_flow = 0, min_num = t;
    for (j = g[u]; j; j = edge[j].next)
	{
	    if (edge[j].c > 0)
		{
		    v = edge[j].v;
		    if (d[u] == d[v] + 1)
			{
			    ret = min(edge[j].c,lim);
			    ret = flow(v,ret);
			    edge[j].c -= ret, edge[opp(j)].c += ret;
			    lim -= ret, max_flow += ret;
			    if (lim == 0 || d[s] >= t) return max_flow;
			}
		    min_num = min(d[v]+1,min_num);
		}
	}
    if (d[u] == min_num) return max_flow;
    --c[d[u]];
    if (c[d[u]] == 0) d[s] = t;
    d[u] = min_num;
    c[d[u]] ++;
    return max_flow;
}
int maxflow::opp(int x)
{ return (x & 1) ? x + 1 : x - 1; }

