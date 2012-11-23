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

int n,anstmp[222],ans[222],atmp[222][222],a[222][222],s[222],ansNum,tmp,pos;

void theIniter()
{
    cin >> n;int t,k;
    rep(i,1,n) {cin >> t;rep(j,1,t) cin >> k,atmp[k][i] = 1;}
    rep(i,1,n) cin >> anstmp[i];
}

void swap(int u,int v) {rep(i,1,n+1) tmp=a[u][i],a[u][i]=a[v][i],a[v][i]=tmp;}
void Xor(int u,int v){rep(i,1,n+1) a[v][i] ^= a[u][i];}

void xorSolver()
{
    int row = 1;
    rep(col,1,n)
	{
	    if (row>n) break;
 	    if (!a[row][col])
		rep(rowFind,row+1,n) if (a[rowFind][col])
		    {
			swap(row,rowFind);
			break;
		    }
	    if (a[row][col])
		{
		    rep(rowAno,row+1,n) if (a[rowAno][col])
			Xor(row,rowAno);
		    row++;
		}
	}
    rep(i,row,n) if (a[i][n+1]) return;

    ansNum = 0;
    memset(s,0,sizeof(s));
    rrep(i,row-1,1)
	{
	    rep(j,1,n) if (a[i][j]) {s[pos=j]=a[i][n+1];break;}
	    rrep(j,i-1,1) if (a[j][pos]) Xor(i,j);
	}
    rep(i,1,n) if (s[i]) ans[++ansNum] = i;
    cout << ansNum << endl;
    rep(i,1,ansNum) cout << ans[i] << " " ;
    exit(0);
}

void theSolver()
{
    rep(i,1,n) rep(j,1,n) a[i][j] = atmp[i][j];
    rep(i,1,n) a[i][n+1] = anstmp[i];
    xorSolver();
    rep(i,1,n) rep(j,1,n) a[i][j] = atmp[i][j];
    rep(i,1,n) a[i][n+1] = 1-anstmp[i];
    xorSolver();
    cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    
    theIniter();
    theSolver();
    return 0;
}
