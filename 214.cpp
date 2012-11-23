#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

const int INF = 0x7FFFFFFF/2;
map<char,int> toNum;
string alphabet,A,B;
int alphabetNum,dist[201][201],minPos1[201],minDist1[201],minPos2[201],minDist2[201];
int f[2002][2002],g[2002][2002];

void theIniter()
{
    cin >> alphabet;alphabetNum = alphabet.size();
    rep(i,0,alphabetNum-1) toNum[alphabet[i]] = i;
    cin >> A >> B;
    rep(i,0,alphabetNum-1) 
	{
	    int mini = INF;
	    rep(j,0,alphabetNum-1)
		{
		    cin >> dist[i][j];
		    if (dist[i][j]<mini)
			mini = dist[i][j],minPos1[i] = j;
		}
	    minDist1[i] = mini;
	}
    rep(i,0,alphabetNum-1)
	{
	    int mini = INF;
	    rep(j,0,alphabetNum-1)
		if (dist[j][i]<mini)
		    mini = dist[j][i],minPos2[i] = j;
	    minDist2[i] = mini;
	}
}
void theSolver()
{
    rep(i,1,A.size())
	f[i][0] = f[i-1][0]+minDist1[toNum[A[i-1]]],g[i][0]=3;
    rep(i,1,B.size())
	f[0][i] = f[0][i-1]+minDist2[toNum[B[i-1]]],g[0][i]=2;
    rep(i,1,A.size()) rep(j,1,B.size())
	{
	    f[i][j] = INF;
	    if (f[i-1][j-1]+dist[toNum[A[i-1]]][toNum[B[j-1]]]<f[i][j])
		f[i][j] = f[i-1][j-1]+dist[toNum[A[i-1]]][toNum[B[j-1]]],g[i][j]=1;
	    if (f[i][j-1]+minDist2[toNum[B[j-1]]]<f[i][j]) 
		f[i][j] = f[i][j-1]+minDist2[toNum[B[j-1]]],g[i][j] = 2;
	    if (f[i-1][j]+minDist1[toNum[A[i-1]]]<f[i][j])
		f[i][j] = f[i-1][j]+minDist1[toNum[A[i-1]]],g[i][j] = 3;
	}
}
void thePrinter()
{
    string ans1="",ans2="";
    int a = A.size(),b = B.size();
    while (a!=0 || b!=0)
	{
	    if (g[a][b] == 1)
		a--,b--,ans1=A[a]+ans1,ans2=B[b]+ans2;
	    else if (g[a][b] == 2)
		b--,ans1=alphabet[minPos2[toNum[B[b]]]]+ans1,ans2=B[b]+ans2;
	    else if (g[a][b] == 3)
		a--,ans1=A[a]+ans1,ans2=alphabet[minPos1[toNum[A[a]]]]+ans2;
	}
    cout << f[A.size()][B.size()] << endl;
    cout << ans1 << endl << ans2 << endl;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);

    theIniter();
    theSolver();
    thePrinter();
    return 0;
}
