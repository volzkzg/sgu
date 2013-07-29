#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef vector<string>::iterator titer;
typedef vector<vector<string> >::iterator viter;
string s;
vector<string> t;
vector<vector<string> > v;
int k;

string real(string p)
{
        if (p[p.size()-1] == '.')
                p.erase(p.size()-1);
        return p;
}

bool eq_no(string p) 
{
        string q = "no";
        if (p.size() != 2) return false;
        for (int i = 0; i < 2; ++i) 
                if (tolower(p[i]) != q[i]) return false;
        return true;
}

bool eq_not(string p) 
{
        string q = "not";
        if (p.size() != 3) return false;
        for (int i = 0; i < 3; ++i)
                if (tolower(p[i]) != q[i]) return false;
        return true;
}

bool eq_can(string p) 
{
        string q = "can";
        if (p.size() != 3) return false;
        for (int i = 0; i < 3; ++i) 
                if (tolower(p[i]) != q[i]) return false;
        return true;
}

bool eq_may(string p)
{
        string q = "may";
        if (p.size() != 3) return false;
        for (int i = 0; i < 3; ++i) 
                if (tolower(p[i]) != q[i]) return false;
        return true;
}

bool eq_must(string p) 
{
        string q = "must";
        if (p.size() != 4) return false;
        for (int i = 0; i < 4; ++i) 
                if (tolower(p[i]) != q[i]) return false;
        return true;
}

bool eq_should(string p)
{
        string q = "should";
        if (p.size() != 6) return false;
        for (int i = 0; i < 6; ++i)
                if (tolower(p[i]) != q[i]) return false;
        return true;
}

bool eq_is(string p)
{
        string q = "is";
        if (p.size() != 2) return false;
        for (int i = 0; i < 2; ++i)
                if (tolower(p[i]) != q[i]) return false;
        return true;
}

bool eq_are(string p)
{
        string q = "are";
        if (p.size() != 3) return false;
        for (int i = 0; i < 3; ++i) 
                if (tolower(p[i]) != q[i]) return false;
        return true;
}

bool eq_a(string p)
{
        string q = "a";
        if (p.size() != 1) return false;
        for (int i = 0; i < 1; ++i)
                if (tolower(p[i]) != q[i]) return false;
        return true;
}

bool eq_the(string p)
{
        string q = "the";
        if (p.size() != 3) return false;
        for (int i = 0; i < 3; ++i)
                if (tolower(p[i]) != q[i]) return false;
        return true;
}

bool eq_negation(string p) 
{
        //p = real(p);
        if (eq_no(p)) return true;
        if (eq_not(p)) return true;
        return false;
}

bool eq_keyword1(string p) 
{
        //p = real(p);
        if (eq_can(p)) return true;
        if (eq_may(p)) return true;
        if (eq_must(p)) return true;
        if (eq_should(p)) return true;
        return false;
}

bool eq_keyword2(string p)
{
        //p = real(p);
        if (eq_is(p)) return true;
        if (eq_are(p)) return true;
        return false;
}

bool eq_keyword(string p) 
{
        //p = real(p);
        if (eq_can(p)) return true;
        if (eq_may(p)) return true;
        if (eq_must(p)) return true;
        if (eq_should(p)) return true;
        if (eq_is(p)) return true;
        if (eq_are(p)) return true;
        return false;
}

int main()
{
        ios::sync_with_stdio(false);

        while (cin >> s) {
                t.push_back(s);
                if (s[s.size()-1] == '.') {
                        v.push_back(t);
                        t.clear();
                }
        }

        for (viter vit = v.begin(); vit != v.end(); ++vit) {
                for (titer tit = vit->begin(); tit != vit->end(); ++tit) {
                        *tit = real(*tit);
                        if (eq_negation(*tit)) {
                                /*
                                cout << 0 << endl;
                                return 0;
                                */
                        } else if (eq_keyword(*tit)) {
                                k++;
                        }
                }
        }

        cout << k << endl;

        for (viter vit = v.begin(); vit != v.end(); ++vit) {
                for (titer tit = vit->begin(); tit != vit->end(); ++tit) {
                        if (eq_keyword1(*tit)) {
                                titer tit2 = vit->begin();
                                while (true) {
                                        if (tit2 == tit) break;
                                        cout << *tit2++ << " ";
                                } 
                                cout << *tit2++ << " ";
                                cout << "not";
                                while (tit2 != vit->end()) {
                                        cout << " " << *tit2++;
                                }
                                cout << "." << endl;
                        } else if (eq_keyword2(*tit)) {
                                titer tit2 = vit->begin();
                                while (true) {
                                        if (tit2 == tit) break;
                                        cout << *tit2++ << " ";
                                } 
                                cout << *tit2++ << " ";
                                cout << "no";
                                if (tit2 != vit->end() && (eq_a(*tit2) || eq_the(*tit2))) ++tit2;
                                while (tit2 != vit->end()) {
                                        cout << " " << *tit2++;
                                }
                                cout << "." << endl;
                        }
                }
        }
        return 0;
}