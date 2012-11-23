/*
 *NAME:Little Queen
 *LANG:C++
 *Source:sgu224
 */
#include <cstdio>
using namespace std;
typedef long long LL;
LL sum,upperlim,n,k;
void test(int ld,int rd,int line,int cnt){
    int pos , p;
    if (line<n && cnt<k){
	pos = upperlim & ~(ld | rd);
	while (pos){
	    p = pos & -pos;
	    pos = pos - p;
	    test((ld+p) << 1,(rd+p) >> 1,line+1,cnt+1);
	}
	test(ld << 1,rd >> 1,line+1,cnt);
    }
    else if (cnt == k) sum++;
}
int main(){
    scanf("%d%d\n",&n,&k);
    if (k>n) {
	printf("0\n");
	return 0;
    }
    upperlim = (1 <<  n)-1;
    test(0,0,0,0);
    printf("%I64d\n",sum);
    return 0;
}
