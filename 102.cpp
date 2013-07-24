#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)
#define MAX 11111

using namespace std;

int prime[MAX],phi[MAX],tot,n;
bool vis[MAX];

int main()
{
    ios::sync_with_stdio(false);
    phi[1] = 1;
    cin >> n;
    rep(i,2,n)
	{
	    if (!vis[i])
		{
		    prime[++tot] = i;
		    phi[i] = i-1;
		}
	    rep(j,1,tot)
		{
		    if (i * prime[j] > n) break;
		    vis[i * prime[j]] = true;
		    if (i % prime[j] == 0)
			{
			    phi[i * prime[j]] = phi[i] * prime[j];
			    break;
			}
		    else
			{
			    phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			}
		}
	}
    cout << phi[n] << endl;
    return 0;
}
