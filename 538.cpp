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

string s;
int num,p;

int main()
{
    ios::sync_with_stdio(false);
    getline(cin,s);
    rep(i,0,s.size()-1) if (s[i] == ')' || s[i] == '(') p++;
    rep(i,0,s.size()-1) 
	{
	    if (s[i] == '(')
		{
		    bool check = true;
		    int j = i+1;
		    while (s[j]!=')' && j<s.size())
			{
			    if (s[j]!=' ' && !((s[j]>='a' && s[j]<='z')||(s[j]>='A' && s[j]<='Z')))
				{
				    check = false;
				    break;
				}
			    j++;
			}
		    if (check && s[j] == ')') num++;
		}
	    if (s[i] == ')')
		{
		    bool check =true;
		    int j = i-1;
		    while (s[j]!='(' && j>=0)
			{
			    if (s[j]!=' ' && !((s[j]>='a' && s[j]<='z')||
					       (s[j]>='A' && s[j]<='Z')))
				{
				    check = false;
				    break;
				}
			    j--;
			}
		    if (check && s[j] == '(') num++;
		}
	}
    cout << p-num << endl;
    return 0;
}
