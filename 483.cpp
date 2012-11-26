#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

typedef deque<int>::iterator iter;
int n,h,k;
deque<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> h;
    rep(i,0,h) k+=(2*i+1);
    q.push_front(k);
    h++;
    while (true)
	{
	    k += h;
	    if (k<=n) q.push_front(k);else break;
	    k += h;
	    if (k<=n) q.push_back(k);else break;
	    h++;
	}
    for (iter it = q.begin();it!=q.end();it++)
	cout << *it << " ";
    cout << endl;
    return 0;
}
