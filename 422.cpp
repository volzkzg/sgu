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
double p[MAX],q[MAX],f[MAX],now,add;
int n,t;

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> n >> t;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		q[i] = 1 - p[i];
	}
	for (int i = n-1; i >= 0; --i) {
		for (int j = 1; i + j <= n; ++j) {
			if (j == 1) {
				now = 1 + t + p[i+1] + q[i+1] * f[i+1];
				f[i] = now / q[i+1];
				add = q[i+1];
			} else {
				add *= q[i+j];
				now += 2 + add * (f[i+j] - f[i+j-1] - 1);
				f[i] = min(f[i],now / q[i+1]);
			}
		}
	}
	cout << setiosflags(ios::fixed)
	     << setprecision(7)
	     << f[0] << endl;
	
	return 0;
}
