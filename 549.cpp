#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 4000 + 10;

int n, k;
int w[MAXN], c[MAXN];
vector <int> Q[MAXN];
int cnt[MAXN];

int main() {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) {
                scanf("%d%d", &w[i], &c[i]);
                cnt[w[i]]++;
                Q[w[i]].push_back(c[i]);
        }
        sort(cnt + 1, cnt + 1 + 4000);
        int ans = 1000000;
        for (int i = 4000; i > 4000 - k; --i)
                ans = min(ans, cnt[i]);
        for (int i = 1; i <= n; ++i)
                cnt[i] = 0;
        for (int i = 1; i <= 4000; ++i) {
                if (Q[i].size() >= ans) {
                        sort(Q[i].begin(), Q[i].end());
                        reverse(Q[i].begin(), Q[i].end());
                        int cur = 0;
                        for (int j = 0; j < ans; ++j)
                                cur += Q[i][j];
                        cnt[++cnt[0]] = cur;
                }
        }
        sort(cnt + 1, cnt + 1 + cnt[0]);
        int ans2 = 0;
        for (int i = cnt[0]; i >= cnt[0] - k + 1; --i)
                ans2 += cnt[i];
        printf("%d %d\n", ans, ans2);

        return 0;
}
