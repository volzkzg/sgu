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

int a,b,nowa,nowb;
int sum,now;
int k,ans[111][2];

int main()
{
    scanf("%d %d\n",&a,&b);
    sum = b;
    scanf("%d\n",&k);
    rep(i,1,k)
	{
	    scanf("%d",&now);
	    int w = now-sum;
	    if (w>0)
		{
		    if (a-w>=0)
			{
			    ans[i][0] = w;
			    a-=w;
			}
		    else
			{
			    cout << "ERROR" << endl;
			    return 0;
			}
		}
	    else if (w<0)
		{
		    if (b+w>=0)
			{
			    ans[i][1] = -w;
			    b+=w;
			}
		    else
			{
			    cout << "ERROR" << endl;
			    return 0;
			}
		}
	    sum = now;
	}
    rep(i,1,k) 
	printf("%d %d\n",ans[i][0],ans[i][1]);
}
