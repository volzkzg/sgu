/*
 *NAME:Factorial
 *LANG:C++
 *Source:sgu154
 */
#include <iostream>
#include <cstdio>
using namespace std;

int q;
int main(){
    cin >> q;
    int l=1,r=500000016;
    while (l<r){
	int mid = (l+r)/2;
	//	cout << mid << endl;
	int tmp=mid,suffix=0;
	while (tmp>0){
	    suffix+=tmp/5;
	    tmp/=5;
	}
	if (suffix==q) {
	    if (mid-mid%5==0) cout << 1 << endl;
	    else cout << mid-mid%5 << endl;
	    return 0;
	}
	if (suffix>q) r=mid-1;
	else l=mid+1;
    }
    cout << "No solution" << endl;
    return 0;
}
