#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)
#define PB(i) push_back(i)
#define vInt vector<int>

using namespace std;

struct childList{childList *next;int pos;}buf[500002];
struct treeNode{treeNode():child(0),withoutTo(0){}int without,with,withoutTo;childList *child;}*g[500002],buffer[500002];
int top,n,k,cnt,t,pos;
vInt ans;

void insert(int u,int v)
{
    if (g[u] == 0) g[u] = &buffer[top++];
    childList * x = &buf[cnt++];
    x->pos = v,x->next = g[u]->child,g[u]->child = x;
}
void theIniter()
{
    cin >> n;memset(g,0,sizeof(g));
    rep(i,2,n) cin >> k,insert(k,i);
}
void dfsI(int u)
{
    childList *y;treeNode *x = g[u];
    if (x==0) {g[u] = &buffer[top++],g[u]->child = 0,g[u]->with=1,g[u]->without = g[u]->withoutTo = 0;return;}
    for (y=x->child;y;y=y->next) dfsI(y->pos);
    int sum=0,maxi=0;
    for (y=x->child;y;y=y->next) sum += g[y->pos]->without;g[u]->with = sum+1;
    for (y=x->child;y;y=y->next) 
	{
	    maxi = max(maxi,t=(sum-g[y->pos]->without+g[y->pos]->with));
	    if (t==maxi) pos = y->pos;
	}g[u]->without = maxi,g[u]->withoutTo = pos;
    return;
}
void dfsII(int u,int mode)
{
    childList *y;
    if (mode) 
	{
	    ans.PB(u);
	    for (y=g[u]->child;y;y=y->next) dfsII(y->pos,0);
	}
    else 
	for (y=g[u]->child;y;y=y->next) (y->pos==g[u]->withoutTo)?dfsII(y->pos,1):dfsII(y->pos,0);
}
void theSolver()
{
    dfsI(1);dfsII(1,0);
    cout << g[1]->without * 1000 << endl;
    sort(ans.begin(),ans.end());
    for (vInt::iterator e=ans.begin();e!=ans.end();e++) cout << *e << " ";cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    theIniter();
    theSolver();
    return 0;

}
