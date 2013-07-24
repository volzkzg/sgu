#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

int num[1111111],n,m,x;

bool check(int pos)
{
    static int cnt,i;
    for (i = pos,cnt = 0; i <= m && cnt < 2; i += pos)
	cnt += num[i];
    return cnt > 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i,1,n)
	{
	    cin >> x;
	    num[x]++;
	    m = max(m,x);
	}
    rrep(mm,m,1)
	if (check(mm)) 
	    {
		cout << mm << endl;
		return 0;
	    }
    return 0;
}
