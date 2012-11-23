/*
 *NAME: Little Kings
 *LANG:C++
 *Source:sgu223
 *Method:×´Ì¬Ñ¹ËõDP
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const int MAXN = 200,MAXS = 300,MAXPN = 200;
int s[MAXS],c[MAXS];
LL f[2][MAXS][MAXPN],ans;
int n,pn;
void dfs(int p,int last,int now,int cnt){
    if (p == n){s[++s[0]]=now;c[s[0]]=cnt;return ;}
    dfs(p+1,0,now*2,cnt);
    if (!last) dfs(p+1,1,now*2+1,cnt+1);
}
int main(){
    cin >> n >> pn;
    if (pn>pow((n+1)/2,2)){
	cout << 0  << endl;
	return 0;
    }
    dfs(0,0,0,0);
    f[0][1][0]=1;
    for (int i=1;i<=n;++i){
	for (int j=1;j<=s[0];++j)
	    for (int k=c[j];k<=pn;++k)
		for (int p=1;p<=s[0];++p)
		    if (!(s[p] & s[j]) && ! (s[p] & (s[j] << 1))  && !(s[p] &(s[j] >> 1)) && (k-c[j]>=c[p]))
			f[i & 1][j][k] += f[1-i&1][p][k-c[j]];
	memset(f[1-i&1],0,sizeof(f[1-i&1]));
    }
    for (int i=1;i<=s[0];++i) ans += f[n&1][i][pn];
    cout << ans << endl;
    return 0;
}


