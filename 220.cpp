#include <iostream>
#include <cstdio>
#include <cstdlib>
#define maxn 12
using namespace std;

int n,k;
long long f[maxn][maxn*maxn];
long long g[maxn][maxn*maxn];
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d %d\n",&n,&k);
    f[0][0] = 1;long long tmp = 1;
    for (int i=1;i<=n;++i){
	for (int j=0;j<=k;++j){
	    f[i][j] = f[i-1][j];
	    if (j>=1) f[i][j]+=f[i-1][j-1]*(tmp-(j-1));
	}
	if (i % 2==0) tmp+=2;
    }tmp = 2;
    g[0][0] = 1;
    for (int i=1;i<=n-1;++i){
	for (int j=0;j<=k;++j){
	    g[i][j] = g[i-1][j];
	    if (j>=1) g[i][j]+=g[i-1][j-1]*(tmp-(j-1));
	}
	if (i % 2==0) tmp+=2;
    }long long ans = 0;
    for (int t = 0;t<=k;++t){
	ans += f[n][t]*g[n-1][k-t];
	cout << ans << " " << f[n][t] << " " << g[n-1][k-t] << endl;
    }
    printf("%lld\n",ans);
}
