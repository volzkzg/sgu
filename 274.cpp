#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char s[1000];
int n;

bool letter(char c){
    if ((c>='a' && c<='z')||(c>='A' && c<='Z')) return true;
    return false;
}
bool symbol(char c){
    if (letter(c)) return true;
    if ((c>='0' && c<='9') || c == '_' || c == '-') return true;
    return false;
}
bool word(int l,int r){
    if (l == r) return symbol(s[l]);
    else return symbol(s[l]) && word(l+1,r);
}
bool prefix(int l,int r){
    for (int i=r;i>=l;--i) 
	if (s[i] == '.') return prefix(l,i-1) && word(i+1,r);
    return word(l,r);
}
bool domain(int l,int r){
    //    cout << l << " " << r << endl;
    if (((r-l+1)==2 || (r-l+1)==3)){
	for (int i=l;i<=r;++i) 
	    if (!letter(s[i])) return false;
	return true;
    }else return false;
}
bool suffix(int l,int r){
    for (int i=r;i>=l;--i)
	if (s[i] == '.') return prefix(l,i-1) && domain(i+1,r);
    return false;
}
bool address(int l,int r){
    for (int i=r;i>=l;--i) 
	if (s[i] == '@') return prefix(l,i-1) && suffix(i+1,r);
    return false;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);freopen("test.out","w",stdout);
#endif
    scanf("%d\n",&n);
    while (n--){
	gets(s);
	if (address(0,strlen(s)-1)) puts("YES");
	else puts("NO");
    }
}
