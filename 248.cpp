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

int c1,c2,c3,x1,x2,x3,n,V;

int main()
{
    //    freopen("test.in","r",stdin);
    ios::sync_with_stdio(false);
    
    cin >> n;
    if (n==1)
	{
	    cin >> c1;
	    cin >> V;
	    if (V % c1 != 0) cout << -1 << endl;
	    else cout << V/c1 << endl;
	}
    else if (n==2)
	{
	    cin >> c1 >> c2;
	    cin >> V;
	    int maxX2 = V/c2,ans = 0x7FFFFFFF/2;
	    rep(i,0,maxX2)
		{
		    x2 = i;
		    if ((V-x2*c2)%c1!=0) continue;
		    x1 = (V-x2*c2)/c1;
		    ans = min(x1+x2,ans);
		}
	    if (ans == 0x7FFFFFFF/2) cout << -1 << endl;
	    else cout << ans << endl;
	}
    else 
	{
	    int tmp;
	    cin >> c1 >> c2 >> c3;
	    if (c2<c1){tmp = c1,c1 = c2,c2 = tmp;}
	    if (c3<c2){tmp = c2,c2 = c3,c3 = tmp;}
	    if (c2<c1){tmp = c1,c1 = c2,c2 = tmp;}
	    cin >> V;
	    int maxX3 = V/c3,ans = 0x7FFFFFFF/2,vv,cnt=0;
	    bool check = false;
	    rrep(i,maxX3,0)
		{
		    x3 = i;vv = V-c3*x3;
		    int maxX2 = vv/c2;
		    rrep(j,maxX2,0)
			{
			    x2 = j;
			    if ((vv-x2*c2)%c1!=0) continue;
			    x1 = (vv-x2*c2)/c1;
			    ans = min(ans,x1+x2+x3);
			}
		    if (ans != 0x7FFFFFFF/2) check = true;
		    if (check) cnt++;
		    if (cnt>=100) break;
		}
	    if (ans == 0x7FFFFFFF/2) cout << -1 << endl;
	    else cout << ans << endl;
	}
    return 0;
}
