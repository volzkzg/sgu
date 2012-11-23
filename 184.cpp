/*
 *NAME:Patties
 *LANG:C++
 *Source:sgu184
 */
#include <iostream>
#include <cstdio>
using namespace std;
int P,M,C,K,R,V;
int main(){
    cin >> P >> M >> C >> K >> R >> V;
    cout << min(min(P/K,M/R),C/V) << endl;
    return 0;
}
