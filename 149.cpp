/*
 *NAME:Compute Network
 *LANG:C++
 *SOURCE:sgu149
 *TIMES:4
 *METHOD:
 *树形DP
 *假设电脑1为根节点
 *首先进行一次前序遍历，计算每个点为根节点的子树的由根节点扩展出去的最大距离
 *再进行一次后序遍历，计算除每个点为根节点的子树的树由该点扩展出去的最大距离
 *对于每个点，两者取一个最大值即可
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int mn = 10010;
struct node{
    int v,c;
    node *next;
};
node *g[mn];
int f[mn],fs[mn],father[mn],ans[mn],up[mn];
int n;
void insert(int u,int v,int w){
    node *x = new node();father[v]=u;
    x->v = v;x->c = w;
    x->next = g[u];g[u]=x;
}
void dfs(int p){
    //    cout << p << endl;
    node *x = g[p];
    while (x!=0){
	dfs(x->v);
	if (f[x->v]+x->c>f[p]){
	    fs[p]=f[p];
	    f[p] = f[x->v]+x->c;
	}else if (f[x->v]+x->c>fs[p])
	    fs[p]=f[x->v]+x->c;
	x = x->next;
    }
}
void dfsAns(int p){
    node *x= g[p];
    while (x!=0){
	int v = x->v;
	if (x->c+f[v]==f[p]){
	    up[v] = x->c+max(up[p],fs[p]);
	}
	else{
	    up[v] = x->c+max(up[p],f[p]);
	}
	x=x->next;
    }
    x = g[p];
    while (x!=0){
	dfsAns(x->v);
	x=x->next;
    }
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    //init
    scanf("%d\n",&n);memset(g,0,sizeof(g));
    for (int i=2,x,y;i<=n;++i){
	scanf("%d %d\n",&x,&y);
	insert(x,i,y);
    }
    //solve
    dfs(1);
    dfsAns(1);
    //print
    for (int i=1;i<=n;++i)
	printf("%d\n",max(up[i],f[i]));
    return 0;
}
