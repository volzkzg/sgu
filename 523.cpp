#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

int n,f,k,a[111];
set<int> s;
bool vis[111];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> f;    
    rep(i,1,n) cin >> k,vis[k] = true,a[i] = k;
    rep(i,1,n) if (vis[a[i]])
	{
	    int to = a[i];
	    if (to>f)
		{
		    rep(i,f+1,to) if (vis[i])
			{
			    cout << i << " ";
			    vis[i] = false;
			}
		}
	    else
		{
		    rrep(i,f-1,to) if (vis[i])
			{
			    cout << i << " ";
			    vis[i] = false;
			}
		}
	}
    return 0;
}
