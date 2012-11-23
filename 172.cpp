/*
 *NAME:eXAM
 *LANG:C++
 *SOURCE:sgu172
 *TIME:3
 *METHOD:二分图判定问题，黑白染色即可
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
bool adj[210][210];
int color[210];
int n,ans,m;
int print[210];
void dfs(int p,int c){
    color[p]=c;
    for (int i=1;i<=n;++i){
	if (!adj[p][i]){
	    if (color[i]==color[p]){
		cout << "no" << endl;
		exit(0);
	    }
	    else if (!color[i])
		dfs(i,3-c);
	}
    }
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d %d\n",&n,&m);memset(adj,true,sizeof(adj));
    for (int i=1,x,y;i<=m;++i){
	cin >> x >> y;
	adj[x][y]=false;adj[y][x]=false;
    }
    for (int i=1;i<=n;++i)
	if (!color[i])
	    dfs(i,1);
    for (int i=1;i<=n;++i)
	if (color[i]==1)
	    print[++print[0]]= i;
    cout << "yes" << endl;
    cout << print[0] << endl;
    for (int i=1;i<print[0];++i)
	cout << print[i]  << " " ;
    cout << print[print[0]] << endl;
    return 0;
}
