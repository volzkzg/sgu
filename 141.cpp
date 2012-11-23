#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

long long A,B,D;
long long x1,x2,P,K;

void extendedEuclid(long long x1,long long x2)
{
    if (x2 == 0)
	D = x1,A = 1,B = 0;
    else
	{
	    extendedEuclid(x2,x1%x2);
	    long long tmp = A;
	    A = B,B = tmp-(x1/x2)*B;
	}
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
    
    cin >> x1 >> x2 >> P >> K;
    extendedEuclid(x1,x2);

    if (P % D!=0)
	{
	    cout << "NO" << endl;
	    return 0;
	}
    else
	{
	    A = A*P/D,B = B*P/D;
	    int x1Add = x1/D;
	    int x2Add = x2/D;
	    long long AA = A,BB = B;
	    bool che = false;
	    long long t = 0;
	    while (!che && t<=10000000)
		{
		    t++,A+=x2Add,B-=x1Add;
		    if ((abs(A)+abs(B))<=K && ((K-abs(A)-abs(B)) %2==0))
			che = true;
		}
	    if (!che) A = AA,B = BB,t=0;
	    while (!che && t<=10000000)
		{
		    t++,A-=x2Add,B+=x1Add;
		    if ((abs(A)+abs(B))<=K && ((K-abs(A)-abs(B)) %2==0))
			che = true;
		}
	    if (che)
		{
		    long long N = (K-abs(A)-abs(B))/2;
		    long long P1,N1,P2,N2;
		    if (A>0)
			P1 = abs(A)+N,N1 = N;
		    else
			N1 = abs(A)+N,P1 = N;
		    if (B>0)
			P2 = abs(B),N2 = 0;
		    else
			N2 = abs(B),P2 = 0;
		    cout << "YES" << endl;
		    cout << P1 << " " << N1 << " " << P2 << " " << N2 << endl;
		}
	    else
		cout << "NO" << endl;
	}
    return 0;
}
