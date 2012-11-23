/*
 *NAME:Inversions
 *LANG:C++
 *SOURCE:sgu180
 *METHOD:归并排序求逆序数
 *Times:2,ans没开long long 多交了一次。。
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 66666,INF = 0x7FFFFFFF;
int a[maxn];
long long ans,n;
void Merge(int p,int q,int r){
    int n1 = q-p+1,n2 = r-q;
    int L[maxn],R[maxn];
    for (int i=1;i<=n1;++i) L[i] = a[p+i-1];L[n1+1]=INF;
    for (int i=1;i<=n2;++i) R[i] = a[q+i];R[n2+1]=INF;
    int i =1,j=1;
    for (int k=p;k<=r;++k){
	if (L[i]<=R[j]){
	    a[k] = L[i];
	    i++;
	}
	else{
	    a[k] = R[j];
	    j++;ans+=(n1-i+1);
	}
    }
}
void MergeSort(int p,int r){
    if (p<r){int q = (p+r)/2;
	MergeSort(p,q);
	MergeSort(q+1,r);
	Merge(p,q,r);
    }
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;++i)
	cin >> a[i];
    MergeSort(1,n);
    cout << ans << endl;
}
