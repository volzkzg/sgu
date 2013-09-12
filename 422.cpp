#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAX = 3333;
double p[MAX],f[MAX][MAX],t,now;
int n;

void init()
{
        cin >> n >> t;
        for (int i = 1; i <= n; ++i) cin >> p[i];
}

void solve()
{
        for (int y = 1; y <= n; ++y) 
                for (int x = y-1; x >= 0; --x) {
                        now = (double)1 - p[x+1];
                        f[x][y] = (y - x + t) + (y - x) * p[x+1];
                        for (int z = x + 2; z <= y; ++z) {
                                f[x][y] += now * p[z] * (y - z + 1 + f[z-1][y]);
                                now *= ((double)1 - p[z]);
                        }
                        f[x][y] /= ((double)1-p[x+1]);
                }
        cout << setiosflags(ios::fixed)
                << setprecision(8) 
                << f[0][n] << endl;
}

int main()
{
        freopen("test.in","r",stdin);
        ios::sync_with_stdio(false);

        init();
        solve();

        return 0;
}