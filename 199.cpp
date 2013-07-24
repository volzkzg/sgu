#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define INF 0x7FFFFFFF
using namespace std;
struct node{
	int s,b,num;
}per[200100];
node perr[200100];
int f[200100],g[200100],gg[200100],mark[200100],pre[1001000];
int n,pos;
int cmp(const void *a,const void *b){
	struct node * aa = (node *)a;
	struct node * bb = (node *)b;
	if (aa->s!=bb->s)
		return aa->s>bb->s;
	else 
		return aa->b<bb->b;
}
void dfs(int p){
	if (pre[p]>0)
		dfs(pre[p]);
	cout << perr[p].s << " " << perr[p].b << endl;
}
int main(){
	//freopen("199.in","r",stdin);
	//freopen("199.out","w",stdout);
	//init
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i=1;i<=n;++i){
		cin >> per[i].s >> per[i].b;
		per[i].num = i;
		perr[i]=per[i];
	}
	qsort(per+1,n,sizeof(per[1]),cmp);
	//solve
	memset(mark,-1,sizeof(mark));
	fill(g+1,g+n+1000,INF);gg[0]=-1;
	fill(gg+1,gg+n+1000,INF);g[0]=-1;
	for (int i=1;i<=n;++i){
	
	}
	//print
	pos = *max_element(f+1,f+n+1);
	cout << pos << endl;
	pos = mark[pos];
	dfs(pos);
	putchar(10);
	return 0;
}
