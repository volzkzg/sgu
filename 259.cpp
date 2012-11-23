#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)

using namespace std;

int n,ans,now;
struct node{
    int t,l;
}pr[111];

bool cmp(node a,node b){
    return (a.l>b.l);
}
int main(){
    cin >> n;
    rep(i,1,n) cin >> pr[i].t;
    rep(i,1,n) cin >> pr[i].l;
    sort(pr+1,pr+n+1,cmp);
    rep(i,1,n) now+=pr[i].t,ans = max(ans,now+pr[i].l);
    cout << ans << endl;
    return 0;
}
