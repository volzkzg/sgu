#include <cstdio>
#include <iostream>
#define rep(i,j,k) for (int i=j;i<=k;++i)

using namespace std;

int a[222],b[222],m,n,k,l,r,o;
bool vis[222];

bool haveCommon(int i,int j,int &k)
{
    int p = b[i]^b[j];
    for (k=1;k<=m;++k) if (b[k] == p) return true;
    return false;
}
int main()
{
    cin >> m;
    rep(i,1,m) cin >> b[i];
    if (m == 1)
	{
	    cout << b[1]+1 << " " << (b[1]^(b[1]+1)) << endl;
	    return 0;
	}
    rep(i,1,m) rep(j,1,m) if (i!=j) if (haveCommon(i,j,k))
	{
	    vis[i] = vis[j] = vis[k] = true;
	    a[1] = 0,a[2] = b[i],a[3] = b[j];
	    n = 3;
	    l = i,r = j;
	    rep(ii,1,m) if (!vis[ii])
		if (haveCommon(ii,l,o) && haveCommon(ii,r,o))
		    a[++n] = b[ii];
	    rep(ii,1,n) cout << a[ii] << " ";
	    cout << endl;
	    return 0;
	}
}
