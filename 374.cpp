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

struct bigNum
{
public:
    int len;
    int num[8000];
    void make(long long x)
    {
	len = 0;
	memset(num,0,sizeof(num));
	while (x>0)
	    {
		num[len++] = x%10;
		x/=10;
	    }
    }
    bigNum operator + (bigNum a) const
    {
	bigNum b;
	b.make(0);
	rep(i,0,max(len,a.len)-1)
	    {
		b.num[i]+=num[i]+a.num[i];
		b.num[i+1]+=b.num[i]/10;
		b.num[i]%=10;
	    }
	b.len = max(len,a.len);
	while (b.num[b.len]>0)
	    {
		b.num[b.len+1] += b.num[b.len]/10;
		b.num[b.len] %= 10;
		b.len++;
	    }
	return b;
    }
    bigNum operator * (bigNum a) const
    {
	bigNum b;
	b.make(0);
	rep(i,0,len-1) rep(j,0,a.len-1)
	    {
		b.num[i+j] += num[i]*a.num[j];
		b.num[i+j+1] += b.num[i+j]/10;
		b.num[i+j]%=10;
	    }
	b.len = len+a.len-1;
	while (b.num[b.len]>0)
	    {
		b.num[b.len+1] += b.num[b.len]/10;
		b.num[b.len]%=10;
		b.len++;
	    }
	//b.print();
	return b;
    }
    void print()
    {
	rrep(i,len-1,0)
	    cout << num[i];
	cout << endl;
    }
};
bigNum A[22],B[22],ans,tmp;
long long a,b,k;
long long num[22];

int main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b >> k;
    A[0].make(1);A[1].make(a);
    B[0].make(1);B[1].make(b);
    rep(i,2,k)
	{
	    A[i] = A[i-1]*A[1];
	    B[i] = B[i-1]*B[1];
	}
    num[0] = num[k] = 1;
    rep(i,1,k-1)
	num[i] = num[i-1]*(k-i+1)/i;
    
    ans.make(0);
    rep(i,0,k) 
	{
	    tmp.make(num[i]);
	    tmp = tmp*A[i];
	    tmp = tmp*B[(k-i)];
	    //tmp.print();
	    ans = ans+tmp;
	}
    ans.print();
    return 0;
}
