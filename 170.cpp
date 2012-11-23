/*
 *NAME:Particles
 *LANG:C++
 *SOURCE:sgu170
 *TIMES:1
 *METHOD:模拟，按顺序找一个不相同的，然后往后找一个不相同的，跳到这个位置即可
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
string s1,s2;
int ans;
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    cin >> s1 >> s2;
    for (int i=0;i<s1.size();++i)
	if (s1[i]!=s2[i]){
	    bool f = false;int pos =0;
	    for (int j=i+1;j<s1.size();++j){
		if (s1[j]!=s1[i]){
		    ans += j-i;pos = j;
		    f = true;
		    break;
		}
	    }
	    if (!f) {
		cout << -1 << endl;
		return 0;
	    }
	    else
		for (int j=pos;j>i;--j) swap(s1[j],s1[j-1]);
	}
    cout << ans << endl;
    return 0;
}
