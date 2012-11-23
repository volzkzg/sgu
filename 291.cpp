#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

struct node{int x,y,ti,num;};
int q,c,n,t;
int number[22222],bel[1001][1001],tt[1001][1001];
int turn[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
queue<node> line;

void insert(int x,int y,int ti,int num)
{
    node p;
    p.x = x,p.y = y,p.ti = ti,p.num = num;
    line.push(p);
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
    
    cin >> q >> c >> n >> t;
    rep(i,1,n)
	{
	    int x,y;
	    cin >> x >> y;
	    if (x>q || x<=0 || y>c || y<=0) continue;
	    insert(x,y,0,i);
	    bel[x][y] = i;
	    tt[x][y] = 0;
	}

    while (!line.empty())
	{
	    node p = line.front();
	    line.pop();
	    int x,y,ti,num;
	    x = p.x,y = p.y,ti = p.ti,num = p.num;
	    if (ti>=t) continue;
	    rep(i,0,3)
		{
		    int xx = x+turn[i][0];
		    int yy = y+turn[i][1];
		    if (xx>q || xx<=0 || yy>c || yy<=0) continue;
		    if (bel[xx][yy] == 0)
			{
			    bel[xx][yy] = num;
			    tt[xx][yy] = ti;
			    insert(xx,yy,ti+1,num);
			}
		    else
			if (bel[xx][yy] == num && tt[xx][yy]>ti)
			    {
				tt[xx][yy] = ti;
				insert(xx,yy,ti+1,num);
			    }
		}
	}
    
    rep(i,1,q) rep(j,1,c)
	number[bel[i][j]]++;
    rep(i,1,n) cout << number[i] << endl;
    
    return 0;
}
