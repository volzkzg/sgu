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

int T,n,m,S[10],cirLen;
bool status[1001];//use false to mark N-Positions,true to mark P-Positions

bool check(int u,int w,int v)
{
    rep(i,0,w-1)
	if (status[u+i]!=status[v+i]) return false;
    return true;
}
void theIniter()
{
    cin >> n >> m;S[0] = 1;
    rep(i,1,m) cin >> S[i];
    status[0] = false;
    rep(i,1,1000) 
	{
	    bool che = true;
	    rep(j,0,m) 
		{
		    if (i-S[j]<0) continue;
		    if (status[i-S[j]]) che = false;
		}
	    status[i] = che;
	}
    rep(len,1,300)
	{
	    bool che = true;
	    rep(t,1,(1000/len)-1)
		if (!check(0,len,len*t)) {che = false;break;}
	    if (che) {cirLen = len;break;}
	}
}
void thePrinter()
{
    if (status[n%cirLen]) 
	cout << "SECOND PLAYER MUST WIN" << endl;
    else
	cout << "FIRST PLAYER MUST WIN" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
	{
	    theIniter();
	    thePrinter();
	}
}
