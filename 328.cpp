#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#define rep(i,j,k) for (long long i=j;i<=k;++i)
#define rrep(i,j,k) for (long long i=j;i>=k;--i)

using namespace std;

string s;
long long move,inside,last,len;

long long max(long long a,long long b)
{
    return (a>b)?a:b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> len;
    cin >> s;

    int tmp1,tmp2,ans = 0,l = 0,r = s.size()-1;
    while (s[l] == '0' && l <= r) l++,move++;
    tmp1 = move;
    if (l > r)
	{
	    if (tmp1 & 1) 
		cout << "FIRST" << endl;
	    else
		cout << "SECOND" << endl;
	    return 0;
	}
    while (s[r] == '0' && r >= l) r--,move++;
    tmp2 = move - tmp1;
    ans ^= tmp1;
    ans ^= tmp2;
    
    if (r-l+1 > 0)
	{
	    last = l;
	    rep(i,l+1,r)
		{
		    if (s[i] != '0')
			{
			    inside = i - last - 1;
			    if (s[i] == s[last])
				ans ^= 1;
			    last = i;
			}
		}
	}

    if (ans)
	cout << "FIRST" << endl;
    else
	cout << "SECOND" << endl;
    
    return 0;
}
