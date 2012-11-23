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

struct node
{
    int v;
    node *next;
}*g[20],buffer[20*20];
int childNum[20],father[20],top,n,k;

void insert(int u,int v)
{
    node *x = &buffer[top++];
    x->v = v,x->next = g[u],g[u] = x;
}
void theIniter()
{
    memset(g,0,sizeof(g));
    cin >> n;
    rep(i,1,n)
	{
	    cin >> childNum[i];
	    rep(j,1,childNum[i])
		{
		    cin >> k;
		    father[k] = i;
		    insert(i,k);
		}
	}
}
long long theFinder(int x)
{
    if (childNum[x] == 0)
	{
	    if (n>=2) return 1;
	    else return 0;
	}
    long long tmp = 0;
    for (node *t = g[x];t;t=t->next)
	tmp+=theFinder(t->v);tmp++;
    return tmp;
}
void theSolver()
{
    long long sum = 0;
    rep(i,1,n)
	if (!father[i])
	    sum+=theFinder(i); 
    sum++;
    cout << sum << endl;
    
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
    
    theIniter();
    theSolver();
}
