#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)

using namespace std;

string s;
int queue[1111],n,l,r,ans[1111],ansNum;

int main(){
	cin >> s;
	cin >> n;l = 1;
	rep(i,0,n-1){
		while (r>=l && s[queue[r]]<s[i]) r--;
		queue[++r] = i;
	}
	rep(i,n,s.size()-1){
		while (r>=l && s[queue[r]]<s[i]) r--;queue[++r] = i;
		while (queue[l]<i-n) l++;
		ans[++ansNum] = queue[l++];
	}l = 1;
	//while (s[ans[l]]=='0' && l<=ansNum) l++;
	//if (l<=ansNum) 
	rep(i,l,ansNum) cout << s[ans[i]];
	//else cout << 0 << endl;
	return 0;
}

