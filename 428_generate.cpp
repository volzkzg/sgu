#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<string,int> to;
char c[18];
int a[18],len,bound;

void get_in(int num,int pos)
{
        if (num == 0) {
                a[pos] = 0;
                return;
        } else {
                while (num) {
                        a[pos--] = num % 10;
                        num /= 10;
                }
        }
}

void trans()
{
        string s = "";
        char now = 'A';
        for (int i = 1; i <= len * 3; ++i) {
                if (a[i] != -1) {
                        c[i] = now;
                        for (int j = i+1; j <= len * 3; ++j) {
                                if (a[j] == a[i]) {
                                        c[j] = now;
                                        a[j] = -1;
                                }
                        }
                        a[i] = -1;
                        now++;
                }
        }
        for (int i = 1; i <= len * 3; ++i) {
                s += c[i];
                if (i == len) s += '+';
                if (i == len * 2) s += '=';
        }
        //cout << s << endl;
        if (to.find(s) == to.end()) {
                to[s] = 1;
        } else {
                to[s] ++;
        }
}

int main()
{
        freopen("test1.out","w",stdout);
        ios::sync_with_stdio(false);

        len = 4;
        bound = 10000;
        int low = 1000;
        int up = 9999;
        for (int i = low; i <= up; ++i)
                for (int j = low; j <= up; ++j) {
                                int k = i + j;
                                if (k >= bound) continue;
                                get_in(i,len);
                                get_in(j,2*len);
                                get_in(k,3*len);
                                //cout << i << " " << j<< " " << k << endl;
                                trans();
                        }
        for (map<string,int>::iterator it = to.begin(); it != to.end(); ++it) {
                //cout << it->first << " " << it->second << endl;
                if (it->second == 1) {
                        cout << it->first << endl;
                }
        }
}