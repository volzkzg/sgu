#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

int n;
double d[402],dd[402],ddd[402],ans,blk,tmp;

int main()
{
    ios::sync_with_stdio(false);
    ans = 0x7FFFFFFF;
    cin >> n;
    rep(i,1,n) cin >> d[i];
    rep(i,1,n) rep(j,i+1,n)
	{
	    blk = (d[j]-d[i])/(j-i);
	    tmp = 0;
	    rrep(k,i,1) dd[k] = d[i]-blk*tmp,tmp+=1;
	    tmp = 1;
	    rep(k,i+1,n) dd[k] = d[i]+blk*tmp,tmp+=1;
	    tmp = 0;
	    rep(k,1,n) tmp+=fabs(dd[k]-d[k]);
	    if (tmp<ans)
		{
		    ans = tmp;
		    rep(i,1,n) ddd[i] = dd[i];
		}
	}
    cout << setiosflags(ios::fixed) 
	 << setprecision(4)
	 << ans << endl;
    rep(i,1,n) 
	cout << setiosflags(ios::fixed)
	     << setprecision(10)
	     << ddd[i] << " " ;
    cout << endl;
    return 0;
}
