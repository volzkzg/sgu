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

const int maxn = 666;
struct node
{
    int key,p1,p2;
    node(){}
    node(int kk,int pp1,int pp2):key(kk),p1(pp1),p2(pp2){}
    bool operator <(const node & a) const
    {
	return key<a.key;
    }
}xMan[maxn],yMan[maxn];
int xNum,yNum,n;
long long ans;

inline int bin1(int x)
{
    int l = 1,r = yNum,mid,pos = yNum+1;
    while (l<=r)
	{
	    mid = (l+r)>>1;
	    if (yMan[mid].key>=x)
		r = mid-1,pos = mid;
	    else
		l = mid+1;
	}
    return pos;
}

inline int bin2(int x)
{
    int l = 1,r = yNum,mid,pos = -1;
    while (l<=r)
	{
	    mid = (l+r)>>1;
	    if (yMan[mid].key<=x)
		l = mid+1,pos = mid;
	    else
		r = mid-1;
	}
    return pos;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i,1,n)
	{
	    int x1,y1,x2,y2;
	    cin >> x1 >> y1 >> x2 >> y2;
	    if (x1 == x2) xMan[++xNum] = node(x1,min(y1,y2),max(y1,y2));
	    else yMan[++yNum] = node(y1,min(x1,x2),max(x1,x2));
	}
    sort(xMan+1,xMan+xNum+1);
    sort(yMan+1,yMan+yNum+1);
    rep(i,1,xNum) rep(j,i+1,xNum) if (xMan[i].key<xMan[j].key)
	{
	    int low = max(xMan[i].p1,xMan[j].p1);
	    int high = min(xMan[i].p2,xMan[j].p2);
	    if (low>=high) continue;
	    int l1 = bin1(low);
	    int l2 = bin2(high);
	    int num = 0;
	    rep(k,l1,l2) if (yMan[k].p1<=xMan[i].key && 
			     yMan[k].p2>=xMan[j].key)
		num++;
	    ans = ans+(num*(num-1)/2);
	}
    cout << ans << endl;
    return 0;
}
