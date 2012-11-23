/*
 *NAME:self-numbers 2
 *LANG:C++
 *Source:sgu108
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
pair<int,int> q[5010];
bool f1[64],f2[64];
int ans[5010];
int num,n,m;

int main(){
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;++i){
	scanf("%d",&q[i].first);q[i].second=i;
    }
    sort(q,q+m);int pos=0;
    memset(f1,true,sizeof(f1));memset(f2,true,sizeof(f2));
    for (int i=1;i<=n;++i){
	if (i%64==0){
	    memcpy(f1,f2,64);
	    memset(f2,true,sizeof(f2));
	}
	if (f1[i%64]){
	    num++;
	    //printf("%d %d\n",num,i);
	    while (q[pos].first==num) ans[q[pos++].second]=i;
	}
	int tmp=0,j=i;
	while (j>0){
	    tmp+=j%10;
	    j/=10;
	}
	if (tmp+i%64>=64) f2[(tmp+i%64)%64]=false;
	else f1[tmp+i%64]=false;
    }
    printf("%d\n",num);
    for (int i=0,j;i<m;++i){
	printf("%d",ans[i]);
	if (i!=m-1) printf(" ");else printf("\n");
    }
    return 0;
}

