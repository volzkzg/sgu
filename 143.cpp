/*
 *NAME:Long Live the Queen
 *LANG:C++
 *SOURCE:sgu143
 *METHOD:树形DP，记录下每个节点为根节点时，他的儿子和他所能构成的最大值。
 *TIMES：3
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50000;
struct node{
    int v,next;
}e[maxn];
int g[maxn],edgeNum,n,ans;
int father[maxn],f[maxn];
bool visit[maxn];
void insert(int a,int b){
    e[++edgeNum].v= b;e[edgeNum].next= g[a];g[a]=edgeNum;
    e[++edgeNum].v= a;e[edgeNum].next= g[b];g[b]=edgeNum;
}
void dfs(int p){
    visit[p] = false;
    int z = g[p];
    while (z!=0){
	if (visit[e[z].v]){
	    father[e[z].v]=p;
	    dfs(e[z].v);
	}
	if (e[z].v!=father[p] && f[e[z].v]>0) f[p]+=f[e[z].v];
	z=e[z].next;
    }
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d\n",&n);
    for (int i = 1;i <= n; ++i)
	scanf("%d\n",&f[i]);
    for (int i=1,x,y;i<n;++i){
	scanf("%d %d\n",&x,&y);
	insert(x,y);
    }memset(visit,true,sizeof(visit));
    dfs(1);ans = -0x7FFFFFFF;
    for (int i=1;i<=n;++i)
	ans = max(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}
	   
