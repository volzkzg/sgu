#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <complex>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)
#define x real()
#define y imag()

using namespace std;

const double eps = 1e-8;
typedef complex<double> point;
point p[4111],seg[4111];
double len[4111],ans;
int n;

double dist(int u,int v)
{
  return (fabs(p[u].x-p[v].x) +
	  fabs(p[u].y-p[v].y));
}
int dblcmp(double k)
{
  if (fabs(k) < eps) return 0;
  if (k>0) return 1;
  else return -1;
}
double cross(point &u,point &v)
{
  return (u.x * v.y - u.y * v.x);
}
double cross(point &o,point &a,point &b)
{
  point oa = a-o;
  point ob = b-o;
  return cross(oa,ob);
}
bool intersect(point &o,point &a,point &b)
{
  if (o.x >= min(a.x,b.x) &&
      o.x <= max(a.x,b.x) &&
      o.y >= min(a.y,b.y) && 
      o.y <= max(a.y,b.y))
    return true;
  else
    return false;
}
bool cross(int u,int v)
{
  int d1 = dblcmp(cross(p[u],p[v],p[v+1]));
  int d2 = dblcmp(cross(p[u+1],p[v],p[v+1]));
  int d3 = dblcmp(cross(p[v],p[u],p[u+1]));
  int d4 = dblcmp(cross(p[v+1],p[u],p[u+1]));
  if (d1 * d2 < 0 && d3 * d4 < 0) return true;
  if (d1 == 0 && intersect(p[u],p[v],p[v+1])) return true;
  if (d2 == 0 && intersect(p[u+1],p[v],p[v+1])) return true;
  if (d3 == 0 && intersect(p[v],p[u],p[u+1])) return true;
  if (d4 == 0 && intersect(p[v+1],p[u],p[u+1])) return true;
  return false;
}

int main()
{
  freopen("test.in","r",stdin);
  freopen("test.out","w",stdout);
  ios::sync_with_stdio(false);
  
  cin >> n;
  cin >> p[1].x >> p[1].y;
  len[1] = 0;
  rep(i,2,n)
    {
      cin >> p[i].x >> p[i].y;
      len[i] = dist(i,i-1) + len[i-1];
    }
  ans = len[n];
  rep(i,1,n-1) rep(j,i+3,n-1)
    {
      if (cross(i,j))
	{
	  if (p[i].y == p[i+1].y)
	    {
	      ans = min(ans,len[j] - len[i+1] + fabs(p[i].y - p[j].y) + fabs(p[i+1].x - p[j].x));
	    }
	  else
	    {
	      ans = min(ans,len[j] - len[i+1] + fabs(p[i].x - p[j].x) + fabs(p[i+1].y - p[j].y));
	    }
	  break;
	}
    }
  cout << (int)ans << endl;
  return 0;
}
