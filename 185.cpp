#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 401
#define INF 0x7FFFFFFF

using namespace std;

struct edgeNode{
    int v,c,next;
}e[maxn*maxn];
int ind[maxn],edgeNum;
int d[maxn];
int c[maxn];
int s,t,n,m,ans;

void insertGraph(int a,int b,int c){
    e[++edgeNum].v = b,e[edgeNum].c = c,e[edgeNum].next = ind[a],ind[a] = edgeNum;
    e[++edgeNum].v = a,e[edgeNum].c = 0,e[edgeNum].next = ind[b],ind[b] = edgeNum;
}
inline void dijkstra(){
    int i,j,k;
    int g[maxn][maxn];
    int d[maxn];
    bool f[maxn];
    for (i=1;i<=m;++i){
	int a,b,c;
	scanf("%d%d%d\n",&a,&b,&c);
	g[a][b] = g[b][a] = c;
    }
    for (i=1;i<=n;++i){f[i] = true; d[i] = INF;}
    d[1] = 0;
    for (i=1;i<n;++i){
	int minNum = INF,pos;
	for (j=1;j<=n;++i)
	    if (d[j]<minNum){
		minNum = d[j];
		pos = j;
	    }
	f[pos] = false;
	for (j=1;j<=n;++j)
	    if (f[j] && g[pos][j]!=0)
		if (g[pos][j]+d[pos]<d[j])
		    d[j] = g[pos][j]+d[pos];
    }
}
int opp(int x){
    return (x%2 == 1)?x+1:x-1;
}
void makeGraph(){
    int queue[maxn];memset(queue,0,sizeof(queue));
    bool v[maxn];memset(v,false,sizeof(v));v[n] = true;
    int head = 0,tail = 1;
    queue[1] = n;
    while (head<tail){
	int point = queue[head = head%n+1];
	node *x = g[point];
	while (x!=0){
	    if (d[x->v]+x->w == d[point]){
		insertGraph(x->v,point,1);
		if (!v[x->v]){
		    v[x->v] = true;
		    queue[tail = tail%n+1] = x->v;
		}
	    }
	    x = x->next;
	}
    }
}
int maxflow(int x,int lim){
    int ret,maxFlow,minNum,i,j;
    if (x == t) return lim;
    maxFlow = 0,minNum= n;
    j = ind[x];
    while (j!=0){
	if (e[j].c>0){
	    if (d[e[j].v]+1 == d[x]){
		ret = min(lim,(int)e[j].c);
		ret = maxflow(e[j].v,ret);
		e[j].c -= ret,e[opp(j)].c += ret;
		lim-=ret,maxFlow+=ret;
		if (d[s] >= n || lim == 0) return maxFlow;
	    }
	    minNum = min(minNum,d[e[j].v]+1);
	}
	j = e[j].next;
    }
    if (d[x] == minNum) return maxFlow;
    --c[d[x]];
    if (c[d[x]] == 0) d[s] = n;
    d[x] =minNum;++c[d[x]];
    return maxFlow;
}
void printGraph(int p){
    printf("%d ",p);
    while (p!=n){
	int j = ind[p];
	while (j!=0){
	    if (e[j].c==0 && j%2 == 1){
		e[j].c = -1;
		p = e[j].v;
		printf("%d ",p);
		break;
	    }else j = e[j].next;
	}
    }printf("\n");
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d%d\n",&n,&m);
    dijkstra();
    makeGraph();
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    s = 1,t = n;c[0] = t;
    while (d[s]<n) ans+=maxflow(s,INF);
    if (ans<2)
	printf("No solution\n");
    else{
	printGraph(1);
	printGraph(1);
    }
    return 0;
}
