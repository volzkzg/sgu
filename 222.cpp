/*
 *NAME:Little Rooks
 *LANG:C++
 *Source:sgu222
 */
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
LL n,k,ans=1;
int main(){
    cin >> n >> k;
    if (k>n*n){
	cout << 0 << endl;
	return 0;
    }
    for (int i=n;i>=n-k+1;i--)
	ans*=i;
    ans *=ans;
    for (int i=2;i<=k;++i)
	ans/=i;
    cout << ans << endl;
    return 0;
}
