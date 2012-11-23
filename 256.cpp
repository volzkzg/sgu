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

const int INF = 0x7FFFFFFF/2;
int a[11],b[11],N,M;
int f[101][11][11][11][11];

int dfs(int m,int a1,int a2,int a3,int a4)
{
    if (m<=0) return 0;
    if (f[m][a1][a2][a3][a4]!=INF) return f[m][a1][a2][a3][a4];

    rep(i,1,N)
	{
	    if (i == a1 && b[i]>3) continue;
	    if (i == a2 && b[i]>2) continue;
	    if (i == a3 && b[i]>1) continue;
	    if (i == a4) continue;
	    f[m][a1][a2][a3][a4] = min(f[m][a1][a2][a3][a4],dfs(m-a[i],a2,a3,a4,i)+1);
	}
    if (f[m][a1][a2][a3][a4]>=INF)
	f[m][a1][a2][a3][a4] = min(f[m][a1][a2][a3][a4],dfs(m,a2,a3,a4,0)+1);
    return f[m][a1][a2][a3][a4];
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);

    cin >> M >> N;
    rep(i,1,N) cin >> a[i] >> b[i];
    rep(i,0,100) rep(i1,0,10) rep(i2,0,10) rep(i3,0,10) rep(i4,0,10)
	f[i][i1][i2][i3][i4] = INF;
    cout << dfs(M,0,0,0,0) << endl;
    return 0;
}
