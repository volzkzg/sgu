/*
 *NAME:Divide and conquer
 *LANG:C++
 *TIMES:18
 *METHOD:枚举旋转+平移，判断是否存在奇链和奇环验证正确性
 *时间复杂度：O(n^4)
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 30

using namespace std;

int a[maxn][maxn];
int in[maxn*maxn];//表示连入的是哪个
int out[maxn*maxn];//表示连出去的是哪个
struct Enode{
    int x,y;
}posPoint[maxn*maxn];
int Matrix[maxn][maxn];
int numOfOne,sqrN,n,top;
char op[maxn];
bool v[maxn*maxn];

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d\n",&n);
    for (int i=1; i<=n;++i){
	scanf("%s\n",op+1);
	for (int j=1;j<=n;++j){
	    a[i][j] = op[j]-'0';
	    if (a[i][j]){
		a[i][j] = ++numOfOne;
		posPoint[numOfOne].x = i;
		posPoint[numOfOne].y = j;
	    }
	}
    }
    if (numOfOne%2){
	printf("NO\n");
	return 0;
    }
    for (int turn=0;turn<=3;++turn)
	for (int rowInc = -n;rowInc<=n;++rowInc)
	    for (int colInc = -n;colInc<=n;++colInc){
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		bool f = false;
		for (int x = 1;x<=n;++x)
		    for (int y = 1;y<=n;++y)
			if (a[x][y]){
			    int xx,yy;
			    switch(turn){
			    case 0:
				xx = x,yy = y;break;
			    case 1:
				xx = y,yy = n-x+1;break;
			    case 2:
				xx = n-x+1,yy = n-y+1;break;
			    case 3:
				xx = n-y+1,yy = x;break;
			    }
			    xx+=rowInc;yy+=colInc;
			    if (xx>=1 && xx<=n && yy>=1 && yy<=n && a[xx][yy]){
				int p = a[x][y],q = a[xx][yy];
				if (p == q) {f = true;break;}
				in[q] = p;out[p] = q;
			    }
			}
		if (f) continue;
		memset(v,false,sizeof(v));
		memset(Matrix,0,sizeof(Matrix));
		for (int i=1;i<=numOfOne;++i)
		    if (!v[i] && out[i] && in[i]==0){
			int j = i;
			while (true){
			    Matrix[posPoint[j].x][posPoint[j].y] = 1;
			    v[j] = v[out[j]] = true;
			    j = out[out[j]];
			    if (j == 0) break;
			    if (out[j] == 0) {f = true;break;}
			}
			if (f) break;
		    }
		if (f) continue;
		for (int i=1;i<=numOfOne;++i)
		    if (!v[i]){
			int j = i;
			while (true){
			    Matrix[posPoint[j].x][posPoint[j].y] = 1;
			    v[j] = true;
			    if (v[out[j]]){f = true;break;}
			    v[out[j]] = true;
			    j = out[out[j]];
			    if (v[j]) break;
			}
			if (f) break;
		    }
		if (f) continue;
		printf("YES\n");
		for (int i=1;i<=n;++i){
		    for (int j=1;j<=n;++j)
			printf("%d",Matrix[i][j]);
		    printf("\n");
		}
		return 0;
	    }
    printf("NO\n");
    return 0;
}
