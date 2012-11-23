#include <cstdio>
using namespace std;
 
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    if (n==2) printf("3 4\n5 2 3\n");
    else
    {
        printf("%d",k=n);
        for (i=2;i<n;i++)
            for (j=n-i+1;j<n;j++) printf(" %d",i*n+j+1);
        printf("\n%d",k+=1+(n&1));
        for (j=0;j<n-1;j++) printf(" %d",n*2+j*(n-1));
        for (k+=2,i=n;k<3*n+1;k+=2,i--)
        {
            printf("\n%d",k);
            for (j=0;j<i;j++) printf(" %d",i+j*(n-1));
        }
    }
    return 0;
}
