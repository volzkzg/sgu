/*
 *NAME:Making round
 *LANG:C++
 *SOURCE:sgu152
 *TIMES:5
 *METHOD:Ì°ÐÄ
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 11000;
int sum,a[maxn],n,t,c[maxn];
double b[maxn],eps = 1e-9;
bool isInt[maxn] = {0};
int dblcmp(double x){return (fabs(x)<eps)?0:1;}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d\n",&n);
    for (int i = 1;i<=n;++i){
	scanf("%d ",&a[i]);
	sum+=a[i];
    }int rem = 100;
    for (int i=1;i<=n;++i){
	b[i] = (double)a[i]*100/sum;c[i]=(int)b[i];
	if (dblcmp(b[i]-c[i]) == 0) isInt[i] = 1;
	rem-=c[i];
    }
    for (int i=1;i<=n;++i){
	if (rem && !isInt[i]){
	    printf("%d ",c[i]+1);
	    rem--;
	}
	else{
	    printf("%d ",c[i]);
	}
    }
    printf("\n");
    return 0;
}
