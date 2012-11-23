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

int main()
{
    ios::sync_with_stdio(false);
    
    int n;cin >> n;
    rep(i,1,n)
	{
	    long long ans,l=1,r=100000,M,mid;
	    bool check = false;
	    cin >> M;
	    while (l<=r)
		{
		    mid = (l+r)/2;ans = (1+mid)*mid/2+1;
		    if (ans==M) {check = true;break;}
		    if (ans<M) l = mid+1;else r = mid-1;
		}
	    if (check) cout << "YES";else cout << "NO";
	    cout << endl;
	}
    return 0;
}
