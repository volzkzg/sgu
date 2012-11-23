/*
 *Name:Little shop of flowers
 *LANG:C++
 *Source:sgu104
 */
#include <cstdio>
#include <cstring>
#define INF -0x7FFFFFFF/2
using namespace std;

int a[200][200],ff[200][200];
int f,v,max=INF;

void print(int x,int y){
    if (x>0){
	int i=x;
	while (ff[x][i]!=y) ++i;
	print(x-1,y-a[x][i]);
	printf("%d",i);
	if (x!=f) printf(" ");
	else printf("\n");
    }
}
int main(){
    scanf("%d %d",&f,&v);
    for (int i=1;i<=f;++i)
	for (int j=1;j<=v;++j)
	    scanf("%d",&a[i][j]);
    for (int i=0;i<=110;++i)
	for (int j=0;j<=110;++j)
	    ff[i][j]=INF;
    for (int i=0;i<=v;++i) ff[0][i]=0;
    for (int i=1;i<=f;++i)
	for (int j=i;j<=v;++j)
	    for (int k=0;k<j;++k)
		if (ff[i-1][k]+a[i][j]>ff[i][j])
		    ff[i][j]=ff[i-1][k]+a[i][j];
    for (int i=1;i<=v;++i)
	if (max<ff[f][i]) max=ff[f][i];
    printf("%d\n",max);
    print(f,max);
    return 0;
}
