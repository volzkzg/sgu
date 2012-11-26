#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int maxn = 1001100,maxm = 111,inf = 0x7FFFFFFF/2;
int n,m;
int c[maxn],s[maxm][maxm];

int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int i,j,k;
    scanf("%d%d\n",&n,&m);
    for (i=1;i<=n;++i)
	scanf("%d\n",&c[i]);
    for (i=1;i<=n+1;++i){
	s[i % maxm][0] = inf;
	for (j=1;j<=i && j<=m;++j){
	    if (i<m) 
		s[i % maxm][j] = min(s[i %maxm][j-1],c[i]+c[i-j]);
	    else
		s[i % maxm][j] = min(s[i % maxm][j-1],s[(i-j)%maxm][(m-j)]+c[i]);
	}
    }
    printf("%d\n",s[(n+1)%maxm][m-1]);
    return 0;
}
