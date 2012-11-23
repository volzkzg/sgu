#include <iostream>
#include <string>
#define maxn 200

using namespace std;

string s[maxn];

int main(){
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=m;++i)
	cin >> s[i];
    n = n % m;
    if (n == 0) n = m;
    cout << s[n] << endl;
    return 0;
}
