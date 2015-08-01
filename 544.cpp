#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXN = 500 + 10;
const int MOD = 1000000009;

long long dp[2][MAXN][MAXN];
int n, k;
int cur, nxt;
pair <int, int> Q[MAXN * 2];

inline void Add(long long &x, long long y) {
        x = (x + y) % MOD;
}

int main() {
        scanf("%d%d", &n, &k);
        if (n % 2 != k % 2) {
                puts("0");
                return 0;
        }
        for (int i = 1; i <= n; ++i) {
                scanf("%d", &Q[i].first);
                Q[i].second = 1;
        }
        for (int i = n + 1; i <= 2 * n; ++i) {
                scanf("%d", &Q[i].first);
                Q[i].second = 2;
        }
        sort(Q + 1, Q + 1 + 2 * n);
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        cur = 1;
        nxt = 0;
        int s1 = 0, s2 = 0; //total num
        for (int i = 1; i <= 2 * n; ++i) {
                nxt ^= 1;
                cur ^= 1;
                for (int j = 0; j <= n; ++j)
                        for (int k = 0; k <= n; ++k) {
                                if (dp[cur][j][k] == 0)
                                        continue;
                                int c1 = s1 - j - k;
                                int c2 = s2 - j - k; // current num
                                Add(dp[nxt][j][k], dp[cur][j][k]);
                                if (Q[i].second == 1) {
                                        Add(dp[nxt][j + 1][k], dp[cur][j][k] * (long long)c2);
                                }
                                else {
                                        Add(dp[nxt][j][k + 1], dp[cur][j][k] * (long long)c1);
                                }
                        }
                if (Q[i].second == 1)
                        s1 ++;
                else
                        s2 ++;
                memset(dp[cur], 0, sizeof(dp[cur]));
        }
        printf("%lld\n", dp[nxt][(n + k) / 2][(n - k) / 2]);

        return 0;
}
