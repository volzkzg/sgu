/*
 *NAME:Centroid
 *LANG:C++
 *SOURCE:sgu134
 *TIMES:7
 *ERROR REASON:范围要开大啊,要开大啊
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 46100;
struct node{
    int u,v,next;
}e[maxn];
int g[maxn],father[maxn],f[maxn],ans[maxn],t[maxn];
bool visit[maxn];
int n,edgeNum;
void insert(int a,int b){
    e[++edgeNum].u = a;e[edgeNum].v = b;e[edgeNum].next = g[a]; g[a] = edgeNum;
    e[++edgeNum].u = b;e[edgeNum].v = a;e[edgeNum].next = g[b];g[b]=edgeNum;
}
void dfs(int p){
    visit[p] = false;
    int z = g[p];
    while (z!=0){
	if (visit[e[z].v]){
	    visit[e[z].v]=false;father[e[z].v] = p;
	    dfs(e[z].v);
	}
	if (e[z].v!=father[p]) f[p] += f[e[z].v];
	z=e[z].next;
    }
    f[p]++;
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d\n",&n);
    for (int i=1,x,y;i<n;++i){
	scanf("%d %d\n",&x,&y);
	insert(x,y);
    }memset(visit,true,sizeof(visit));
    dfs(1);f[0]=f[1];
    for (int i=1;i<=n;++i){
	t[i]=max(t[i],f[1]-f[i]);
	t[father[i]]=max(t[father[i]],f[i]);
    }int crash = 0x7FFFFFFF;
    for (int i=1;i<=n;++i){
	if (t[i] < crash){
	    crash = t[i];
	    ans[0] = 1;
	    ans[1] = i;
	}
	else if (t[i]==crash) ans[++ans[0]]=i;
    }
    printf("%d %d\n",crash,ans[0]);
    for (int i=1;i<=ans[0];++i)
	printf("%d\n",ans[i]);
    return 0;
}
