#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)

using namespace std;

const int maxNum = 1<<21;
bool f[maxNum];
int row[maxNum],col[maxNum],num[22],n,m;

int main(){
	/*
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	*/
	memset(f,false,sizeof(f));f[0] = true;
	cin >> n >> m;
	num[0] = 1;rep(i,1,n+m) num[i] = num[i-1]*2;

	rep(i,1,(1<<n)-1){
		rep(j,0,n-1){
			int tmp = (row[i-1] & num[j])?-1:1;
			if (!f[row[i-1]+tmp*num[j]]){
				row[i] = row[i-1]+tmp*num[j];
				f[row[i]] = true;
				break;
			}
		}

	}

	rep(i,1,(1<<m)-1){
		rep(j,n,n+m-1){
			int tmp = (col[i-1] & num[j])?-1:1;
			if (!f[col[i-1]+tmp*num[j]]){
				col[i] = col[i-1]+tmp*num[j];
				f[col[i]] = true;
				break;
			}
		}

	}

	rep(i,1,1<<n){
		int out = 0+row[i-1];
		rep(j,1,1<<m) cout << out+col[j-1] << " ";
		cout << endl;
	}return 0;

}
