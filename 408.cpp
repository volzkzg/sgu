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

double score,v1,v2;
int n;

int main()
{
    scanf("%d\n",&n);
    rep(i,1,n)
	{
	    if (i<=2) v1+=1,v2+=1;
	    else if (v1 == v2) v1+=1;
	    else v2+=1;
	    score += v1*v2;
	}
    printf("%.3lf\n",score);
}
