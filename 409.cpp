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

const int maxn = 401;
int n,k,sx,sy,ex,ey,px,py;
char map[maxn][maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    rep(i,1,n*n) rep(j,1,n*n) map[i][j] = '.';
    rep(i,1,n) rep(j,1,n)
	{
	    sx = (i-1)*n+1;
	    sy = (j-1)*n+1;
	    ex = i*n;
	    ey = j*n;
	    px = (i-1)*n+j;
	    py = (j-1)*n+i;
	    rep(w,1,k)
		{
		    map[px][py] = '*';
		    py++;
		    if (py>ey) px++,py = sy;
		    if (px>ex) px = sx;
		}
	}
    rep(i,1,n*n) 
	{
	    rep(j,1,n*n) cout << map[i][j];
	    cout << endl;
	}
    return 0;
}
