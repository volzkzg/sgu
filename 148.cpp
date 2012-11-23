#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 15555;
typedef pair<int,int> level_pair;
typedef pair<level_pair,int> set_pair;
typedef set<set_pair>::iterator iter;
set<set_pair> level_set,ans_set;
bool operator < (set_pair a,set_pair b){
    return (a.first.first<b.first.first);
}
int w[maxn],l[maxn],p[maxn],sum[maxn],_ans[maxn],ans_num;

int main(){
    int i,j,k,n;
    scanf("%d\n",&n);
    sum[0] = 0;
    for (i=1;i<=n;++i)
	{
	    scanf("%d %d %d\n",&w[i],&l[i],&p[i]);
	    sum[i] = sum[i-1]+w[i];
	}
    int cost = 0,ans = 0x7FFFFFF;
    for (i=n;i>=1;--i){
	if (!level_set.empty())
	    {
		iter t = level_set.end();t--;bool f = false;
		while (true){
		    if (t == level_set.begin()) f = true;
		    if (t->first.first>sum[i-1]){
			cost-=t->first.second;
			level_set.erase(t--);
		    }else break;
		    if (f) break;
		}
	    }
	cost+=p[i];
	level_set.insert(make_pair(make_pair(sum[i]-l[i],p[i]),i));
	if (cost<ans){
	    ans_set = level_set;
	    ans = cost;
	}
    }
    iter t = ans_set.begin();
    while (t!=ans_set.end()){
	_ans[ans_num++] = t->second;
	++t;
    }sort(_ans+1,_ans+ans_num);
    for (i=0;i<ans_num;++i)
	printf("%d\n",_ans[i]);
    return 0;
}
