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

int hitPoint[10],scorePoint[10],n,m,x,y;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i,1,n) hitPoint[i] = 100;
    rep(i,1,m)
	{
	    cin >> x >> y;
	    if (hitPoint[x]>0)
		{
		    if (hitPoint[y]>0) scorePoint[x]+=3;
		    hitPoint[y] -= 8;
		}
	}
    rep(i,1,n) if (hitPoint[i]>0) scorePoint[i]+=hitPoint[i]/2;
    rep(i,1,n) cout << hitPoint[i] << " " << scorePoint[i] << endl;
    return 0;
}
