#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define maxn 301
#define INF 0x7FFFFFFF

using namespace std;

bool f[maxn][maxn];
int ff[maxn][maxn];
int d[maxn][4];
int color[maxn];
struct node{
    int v,c;
}queue[maxn*3+10];
int n,m;
int a,b,c;
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for (int i=2;i<=n;++i) d[i][1] = d[i][2] = d[i][3] = INF;
    d[1][1] = d[1][2] = d[1][3] = 0;
    for (int i=1;i<=m;++i){
	scanf("%d %d %d\n",&a,&b,&c);
	f[a][b] = true;
	ff[a][b] = c;
    }
    //spfa
    bool inqueue[maxn][4];
    memset(inqueue,false,sizeof(inqueue));
    int tail,head;tail = head = 0;
    queue[++tail].v = 1,queue[tail].c = 1;
    queue[++tail].v = 1,queue[tail].c = 2;
    queue[++tail].v = 1,queue[tail].c = 3;
    inqueue[1][1] = inqueue[1][2] = inqueue[1][3] = true;
    int mood = maxn*3+10;
    while (head <= tail){
	head = (head % mood)+1;
	int p,q;
	p = queue[head].v;q = queue[head].c;
	inqueue[p][q] = false;
	for (int i=1;i<=n;++i)
	    if (f[p][i] && ff[p][i]!=q && (d[p][q]+1)<d[i][ff[p][i]]){
		//		printf("%d %d\n",i,ff[p][i]);
		d[i][ff[p][i]] = d[p][q]+1;
		tail = (tail % mood)+1;
		if (!inqueue[i][ff[p][i]]){
		    queue[tail].v = i;
		    queue[tail].c = ff[p][i];
		}
	    }
    }
    int ans = min(d[n][1],min(d[n][2],d[n][3]));
    (ans == INF)? printf("-1\n"):printf("%d\n",ans);
    return 0;
}
