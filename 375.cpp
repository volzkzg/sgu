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

void dfs(int n,int t)
{
    if (n == 1) {cout << t << endl;return;}
    int p1 = (n-1)/2;
    int p2 = (n+1)/2;
    int p =(p1 % 2==0)?p2:p1;
    dfs(p,t+1);cout << ((p==p1)+1) << " ";
}
int main()
{
    int n;
    cin >> n;
    if (n%2 == 0)
	{
	    cout << "No solution" << endl;
	    return 0;
	}
    else 
	dfs(n,0);
}
