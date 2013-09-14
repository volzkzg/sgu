#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

string s;

int main()
{
        freopen("test1.out","r",stdin);
        freopen("test2.out","w",stdout);
        ios::sync_with_stdio(false);
        while (getline(cin,s)) {
                if (s.substr(0,4) < s.substr(5,4)) {
                        //cout << s.substr(0,4) << " " << s.substr(5,4) << endl;
                        cout << "cout << ";
                        cout << "\"";
                        cout << s;
                        cout << "\"";
                        cout << " << endl";
                        cout << endl;
                }
        }
}