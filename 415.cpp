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

bool f[11111];
int a[222],ans[222],n,x;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> x;
    rep(i,1,n) cin >> a[i];
    sort(a+1,a+n+1);
    rep(i,1,n)
	{ 
	    memset(f,false,sizeof(f));
	    f[0] = true;
	    rep(j,1,n) if (i!=j && a[j]<=x)
		{
		    rrep(k,x,1)
			if (!f[k] && k-a[j]>=0 && f[k-a[j]])
			    f[k] = true;
		}
	    if (!f[x]) ans[++ans[0]] = a[i];
	}
    sort(ans+1,ans+ans[0]+1);
    cout << ans[0] << endl;
    rep(i,1,ans[0]) cout << ans[i] << " " ;
    cout << endl;
    return 0;
}
