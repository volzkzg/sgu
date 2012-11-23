#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define rep(i,j,k) for (int i=j;i<=k;++i)

using namespace std;

bool f[111][111];
struct node{
    int v;
    node *next;
}*g[111];
int n,m,in[111];

void insert(int a,int b){
    node *x = new node();
    x->v = b,x->next = g[a];g[a] = x;
}
int main(){
    ios::sync_with_stdio(false);
    memset(f,false,sizeof(f));
    memset(g,0,sizeof(g));
    cin >> n >> m;
    int x,y;
    rep(i,1,m){
	cin >> x >> y;
	if (!f[x][y]){
	    if (f[y][x]) {cout << "No solution" << endl;return 0;}
	    insert(x,y);
	    ++in[y],f[x][y] = true;
	}
    }
    int queue[111],l,r;l = r = 0;
    int anum = 0;
    int put[111];
    rep(i,1,n)
	if (in[i] == 0)
	    queue[++r] = i;

    while (l<r){
	l++;
	int k = queue[l];
	put[k] = ++anum;
	node *x = g[k];
	while (x!=0){
	    k = x->v;--in[k];
	    if (in[k] == 0) queue[++r] = k;
	    x=x->next;
	}
    }

    if (anum==n)
	rep(i,1,n) cout << put[i] << " ";
    else
	cout << "No solution" << endl;
    return 0;

}
