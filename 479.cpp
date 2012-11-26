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

struct node
{
    int x,y;
    node(){}
    node(int i,int j):x(i),y(j){}
};
node queue[222*222],ans[222*222];
bool vis[222][222];
int l,r,a[222][222],ansNum;
int turn[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i,1,n) rep(j,1,m) 
	{
	    cin >> a[i][j];
	    if (a[i][j] == 1) queue[r++] = node(i,j);
	}
    while (l<r)
	{
	    node k = queue[l++];
	    ans[++ansNum] = k;
	    int x = k.x,y = k.y;
	    vis[x][y] = true;
	    if (a[x][y]!=1) {cout << "No solution" << endl;return 0;}
	    a[x][y]--;
	    rep(i,0,3)
		{
		    int xx = x+turn[i][0];
		    int yy = y+turn[i][1];
		    if (xx>=1 && xx<=n && yy>=1 && yy<=m)
			{
			    if (a[xx][yy]>=1) a[xx][yy]--;
			    if (a[xx][yy] == 1) 
				queue[r++] = node(xx,yy);
			}
		}
	}
    rep(i,1,n) rep(j,1,m) 
	if (!vis[i][j]) {cout << "No solution" << endl;return 0;};
    rrep(i,ansNum,1) 
	cout << ans[i].x << " " << ans[i].y << endl;
    return 0;
}
