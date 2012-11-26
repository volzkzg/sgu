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

int a[2][51],n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;n/=2;
    if (n % 2 == 1)
	{
	    for (int t = 1,i = 0;i<n;++i,t+=2) 
		a[i%2][(-i+n)%n] = t;
	    for (int t = 2,i = 1;i<=n;++i,t+=2) 
		a[i%2][i%n] = t;
	}
    else
	{
	    int p = n*2+1;
	    for (int t = 1,i = 0;i<n/2;++i,t+=2) 
		{
		    //cout << i%2 << " " << (-i+n)%n << endl;
		    a[i%2][(-i+n)%n] = t;
		}
	    for (int t = 2,i = 1;i<=n/2;++i,t+=2)
		{
		    //cout << 1-i%2 << " " << i%n << endl;
		    a[i%2][i%n] = t;
		}
	    rep(i,0,n-1) 
		{
		    if (a[0][i]) a[1][i] = p- a[0][i];
		    else a[0][i] = p-a[1][i];
		}
	}
    rep(i,0,n-1) cout << a[0][i] << " " << a[1][i] << " " ;
    cout << endl;
    return 0;
}


