#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 222;
int n, a, b, f[N][N][N], g[N][N][N];
string s;

void upd(int x, int &y, int w, int &z)
{
        if (y == -1) {
                y = x;
                z = w;
        } else {
                if (x < y) {
                        y = x;
                        z = w;
                }
        }
}

void update(int k, int i, int j)
{
        int c = s[k] - '0';
        for (int cc = 0; cc <= 2; ++cc) {
                int x = f[k][i][j];
                if (c != cc) x++;
                int ii = i, jj = j;
                if (cc == 0) ii++;
                else if (cc == 1) jj++;
                upd(x, f[k + 1][ii][jj], cc, g[k + 1][ii][jj]);
        }
}

void dfs(int pos, int a, int b)
{
        if (pos == 0) return;
        int ret = g[pos][a][b];
        if (ret == 2)
                dfs(pos - 1, a, b);
        else if (ret == 1)
                dfs(pos - 1, a, b - 1);
        else
                dfs(pos - 1, a - 1, b);
        cout << ret;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> a >> b;
        cin >> s;

        memset(f, -1, sizeof(f));
        f[0][0][0] = 0;
        for (int k = 0; k < n; ++k) {
                for (int i = 0; i <= a; ++i)
                        for (int j = 0; j <= b; ++j) {
                                if (f[k][i][j] == -1) continue;
                                update(k, i, j);
                        }
        }
        if (f[n][a][b] != -1) {
                cout << f[n][a][b] << endl;
                dfs(n, a, b);
                cout << endl;
        } else {
                cout << -1 << endl;
        }
        return 0;
}
