#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define rrep(i,j,k) for (int i=j;i>=k;--i)
#define mkp make_pair
#define pbk push_back

using namespace std;

const int INF = 0x7FFFFFFF/2;
typedef pair<int,int> vd;
typedef vector<vd>::iterator iter;
struct stableStr
{
  int X,M;
  vector<vd> horse;

  void input();
  void adjust();
  void print()
  {
    iter it = horse.begin();
    for (;it != horse.end(); ++it)
      cout << (*it).first << " " << (*it).second << endl;
    cout << endl;
  }
}stable[5555];
int B,N;
int map[5555];
double timeToStable[5555];

inline bool horseCmp(const vd &a,const vd &b)
{
  if (a.first == b.first) return (a.second > b.second);
  else return (a.first > b.first);
}
void stableStr::input()
{
  cin >> X >> M;
  rep(i,1,M)
    {
      int v,d;
      cin >> v >> d;
      horse.pbk(mkp(v,d));
    }  
}
void stableStr::adjust()
{
  sort(horse.begin(),horse.end(),horseCmp);
  iter it = horse.begin()+1;
  while (it != horse.end())
    {
      if ((*it).first == (*(it-1)).first)
	it = horse.erase(it);
      else if ((*it).second < (*(it-1)).second)
	it = horse.erase(it);
      else 
	++it;
    }
}


inline bool tmpCmp(const vd &a,const vd &b)
{
  return (a.second < b.second);
}
void getMap()
{
  vd tmp[5555];
  rep(i,1,N+1) tmp[i] = mkp(i,stable[i].X);
  sort(tmp+1,tmp+N+2,tmpCmp);
  rep(i,1,N+1) map[i] = tmp[i].first;
  if (stable[map[1]].X != 0) cout << -1 << endl,exit(0);
}

int main()
{
  freopen("test.in","r",stdin);
  freopen("test.out","w",stdout);
  ios::sync_with_stdio(false);
  cin >> B >> N;
  rep(i,1,N)
    {
      stable[i].input();
      stable[i].adjust();
    }stable[N+1].X = B;
  getMap();
  
  rep(i,2,N+1) timeToStable[i] = INF;
  timeToStable[1] = 0;

  int ansPos = -1;
  rep(i,1,N+1)
    {
      int to = i+1;
      int realStable = map[i];
      if (map[i] == N+1) {ansPos = i;break;}
      for (iter it = stable[realStable].horse.begin();it != stable[realStable].horse.end();++it)
	{
	  int v = (*it).first;
	  int d = (*it).second;
	  while (stable[realStable].X + d >= stable[map[to]].X && to<=(N+1))
	    {
	      timeToStable[to] = min(timeToStable[to],
				     timeToStable[i] + (double)(stable[map[to]].X - stable[realStable].X)/(double)(v));
	      to++;
	    }
	}
    }

  if (timeToStable[ansPos] == INF || ansPos == -1)
    cout << -1 << endl;
  else
    cout << setiosflags(ios::fixed)
	 << setprecision(7)
	 << timeToStable[ansPos]
	 << endl;
  
  return 0;
}
