#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <complex>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)
#define x real()
#define y imag()

using namespace std;

typedef complex<double> point;
point p[111111],P;
int n,m,k;

double det(point p,point q)
{
    return p.x*q.y-p.y*q.x;
}
void theIniter()
{
    cin >> n >> m >> k;
    rep(i,1,n) cin >> p[i].x >> p[i].y;
    rep(i,2,n) p[i]-=p[1];
}
void theSolver()
{
    rep(i,1,m)
	{
	    cin >> P.x >> P.y;
	    P-=p[1];
	    if (det(p[2],P)<0 || det(p[n],P)>0) continue;
	    int l = 3,r = n;
	    while (l<=r)
		{
		    int mid = (l+r)>>1;
		    double d1 = det(p[mid],P);
		    double d2 = det(p[mid-1],P);
		    if (d1<=0)
			{
			    if (d2>=0)
				{
				    if (det(P-p[mid-1],p[mid]-p[mid-1])<=0)
					k--;
				    break;
				}
			    else r = mid-1;
			}
		    else
			l = mid+1;
		}

	}
    if (k<=0)cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
    theIniter();
    theSolver();
}
