#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
ofstream fout("199.in");
int n;
int main(){
    cin >> n;
    fout << n << endl;
    srand(0);
    for (int i=1;i<=n;++i){
	fout << abs((int)(423432*abs(rand())))+10 << " " << abs((int)(234738*abs(rand())))+10 << endl;
    }
}

