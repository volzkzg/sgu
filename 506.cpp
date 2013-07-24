#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
#define rep(i,j,k) for (int i = j; i <= k; ++i)
#define rrep(i,j,k) for (int i = j; i >= k; --i)

using namespace std;

string s,t;
long long ans,start[111],lens,lent;

int main()
{
    cin >> s >> t;
    lens = s.size();
    lent = t.size();

    memset(start,-1,sizeof(start));
    rep(i,0,lens-1)
	{
	    rrep(j,lent-1,1)
		if (s[i] == t[j])
		    start[j] = max(start[j],start[j-1]);
	    if (s[i] == t[0]) start[0] = i;
	    if (start[lent-1] != -1)
		ans += (start[lent-1]+1);
	}
    cout << ans << endl;
    return 0;
}

