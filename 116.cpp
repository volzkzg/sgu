/*
 *NAME:Index of super-prime
 *LANG:C++
 *Source:sgu116
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool check[10101];
int prime[8000];
int n,k;
struct node{
    bool f;
    int pre;
    int time;
}num[10101];

void print(int w){
    if (w==0) return;
    else print(w-num[w].pre);
    cout << num[w].pre;
    if (w!=k) cout << " " ;
    else cout << endl;
}
int main(){
    //init
    num[0].f=true;
    cin >> k;
    for (int i=1;i<=k;++i) {num[i].f=false;num[i].time=0x7FFFFFFF/2;}
    memset(check,true,sizeof(check));check[1]=false;
    for (int i=2;i<=k;++i){
	if (check[i]) prime[n++]=i;
	for (int j=0;j<n;++j){
	    if (prime[j]*i>10000) break;
	    check[prime[j]*i]=false;
	    if (i%prime[j]==0) break;
	}
    }
    //solve
    for (int i=1;i<=k;++i)
	for (int j=0;j<n;++j)
	    if (check[j+1] && i-prime[j]>=0){
		if (num[i-prime[j]].f &&
		    num[i-prime[j]].time+1<num[i].time){
		    num[i].f=true;
		    num[i].pre=prime[j];
		    num[i].time=num[i-prime[j]].time+1;
		}
	    }
    //print
    if (num[k].f){
	cout << num[k].time << endl;
	print(k);
    }
    else {
	cout << 0 << endl;
    }
    return 0;
}
