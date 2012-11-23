#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    string s;
    bool operator < (const node & a) const
    {
	return(s+a.s<a.s+s);
    }
}str[111];
int main()
{
    int n;
    cin >> n;
    for (int i=0;i<n;++i) cin >> str[i].s;
    sort(str,str+n);
    for (int i=0;i<n;++i) cout << str[i].s;
    cout << endl;return 0;
}
