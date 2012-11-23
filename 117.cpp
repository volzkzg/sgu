/*
 *NAME:Counting
 *LANG:C++
 *Source:sgu117
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n,m,k,p;
int check[10001];
int prime[5000];
int primeNum;
int kthNum;
int kth[5000];
int pos[5000];
int pthNum;
int pth[5000];
int pPos[5000];
int ans;
int main(){
    memset(check,true,sizeof(check));check[1]=false;
    memset(kth,0,sizeof(kth));
    for (int i=2;i<=10000;++i){
	if (check[i]) prime[primeNum++]=i;
	for (int j=0;j<primeNum;++j){
	    if (i*prime[j]>10000) break;
	    check[prime[j]*i]=false;
	    if (i%prime[j]==0) break;
	}
    }
    cin >> n >> m >> k;
    for (int i=0;i<primeNum;++i){
	if (k>0){
	    if (k%prime[i]==0 && k>0){
		pos[++kthNum]=i;
		while (k%prime[i]==0 && k>0){
		    kth[i]++; 
		    k/=prime[i];
		}
	    }
	}
	else break;
    }
    for (int t=1;t<=n;++t){
	cin >> p;memset(pth,0,sizeof(pth));pthNum=0;
	for (int i=0;i<primeNum;++i){
	    if (p>0){
		if (p%prime[i]==0){
		    pPos[++pthNum]=i;
		    while (p%prime[i]==0 && p>0){
			pth[i]++;
			p/=prime[i];
		    }
		}
	    }
	}
	for (int i=1;i<=pthNum;++i)
	    pth[pPos[i]]*=m;
	bool check=true;
	for (int i=1;i<=kthNum;++i)
	    if (pth[pos[i]]-kth[pos[i]]<0) {check=false;break;}
	if (check) ans++;
    }
    cout << ans << endl;
    return 0;
}
