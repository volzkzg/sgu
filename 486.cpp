#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#define rep(i,j,k) for (int i = j; i <= k; ++i)

using namespace std;

string n,m;
int bull,cows,cnt[10];
bool f[4];

int main()
{
    cin >> n >> m;
    rep(i,0,3) if (n[i] == m[i]) bull++,f[i] = true;
    rep(i,0,3) if (!f[i]) cnt[n[i] - '0']++;
    rep(i,0,3) if (!f[i]) 
	{
	    int p = m[i] - '0';
	    if (cnt[p]) cnt[p]--,cows++;
	}
    cout << bull << " " << cows << endl;
    return 0;
}
