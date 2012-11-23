#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

const int INF = 0x7FFFFFFF/2;
int M,N,ned[333];
double maxSum,maxPos,D[333],P[333],L;

void theIniter()
{
    cin >> L >> M;
    rep(i,1,M) cin >> P[i];cin >> N;
    rep(i,2,N) cin >> D[i];
    rep(i,1,M) 
	{
	    double mini = INF;
	    rep(j,1,N) if (fabs(P[i]-D[j])<mini){mini=fabs(P[i]-D[j]),ned[i]=j;}
	}maxSum = maxPos = 0;
    rep(i,1,M) maxSum+=fabs(P[i]-D[ned[i]]);
}
void theSolver()
{
    rep(i,1,2*L)
	{
	    double k = i*0.5;
	    if (k+D[N]>L) break;
	    rep(j,1,M)
		{
		    int l,r,mid;
		    mid = ned[j];l=ned[j]-1;r = ned[j]+1;
		    while (l<=0) l++;while (r>=N) r--;
		    double tmp = INF;int pos;
		    if (fabs(D[mid]+k-P[j])<tmp)tmp=fabs(D[mid]+k-P[j]),pos=mid;
		    if (fabs(D[l]+k-P[j])<tmp) tmp=fabs(D[l]+k-P[j]),pos=l;
		    if (fabs(D[r]+k-P[j])<tmp) tmp=fabs(D[r]+k-P[j]),pos=r;
		    ned[j] = pos;
		}
	    double tmp = 0;
	    rep(j,1,M) tmp+=fabs(D[ned[j]]+k-P[j]);
	    if (tmp>maxSum) maxSum = tmp,maxPos = k;
	}
}
void thePrinter()
{
    cout << setiosflags(ios::fixed) << setprecision(1) << maxPos << " " << maxSum << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    
    theIniter();
    theSolver();
    thePrinter();
    return 0;

}
