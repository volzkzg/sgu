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

string str[2],st[2],p;
int z[2][4010],len;
int f[4011][4011];
int ans,pos;

int match(int a,int b,int c)
{
    int x = 0;//這裏一定要從0開始，是爲了防止a<0或者b>=len
    while (a-x>=0 && b+x<len && st[c][a-x] == st[c][b+x]) x++;
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    rep(i,0,1) 
	{
	    cin >> str[i];
	    rep(j,1,2*str[i].size()+1) st[i] = st[i]+"#";
	    rep(j,0,str[i].size()-1) st[i][j*2+1] = str[i][j];
	    
	    z[i][0] = 1;len = st[i].size();
	    int L = 0,R = 0;
	    rep(j,1,len-1)
		{
		    int ii = 2*L-j;
		    int n = R-j+1;
		    if (R<j)
			{
			    z[i][j] = match(j,j,i);
			    L = j,R = j+z[i][j]-1;
			}
		    else if (z[i][ii] == n)
			{
			    z[i][j] = match(j-n,j+n,i)+n;
			    L = j,R = j+z[i][j]-1;
			}
		    else
			{
			    z[i][j] = min(z[i][ii],n);
			}
		}
	}
    rep(i,1,st[0].size()) rep(j,1,st[1].size())
	{
	    if (st[0][i-1] == st[1][j-1])
		f[i][j] = f[i-1][j-1]+1;
	    int k = min(f[i][j]-1,min(z[0][i-1]-1,z[1][j-1]-1));
	    //上面z[0][i-1]和z[1][j-1]必須都減1。忘記減了一直WA4
	    if (k>ans)
		{
		    ans = k;
		    pos = j-1;
		}
	}
    rep(i,pos-ans+1,pos+ans-1) if (st[1][i]!='#') p+=st[1][i];
    cout << p << endl;
    return 0;
}
