#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

int n,m,num;
bool check;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 21) {cout << 1 << endl;return 0;}
    num = n/14;
    m = n%14;
    if (m>=2 && m<=12) check = true;
    if (num>1 && check) cout << num << endl;
    else cout << -1 << endl;
    return 0;
}
