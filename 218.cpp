#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int a[510][510],last[510],p[510];
bool b[510];
int n,ans,l,r,mid,num;

void init()
{
    scanf("%d",&n);
    l=2147483647;
    r=-2147483646;
    for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	    {
		scanf("%d",&a[i][j]);
		if (a[i][j]>r) r=a[i][j];
		if (a[i][j]<l) l=a[i][j];
	    }
}

bool augment(int x)//二分图匹配
{
    for (int i=1;i<=n;i++)
	if (b[i]==false  &&  a[x][i]<=mid)
            {   
                b[i]=true;       
                if (last[i]==0 || augment(last[i]))        
                    {
                        last[i]=x;
                        return true;
                    }            
            }
    return false;
}

void Main()
{
    while (l<=r)
	{
	    mid=(l+r)/2;
	    memset(last,0,sizeof(last));
	    ans=0;
	    for (int i=1;i<=n;i++)
		{
		    memset(b,false,sizeof(b));
		    if (augment(i))  ans++;
		}
	    if (ans==n)  r=mid-1;           
	    else l=mid+1;
	    if (ans==n)      
		for (int j=1;j<=n;j++)  p[last[j]]=j;
	}     
    printf("%d\n",l);
    for (int i=1;i<=n;i++) printf("%d %d\n",i,p[i]);
}

int main()
{
    init();
    Main();
}
