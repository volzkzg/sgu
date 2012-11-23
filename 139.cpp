/*
 *NAME:Help Needed!
 *LANG:C++
 *SOURCE:sgu139
 *TIMES:1
 *METHOD:判断0点所在位置距离目标点的汉密尔顿距离,以及序列逆序数的个数,如果两者同奇偶,那么为NO,否则为YES.
 *PROVE:当你移动0点时,他的汉密尔顿距离+或者-1,但是此时逆序数的个数会有奇数的变化,而目标状态两者是不同奇偶的,所以方法得证.
 */
#include <cstdio>
using namespace std;
int a[20],p;
int main(){
    for (int i=1;i<=16;++i){
	scanf("%d",&a[i]);
	if (! a[i]) p = (i % 4) + (i + 3)/4;
    }
    for (int i=1;i<16;++i)
	for (int j=i+1;j<=16;++j)
	    if (a[j]<a[i]) p--;
    if ((p+100) % 2) printf("YES\n");else printf("NO\n");
    return 0;
}
