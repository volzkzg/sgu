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

int n,num,bet;
string s,ss,tmp;

void process()
{
    if (num == 0) ss+=' ';
    else if (num == 1) ss+='-';
    else if (num == 2) ss+=" -- ";
    else 
	{
	    if (num%2 == 1)
		{
		    ss += " --- ";
		    num-=3;
		}
	    else
		{
		    ss += " -- ";
		    num-=2;
		}
	    while (num>0)
		{
		    ss+= "-- ";
		    num-=2;
		}
	}
    bet = 0;
    num = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    getline(cin,s);
    rep(i,1,n)
	{
	    ss = "";
	    num = 0;bet = 0;
	    getline(cin,s);
	    bool check = false;
	    bool word = false;
	    rep(i,1,s.size()-2)
		{
		    if ((s[i]>='a' && s[i]<='z') || 
			(s[i]>='A' && s[i]<='Z'))
			{
			    if (bet) 
				{
				    if (!word && num == 1) 
					{
					    check = true;
					    bet = 0;num = 0;
					}
				    else
					if (!(!word && num == 0)) process();
					else
					    bet = num =0;
				}
			    ss+=s[i];
			    word = true;
			}
		    else
			{
			    bet = 1;
			    if (s[i] == '-') num++;
			}
		}
	    if (bet) 
		{
		    if (num == 1) check = true;
		    else 
			{
			    if (num!=0)
				process();
			}
		}
	    if (!check) cout << '"' << ss << '"' << endl;
	    else cout << "error" << endl;
	}	
    return 0;
}
