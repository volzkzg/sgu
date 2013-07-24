#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cmath> 
#include <iostream> 
#include <fstream> 
#include <algorithm> 
#include <string> 
#define rep(i,j,k) for (int i=j;i<=k;++i) 
#define rrep(i,j,k) for (int i=j;i>=k;==i) 

using namespace std; 

const int maxn = 200000+10; 
struct node 
{ int u,v,next,w; }
edge[maxn*2]; 
int g[maxn],need[maxn],edgeNum,n,selfNeed[maxn]; 
int ans[maxn],ansNum; 
string s; 

void insert(int u,int v,int w) 
{
  edgeNum++; edge[edgeNum].u = u,edge[edgeNum].v = v,edge[edgeNum].w = w; 
  edge[edgeNum].next = g[u],g[u] = edgeNum;
  edgeNum++; edge[edgeNum].u = v,edge[edgeNum].v = u,edge[edgeNum].w = w; 
  edge[edgeNum].next = g[v],g[v] = edgeNum; 
} 
void findNeed(int u,int pre,int dep,int have) 
{ 
  for (int t = g[u];t;t = edge[t].next) 
    if (edge[t].v!=pre) 
      {
	int v = edge[t].v; 
	int w = edge[t].w; 
	findNeed(v,u,dep+1,have+w); 
	need[u] = max(need[v],need[u]); 
      } 
  need[u] = max(need[u],(dep+1)/2-have); 
  selfNeed[u] = (dep+1)/2-have; 
} 
void getAns(int u,int pre,int plus) 
{ 
  if (selfNeed[u]-plus>0) 
    { 
      cout << -1 << endl; exit(0); 
    } 
  for (int t = g[u];t;t=edge[t].next) 
    if (edge[t].v!=pre) 
      { 
	int v = edge[t].v; 
	int w = edge[t].w; 
	if (need[v]-plus<=0) continue; 
	if (w == 0) 
	  { 
	    ans[++ansNum] = (t+1)/2; 
	    getAns(v,u,plus+1); 
	  } 
	else 
	  getAns(v,u,plus); 
      } 
} 

int main() 
{ 
  ios::sync_with_stdio(false); 
  cin >> n; 
  rep(i,1,n-1) 
    { 
      int u,v; 
      string s; 
      cin >> u >> v; 
      cin >> s; 
      if (s[0] == 'a') 
	{ 
	  cin >> s; 
	  insert(u,v,0); 
	} 
      else insert(u,v,1); 
    } 
  findNeed(1,-1,0,0); 
  getAns(1,-1,0); 
  cout << ansNum << endl; 
  rep(i,1,ansNum) cout << ans[i] << " " ;
  cout << endl; 
  return 0; 
}
