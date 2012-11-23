/*
 *NAME:Bridge painting
 *LANG:C++
 *SOURCE:sgu121
 *TIMES:3
 *METHOD:
 *找到一个度为奇数的点(如果没有那么从度为偶数的点开始)
 *对于从度为奇数的点进行扩展,
 *假设我们扩展出的第一个条边的颜色为1,
 *1、如果我们可以沿着这条边,经过一个环,回到这个点(此时我们利用了该点的两条边),
 *那么我们可以通过该点的另一条边,继续扩展边并且颜色为2
 *2、如果我们沿着这条边，只能访问一条路径，不能访问贿赂，
 *那么同理，可以扩展另一条路径，并且颜色为2
 *如果该点为偶数点，显然可以同时扩展颜色为1和颜色为2的边，不多说了
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int mn = 110;
struct node{
    int v;
    node * next;
};
node * g[mn];
int num[mn],l,now[mn],n,k;
int cc[mn][mn];
bool visit[mn][mn] = {0};
void insert(int x,int y){
    node *z = new node();
    z->v = x;z->next = g[y];g[y]=z;
}
void dfs(int p,int color){
    int c = 3-color;
    node *x = g[p];
    while (x){
	if (!visit[p][x->v] && !visit[x->v][p]) {
	    visit[p][x->v]=visit[x->v][p]=true;
	    cc[p][x->v] = cc[x->v][p] = c;
	    dfs(x->v,c);c = 3-c;
	}
	x = x->next;
    }
}
void print(node *x,int pos){
    if (x!=0) print(x->next,pos);
    else return ;
    cout << cc[pos][x->v] << " ";
}
int main(){
    cin >> n;memset(g,0,sizeof(g));
    for (int i=1;i<=n;++i){
	cin >> k;
	while (k){
	    insert(k,i);num[i]++;cin >> k;
	}now[i] = 1;
    }
    for (int i=1;i<=n;++i)
	if (num[i] & 1) dfs(i,1);
    for (int i=1;i<=n;++i)
	dfs(i,1);
    for (int i=1;i<=n;++i){
	node * x= g[i];int tmp=0;
	while (x!=0){
	    tmp = tmp | cc[i][x->v];
	    x=x->next;
	}
	if (tmp!=3 && num[i]>1){
	    cout << "No solution" << endl;
	    return 0;
	}
    }
    for (int i =1;i<=n;++i){
	print(g[i],i);
	cout << "0" << endl;
    }return 0;
}
