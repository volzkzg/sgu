#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

const int N = 200010;
const int MOD = 99990001;

struct Edge {
        int u, v;
        Edge() {}
        Edge(int _u, int _v) {
                u = min(_u, _v);
                v = max(_u, _v);
        }
        bool operator < (const Edge &rhs) const {
                if (u == rhs.u) return v < rhs.v;
                return u < rhs.u;
        }
};

struct State {
        int u, ufather, qhead, uehead;
        vector<int> q;
        vector<int> father;
        State() {}
        State(int _u) {
                q.push_back(_u);
                father.push_back(0);
                u = _u;
                qhead = 1;
                ufather = 0;
                uehead = 0;
        }
        void init(int _u) {
                q.clear();
                father.clear();
                q.push_back(_u);
                father.push_back(0);
                u = _u;
                qhead = 1;
                ufather = 0;
                uehead = 0;
        }
};
set<Edge> inGraph;
map<Edge, int> weight;
vector<int> G[N];
int n, edgeu[N], edgev[N], belong[N], delta[N];

void add(int &x, int y) {
        x += y;
        x %= MOD;
}

void multiply(int &x, int y) {
        x = (long long)x * y % MOD;
}

bool update(State &now)
{
        int u, v;
        for (int i = now.uehead; i < (int)G[now.u].size(); ++i) {
                v = G[now.u][i];
                if (v != now.ufather && 
                    inGraph.count(Edge(now.u, v))) {
                        now.q.push_back(v);
                        now.father.push_back(now.u);
                        now.uehead = i + 1;
                        return false;
                }
        }
        vector<int> &q = now.q;
        while (now.qhead < (int)q.size()) {
                u = q[now.qhead];
                int tt = now.qhead;
                ++now.qhead;
                for (int i = 0; i < G[u].size(); ++i) {
                        v = G[u][i];
                        if (v != now.father[tt] &&
                            inGraph.count(Edge(u, v))) {
                                now.q.push_back(v);
                                now.father.push_back(u);
                                now.u = u;
                                now.ufather = now.father[tt];
                                now.uehead = i + 1;
                                return false;
                        }
                }
        }
        return true;
}

void doing(State &now, int w, int pos)
{
        vector<int> &q = now.q;
        delta[pos] = 0;
        for (int i = 0; i < (int)q.size(); ++i) {
                int u = q[i];
                for (int j = 0; j < (int)G[u].size(); ++j) {
                        int v = G[u][j];
                        if (u < v) {
                                add(weight[Edge(u, v)], delta[belong[u]]);
                                multiply(weight[Edge(u, v)], w);
                        }
                }
                belong[u] = pos;
        }
}

int main()
{
        scanf("%d", &n);
        for (int i = 1; i < n; ++i) {
                static int u, v, w;
                scanf("%d%d%d", &u, &v, &w);
                G[u].push_back(v);
                G[v].push_back(u);
                weight[Edge(u, v)] = w;
                edgeu[i] = u, edgev[i] = v;
                inGraph.insert(Edge(u, v));
        }
	
        for (int i = 1; i <= n; ++i) {
                belong[i] = 1;
                delta[i] = 0;
        }
	
        for (int i = 2; i <= n; ++i) {
                static int id, u, v, w;
                scanf("%d", &id);
                u = edgeu[id], v = edgev[id];
                w = weight[Edge(u, v)];
                add(w, delta[belong[u]]);
                inGraph.erase(Edge(u, v));

                printf("%d\n", w);
                fflush(stdout);

                State su(u), sv(v);
                while (true) {
                        bool bu = update(su);
                        bool bv = update(sv);

                        if (bu && bv) {
                                vector<int>::iterator min_uid = min_element(su.q.begin(), su.q.end());
                                vector<int>::iterator min_vid = min_element(sv.q.begin(), sv.q.end());
                                if (!su.q.empty() && (sv.q.empty() || *min_uid < *min_vid)) {
                                        bv = false;
                                } else {
                                        bu = false;
                                }
                        }

                        if (bu) {
                                doing(su, w, i);
                                add(delta[belong[v]], w);
                                su.q.resize(0);
                                su.father.resize(0);
                                sv.q.resize(0);
                                sv.father.resize(0);
                                break;
                        }
                        if (bv) {
                                doing(sv, w, i);
                                add(delta[belong[u]], w);
                                su.q.resize(0);
                                su.father.resize(0);
                                sv.q.resize(0);
                                sv.father.resize(0);
                                break;
                        }
                }
        }
        return 0;
}
