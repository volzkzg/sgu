/*
 *NAME:Nearly prime numbers
 *LANG:C++
 *Source:sgu113
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int t,n,num,k;
int prime[7000];
bool check[33001];

bool checkIt(int x){
    if (x==1) return false;
    int y = sqrt(x);
    for (int i=0;i<num;++i){
	if (prime[i]>y) return true;
	if (x%prime[i] == 0) return false;
    }
    return true;
}
int main(){
    memset(check,true,sizeof(check));
    for (int i=2;i<=33000;++i){
	if (check[i]) prime[num++]=i;
	for (int j=0;j<num;++j){
	    if (prime[j]*i>33000) break;
	    check[prime[j]*i]=false;
	    if (i%prime[j]==0) break;
	}
    }
    scanf("%d",&t);
    for (int i=1;i<=t;++i){
	cin >> k;bool f=false;
	for (int j=0;j<num;++j){
	    if (k % prime[j]==0 && checkIt(k/prime[j])){
		printf("%s\n","Yes");f=true;
		break;
	    }
	    if (prime[j]>sqrt(k)) break;
	}
	if (!f) printf("%s\n","No");
    }
}
