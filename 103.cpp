/*
 *Name:Traffic Lights
 *LANG:C++
 *source:sgu103
 */
#include <cstring>
#include <iostream>
#include <fstream>
#define MAXN 350
#define MAXM 15000
#define INF 0x7FFFFFFF/2;
using namespace std;
/*
ifstream fin("test.in");
ofstream fout("test.out");
*/
int s,t,hl,n,m,suck;
struct junction{
    int c,rc;
    int t[2];
}junc[MAXN];
struct heapType{
    int v,d,p;
}heap[MAXN];
struct node{
    node *next;
    int v,w;
};
node *g[MAXN];
int hpos[MAXN];

inline void insert(int u,int v,int w){
    node *x = new node;
    x->v=v;x->w=w;x->next=g[u];g[u]=x;
}
void init(){
    int i,j,k,u,v,w;char c;
    cin >> s >> t;
    cin >> n >> m;
    for (i=1;i<=n;++i){
	cin >> c >> junc[i].rc >> junc[i].t[0] >> junc[i].t[1];
	junc[i].c=(c=='B')?0:1;
    }
    memset(g,0,sizeof(g));
    for (i=1;i<=m;++i){
	cin >> u >>v >> w;
	insert(u,v,w);
	insert(v,u,w);
    }
}
void swap(int a,int b){
    heap[0]=heap[a];heap[a]=heap[b];heap[b]=heap[0];
    hpos[heap[a].v]=a;hpos[heap[b].v]=b;
}
void heapUp(int i){
    while (i!=1 && heap[i].d<heap[i/2].d){
	swap(i,i/2);
	i/=2;
    }
}
void heapDown(){
    int i=2;
    while (i<=hl){
	if (i<hl && heap[i+1].d<heap[i].d) ++i;
	if (heap[i].d<heap[i/2].d){
	    swap(i,i/2);
	    i*=2;
	}
	else break;
    }
}
void relax(int u,int v,int w){
    int tmp=heap[hpos[u]].d,time=0;
    int t1=junc[u].c,t2=junc[v].c,t3=junc[u].rc,t4=junc[v].rc;

    tmp%=(junc[u].t[0]+junc[u].t[1]);
    while (tmp>=junc[u].rc){tmp-=junc[u].rc;junc[u].c=1-junc[u].c;junc[u].rc=junc[u].t[junc[u].c];}
    junc[u].rc-=tmp;
    tmp=heap[hpos[u]].d;
    tmp%=(junc[v].t[0]+junc[v].t[1]);
    while (tmp>=junc[v].rc){tmp-=junc[v].rc;junc[v].c=1-junc[v].c;junc[v].rc=junc[v].t[junc[v].c];}
    junc[v].rc-=tmp;

    suck=0;
    while (junc[u].c!=junc[v].c){
	suck++;
	if (suck>3) break;
	if (junc[u].rc>junc[v].rc){
	    junc[u].rc-=junc[v].rc;
	    time+=junc[v].rc;
	    junc[v].c=1-junc[v].c;
	    junc[v].rc=junc[v].t[junc[v].c];
	}
	else if (junc[u].rc<junc[v].rc){
	    junc[v].rc-=junc[u].rc;
	    time+=junc[u].rc;
	    junc[u].c=1-junc[u].c;
	    junc[u].rc=junc[u].t[junc[u].c];
	}
	else{
	    time+=junc[u].rc;
	    junc[v].c=1-junc[v].c;
	    junc[v].rc=junc[v].t[junc[v].c];	    
	    junc[u].c=1-junc[u].c;
	    junc[u].rc=junc[u].t[junc[u].c];
	}
    }
    if (suck<=3 && time+w+heap[hpos[u]].d<heap[hpos[v]].d){
	heap[hpos[v]].p=u;
	heap[hpos[v]].d=time+w+heap[hpos[u]].d;
	heapUp(hpos[v]);
    }
    junc[u].c=t1,junc[v].c=t2,junc[u].rc=t3,junc[v].rc=t4;
}
void dijkstra(){
    int u;node * p =0;
    for (u=1;u<=n;++u){
	heap[u].v=u;
	heap[u].d=INF;
	hpos[u]=u;
    }
    heap[s].d=0;heap[s].p=s;swap(1,s);hl=n;
    while (hl>0){
	u=heap[1].v;
	swap(1,hl);hl--;heapDown();
	p=g[u];
	while (p!=0){
	    if (hpos[p->v]<=hl) relax(u,p->v,p->w);
	    p=p->next;
	}
    }
}
void dfs(int x){
    if (x==0) return;
    if (heap[hpos[x]].p!=s)
	dfs(heap[hpos[x]].p);
    cout << " " << x;
}
void print(){
    if (heap[hpos[t]].p==0){
	cout << 0 << endl;
	return;
    }
    cout << heap[hpos[t]].d << endl;
    cout << s;
    dfs(t);
    cout << endl;
}
int main(){
    init();
    dijkstra();
    print();
    return 0;
}
