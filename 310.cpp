#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

long long l[65537],r[65537];
int num[65537],sum;
long long n,k,a,b,ss;
long long ans;
bool vis[65537];

void calc(int t)
{
     int tt = t;
     num[tt] = 0;
     while (t>0)
     {
           num[tt]+=t%2;
           t/=2;
     } 
}

void dfs(int x,int len)
{
     if (len == k)
     {
            if (vis[x])
               r[x] = 1;
     }
     else
     {
         dfs(x<<1,len+1);
         dfs((x<<1)+1,len+1);
     }   
}

int main()
{
    ios::sync_with_stdio(false);
    
    memset(vis,false,sizeof(vis));
    cin >> n >> k >> a;
    sum = 1<<k;
    rep(i,0,sum) calc(i);
    rep(i,0,sum) if (num[i]>=a) vis[i] = true;
    rep(i,0,sum) r[i] = 0;
    dfs(0,0);
    int sss = 1<<(k-1);
    rep(i,k+1,n)
    {
                rep(j,0,sum) l[j] = r[j];
                rep(j,0,sum) r[j] = 0;
                rep(j,0,sum) if (vis[j]) 
                {
                               int now = j>>1; 
                               int is = j&1;
                               if (vis[now+sss])
                                  r[j] += l[now+sss];
                               if (vis[now])
                                  r[j] += l[now];      
                }

    }
    
    ans = 0;
    rep(i,0,sum-1) if (vis[i]) ans+=r[i];
    cout << ans << endl;
    
    return 0; 
}
