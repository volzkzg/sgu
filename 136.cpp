#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

int n,i,j,k;
double x[10002],y[10002];

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d\n",&n);
    for (i=1;i<=n;++i){
	scanf("%lf %lf\n",&x[i],&y[i]);
	x[0]+=(i&1)?x[i]:-x[i];
	y[0]+=(i&1)?y[i]:-y[i];
    }
    if (!(n&1)){
	if (x[0] == 0 && y[0] == 0)
	    {x[0] = -1,y[0] = 1;}
	else{
	    printf("NO\n");
	    return 0;
	}
    }printf("YES\n%.3lf %.3lf\n",x[0],y[0]);
    for (i=1;i<n;++i){
	x[i] = 2*x[i]-x[i-1];
	y[i] = 2*y[i]-y[i-1];
	printf("%.3lf %.3lf\n",x[i],y[i]);
    }return 0;
}
