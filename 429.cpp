#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int a[10],n;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (n == 1) {
                cout << "FEDOR" << endl;
        } else if (n == 2) {
                if (a[1] != a[2]) cout << "FEDOR" << endl;
                else cout << "SERGEY" << endl;
        } else if (n == 3) {
                if (a[1] == a[3] && a[2] != a[1]) cout << "SERGEY" << endl;
                else cout << "FEDOR" << endl;
        } else if (n == 4) {
                if (a[1] > a[4]) {
                        swap(a[1],a[4]);
                        swap(a[2],a[3]);
                }
                if (a[1] == a[4]) {
                        if (a[2] > a[1] && a[3] > a[1]) cout << "SERGEY" << endl;
                        else if (a[2] == a[1] && a[3] == a[1]) cout << "SERGEY" << endl;
                        else if (a[2] < a[1] && a[3] < a[1]) cout << "SERGEY" << endl;
                        else cout << "FEDOR" << endl;
                } else if (a[1] == (a[4] - 1)) {
                        if (a[2] <= a[1] && a[3] >= a[4]) 
                                cout << "SERGEY" << endl;
                        else 
                                cout << "FEDOR" << endl;
                } else cout << "FEDOR" << endl;
        } else if (n == 5) {
                if (a[1] > a[5]) {
                        swap(a[1],a[5]);
                        swap(a[2],a[4]);
                }
                if (a[1] == a[5]) {
                        if (a[2] > a[4]) {
                                swap(a[2],a[4]);
                        }
                        if (a[3] < a[1]) {
                                if (a[2] < a[1] && a[4] < a[1]) cout << "SERGEY" << endl;
                                else if (a[2] >= a[1] && a[4] >= a[1]) cout << "SERGEY" << endl;
                                else cout << "FEDOR" << endl;
                        } else if (a[3] == a[1]) {
                                if (a[2] < a[1] && a[4] <= a[1]) cout << "SERGEY" << endl;
                                else if (a[2] >= a[1] && a[4] > a[1]) cout << "SERGEY" << endl;
                                else cout << "FEDOR" << endl;
                        } else if (a[3] > a[1]) {
                                if (a[2] <= a[1] && a[4] <= a[1]) cout << "SERGEY" << endl;
                                else if (a[2] > a[1] && a[4] > a[1]) cout << "SERGEY" << endl;
                                else cout << "FEDOR" << endl;
                        }
                } else if (a[1] == (a[5] - 1)) {
                        if (a[2] < a[1]) {
                                if (a[3] <= a[1] && a[4] >= a[5]) cout << "SERGEY" << endl;
                                else if (a[3] > a[1] && a[4] > a[5]) cout << "SERGEY" << endl;
                                else cout << "FEDOR" << endl;
                        } else if (a[2] == a[1]) {
                                if (a[3] > a[1] && a[4] > a[5]) cout << "SERGEY" << endl;
                                else cout << "FEDOR" << endl;
                        } else cout << "FEDOR" << endl;
                } else cout << "FEDOR" << endl;
        }
        return 0;
}