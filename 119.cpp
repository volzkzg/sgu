/*
 *Magic Pairs
 *LANG:C++
 *Source:sgu119
 *way:如果N|a0*x+b0*y,那么N|(a0*i)%i*x+(b0*i)%i*y,i>=0 && i<N
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define INF 0x7FFFFFFF
using namespace std;

pair<int,int> ans[10001];
int num,n,a0,b0;
int main(){
    cin >> n;
    cin >> a0 >> b0;
    for (int i=0;i<n;++i){
	ans[i].first=(a0*i)%n;
	ans[i].second=(b0*i)%n;
    }
    sort(ans,ans+n);
    ans[n].first=INF;ans[n].second=INF;
    if (ans[0].first!=ans[1].first || ans[0].second!=ans[1].second) num++;
    for (int i=1;i<n;++i) 
	if (ans[i].first!=ans[i+1].first || ans[i].second!=ans[i+1].second)
	    num++;
    cout << num << endl;
    if (ans[0].first!=ans[1].first || ans[0].second!=ans[1].second) 
	cout << ans[0].first << " " << ans[0].second << endl;
    for (int i=1;i<n;++i) 
	if (ans[i].first!=ans[i+1].first || ans[i].second!=ans[i+1].second)
	    cout << ans[i].first << " " << ans[i].second << endl;
}
