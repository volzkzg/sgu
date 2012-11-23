#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

struct P{int deg,pos;}in[101];
int n,sum,bre;
short win[10001],lose[10001];

bool cmp(const P & a,const P & b)
{
    if (a.deg == b.deg) return (a.pos<b.pos);
    return (a.deg>b.deg);
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    rep(i,1,n) cin >> in[i].deg,in[i].pos = i,sum+=in[i].deg;sum/=2;
    cout << sum << endl;

    sort(in+1,in+n+1,cmp);
    int winPos=1;
    rep(i,1,n)
	{
	    if (in[i].deg>1)
		{
		    int p = in[i].deg;
		    rep(j,1,p-1)
			{
			    win[winPos++] = in[i].pos;
			    in[i].deg--;
			    if (winPos>sum) {bre = i;break;}
			}
		    if (winPos>sum) {bre = i;break;}
		    lose[winPos] = in[i].pos;in[i].deg--;
		}
	}
    int losePos = 1;
    rep(i,1,in[bre].deg) 
	{
	    while (lose[losePos]!=0 || 
		   (lose[losePos]==0 && win[losePos] == in[bre].pos)) losePos++;
	    lose[losePos] = in[bre].pos;
	}bre = in[bre].pos;
    sort(in+1,in+n+1,cmp);
    rep(i,1,n)
	{
	    if (in[i].pos == bre) continue;
	    losePos = 1;
	    rep(j,1,in[i].deg)
		{
		    while (lose[losePos]!=0 || 
			   (lose[losePos]==0 && win[losePos] == in[i].pos)) losePos++;
		    lose[losePos] = in[i].pos;
		}
	}
    
    rep(i,1,sum)
	cout << win[i] << " " << lose[i] << endl;
    
    return 0;
    
}
