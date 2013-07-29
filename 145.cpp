#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX = 111;

int n,m,k,s,t,mid,u,v,w,l,r;
int g[MAX][MAX];
int ans[MAX],Z,have;
bool vis[MAX];

void dfs(int u,int dist)
{
        vis[u] = true;
        if (u == t) {
                ++have;
        } else {
                for (int i = 1; i <= n; ++i) {
                        if (!vis[i] && g[u][i] && dist+g[u][i] <= mid) {
                                dfs(i,dist+g[u][i]);
                                if (have >= k) return;
                        }
                }
        }
        vis[u] = false;
}

bool find(int u,int dist)
{
        vis[u] = true;
        if (u == t) {
                if (dist == l) {
                        ans[++ans[0]] = u;
                        return true;
                }
        } else {
                for (int i = 1; i <= n; ++i) {
                        if (!vis[i] && dist+g[u][i] <= l && g[u][i] && find(i,dist+g[u][i])) {
                                ans[++ans[0]] = u;
                                return true;
                        }
                }
        }
        vis[u] = false;
        return false;
}

int main()
{
        scanf("%d %d %d",&n,&m,&k);
        for (int i = 0; i < m; ++i) {
                scanf("%d %d %d",&u,&v,&w);
                g[u][v] = g[v][u] = w;
        }
        scanf("%d %d",&s,&t);

        l = 0;
        r = 10000*n;
        while (l <= r) {
                memset(vis,false,sizeof(vis));
                have = 0;
                mid = (l + r) >> 1;
                dfs(s,0);
                if (have >= k)
                        r = mid - 1;
                else
                        l = mid + 1;
        }

        memset(vis,false,sizeof(vis));
        find(s,0);
        printf("%d %d\n",l,ans[0]);
        for (int i = ans[0]; i > 0; --i)
                printf("%d ",ans[i]);
        printf("\n");

        return 0;
}