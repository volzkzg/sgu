#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int Maxn = 210000;

class dragon
{
public:
        int gold, pos;
        bool operator < (const dragon &b) const
        {
                if(gold == b.gold) return pos > b.pos;
                return gold > b.gold;
        }
};

dragon d[Maxn];
int bound[Maxn], n;
const int inf = 0x3f3f3f3f;

class Node
{
public:
        int delta;
        int l, r, min, val;
        int L, R;
};

Node t[4 * Maxn];

const int rt = 1;

void update(int x)
{
        int lch = x << 1, rch = x << 1 | 1;
        t[x].min = min(t[lch].min, t[rch].min);
}

void mark(int x, int delta)
{
        t[x].min += delta;
        if(t[x].L == t[x].R)
                t[x].val += delta;
        t[x].delta += delta;
}

void pushdown(int x)
{
        if(t[x].delta && t[x].L != t[x].R)
                {
                        mark(x << 1, t[x].delta);
                        mark(x << 1 | 1, t[x].delta);
                }
        t[x].delta = 0;
}

class Segtree
{
public:
        void Build(int *arr, int L, int R, int cur)
        {
                t[cur].l = L, t[cur].R = R;
                t[cur].L = L, t[cur].r = R;
                t[cur].delta = 0, t[cur].min = inf;
                if(L == R)
                        {
                                t[cur].min = t[cur].val = arr[L];
                                return;
                        }
                else
                        {
                                int mid = (L + R) >> 1;
                                Build(arr, L, mid, cur << 1);
                                Build(arr, mid + 1, R, cur << 1 | 1);
                                update(cur);
                        }
        }
        void modify(int L, int R, int delta, int cur)
        {
                pushdown(cur);
                int x = cur;
                if(L == t[x].L && R == t[x].R)
                        mark(x, delta);
                else
                        {
                                int mid = (t[x].L + t[x].R) >> 1;
                                if(R <= mid) modify(L, R, delta, cur << 1);
                                else if(L > mid) modify(L, R, delta, cur << 1 | 1);
                                else modify(L, mid, delta, cur << 1), modify(mid + 1, R, delta, cur << 1 | 1);
                                update(cur);
                        }
        }
        int query(int L, int R, int cur)
        {
                pushdown(cur);
                int x = cur;
                if(L == t[x].L && R == t[x].R)
                        {
                                return t[x].min;
                        }
                else
                        {
                                int mid = (t[x].L + t[x].R) >> 1;
                                if(R <= mid) return query(L, R, cur << 1);
                                else if(L > mid) return query(L, R, cur << 1 | 1);
                                else return min(query(L, mid, cur << 1), query(mid + 1, R, cur << 1 | 1));
                        }
        }
};

Segtree st;

int main()
{
        while(scanf("%d", &n) == 1)
                {
                        for(int i = 1; i <= n + 1; ++i)
                                bound[i] = inf;
                        int totd = 0;
                        int aim;
                        for(int i = 2; i <= n; ++i)
                                {
                                        static char s[10];
                                        int val;
                                        scanf("%s%d", s, &val);
                                        if(s[0] == 'p')
                                                bound[i] = val;
                                        else
                                                {
                                                        d[totd].pos = i;
                                                        d[totd++].gold = val;
                                                }
                                }
                        sort(d, d + totd);
                        aim = bound[n];
                        bound[n] = inf;
                        for(int i = n; i >= 1; --i)
                                bound[i] = min(bound[i + 1], bound[i]);
                        st.Build(bound, 1, n, rt);
		
                        int ans = 0, ansCnt = 0;
                        vector<int> answer;
                        for(int i = 0; i < totd; ++i)
                                {
                                        int pos = d[i].pos;
                                        int v = d[i].gold;
                                        //if(bit.query(nxtPri) + 1 < bound[nxtPri])
                                        if(st.query(pos, n, rt) - 1 >= 1)
                                                {
                                                        ans += v, ansCnt++;
                                                        st.modify(pos, n, -1, rt);//bit.insert(pos, 1);
                                                        answer.push_back(pos);
                                                }
                                }
                        if(ansCnt < aim)
                                printf("-1\n");
                        else
                                {
                                        printf("%d\n", ans);
                                        sort(answer.begin(), answer.end());
                                        printf("%d\n", (int)answer.size());
                                        for(int i = 0; i < answer.size(); ++i)
                                                printf("%d%c", answer[i], i + 1 == answer.size() ? '\n' : ' ');
                                }
                }
        return 0;
}
