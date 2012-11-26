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

struct node
{
    int first,second;
    node(){}
    node(int f,int s):first(f),second(s){}
    bool operator < (node a) const
    {
	if (second == a.second) return first<a.first;
	return second<a.second;
    }
};
set<node> planet;
int arrange[11111],num,t;
int minu,blk,n,k;

void add(int u)
{
    ++num;
    arrange[num] = u;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i,1,n) {cin >> k;planet.insert(node(i,k));}
    blk = (*planet.rbegin()).second;
    while (true)
	{
	    int u = (*planet.begin()).first;
	    int v = (*planet.begin()).second;
	    if (v*2>blk) break;
	    planet.erase(planet.begin());
	    while (v*2<=blk)
		{
		    v*=2;t++;
		    if (num<10000) add(u);
		}
	    planet.insert(node(u,v));
	}
    while (true)
	{
	    int u = (*planet.begin()).first;
	    int v = (*planet.begin()).second;
	    if ((v-minu)==blk-minu) break;
	    planet.erase(planet.begin());
	    int c = (v-minu)*2-(blk-minu);
	    rep(i,1,min(10000-num,c)) add(-1);
	    minu+=c;t+=c;
	    v = (v-minu)*2+minu;t++;
	    if (num<10000) add(u);
	    planet.insert(node(u,v));
	}
    blk -= minu;t+=blk;
    rep(i,1,min(10000-num,blk)) add(-1);
    cout << t << endl;
    if (t<=1000) 
	rep(i,1,t)
	    {
		if (arrange[i] == -1)
		    cout << "flying mission" << endl;
		else
		    cout << "science mission to the planet " << arrange[i] << endl;
	    }
    return 0;
}
