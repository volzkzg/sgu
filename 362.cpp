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

int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
char c[4] = {'D','L','U','R'};
bool vis[11][11];
int n,m;

void dfs(int x,int y)
{
    vis[x][y] = true;
    rep(i,0,3)
	{
	    int xx = x+dir[i][0];
	    int yy = y+dir[i][1];
	    if (xx>=1 && xx<=n && yy>=1 && yy<=m && !vis[xx][yy])
		{cout << c[i];dfs(xx,yy);break;}
	}
}
int main()
{
    ios::sync_with_stdio(false);
    int x,y;
    cin >> n >> m;
    cin >> x >> y;
    dfs(x,y);
    cout << endl;
    return 0;
}

