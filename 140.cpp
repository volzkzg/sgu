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

int n,p,a,b;
short prev[10001],ans[101],posi[10001];
bool f[10001],ff[10001];

int main()
{
    ios::sync_with_stdio(false);
    
    memset(f,false,sizeof(f));
    cin >> n >> b >> p;
    
    f[0] = true;
    rep(i,1,n)
	{
	    cin >> a;
	    rep(j,0,b-1) ff[j] = f[j];
	    rep(j,0,b-1) 
		if (ff[j])
		    {
			int pos,last=j;
			pos=last+a;pos%=b;
			while (!ff[pos])
			    {
				f[pos] = true;
				posi[pos] = i;prev[pos] = last;
				last = pos;pos += a,pos%=b;
			    }
		    }
	}
    
    int re = p%b;
    if (f[re])
	{
	    cout << "YES" << endl;
	    while (re!=0)
		{
		    ans[posi[re]]++;
		    re = prev[re];
		}
	    rep(i,1,n-1) cout << ans[i] << " ";
	    cout << ans[n] << endl;
	}
    else
	cout << "NO" << endl;
}
