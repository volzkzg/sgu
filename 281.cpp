#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

string name[500001],s;
map<string,int> _map;
int n,rating[500001],block[500001];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i,1,n)
	{
	    cin >> name[i];
	    _map[name[i]] = i;
	}
    rep(i,1,n)
	{
	    cin >> s;
	    rating[_map[s]] = i;
	}
    block[1] = rating[1];
    rep(i,2,n) block[i] = max(block[i-1],rating[i]);
    int pre = 1,now = 1;
    while (now<=n)
	{
	    if (block[now] == now) 
		{
		    sort(name+pre,name+now+1);
		    pre = now+1;
		}
	    now++;
	}
    rep(i,1,n) cout << name[i] << endl;
    return 0;
}
