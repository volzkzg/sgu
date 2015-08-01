#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const long long MAXN = 2000 + 10;
long long org[MAXN], a[MAXN];
long long n, r;

bool check(long long cur_table) {
        long long size_even, size_odd, num2 = 0, num3 = 0, num_even = 0, num_odd = 0;
        for (long long i = 1; i <= n; ++i)
                a[i] = org[i];
        for (long long i = 1; i <= n; ++i) {
                if (a[i] % 2 == 1) {
                        a[i] -= 3;
                        num3++;
                }
        }
        if (r % 2 == 1) {
                size_even = r - 3;
                size_odd = r;
                num_even = 0;
                num_odd = cur_table;
        }
        else {
                size_even = r;
                size_odd = 0;
                num_even = cur_table;
                num_odd = 0;
        }
        if (num3 >= num_odd) {
                num3 -= num_odd;
                num_even += num_odd;
                num_odd = 0;
        }
        else {
                for (long long i = 1; i <= n; ++i) {
                        if (num3 + 1 >= num_odd)
                                break;
                        while (a[i] >= 6) {
                                num3 += 2;
                                a[i] -= 6;
                                if (num3 + 1 >= num_odd)
                                        break;
                        }
                }
                if (num3 == num_odd) {
                        num_even += num_odd;
                        num3 -= num_odd;
                        num_odd = 0;
                }
                else {
                        num_even += num3;
                        num_odd -= num3;
                        num3 = 0;
                }
        }

        for (long long i = 1; i <= n; ++i)
                num2 += a[i] / 2;

        if (num_odd > 0) {
                long long cnt = 0;
                cnt += (size_odd / 2) * num_odd;
                if (cnt >= num2)
                        return true;
                cnt += (size_even / 2) * num_even;
                if (cnt >= num2)
                        return true;
        }
        else {
                long long RLG = (size_even / 6) * 2;
                while (num_even--) {
                        long long now = size_even;
                        if (num3 >= RLG) {
                                num3 -= RLG;
                                now -= RLG * 3;
                        }
                        else {
                                now -= num3 * 3;
                                num3 = 0;
                        }
                        long long wocao = now / 2;
                        wocao = min(wocao, num2);
                        now -= wocao * 2;
                        num2 -= wocao;
                        wocao = now / 3;
                        wocao = min(wocao, num3);
                        num3 -= wocao;
                        now -= wocao * 3;
                        if (num3 <= 0 && num2 <= 0)
                                return true;
                }
        }

        return false;
}

int main () {
        ios::sync_with_stdio(false);
        cin >> n >> r;
        for (long long i = 1; i <= n; ++i)
                cin >> org[i];
        long long l = 1, r = MAXN * MAXN, ans;
        while (l <= r) {
                long long mid = (l + r) >> 1;
                if (check(mid)) {
                        r = mid - 1;
                        ans = mid;
                }
                else
                        l = mid + 1;
        }
        cout << ans << endl;
        //printf("%d\n", ans);

        return 0;
}
