#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

int stack[1000],top;
string s;

int main()
{
    ios::sync_with_stdio(false);

    cin >> s;int i=0;
    while (i<s.size())
	{
	    if (s[i] == '<')
		{
		    if (s[i+1] == '/') 
			{
			    top--;
			    while (s[i]!='>') i++;i++;
			}
		    else
			{
			    string tmp = "";i++;
			    while (s[i]!='>')
				tmp+=s[i++];i++;
			    if (tmp == "UP") s[++top] = 1;
			    else s[++top] = 2;
			}
		}
	    else
		{
		    if (s[top] == 1 && islower(s[i])) s[i] = toupper(s[i]);
		    else if (s[top] == 2 && isupper(s[i])) s[i] = tolower(s[i]);
		    cout << s[i];
		    i++;
		}
	}
    cout << endl;
    return 0;
}
