/*
 *NAME:Matrix
 *LANG:C++
 *SOURCE:sgu168
 *TIMES:3
 *TIME Complexity:O(n^2)
 *SPACE Complexity:O(n^2)
 *METHOD:后缀最值优化
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int maxn = 1020;
int a[maxn][maxn],c[maxn][maxn];
int n,m;
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    //input
    scanf("%d %d\n",&n,&m);
    for (int i=1;i<=n;++i)
	for (int j=1;j<=m;++j)
	    scanf("%d ",&a[i][j]);
    //solve
    for (int j=m;j>=1;--j){
	c[n][j] = a[n][j];
	for (int i=n-1;i>=1;--i)
	    c[i][j] = min(a[i][j],c[i+1][j]);
	for (int i=n;i>=1;--i){
	    if (i-1>=1 && j+1<=m)
		c[i][j] = min(c[i][j],c[i-1][j+1]);
	    if (i-1<=0 && j+1<=m)
		c[i][j] = min(c[i][j],c[1][j+1]);
	}
    }
    //print
    for (int i=1;i<=n;++i){
	for (int j=1;j<=m;++j)
	    printf("%d ",c[i][j]);
	printf("\n");
    }
    return 0;
}
