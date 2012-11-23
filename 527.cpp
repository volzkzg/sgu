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

char a[33][33],b[33][33];
int num[66666666],n,m,row[33],last[33];
int ans,pp;

void dfs(int now,int t,int pos)
{
    if (pos == m)
	{
	    num[now] = t;
	    return;
	}
    dfs(now*2+1,t+1,pos+1);
    dfs(now*2,t,pos+1);
}

void getRowNum(int x)
{
    int tmp = 0;
    rep(i,1,m) tmp = tmp*2+(a[x][i] == '*');
    row[x] = tmp;
}

void find(int s,int t,int p)
{
    if (t>n || t>=ans || s>n+1) return;
    pp = p|last[s];
    if (num[pp]<=t) {ans = t;return;}
    rep(i,s,n)
	{
	    find(i+1,t+1,p);
	    p|=row[i];
	}
}

int main()
{
    freopen("test.in","r",stdin);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    rep(i,1,n) rep(j,1,m) cin >> b[i][j];
    if (n<m) 
	{
	    swap(n,m);
	    rep(i,1,n) rep(j,1,m) a[i][j] = b[j][i];
	}
    else 
	rep(i,1,n) rep(j,1,m) a[i][j] = b[i][j];

    dfs(0,0,0);
    rep(i,1,n) getRowNum(i);
    rrep(i,n,1) last[i] = last[i+1]|row[i];

    ans = 0x7FFFFFFF;
    find(1,0,0);
    cout << ans << endl;
    return 0;
}
