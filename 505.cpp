#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#define rep(i,j,k) for (int i = j; i <= k; ++i)
#define rrep(i,j,k) for (int i = j; i >= k; --i)
#define BE(a) a.begin(), a.end() // begin to end
#define pb push_back

using namespace std;

const int MAX = 110000;
struct segment
{
    int l,r,pos,add;
    segment(int _l,int _r,int _pos,int _add):
	l(_l),r(_r),pos(_pos),add(_add){}
};
vector<segment> seg[MAX];
int n,m,seg_num,pos[MAX];
string genome[MAX],rev_genome[MAX];
string prefix,suffix;
int l_pre,l_suf,r_pre,r_suf;
int sum[MAX],ans[MAX];

inline void getlr(string *s, string tmp, int &l, int &r)
{
    l = lower_bound(s + 1, s + n + 1, tmp) - s;
    tmp[tmp.size()-1] ++;
    r = lower_bound(s + 1, s + n + 1, tmp) - s - 1;
}

void add(int p,int d)
{
    for ( ; p <= n; p += p&(-p))
	sum[p] += d;
}
int presum(int p)
{
    int ret = 0;
    for ( ; p > 0; p -= p&(-p))
	ret += sum[p];
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i,1,n) 
	{
	    cin >> genome[i];
	    rev_genome[i] = genome[i];
	    reverse(BE(rev_genome[i]));
	}
    sort(genome + 1, genome + n + 1);
    sort(rev_genome + 1, rev_genome + n + 1);

    rep(i,1,n)
	{
	    string tmp = rev_genome[i];
	    reverse(BE(tmp));
	    pos[i] = lower_bound(genome + 1, genome + n + 1, tmp) - genome;
	}
    
    cin >> m;
    rep(i,1,m)
	{
	    cin >> prefix >> suffix;
	    reverse(BE(suffix));
	    getlr(genome,prefix,l_pre,r_pre);
	    getlr(rev_genome,suffix,l_suf,r_suf);
	    if (l_pre > r_pre || l_suf > r_suf) continue;
	    seg[l_suf-1].pb(segment(l_pre,r_pre,i,-1));
	    seg[r_suf].pb(segment(l_pre,r_pre,i,1));
	}

    rep(i,1,n)
	{
	    add(pos[i],1);
	    vector<segment>::iterator iter;
	    for (iter = seg[i].begin(); iter != seg[i].end(); ++iter)
		ans[iter->pos] += (iter->add) * (presum(iter->r) - presum(iter->l-1));
	}
    rep(i,1,m) cout << ans[i] << endl;

    return 0;
}
