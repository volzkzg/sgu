//fix leading zero to make the ans bigger 
//fix string end bug
//fix string k_num bug 
//fix int bug that allow situation like "ie" exist. to fuck WA9
//fix string bug when I use int rather than long long

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

struct decode
{
    long long m,pos,e_num,len;
    string s;
    decode():pos(0),e_num(0){}
    void input();
    bool get_int();
    bool get_string();
    bool get_list();
    bool get_dict();
    bool get_element();
    bool get_double_element();
    void run();
}bencode;

void decode::input()
{ 
    cin >> m >> s; 
    len = s.size();
}
bool decode::get_int()
{
    if (pos + e_num + 3 <= m)
	{
	    pos++,e_num++;
	    if (s[pos] == 'e') return false;
	    if (s[pos] == '-') return false;
	    if (s[pos] == '0' && s[pos+1] != 'e') 
		{
		    pos++;
		    return false;
		}
	    while (s[pos] != 'e')
		{
		    if (s[pos]>='0' && s[pos]<='9' &&
			pos + e_num + 1 <= m && pos<len) pos++;
		    else return false;
		}
	    pos++,e_num--;
	    return true;
	}
    else
	return false;
}
bool decode::get_string()
{
    long long k;
    if (pos + e_num + 2 <= m)
	{
	    k = 0;
	    if (s[pos] == '0' && s[pos+1] != ':') 
		{
		    pos++; 
		    return false;
		}
	    while (s[pos] != ':')
		{
		    if (s[pos]>='0' && s[pos]<='9' && pos<len)
			{
			    k = k * 10 + s[pos] - '0';
			    if (pos + e_num + 2 + k <= m) pos++;
			    else return false;
			}
		    else return false;
		}
	    pos = pos + 1 + k;
	    if (pos > len)
		{
		    pos = len;
		    return false;
		}
	    else
		return true;
	}
    else 
	return false;
}
bool decode::get_list()
{
    if (pos + e_num + 2 <= m)
	{
	    pos++,e_num++;
	    while (pos<len && s[pos] != 'e')
		if (!get_element()) return false;
	    if (pos >= len)
		{
		    pos = len;
		    return false;
		}
	    pos++,e_num--;
	    return true;
	}
    else 
	return false;
}
bool decode::get_dict()
{
    if (pos + e_num + 2 <= m)
	{
	    pos++,e_num++;
	    while (pos<len && s[pos] != 'e')
		if (!get_double_element()) return false;
	    if (pos >= len)
		{
		    pos = len;
		    return false;
		}
	    pos++,e_num--;
	    return true;
	}
    else 
	return false;
}
bool decode::get_double_element()
{
    long long tpos,te_num;
    tpos = pos,te_num = e_num;
    if (get_element())
	{
	    long long mark = pos;
	    if (get_element())
		{
		    return true;
		}
	    else
		{
		    if (mark != pos) return false;
		    m-=2;
		    pos = tpos,e_num = te_num;
		    get_element();
		    m+=2;
		    return false;
		}
	}
    else
	{
	    m-=2;
	    pos = tpos,e_num = te_num;
	    get_element();
	    m+=2;
	    return false;
	}
}
bool decode::get_element()
{
    switch (s[pos])
	{
	case 'i':return get_int();
	case 'l':return get_list();
	case 'd':return get_dict();
	default:
	    if (s[pos]>='0' && s[pos]<='9') 
		return get_string();
	    else 
		return false;
	}
}
void decode::run()
{
    if (get_element() && pos == len)
	cout << "ok" << endl;
    else 
	cout << "Error at position " << pos << "!" << endl;
}
int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
    
    bencode.input();
    bencode.run();
    
    return 0;
}
