#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

const int MAX = 51111;

struct roadStr
{ 
    int u,v,w;
    inline bool operator < (roadStr a) const
    { return w < a.w; }
};
struct operStr
{ int road,val; };
struct kruskalStr
{
    int father[MAX];
    int rank[MAX];
    int fu,fv;
    inline void init(int num)
    { rep(i,1,num) father[i] = i,rank[i] = 0; }
    inline int getfather(int x)
    { return (father[x] == x) ? x : father[x] = getfather(father[x]); }
    inline void mergeJudge(int fu,int fv)
    {
	if (rank[fu] > rank[fv])
	    father[fv] = fu;
	else
	    {
		father[fu] = fv;
		if (rank[fu] == rank[fv])
		    ++rank[fv];
	    }
    }
    inline void merge(int u,int v)
    { mergeJudge(getfather(u),getfather(v)); }
};

void qs(int l, int r,roadStr *ori,int *index)
{
    long long md = ori[index[l + r >> 1]].w;
    int i = l, j = r;
    while (i < j)
	{
	    while (ori[index[i]].w < md) ++i;
	    while (ori[index[j]].w > md) --j;
	    if (i <= j)
		swap(index[i++], index[j--]);
	}
    if (l < j) qs(l, j,ori,index);
    if (i < r) qs(i, r,ori,index);
}

void solve(int n,int m,int t,long long cost,roadStr *road,operStr *oper)
{
    static bool isModify[MAX];
    static int mustIn[MAX];
    static kruskalStr MST;
    static int unModifyNum,mustInNum;
    static int edgeMap[MAX];
    static int vtxMap[MAX];
    static int tmp[MAX];

    if (t == 1)
	{
	    road[oper[1].road].w = oper[1].val;
	    rep(i,1,m) tmp[i] = i;
	    MST.init(n);
	    qs(1,m,road,tmp);
	    rep(i,1,m) 
		{
		    int fu = MST.getfather(road[tmp[i]].u);
		    int fv = MST.getfather(road[tmp[i]].v);
		    if (fu!=fv)
			{
			    cost += road[tmp[i]].w;
			    MST.mergeJudge(fu,fv);
			}
		}
	    printf("%lld\n",cost);
	    return;
	}

    roadStr newRoad[2*t+1];
    int newN,newM,half;

    //find unmodified road
    MST.init(n);
    memset(isModify+1,false,m);
    rep(i,1,t) isModify[oper[i].road] = true;

    //extract unmodified road & add modified road to MST
    unModifyNum = 0;
    rep(i,1,m) if (!isModify[i]) tmp[++unModifyNum] = i;
    else MST.merge(road[i].u,road[i].v);

    //sort unmodified road
    //insert unmodified road to MST and save
    mustInNum = 0;
    qs(1,unModifyNum,road,tmp);
    rep(i,1,unModifyNum)
	{
	    int u = MST.getfather(road[tmp[i]].u);
	    int v = MST.getfather(road[tmp[i]].v);
	    if (u != v)
		{
		    mustIn[++mustInNum] = tmp[i];
		    MST.mergeJudge(u,v);
		    cost += road[tmp[i]].w;
		}
	}
    
    //remark the vertex mark
    newN = 0;
    MST.init(n);
    rep(i,1,mustInNum)
	MST.merge(road[mustIn[i]].u,road[mustIn[i]].v);
    rep(i,1,n) if (MST.father[i] == i) vtxMap[i] = ++newN;
    rep(i,1,n) if (MST.father[i] != i) vtxMap[i] = vtxMap[MST.getfather(i)];

    //add old graph's edge to new graph.
    newM = 0;
    MST.init(newN);
    rep(i,1,unModifyNum)
	{
	    int u = MST.getfather(vtxMap[road[tmp[i]].u]);
	    int v = MST.getfather(vtxMap[road[tmp[i]].v]);
	    if (u != v)
		{
		    MST.mergeJudge(u,v);
		    newRoad[++newM].w = road[tmp[i]].w;
		    newRoad[newM].u = vtxMap[road[tmp[i]].u];
		    newRoad[newM].v = vtxMap[road[tmp[i]].v];
		    edgeMap[i] = newM;
		}
	}
    rep(i,1,m) if (isModify[i])
	{
	    newRoad[++newM].w = road[i].w;
	    newRoad[newM].u = vtxMap[road[i].u];
	    newRoad[newM].v = vtxMap[road[i].v];
	    edgeMap[i] = newM;
	}
    //update road for the father's brother recursion
    rep(i,1,t)
	road[oper[i].road].w = oper[i].val;
    //update oper for the recursion
    rep(i,1,t)
	oper[i].road = edgeMap[oper[i].road];

    half = t / 2;
    solve(newN,newM,half,cost,newRoad,oper);
    solve(newN,newM,t - half,cost,newRoad,oper + half);
}

void read(int & data)
{
    static char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9')
	{
	    data = data * 10 + c - '0';
	    c = getchar();
	}
}

int main()
{
    int n,m,t;
    operStr oper[MAX];
    roadStr road[MAX];
    read(n);read(m);read(t);
    rep(i,1,m) 
	{
	    read(road[i].u);
	    read(road[i].v);
	    read(road[i].w);
	}
    rep(i,1,t)
	{
	    read(oper[i].road);
	    read(oper[i].val);
	}
    solve(n,m,t,0,road,oper);
    return 0;
}
