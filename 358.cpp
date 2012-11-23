#include <iostream>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
using namespace std;
int main()
{
    int a[3],b[3];
    rep(i,0,2) {rep(j,0,2)cin >> b[j];sort(b,b+3);a[i]=b[1];}sort(a,a+3);
    cout << a[1] << endl;return 0;
}
