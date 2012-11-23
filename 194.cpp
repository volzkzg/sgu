#include <iostream>
#include <cstdio>
#include <cstdlib>
#define maxn 222

using namespace std;

const int INF = 0x7FFFFFFF;
int n,m,edgeNum,S,T;
int M[maxn],v[maxn],c[maxn],d[maxn],bound[maxn*maxn];
struct node{
    int v,c,next;
}e[maxn*maxn*2];

inline void insert(int a,int b,int c){
    ++edgeNum;
    e[edgeNum].v = b,e[edgeNum].c = c,e[edgeNum].next=v[a],v[a] = edgeNum;
    ++edgeNum;
    e[edgeNum].v = a,e[edgeNum].c = 0,e[edgeNum].next=v[b],v[b] = edgeNum;
}
inline int opp(int x){
    return (x % 2 == 1 ? x+1 : x-1);
}
inline int maxflow(int x,int lim){
    int ret,minNum,maxFlow,i,j;
    if (x == T) return lim;
    maxFlow = 0,minNum = n+2;
    j = v[x];
    while (j!=0){
	if (e[j].c>0){
	    if (d[e[j].v]+1 == d[x]){
		ret = min(lim,e[j].c);
		ret = maxflow(e[j].v,ret);
		e[j].c-=ret,e[opp(j)].c+=ret;
		lim-=ret,maxFlow+=ret;
		if (lim == 0 || d[S]>=n+2) return maxFlow;
	    }
	    minNum = min(minNum,d[e[j].v]+1);
	}
	j = e[j].next;
    }
    if (d[x] == minNum) return maxFlow;
    --c[d[x]];
    if (c[d[x]] == 0) d[S] = n+2;
    d[x] = minNum,c[d[x]]++;
    return maxFlow;
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int i,j,k;
    scanf("%d%d\n",&n,&m);
    for (i=1;i<=m;++i){
	int u,v,a,b;
	scanf("%d%d%d%d\n",&u,&v,&a,&b);
	bound[i] = a;
	insert(u,v,b-a);
	M[u]-=a,M[v]+=a;
    }S=n+1,T=n+2;
    int tmp = 0,ans = 0;
    for (i=1;i<=n;++i)
	if (M[i]>0) {insert(S,i,M[i]);tmp+=M[i];}
	else insert(i,T,-M[i]);
    c[0] = n+2;
    while (d[S]<n+2)
	ans+=maxflow(S,INF);
    if (ans == tmp){
	printf("YES\n");
	for (i=1;i<=m;++i)
	    printf("%d\n",bound[i]+e[2*i].c);
    }else
	printf("NO\n");
    return 0;

}
