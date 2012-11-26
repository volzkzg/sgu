#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iostream>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

const int maxn = 200001;
int q[maxn],qq[maxn],a[maxn],b[maxn],u,v,w;
int n,d,l=1,r,num,maxNum,ans1=-1,ans2=-1;

inline void read(int &data) {
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    data = 0;
    do
	{
	    data = data*10 + ch-'0';
	    ch = getchar(); 
	}
    while (ch >= '0' && ch <= '9');
}

int main()
{
    ios::sync_with_stdio(false);
    read(n);read(d);
    rep(i,1,n) {read(a[i]);read(b[i]);}
    rep(i,1,n) 
	{
	    while (r>0 && b[i]>b[q[r]]) r--;
	    q[++r] = i;
	    if (b[i]>b[qq[num]])
		qq[++num] = i;
	}
    rep(i,1,num)
	{
	    u = qq[i];
	    while (q[l]<u && l<r) l++;
	    w = l;
	    rep(j,w,r)
		{
		    v = q[j];
		    if (a[v]-a[u]>=d)
			{
			    if (b[v]+b[u]>maxNum)
				{
				    maxNum = b[v]+b[u];
				    ans1 = u,ans2 = v;
				    break;
				}
			    break;
			}
		    else l++;
		}
	}
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
