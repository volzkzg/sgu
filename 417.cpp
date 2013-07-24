#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

long double pi = atan2(0,-1);
long double x,y,r;

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> x >> y >> r;
	r = r * r * pi * log(x*x+y*y);
	cout << setiosflags(ios::fixed)
	     << setprecision(12)
	     << r << endl;
	
	return 0;
}
