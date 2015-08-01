#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> a >> b;
        int ta = a, tb = b;
        int num = 0, times = 0;
        while (true) {
                if (ta == tb) {
                        num += 2;
                        times = ta;
                        if (num >= n)
                                break;
                        ta += a;
                        tb += b;
                }
                else if (ta < tb) {
                        num++;
                        times = ta;
                        if (num == n) {
                                if (tb > times) {
                                        times = tb;
                                        ++num;
                                }
                                break;
                        }
                        ta += a;
                } else if (ta > tb) {
                        ++num;
                        times = tb;
                        if (num == n) {
                                if (ta > times) {
                                        times = ta;
                                        ++num;
                                }
                                break;
                        }
                        tb += b;
                }
        }
        printf("%d %d\n", num, times);

        return 0;
}
