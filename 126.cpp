/*
 *NAME:Boxes
 *LANG:C++
 *Source:sgu126
 */
#include <iostream>
#include <cstdio>
using namespace std;
int step;
int x,y;
int main(){
    cin >> x >> y;
    if (x==0 || y==0) {cout << 0 << endl;return 0;}
    if ((x+y)%2==1){cout << -1 << endl;return 0;}
    while (x!=y){
	if (x>y){
	    x-=y;y*=2;
	    step++;
	}
	else{
	    y-=x;x*=2;
	    step++;
	}
	if (step>40000000) break;
    }
    if (x!=y) cout << -1 << endl;
    else cout << step+1 << endl;
    return 0;
}
