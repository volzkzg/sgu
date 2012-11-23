#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

char stack[33333];
string str;
int top;

int main()
{
    ios::sync_with_stdio(false);
    cin >> stack[top = 1];
    cin >> str;
    bool check = true;
    rep(i,0,str.size()-1)
	{
	    if (top == 0) {check = false;break;}
	    if (str[i]=='A')
		{
		    if (stack[top] == 'A')
			stack[++top] = 'B';
		    else
			top--;
		}
	    else
		{
		    if (stack[top] == 'B')
			stack[++top] = 'A';
		    else 
			top--;
		}
	}
    if (top!=0) check = false;
    if (check) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
