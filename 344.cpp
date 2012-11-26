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

const int maxn = 1111;
struct node
{
    int x,y;
    node(){}
    node(int xx,int yy):x(xx),y(yy){}
}q[maxn*maxn*4];
int n,m,l,r,ans;
char c[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i,1,n) rep(j,1,m) 
	{
	    cin >> c[i][j];
	    if (c[i][j] == 'X') 
		{
		    q[r++] = node(i,j);
		    vis[i][j] = true;
		    ans++;
		}
	}
    while (l<r)
	{
	    node tmp = q[l++];
	    int x,y;
	    x = tmp.x;
	    y = tmp.y;
	    rep(i,0,3)
		{
		    int xx = x+dir[i][0];
		    int yy = y+dir[i][1];
		    if (xx>=1 && xx<=n && yy>=1 && yy<=m &&
			vis[xx][yy] == false)
			{
			    rep(j,0,3) if (i+j!=3)
				{
				    int xxx = xx+dir[j][0];
				    int yyy = yy+dir[j][1];
				    if (xxx>=1 && xxx<=n && yyy>=1 && yyy<=m &&
					vis[xxx][yyy] == true)
					{
					    vis[xx][yy] = true;
					    q[r++] = node(xx,yy);
					    ans++;
					    break;
					}
				}
			}
		}
	}
    cout << ans << endl;
    return 0;
}

