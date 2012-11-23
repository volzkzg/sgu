/*
 *NAME:Another Chocolate Maniac
 *LANG:C++
 *SOURCE:sgu132
 *METHOD:带集合的动态规划
 *TIMES:5
 *TIPS:
 *Time Complexity:M*4^N
 *Space Complexity:4^N
 *因为该题和覆盖满棋盘的问题不一样,覆盖满棋盘的问题,你只要知道
 *当前行的状态就可以推出上一行的状态(因为要满足上一行全放满)
 *而这道题目这样做就会有后效性,因此要用两维分别表示当前行和上一行的状态
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int mn = 80,mm = 10,ms = 512,INF = 0x7FFFFFFF/2;
int f[2][ms][ms],n,m,i,j,k,t;
int a[mn],mi[10]={1};
char op[10];int tmpJ,tmpK;
void dfs(int p,int j,int k,int s,int cnt){
    //保证当前行的前两行不能放入2*1的巧克力
    if (p > 0 && ((k & mi[p-1]) == 0) && ((j & mi[p-1]) == 0)) return ;
    //保证当前行上一行不能放入1*2的巧克力
    if (p > 1 && ((k & mi[p-1]) == 0) && ((k & mi[p-2]) == 0)) return;
    //转移
    if (p == m){
	f[i & 1][k][s] = min(f[i & 1][k][s],f[1-(i&1)][tmpJ][tmpK]+cnt);
	return;
    }
    //什么都不放的状态
    dfs(p+1,j,k,s,cnt);
    //在当前行的上一行放入一个1*2的骨牌
    if (p < (m-1) && ((k & mi[p]) == 0) && ((k & mi[p+1]) ==0)) 
	dfs(p+1,j,k | mi[p] | mi[p+1],s,cnt+1);
    //在当前行的上一行放入一个2*1的骨牌,并影响到当前行
    if (((k & mi[p]) == 0) && ((s & mi[p])==0))
	dfs(p+1,j,k | mi[p],s | mi[p],cnt+1);
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d %d\n",&n,&m);t = (1 << m)-1;
    for (i=1;i<=m;++i) mi[i] = mi[i-1] *2;//计算2的幂次,用来减少计算量
    for (i = 1;i<=n;++i){
	scanf("%s\n",op+1);
	for (j=1;j<=m;++j)
	    a[i] = a[i]*2+(op[j]=='*');
	/*
	 *读入每一行的不能覆盖的方案,二进制转十进制保存
	 *不能放为1,能放为0
	 */
    }
    /*
     *初始化
     */
    for (j = 0;j<=t;++j)
	for (k=0;k<=t;++k) f[0][j][k] = INF;
    f[0][t][a[1]] = 0;
    /*
     *动归过程
     */
    for (i = 1;i<=n;++i){
	//初始化
	for (j=0;j<=t;++j)
	    for (k=0;k<=t;++k)
		f[i & 1][j][k] = INF;
	//枚举当前行前两行的状态
	for (j=0;j<=t;++j)
	    for (k=0;k<=t;++k)
		if (f[1 - (i & 1)][j][k] != INF) {
		    tmpJ = j,tmpK = k,dfs(0,j,k,a[i+1],0);
		}
    }int ans = INF;
    for (i = 0;i<=t;++i)
	ans = min (ans,f[n & 1][i][0]);
    printf("%d\n",ans);
    return 0;
}
