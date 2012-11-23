#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

const int maxn = 222;
int a[maxn][maxn],b[maxn],ans[maxn],ansNum;
bool f[maxn][maxn],vis[maxn];
int n,k;

void dfs(int u,int now)
{
    if (f[u][now]) return;
    f[u][now] = true;
    if (now>k) 
	{
	    vis[u] = true;
	    return;
	}
    rep(v,1,n) if (a[u][v] == b[now]) dfs(v,now+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i,1,n) rep(j,1,n) cin >> a[i][j];
    cin >> k;
    rep(i,1,k) cin >> b[i];
    
    dfs(1,1);
    rep(i,1,n) if (vis[i]) ans[++ansNum] = i;
    cout << ansNum << endl;
    rep(i,1,ansNum) cout << ans[i] << " " ;
    cout << endl;
    return 0;
}
