/*
 *NAME:sequence
 *LANG:C++
 *TIMES:4
 *METHOD:splay
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define keyTree root->ch[1]->ch[0]
using namespace std;
const int maxn = 130100,INF = 0x7FFFFFFF/2;
int n,m;
struct node{
    int key,size;
    bool rev;
    node *pre,*ch[2];
    void reverse(){
	if (size == 0) return;
	rev ^= 1;
	swap(ch[0],ch[1]);
    }
    void push_up(){
	size = ch[0]->size + ch[1]->size + 1;
    }
    void push_down(){
	if (rev){
	    ch[0]->reverse();
	    ch[1]->reverse();
	}rev = 0;
    }
};
class splayTree{
public:
    node *root,*null;int top;
    node data[maxn];
    inline node *newNode(int value){
	node *t;
	t = &data[top++];
	t->key = value;
	t->pre = t->ch[0] = t->ch[1] = null;
	t->size = t->rev = 0;
	return t;
    }
    inline void init(){top = 0;
	null = newNode(INF);null->size = 0;
	root = newNode(INF);root->ch[1] = newNode(INF);root->ch[1]->pre=root;
	root->push_up();
    }
    inline node *build(int l,int r){
	if (l>r) return null;
	int mid = (l+r) >> 1;
	node *p = newNode(mid);
	p->ch[0] = build(l,mid-1);
	p->ch[1] = build(mid+1,r);
	if (p->ch[0] != null) p->ch[0]->pre = p;
	if (p->ch[1] != null) p->ch[1]->pre = p;
	p->push_up();
	return p;
    }
    inline void rotate(node *x,int c){
	node *y = x->pre;
	y->push_down();x->push_down();
	y->ch[!c] = x->ch[c];
	if (y->ch[!c]!=null) y->ch[!c]->pre = y;
	x->pre = y->pre;
	if (x->pre != null) x->pre->ch[y == y->pre->ch[1]] = x;
	y->pre = x;
	x->ch[c] = y;
	y->push_up();
	if (y == root) root = x;
    }
    inline void splay(node *x,node *goal){
	x->push_down();
	while (x->pre != goal){
	    if (x->pre->pre == goal){
		rotate(x,x == x->pre->ch[0]);
		break;
	    }
	    node *y = x->pre,*z = y->pre;
	    int f = (y == z->ch[0]);
	    if (x == y->ch[f])
		rotate(x,!f),rotate(x,f);
	    else
		rotate(y,f),rotate(x,f);
	}
	x->push_up();
    }
    inline void select(int k,node *x){
	node * t = root;
	while (true){
	    t->push_down();
	    int tmp = t->ch[0]->size;
	    if (tmp == k) break;
	    if (tmp < k){
		k-=tmp+1;
		t = t->ch[1];
	    }else
		t = t->ch[0];
	}
	splay(t,x);
    }
    inline void reverse(int l,int r){
	select(l-1,null);
	select(r+1,root);
	keyTree->reverse();
    }
    inline void print(node *t){
	if (t == null) return;
	t->push_down();
	print(t->ch[0]);
	if (t->key != INF) printf("%d ",t->key);
	print(t->ch[1]);
    }
}spt;
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);

    scanf("%d %d\n",&n,&m);
    spt.init();
    spt.keyTree = spt.build(1,n);
    spt.keyTree->pre = spt.root->ch[1];
    spt.splay(spt.keyTree,spt.null);

    for (int i=1,a,b;i<=m;++i)
	scanf("%d %d\n",&a,&b),spt.reverse(a,b);
    
    spt.print(spt.root);
    printf("\n");
    return 0;
}
