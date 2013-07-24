#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)
#define pbk push_back
#define mkp make_pair

using namespace std;

const int maxn = 2222,maxm = 222222;
const int INF = 0x7FFFFFFF/2;
typedef pair<int,int> nb;
typedef vector<nb>::iterator iter;
struct segStr
{ int u,v,w; }segtmp[maxm];
int n,x,y,m;
vector<nb> map[maxn];
nb seg[maxm*2];
int distx[maxn],disty[maxn];
int reach[maxn],reachNum,segtmpNum;
int ans[maxn],all,now;

class priorityCmp
{
public:
    inline int operator()(const nb&a,const nb&b)
    { return a.second < b.second; }
};
inline bool cmp(int a,int b)
{ return distx[a]<distx[b]; }
void spfa(int s,int *d)
{
    static bool inqueue[maxn];
    static int queue[maxn*10];
    static int l,r;
    memset(inqueue,false,sizeof(inqueue));
    rep(i,1,n) d[i] = INF;
    d[s] = l = 0;
    queue[r = 1] = s;
    inqueue[s] = true;

    while (l < r)
	{
	    int u = queue[++l];
	    for (iter it = map[u].begin();it!=map[u].end();++it)
		{
		    int v = (*it).first;
		    int w = (*it).second;
		    if (d[u] + w < d[v])
			{
			    d[v] = d[u] + w;
			    if (!inqueue[v])
				{
				    queue[++r] = v;
				    inqueue[v] = true;
				}
			}
		}
	    inqueue[u] = false;
	}
}

void read(int & data)
{
    data = 0;
    static char c = getchar();
    while (c<'0' || c>'9') c = getchar();
    while (c>='0' && c<='9')
	{
	    data = data*10+c-'0';
	    c = getchar();
	}
}

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
    read(n);read(x);read(y);read(m);
    rep(i,1,m)
	{
	    read(segtmp[i].u);
	    read(segtmp[i].v);
	    read(segtmp[i].w);
	    map[segtmp[i].u].pbk(mkp(segtmp[i].v,segtmp[i].w));
	    map[segtmp[i].v].pbk(mkp(segtmp[i].u,segtmp[i].w));
	}
    spfa(x,distx);
    spfa(y,disty);

    
    rep(i,1,n) if (distx[i] + disty[i] == distx[y])
	{
	    reach[++reachNum] = i;
	    seg[++all] = mkp(distx[i],1);
	    seg[++all] = mkp(distx[i]+1,-1);
	}sort(reach+1,reach+reachNum+1,cmp);

    rep(i,1,m) 
	{
	    if (((distx[segtmp[i].u] + disty[segtmp[i].v] + segtmp[i].w == distx[y]) || 
		 (distx[segtmp[i].v] + disty[segtmp[i].u] + segtmp[i].w == distx[y])) && (segtmp[i].w != 1))
		{
		    int u = distx[segtmp[i].u];
		    int v = distx[segtmp[i].v];
		    seg[++all] = mkp(min(u,v)+1,1);
		    seg[++all] = mkp(max(u,v),-1);
		}
	}sort(seg+1,seg+all+1);

    int tmp = 0;
    now = 1;
    rep(i,1,reachNum)
	{
	    while (now<=all && seg[now].first <= distx[reach[i]])
		{
		    tmp += seg[now].second;;
		    now++;
		}
	    ans[reach[i]] = tmp;
	}

    rep(i,1,n-1) cout << ans[i] << " ";
    cout << ans[n] << endl;
    
    return 0;
}
