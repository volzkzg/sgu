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

int map[111][111];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m,ans,t;
char c;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i,1,n) rep(j,1,m)
	{ 
	    cin >> c;
	    map[i][j] = c-'0';
	    if (map[i][j]!=0) ans+=2;
	}
    rep(k,0,3) rep(i,1,n) rep(j,1,m)
	{
	    t = map[i][j]-map[i+dir[k][0]][j+dir[k][1]];
	    if (t>0) ans+=t;
	}
    cout << ans << endl;
}
