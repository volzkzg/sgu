/*
 *NAME:Border
 *LANG:C++
 *SOURCE:sgu133
 */
#include <cstdio>
#include <algorithm>
using namespace std;
pair <int,int> outpost[16100];
int n;
int main(){
    scanf("%d\n",&n);
    for (int i=1;i<=n;++i)
	scanf("%d %d\n",&outpost[i].first,&outpost[i].second);
    sort(outpost+1,outpost+n+1);
    int x = outpost[1].second, ans = 0;
    for (int i=2;i<=n;++i){
	if (outpost[i].second < x)
	    ans++;
	else 
	    x = outpost[i].second;
    }
    printf("%d\n",ans);
    return 0;
}
