#include <cstdio>
#include <cstdlib>
using namespace std;
cosnst int maxn = 11,maxs = 1024;
long long f[2][maxs];
int n,m,i;
void dfs(int p,int s1,int s2,int b1,int b2){
    if (p > m){
	if (!b1 & !b2) f[i & 1][s1] += f[1 - i & 1][s2];
	return;
    }
    
}
int main(){
    scanf("%d %d\n",&n,&m);
    if (n<m) {n = n ^ m;m = m ^ n;n = n ^ m;}
    f[0][(1 << m) - 1] = 1;
    for (int i=1;i<=n;++i){
	dfs(1,0,0,0,0);
	memset(f[1 - i & 1],0,sizeof(f[0]));
    }
    printf("%I64d\n",&f[n & 1][(1<<m) -1]);
    return 0;
}
