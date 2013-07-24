#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,j,k) for (int i = j; i <= k; ++i)
#define rrep(i,j,k) for (int i = j; i >= k; --i)
#define pb push_back

using namespace std;

const int MAX = 55555,INF = 0x7FFFFFFF;
typedef vector<int>::iterator iter;
typedef multiset<int>::iterator set_iter;
struct treediff
{
    int n,m;
    vector<int> child[MAX];
    multiset<int> have[MAX];
    int father[MAX];
    int ans[MAX];
    int use[MAX];

    void input();
    void dfs(int);
    void print();
    void merge(int, int, int);
}tree;

int main()
{
    tree.input();
    tree.dfs(1);
    tree.print();

    return 0;
}

void treediff::input()
{
    scanf("%d%d\n",&n,&m);
    father[1] = 1;
    rep(i,2,n) 
	{
	    scanf("%d\n",&father[i]);
	    child[father[i]].pb(i);
	}
    rep(i,1,n) use[i] = i, ans[i] = INF;
    rep(i,n-m+1,n)
	{
	    int x;
	    scanf("%d\n",&x);
	    have[i].insert(x);
	}
}

void treediff::dfs(int pos)
{
    if (!child[pos].size()) return;
    for (iter it = child[pos].begin(); it != child[pos].end(); ++it)
	{
	    dfs(*it);
	    ans[pos] = min(ans[pos],ans[*it]);
	}
    int ori = use[*child[pos].begin()];
    iter it = ++child[pos].begin();
    while (it != child[pos].end())
	{
	    int to = use[*it];
	    if (have[ori].size() > have[to].size())
		merge(ori, to, pos);
	    else
		{
		    merge(to, ori, pos);
		    ori = to;
		}
	    ++it;
	}
    use[pos] = ori;
}

void treediff::print()
{
    rep(i,1,n-m)
	printf("%d%c",ans[i], (i == n-m) ? '\n' : ' ');
}

void treediff::merge(int u, int v, int w)
{
    set_iter now,one,two,set_end;
    for (set_iter it = have[v].begin(); it != have[v].end(); ++it)
	{
	    now = have[u].insert(*it);
	    one = two = now;
	    set_end = --have[u].end();
	    if (now != have[u].begin())
		ans[w] = min(ans[w],abs((*now) - (*(--one))));
	    if (now != set_end)
		ans[w] = min(ans[w],abs((*now) - (*(++two))));
	}
}

