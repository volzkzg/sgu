#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)
#define sameWhite(prev,next) p+1,(prev<<1),(next<<1),1
#define sameBlack(prev,next) p+1,(prev<<1)+1,(next<<1)+1,2
#define diffFirst(prev,next) p+1,(prev<<1),(next<<1)+1,0
#define diffSecond(prev,next) p+1,(prev<<1)+1,(next<<1),0

using namespace std;

string s;
int M,P,N[200],mi[400],len,ret,miLen;

typedef vector<vector<int> > mat;
mat zero(int k){return mat(k,vector<int>(k,0));}
mat t,tar;
mat operator*(mat a,mat b)
{
    int l = a.size();
    mat c = zero(l);
    rep(i,0,l-1)rep(j,0,l-1)rep(k,0,l-1)
	c[i][j]+=(a[i][k]*b[k][j])%P,c[i][j]%=P;
    return c;
}

inline void dfs(int p,int last,int now,int status)
{
    if (p == M) {t[last][now] = 1;return;}
    if (status==0) dfs(sameWhite(last,now)),dfs(sameBlack(last,now));
    if (status==1) dfs(sameBlack(last,now));
    if (status==2) dfs(sameWhite(last,now));
    dfs(diffFirst(last,now));
    dfs(diffSecond(last,now));
}
void divide()
{
    rrep(i,len,2)
	{
	    N[i-1] += (N[i]%2)*10;
	    N[i] = N[i]/2;
	}ret = N[1]%2;N[1]/=2;
    while (!N[len]) len--;
}
void _minus()
{
    N[1]--;int pos = 1;
    while (N[pos]==-1 && pos<len) {N[pos]+=10,N[++pos]--;}
}
void theIniter()
{
    cin >> s >> M >> P;len = s.size();
    rep(i,0,s.size()-1) N[len-i] = s[i]-'0';_minus();

    while (len>0)
	{
	    divide();
	    mi[miLen++] = ret;
	}

    t = zero(1<<M),tar = zero(1<<M);
    dfs(0,0,0,0);
}
void theSolver()
{
    bool did = false;
    rep(i,0,miLen-1)
	{
	    if (mi[i]) if (!did) tar = t,did = true;else tar = tar*t;
	    t = t*t;
	}
    int ans = 0;
    rep(i,0,(1<<M)-1)rep(j,0,(1<<M)-1) ans+=tar[i][j],ans%=P;
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    theIniter();
    theSolver();
}
