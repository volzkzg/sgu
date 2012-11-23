#include <iostream>
#include <cstring>
#define rep(i,j,k) for (int i=j;i<=k;++i)

using namespace std;

struct node{
    int v;
    node *next;
}*g[500];
int v,last[500],match,n,k;
bool vis[500];

void insert(int u,int v){
    node *x = new node();
    x->v = v;x->next = g[u];g[u] = x;
}
bool augment(int u){
    node *t = g[u];
    while (t!=0){
	if (!vis[t->v]){
	    vis[t->v] = true;
	    if (last[t->v] == 0 || augment(last[t->v])){
		last[t->v] = u;
		return true;
	    }
	}
	t = t->next;
    }return false;
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int num;
    cin >> n >> k;
    memset(g,0,sizeof(g));
    rep(i,1,n){
	cin >> num;
	rep(j,1,num) {
	    cin >> v;
	    insert(i,v);
	    insert(i,v+222);
	}
    }
    rep(i,1,n){
	memset(vis,false,sizeof(vis));
	if (augment(i)) match++;
    }
    if (match == 2*k){
	cout << "YES" << endl;
	rep(i,1,k)
	    cout << 2 << " " << last[i] << " " << last[i+222] << endl;
    }else cout << "NO" << endl;
    return 0;
}
