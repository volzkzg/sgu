#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#define printIm cout << "Impossible" << endl;
using namespace std;

bool ka(int i,int j,int w){
    if (w>i || w<=j) return true;
    return false;
}
int sa(int x){
    if (x==0) return 7;
    else return x;
}
int n,m,k;
int main(){
    cin >> n >> m;
    switch(m){
    case 1:
	if (ka(31,0,n)) {printIm;return 0;}
	cout << sa(n%7) << endl;return 0;
	break;
    case 2:
	if (ka(28,0,n)) {printIm;return 0;}
	cout << sa((n%7+3)%7) << endl;return 0;
	break;
    case 3: 
	if (ka(31,0,n)) {printIm;return 0;}
	cout << sa((n%7+3)%7) << endl;return 0;
	break;
    case 4:
	if (ka(30,0,n)) {printIm;return 0;}
	cout << sa((n%7+6)%7) << endl;return 0;
	break;
    case 5:
	if (ka(31,0,n)) {printIm;return 0;}
	cout << sa((n%7+1)%7) << endl;return 0;
	break;
    case 6:
	if (ka(30,0,n)) {printIm;return 0;}
	cout << sa((n%7+4)%7) << endl;return 0;
	break;
    case 7:
	if (ka(31,0,n)) {printIm;return 0;}
	cout << sa((n%7+6)%7) << endl;return 0;
	break;
    case 8:
	if (ka(31,0,n)) {printIm;return 0;}
	cout << sa((n%7+2)%7) << endl;return 0;
	break;
    case 9:
	if (ka(30,0,n)) {printIm;return 0;}
	cout << sa((n%7+5)%7) << endl;return 0;
	break;
    case 10:
	if (ka(31,0,n)) {printIm;return 0;}
	cout << sa(n%7) << endl;return 0;
	break;
    case 11:
	if (ka(30,0,n)) {printIm;return 0;}
	cout << sa((n%7+3)%7) << endl;return 0;
	break;
    case 12:
	if (ka(31,0,n)) {printIm;return 0;}
	cout << sa((n%7+5)%7) << endl;return 0;
	break;
    default:
	printIm;return 0;
	break;
    }
}
