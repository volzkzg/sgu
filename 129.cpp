#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <complex>
#include <iomanip>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)
#define x real()
#define y imag()

using namespace std;

const int maxn = 401;
const long double pi = 3.1415926535897932,INF = 0x7FFFFFFF/2;
typedef complex<long double> point;
struct node{int pos;long double arg;}_node[maxn];
struct edge{point s,t;}_edge[maxn];
long double presion = 1e-12;
point p[maxn],pOrd[maxn],in,out,mid,non,zero,inter[2];
int n,m,sta,interNum;


int dblcmp(long double t)
{
    if (fabs(t)<presion) return 0;
    return (t>0)?1:-1;
}
long double cross(point p1,point p2){return p1.x*p2.y-p2.x*p1.y;}
bool cmp(const node & a,const node & b){return a.arg<b.arg;}
long double dist(point p1,point p2){return sqrt(fabs(p2.x-p1.x)*fabs(p2.x-p1.x)+
					   fabs(p2.y-p1.y)*fabs(p2.y-p1.y));}

void theIniter()
{
    cin >> n;
    zero.x = zero.y = 0;
    mid.x = mid.y = 0;
    non.x = non.y = -INF;
    rep(i,1,n) cin >> p[i].x >> p[i].y,mid+=p[i];
    mid.x/=(long double)n,mid.y/=(long double)n;
    rep(i,1,n) _node[i].pos = i,_node[i].arg = arg(p[i]-mid);
    sort(_node+1,_node+n+1,cmp);
    _edge[n].s = p[_node[n].pos],_edge[n].t = p[_node[1].pos];
    rep(i,1,n-1) _edge[i].s = p[_node[i].pos],_edge[i].t = p[_node[i+1].pos];
    pOrd[1] = p[_node[1].pos];
    rep(i,2,n) pOrd[i] = p[_node[i].pos]-pOrd[1];
}

bool intersect(point p,point p1,point p2)
{
    if (p.x>=min(p1.x,p2.x) &&
	p.x<=max(p1.x,p2.x) && 
	p.y>=min(p1.y,p2.y) && 
	p.y<=max(p1.y,p2.y)) return true;
    return false;
}

int check(point poi)
{
    poi-=pOrd[1];
    int dd1 = dblcmp(cross(poi,pOrd[2]));
    int dd2 = dblcmp(cross(poi,pOrd[n]));

    if ((dd1 == 0 && intersect(poi,zero,pOrd[2])) ||
	(dd2 == 0 && intersect(poi,zero,pOrd[n])))
	return 0;

    if (dd1>0 || dd2<0) return (-1);
    int l = 3,r = n;
    while (l<=r)
	{
	    int mid = (l+r)/2;
	    int d1 = dblcmp(cross(poi,pOrd[mid-1]));
	    int d2 = dblcmp(cross(poi,pOrd[mid]));
	    if (d1<=0)
		{
		    if (d2>=0)
			{
			    int d3=dblcmp(cross(poi-pOrd[mid-1],pOrd[mid]-pOrd[mid-1]));
			    if(d3<0)
				return 1;
			    if (d3 == 0) 
				return 0;
			    break;
			}
		    else l = mid+1;
		} 
	    else r = mid-1;
	}
    return (-1);
}

void thePrinter(long double t)
{
    cout << setiosflags(ios::fixed)
	 << setprecision(2)
	 << t
	 << endl;
}

void findInter(point a,point b)
{
    point ret;
    
    rep(i,1,n)
	{
	    if (dblcmp(cross(a-p[i],b-p[i]))==0 &&
		intersect(p[i],a,b))
		inter[interNum++] = p[i];
	}
    rep(i,1,n)
	{
	    point c = _edge[i].s;
	    point d = _edge[i].t;
	    long double s1,s2,s3,s4;
	    int d1,d2,d3,d4,d5;
	    
	    d1 = dblcmp(s1 = cross(c-a,d-a));
	    d2 = dblcmp(s2 = cross(c-b,d-b));
	    d3 = dblcmp(s3 = cross(a-c,b-c));
	    d4 = dblcmp(s4 = cross(a-d,b-d));
	    d5 = d1^d2;
	    
	    if ((d5 == -2 || d5 == 1 || d5 == -1) && (d3^d4) == -2)
		{
		    long double mul = fabs(s3)/fabs(s4);
		    ret.x = (c.x+mul*d.x)/(1.0+mul);
		    ret.y = (c.y+mul*d.y)/(1.0+mul);
		    inter[interNum++] = ret;
		}
	}
}

bool sameLine(point in,point out)
{
    rep(j,1,n)
	{
	    point c = _edge[j].s;
	    point d = _edge[j].t;
	    int d1 = dblcmp(cross(c-in,d-in));
	    int d2 = dblcmp(cross(c-out,d-out));
	    if (d1 == 0 && d2 == 0) 
		{thePrinter(0);return true;}
	}
    return false;
}

double getDist()
{
    interNum = 0;
    findInter(in,out);
    int check1 = check(in);
    int check2 = check(out);

    if (interNum == 0)
	{
	    if (check1==1 && check2==1)
		return (dist(in,out));
	}
    else
	if (interNum == 1)
	    {
		if (check1==1) return (dist(inter[0],in));
		if (check2==1) return (dist(inter[0],out));
	    }
	else
	    if (interNum == 2)
		{
		    return (dist(inter[0],inter[1]));
		}
    return 0;
}

void theSolver()
{
    cin >> m;
    rep(i,1,m)
	{
	    cin >> in.x >> in.y >> out.x >> out.y;
	    bool che = sameLine(in,out);
	    if (!che) thePrinter(getDist());
	}
}
int main()
{
    freopen("test5.in","r",stdin);
    freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);

    theIniter();
    theSolver();
}
