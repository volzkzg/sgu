/*
 *Name:coprimes
 *LANG: C++
 *Source:sgu102
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

int ans=1,n;
bool check[10001];

int gcd(int a,int b){
    if (a!=0) return gcd(b%a,a);
    else return b;
}
int main(){
    //input
    scanf("%d",&n);
    memset(check,true,sizeof(check));
    //solve
    for (int i=2;i<n;++i){
	if (check[i]){
	    if (gcd(min(i,n),max(i,n))==1)
		ans++;
	    else
		for (int j=2;j*i<n;++j)
		    check[j*i]=false;
	}
	else
	    for (int j=2;j*i<n;++j)
		check[j*i]=false;
    }
    printf("%d\n",ans);
    //fout << ans << endl;
    return 0;
}
