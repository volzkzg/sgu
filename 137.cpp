#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

int n,k,add,ans[1001];

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> k;
    add = k/n;k = k%n;
    
    int x = k,y = n-k,r;
    rep(i,1,n-1)
	{
	    if ((x*i+1)%n == 0 &&
		(y*i-1)%n == 0)
		{
		    r = i;
		    break;
		}
	}

    int pos = 0;
    rep(i,1,k) ans[pos] = 1,pos = (pos+r)%n;
    rep(i,0,n-1) ans[i]+=add;
    ans[0]--,ans[n-1]++;
    
    rep(i,0,n-2) cout << ans[i] << " ";cout << ans[n-1] << endl;
    
    return 0;

}
