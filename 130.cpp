/*
 *NAME:Circle
 *LANG:C++
 *Source:sgu130
 */
#include <iostream>
#include <cstdio>
using namespace std;
int n;
long long f[40];
int main(){
    cin >> n;
    f[0]=1;f[1]=1;
    for (int i=2;i<=n;++i){
	for (int j=0;j<i;++j)
	    f[i]+=f[j]*f[i-1-j];
    }
    cout << f[n] << " " << n+1 << endl;
}
