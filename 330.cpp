#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <algorithm>
#define rep(i,j,k) for (long long i=j;i<=k;++i)
#define rrep(i,j,k) for (long long i=j;i>=k;--i)
#define MAX 555

using namespace std;


typedef long long LL;
LL A,B,num[MAX],len,last = -1,mi[42];

void first_odd(LL &,LL &);
void second_odd(LL &,LL &);
void double_even(LL &,LL &);

void failure()
{
    cout << "Impossible" << endl;
    exit(0);
}
void print()
{
    rep(i,0,len) cout << num[i] << endl;
    if (last != -1) cout << last << endl;
}
void first_odd(LL &A,LL &B)
{
    int i;
    for (i = 3; i <= sqrt(A)+10; i += 2)
	if (A % i == 0) break;
    if (A % i != 0 || i >= A || A + i > B) failure();
    A+=i;
    num[++len] = A;
}
void second_odd(LL &A,LL &B)
{
    int i;
    for (i = 3; i <= sqrt(B)+10; i += 2)
	if (B % i == 0) break;
    if (B % i != 0 || i >= B || A > B - i) failure();
    last = B;
    B -= i;
}
void double_even(LL &A,LL &B)
{
    int pos,l,r,mid;
    while (A < B)
	{
	    pos = 1;
	    l = 1,r = 40;
	    while (l<=r)
		{
		    mid = (l+r)>>1;
		    if ((A + mi[mid] <= B) && (A % mi[mid] == 0) && (mi[mid] < A))
			pos = mid,l = mid+1;
		    else
			r = mid-1;
		}
	    A += mi[pos];
	    num[++len] = A;
	}
    print();
}

int main()
{
    cin >> A >> B;
    mi[0] = 1;
    rep(i,1,41) mi[i] = mi[i-1]*2;
    num[len = 0] = A;
    if (A & 1) first_odd(A,B);
    if (B & 1) second_odd(A,B);
    if (A == 2) failure();
    double_even(A,B);

    return 0;
}
