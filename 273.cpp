#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

int B,R,Y,W;
bool change[4][4][4],trans[202][202][4];
char toChar[4] = {'b','r','y','w'};
string s;

int toNum(char c)
{
    int ret;
    switch(c)
	{
	case 'b':ret=0;break;
	case 'r':ret=1;break;
	case 'y':ret=2;break;
	case 'w':ret=3;break;
	}
    return ret;
}
void theIniter()
{
    memset(change,false,sizeof(change));
    cin >> B >> R >> Y >> W;
    rep(i,1,B){cin >> s;change[toNum(s[0])][toNum(s[1])][toNum('b')]=true;}
    rep(i,1,R){cin >> s;change[toNum(s[0])][toNum(s[1])][toNum('r')]=true;}
    rep(i,1,Y){cin >> s;change[toNum(s[0])][toNum(s[1])][toNum('y')]=true;}
    rep(i,1,W){cin >> s;change[toNum(s[0])][toNum(s[1])][toNum('w')]=true;}
}
void theSolver()
{
    memset(trans,false,sizeof(trans));
    cin >> s;int strLen = s.size();
    rep(i,0,strLen-1) trans[i][i][toNum(s[i])]= true;
    rep(len,2,strLen) rep(i,0,strLen-1)
	{
	    if (i+len-1>=strLen) break;
	    rep(ii,1,len-1)
		{
		    int jj = len-ii;
		    rep(l,0,3) if (trans[i][i+ii-1][l])
			rep(r,0,3) if (trans[i+ii][i+len-1][r])
			    rep(to,0,3) if (change[l][r][to])
				trans[i][i+len-1][to] = true;
		}
	}
}
void thePrinter()
{
    bool check = false;
    rep(i,0,3) if (trans[0][s.size()-1][i]) {cout << toChar[i];check = true;}
    if (!check) cout << "Nobody";
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    theIniter();
    theSolver();
    thePrinter();
    return 0;
}
