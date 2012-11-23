/*
 *NAME:telecasting station
 *LANG:C++
 *Source:sgu114
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int n;
pair<int,double> city[15100];;
long long sum=0,sum1=0;
int main(){
    cin >> n;
    for (int i=0;i<n;++i){
	cin >> city[i].first >> city[i].second;
	sum+=city[i].second;
    }
    sort(city,city+n);
    for (int i=0;i<n;++i){
	long long before = sum1;
	sum1+=city[i].second;
	if (sum1==sum/2 && sum%2==0){
	    cout << setiosflags(ios::fixed)
		 << setprecision(5)
		 << (double)(city[i].first+city[i+1].first)/2 << endl;
	    return 0;
	}
	if (sum1==((sum+1)/2) && sum%2==1){
	    cout << setiosflags(ios::fixed)
		 << setprecision(5) 
		 << (double)city[i].first << endl;
	    return 0;
	}
	if (before<sum/2 && sum1>sum/2){
	    cout << setiosflags(ios::fixed)
		 << setprecision(5) 
		 << (double)city[i].first << endl;
	    return 0;
	}
    }
    return 0;

}
