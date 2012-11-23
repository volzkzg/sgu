/*
 *NAME:987654321problem
 *LANG:C++
 *Source:sgu107
 */
#include <cstdio>
#define pZero printf("%d",0)
#define rep(i,p) for (int i=0;i<p;++i)
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    if (n<9) 
	pZero;
    else{
	printf("%d",8*((n!=9)?9:1));
	rep(i,n-10) pZero;
    }
    printf("\n");
}
