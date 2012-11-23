#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define maxn 11111

using namespace std;


struct point{
    int x,y,pos;
}p[maxn];int pointNum;
struct occur{
    int mode,y1,y2,x;
    //mode1 表示这条形平行于x轴的右端点
    //mode2 表示这条线平行于y轴，也就是x1=x2
    //mode3 表示这条平行于x轴线的左端点
}o[maxn*2];int occurNum;
struct node{
    int v;
    node *next;
};
node *g[maxn];
int tree[maxn*2*4] = {0};
int ans = 0;
bool cmpX(point a,point b){
    if (a.x<b.x) return true;
    if (a.x == b.x && a.y<b.y) return true;
    return false;
}
bool cmpY(point a,point b){
    if (a.y<b.y) return true;
    if (a.y == b.y && a.x<b.x) return true;
    return false;
}
bool cmp(occur a,occur b){
    if (a.x < b.x) return true;
    if (a.x == b.x){
	if (a.mode < b.mode) return true;
    }return false;
}
void input(){int i,j;
    memset(g,0,sizeof(g));
    scanf("%d\n",&pointNum);
    for (i=0;i<pointNum;++i){
	scanf("%d%d\n",&p[i].x,&p[i].y);
	p[i].pos = i;
	p[i].x+=10001;
	p[i].y+=10001;
    }
    
}
void insert(int a,int b){
    //    cout << a << " " << b << endl;
    node *x = new node();
    x->v = b;x->next = g[a];g[a] = x;
}
void makeOccur(){int i,j;
    sort(p,p+pointNum,cmpX);
    /*
    for (i=0;i<pointNum;++i) cout << p[i].x << " " << p[i].y << endl;
    cout << endl;
    */
    for (i=0;i<pointNum;i+=2){
	if (p[i].x!=p[i+1].x){
	    printf("0\n");
	    exit(0);
	}
	insert(p[i].pos,p[i+1].pos);
	insert(p[i+1].pos,p[i].pos);

	o[occurNum].mode = 2;
	o[occurNum].y1 = p[i].y;
	o[occurNum].y2 = p[i+1].y;
	o[occurNum++].x = p[i].x;
	ans += abs(p[i+1].y-p[i].y);
    }
    sort(p,p+pointNum,cmpY);
    /*
    for (i=0;i<pointNum;++i) cout << p[i].x << " " << p[i].y << endl;
    cout << endl;
    */
    for (i=0;i<pointNum;i+=2){
	if (p[i].y!=p[i+1].y){
	    printf("0\n");
	    exit(0);
	}
	insert(p[i].pos,p[i+1].pos);
	insert(p[i+1].pos,p[i].pos);

	o[occurNum].mode = 3;
	o[occurNum].y1 = p[i].y;
	o[occurNum].y2 = 0;
	o[occurNum++].x = p[i].x;

	o[occurNum].mode = 1;
	o[occurNum].y1 = p[i+1].y;
	o[occurNum].y2 = 0;
	o[occurNum++].x = p[i+1].x;
	
	ans += abs(p[i+1].x-p[i].x);
    }
    sort(o,o+occurNum,cmp);
    /*
    for (i=0;i<occurNum;++i)
	cout << o[i].mode << " " << o[i].y1 << " " << o[i].y2 << endl;
    */
}

bool f[maxn];
void bfs(int pos){
    int i;
    node *j = g[pos];
    f[pos] =true;
    for (;j!=0;j=j->next){
	if (!f[j->v]) bfs(j->v);
    }
}

void insert(int l,int r,int p,int k){
    if (l == r){
	tree[p] = 1;
	return;
    }
    int mid = (l+r)>>1;
    if (k<=mid) insert(l,mid,p*2,k);
    else insert(mid+1,r,p*2+1,k);
    tree[p] = tree[2*p]+tree[2*p+1];
}
void del(int l,int r,int p,int k){
    if (l == r){
	tree[p] = 0;
	return;
    }
    int mid = (l+r)>>1;
    if (k<=mid) del(l,mid,p*2,k);
    else del(mid+1,r,p*2+1,k);
    tree[p] = tree[2*p]+tree[2*p+1];
}
int query(int l,int r,int p,int a,int b){
    if (l == a && r == b){
	return tree[p];
    }
    int mid = (l+r) >> 1;
    if (b<=mid) return query(l,mid,p*2,a,b);
    else if (a>mid) return query(mid+1,r,p*2+1,a,b);
    else return query(l,mid,p*2,a,mid)+query(mid+1,r,p*2+1,mid+1,b);
}
bool check(){int i,j;
    //我们需要做两个判断
    //第一个判断是判断这个图是否联通
    //第二个判断是判断这个图是否有交叉，使用线段树
    
    //第一个判断，使用一遍bfs
    memset(f,false,sizeof(f));
    bfs(0);bool ff = false;
    for (i=0;i<pointNum;++i)
	if (!f[i]){
	    ff = true;
	    break;
	}
    if (ff) return false;

    //第二个判断，使用线段树
    int II = 20002;int aaa;
    for (i=0;i<occurNum;++i){
	switch(o[i].mode){
	case 1:del(1,II,1,o[i].y1);break;
	case 2:
	    aaa = query(1,II,1,o[i].y1,o[i].y2);
	    if (aaa!=0) return false;
	    break;
	case 3:
	    insert(1,II,1,o[i].y1);
	    break;
	}
    }
    return true;
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    input();
    makeOccur();
    if (check())
	printf("%d\n",ans);
    else
	printf("0\n");
}
