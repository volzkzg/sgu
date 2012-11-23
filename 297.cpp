#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

int n,m,k,ret;
int main(){
	cin >> n >> m;
	rep(i,1,m){
		cin >> k;
		k = k%n;
		ret+=k;
		while (ret>=n) ret-=n;
	}
	cout << ret << endl;
	return 0;
}
