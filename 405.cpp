#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

pair<int,int> g[111];
int score[111];
int n,m;

int main(){
    scanf("%d %d\n",&n,&m);
    for (int i=1;i<=m;++i){
	scanf("%d %d\n",&g[0].first,&g[0].second);
	int rel,rel1,divide;
	divide = g[0].first - g[0].second;
	if (g[0].first == g[0].second) rel = 0;
	else rel = (g[0].first>g[0].second)?1:-1;
	for (int j=1;j<=n;++j){
	    scanf("%d %d\n",&g[j].first,&g[j].second);
	    if (g[j].first == g[j].second) rel1 = 0;
	    else rel1 = (g[j].first>g[j].second)?1:-1;
	    if (rel1 == rel) score[j] += 2;
	    if ((g[j].first - g[j].second) == divide) score[j] += 3;
	    if (g[j].first == g[0].first) score[j]++;
	    if (g[j].second == g[0].second) score[j]++;
	}
    }
    for (int i=1;i<=n-1;++i)
	printf("%d ",score[i]);
    printf("%d\n",score[n]);
    return 0;
}
