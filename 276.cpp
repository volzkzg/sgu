/*
 *NAME:Andrew's Troubles
 *LANG:C++
 *SOURCE:sgu276
 *TIMES:3
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int s,p,min,t;
int main(){
    cin >> s >>p;
    int t = p-s,min = 0;
    while (t>=60){
	t-=60;min++;
    }
    //    if (p!=0) min++;
    if (min>=30){
	cout << 4 << endl;
	return 0;
    }
    else if (min>=15){
	cout << 3 << endl;
	return 0;
    }
    else if (min>=5){
	cout << 2<< endl;
	return 0;
    }
    else if (min>0 || (min == 0 && t>0)){
	cout << 1 << endl;
	return 0;
    }
    else{
	cout << 0 << endl;
	return 0;
    }
}
