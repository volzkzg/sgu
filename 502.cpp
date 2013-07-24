#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#define rep(i,j,k) for (int i = j; i <= k; ++i)
#define rrep(i,j,k) for (int i = j; i >= k; --i)

using namespace std;

long long num[10],len;

void dfs(long long pos,long long sum)
{
    if (len == pos)
	{
	    if (sum % 17 == 0)
		{
		    cout << sum << endl;
		    exit(0);
		}
	    return;
	}
    rep(i,0,9) if (num[i])
	{
	    if (i == 0 && pos == 0) continue;
	    num[i]--;
	    dfs(pos + 1, sum * 10 + i);
	    num[i]++;
	}
}

int main()
{
    string s;
    cin >> s;
    len = s.size();
    rep(i,0,len-1) num[s[i]-'0']++;
    dfs(0,0);
    cout << -1 << endl;
    return 0;
}

