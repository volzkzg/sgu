#include <cstdio>
#include <cmath>
using namespace std;
int n,k,ans,tmp;
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d\n%d\n",&n,&k);
    for (int i=1;i<=n;++i){
	scanf("%ld",&tmp);int tmp1 = pow(tmp,k);
	if (tmp1>0) ans += tmp1;
    }
    printf("%ld\n",ans);
}
