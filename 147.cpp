#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX = 1111111;
int P1,Q1,P2,Q2,P3,Q3;
int n,u,d,ans = 0x7FFFFFFF/2;

int main()
{
        freopen("test.in","r",stdin);
        ios::sync_with_stdio(false);

        cin >> n;
        cin >> P1 >> Q1 >> P2 >> Q2 >> P3 >> Q3;

        if (abs(P1-P2) < abs(Q1-Q2)) {
                swap(P1,Q1);
                swap(P2,Q2);
                swap(P3,Q3);
        }
        if (P1 > P2) {
                swap(P1,P2);
                swap(Q1,Q2);
        }
        
        for (int i = P1; i <= P2; ++i) {
                int dist = abs(i - P3);
                int l = Q3 - dist;
                int r = Q3 + dist;
                int d = max(max(1,Q1-abs(i-P1)),max(1,Q2-abs(i-P2)));
                int u = min(min(n,Q1+abs(i-P1)),min(n,Q2+abs(i-P2)));
                cout << d << " " << u << " " << dist << endl;
                if ((l >= d && l <= u) ||
                    (r >= d && r <= u) ||
                    (l <= d && r >= u && u >= d)) {
                        ans = min(ans,dist);
                }
        }
        if (ans >= ((P2-P1)/2-1)) {
                cout << "NO" << endl;
                cout << P2-P1-1 << endl;
        } else {
                cout << "YES" << endl;
                cout << ans << endl;
        }
        return 0;
}