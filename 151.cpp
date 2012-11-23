/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

double a,b,c,m,x,y;

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%lf %lf %lf\n",&c,&b,&m);
    if ((a = c*c+b*b-2*m*m) >= 0){
	a = sqrt(fabs(a)/2)*2;
	x = (b*b+c*c-a*a)/(2*c);
	y = sqrt(fabs(b*b-x*x));
	printf("%.5lf %.5lf\n",0,0);
	printf("%.5lf %.5lf\n",c,0);
	printf("%.5lf %.5lf\n",x,y);
    }else
	printf("Mission impossible\n");
}
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int main()
{
    double c,b,m,x,y;
    scanf("%lf%lf%lf",&c,&b,&m);
    if (2*m<fabs(c-b) || 2*m>c+b)
        printf("Mission impossible\n");
    else
    {
        x=(4*m*m-c*c-b*b)/c/2;
        y=b*b-x*x>=0?sqrt(b*b-x*x):0;
        printf("%.5lf %.5lf\n%.5lf %.5lf\n%.5lf %.5lf\n",0.0,0.0,c,0.0,x,y);
    }
    return 0;
}
