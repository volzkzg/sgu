/*
 *NAME:DIV 3
 *LANG:C++
 *Source:sgu105
 */
#include <iostream>
using namespace std;

int n,ans;
int main(){
    cin >> n;
    cout << ((n/3*2)+(n%3==2)) << endl;
}
