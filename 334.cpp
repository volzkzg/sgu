#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)
#define mkp make_pair

using namespace std;

struct node
{
    node(){}
    node(int _x, int _y):x(_x),y(_y){}
    int x,y;
}point[20];
int n,m,p,map[10][10],ans_map[10][10],ans = 0x7FFFFFFF/2;
char ans_squ[1000][1000],mark,c[10][10];
bool use[20],vis[4][4];
string s;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int nextx(int x,int y) 
{ return (y == 3) ? x + 1 : x; }
int nexty(int x,int y)
{ return (y == 3) ? 1 : y + 1; }
bool up_link(int u,int v)
{ return ((point[u].x == point[v].x + 1) && (point[u].y == point[v].y)); }
bool left_link(int u,int v)
{ return ((point[u].x == point[v].x) && (point[u].y == point[v].y + 1)); }

void look(int x,int y,int map[][10])
{
    if (!vis[x-1][y] && up_link(map[x][y],map[x-1][y]) && x-1>=1)
	{
	    vis[x-1][y] = true;
	    c[x-1][y] = c[x][y];
	    look(x-1,y,map);
	}
    if (!vis[x+1][y] && up_link(map[x+1][y],map[x][y]) && x+1<=3)
	{
	    vis[x+1][y] = true;
	    c[x+1][y] = c[x][y];
	    look(x+1,y,map);
	}
    if (!vis[x][y-1] && left_link(map[x][y],map[x][y-1]) && y-1>=1)
	{
	    vis[x][y-1] = true;
	    c[x][y-1] = c[x][y];
	    look(x,y-1,map);
	}
    if (!vis[x][y+1] && left_link(map[x][y+1],map[x][y]) && y+1<=3)
	{
	    vis[x][y+1] = true;
	    c[x][y+1] = c[x][y];
	    look(x,y+1,map);
	}
}
int get_block(int m[][10])
{
    mark = 'A' - 1;
    memset(vis,false,sizeof(vis));
    rep(i,1,3) rep(j,1,3) if (!vis[i][j])
	{
	    c[i][j] = (++mark);
	    vis[i][j] = true;
	    look(i,j,m);
	}
    return (mark - 'A' + 1);
}
void dfs(int x,int y)
{
    if (x == 4)
	{
	    int block = get_block(map);
	    if (block < ans)
		{
		    ans = block;
		    rep(i,1,3) rep(j,1,3) ans_map[i][j] = map[i][j];
		}
	    return;
	}
    rep(i,1,9)
	if (!use[i])
	    {
		use[i] = true;
		map[x][y] = i;
		dfs(nextx(x,y),nexty(x,y));
		use[i] = false;
	    }
}

void print()
{
    get_block(ans_map);
    cout << ans << endl;
    memset(ans_squ,'.',sizeof(ans_squ));
    rep(i,1,3) rep(j,1,3)
	{
	    int num = ans_map[i][j];
	    int x = point[num].x;
	    int y = point[num].y;
	    ans_squ[x][y] = c[i][j];
	}
    rep(i,1,n)
	{
	    rep(j,1,m) cout << ans_squ[i][j];
	    cout << endl;
	}

    cout << endl;
    rep(i,1,3) 
	{
	    rep(j,1,3) cout << c[i][j];
	    cout << endl;
	}
}

int main()
{
    cin >> n >> m;
    rep(i,1,n)
	{
	    cin >> s;
	    rep(j,0,s.size()) if (s[j] == 'X')
		point[++p] = node(i,j+1);
	}
    point[0] = node(-1,-1);
    
    dfs(1,1);
    print();
    
    return 0;
}
