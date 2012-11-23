#include <cstdio>
#include <algorithm>
using namespace std;
 
int main()
{
    int chains[100];
    int n,time(0);
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",chains+i);
    sort(chains,chains+n);
    for (int rest=n-1,i=0;rest>0;rest-=chains[i]+1,i++)
        time+=min(rest,chains[i]);
    printf("%d\n",time);
    return 0;
}
