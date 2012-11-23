#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define maxn 41

using namespace std;

struct node{
    int v;
    node *next;
}*g[maxn*maxn];
int row[maxn*maxn],col[maxn*maxn];
struct pospoint{
    int x,y;
}posPoint[maxn*maxn];
bool f[maxn][maxn];
bool visit[maxn][maxn];
int last[maxn*maxn];
bool use[maxn*maxn];
int point[maxn][maxn];
int left[maxn*maxn];
int right[maxn*maxn];
int leftNum,rightNum;
int rowNum,colNum;
int n,p,ans;
bool join[maxn*maxn];
void insert(int a,int b){
    //    printf("%d %d\n",a,b);
    static node buf[maxn*maxn*4];
    static int top = 0;
    node *x = &buf[top++];
    x->v = b;x->next =g[a];g[a] = x;
}
bool augment(int x){
    node * t = g[x];
    while (t!=0){
	if (use[t->v]){
	    use[t->v] = false;
	    if (last[t->v] == 0 || 
		augment(last[t->v])){
		last[t->v] = x;
		return true;
	    }
	}
	t = t->next;
    }
    return false;
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    //input
    scanf("%d %d\n",&n,&p);
    int black,white;
    f[1][1] = false;
    for (int i=2;i<=n;++i) f[1][i] = !f[1][i-1];
    for (int i=2;i<=n;++i)
	for (int j=1;j<=n;++j)
	    f[i][j] = !f[i-1][j];
    black = white = 0;
    for (int i=1,x,y;i<=p;++i){
	scanf("%d %d\n",&x,&y);
	visit[x][y] = true;
	if (f[x][y]) ++white; else ++black;
    }
    if (white != black || black+white == n*n || (n % 2==1)){
	printf("No\n");
	return 0;
    }

    //makegraph
    memset(g,0,sizeof(g));
    for (int i=1;i<=n;++i)
	for (int j=1;j<=n;++j){
	    point[i][j] = (i-1)*n+j;
	    posPoint[point[i][j]].x = i;
	    posPoint[point[i][j]].y = j;
	}memset(join,false,sizeof(join));
    for (int i=1;i<=n;++i)
	for (int j=1;j<=n;++j)
	    if (!visit[i][j] && !f[i][j]){
		left[++leftNum] = point[i][j];
		if (i-1>0 && !visit[i-1][j]){
		    insert(point[i][j],point[i-1][j]);
		    if (join[point[i-1][j]] ==false){
			right[++rightNum] = point[i-1][j];
			join[point[i-1][j]] = true;
		    }
		}
		if (i+1<=n && !visit[i+1][j]){
		    insert(point[i][j],point[i+1][j]);
		    if (join[point[i+1][j]] == false){
			right[++rightNum] = point[i+1][j];
			join[point[i+1][j]] = true;
		    }
		}
		if (j-1>0 && !visit[i][j-1]){
		    insert(point[i][j],point[i][j-1]);
		    if (join[point[i][j-1]] == false){
			right[++rightNum] = point[i][j-1];
			join[point[i][j-1]] = true;
		    }
		}
		if (j+1<=n && !visit[i][j+1]){
		     insert(point[i][j],point[i][j+1]);
		     if (join[point[i][j+1]] == false){
			 right[++rightNum] = point[i][j+1];
			 join[point[i][j+1]] = true;
		     }
		}
	    }

     //solve
     for (int i=1;i<=leftNum;++i){
	 memset(use,true,sizeof(use));
	 if (augment(left[i])) ++ans;
     }
    if (ans != (n*n-black*2)/2){
	printf("No\n");
	return 0;
    }else{
	for (int i=1;i<=rightNum;++i){
	    int p = last[right[i]];
	    int q = right[i];
	    if (abs(p-q) == 1)
		row[++rowNum] = min(p,q);
	    else 
		col[++colNum] = min(p,q);
	}
	sort(row+1,row+rowNum+1);
	sort(col+1,col+colNum+1);
	
	//print
	printf("Yes\n");
	printf("%d\n",colNum);
	for (int i=1;i<=colNum;++i)
	    printf("%d %d\n",posPoint[col[i]].x,posPoint[col[i]].y);
	printf("%d\n",rowNum);
	for (int i=1;i<=rowNum;++i)
	    printf("%d %d\n",posPoint[row[i]].x,posPoint[row[i]].y);
	return 0;
    }
}
