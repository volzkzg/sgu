#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#define maxn 200020
#define INF 1001
#define keyTree root->ch[1]->ch[0]

using namespace std;

int n,m,k;
string a[maxn];
string s;
struct node{
    char key[10];
    int keysize;
    int size;
    bool rev;
    node *pre,*ch[2];

    inline void reverse(){
	if (size == 0) return;
	rev ^= 1;
	swap(ch[0],ch[1]);
    }
    inline void push_up(){
	size = ch[0]->size + ch[1]->size + 1;
    }
    inline void push_down(){
	if (rev){
	    ch[0]->reverse();
	    ch[1]->reverse();
	}rev = 0;
    }
};
class splayTree{

public:
    node *root,*null;
    node buf[maxn];
    int top,cnt,num;
    int pos,tot,c,pop;
    inline node *newNode(string value){
	node *x;
	x = &buf[top++];
	for (int i=0;i<value.size();++i)
	    x->key[i] = value[i];
	x->keysize = value.size();
	//x->key = value;
	x->size = 1,x->rev = 0;
	x->pre = x->ch[0] = x->ch[1] = null;
	return x;
    }
    inline void init(){
	top = cnt = 0;num = n;
	null = newNode("!");null->size = 0;//null->sum = 0;
	root = newNode("!");//root->sum = 0;
	root->ch[1] = newNode("!");root->ch[1]->pre = root;//root->ch[1]->sum =0;
    }
    inline node *build(int l,int r){
	if (l>r) return null;
	int mid = (l+r) >> 1;
	node *x = newNode(a[mid]);
	x->ch[0] = build(l,mid-1);
	x->ch[1] = build(mid+1,r);
	if (x->ch[0] != null) x->ch[0]->pre = x;
	if (x->ch[1] != null) x->ch[1]->pre = x;
	x->push_up();
	return x;
    }
    inline void rotate(node *x,int c){
	node *y = x->pre;
	y->push_down();x->push_down();
	y->ch[!c] = x->ch[c];
	if (y->ch[!c] != null) y->ch[!c]->pre = y;
	x->pre = y->pre;
	if (x->pre != null) x->pre->ch[y == x->pre->ch[1]] = x;
	x->ch[c] = y;
	y->pre = x;
	if (y == root) root = x;
	y->push_up();
    }
    inline void splay(node *x,node *g){
	x->push_down();
	while (x->pre != g){
	    if (x->pre->pre == g){
		rotate(x,x == x->pre->ch[0]);break;
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
    inline void select(node *x,int k){
	node *t = root;
	while (true){
	    t->push_down();
	    int tmp = t->ch[0]->size;
	    if (tmp == k) break;
	    if (tmp < k) k-= tmp+1,t = t->ch[1];
	    else t = t->ch[0];
	}
	splay(t,x);
    }
    inline void insert(){
	num++;tot = 1;pos=0;
	a[1] = "";
	for (int i=4;i<s.size()-1;++i) a[1]+=s[i];
	select(null,pos);
	select(root,pos+1);
	keyTree = build(1,tot);
	keyTree->pre = root->ch[1];
	splay(keyTree,null);
    }
    inline void reverse(){
	pos = 1;if (k>num) tot = num; else tot = k;
	select(null,pos-1);
	select(root,pos+tot);
	if (keyTree != null){
	    keyTree->reverse();
	    splay(keyTree,null);
	}
    }
    inline void print(node *t){
	if (t == null ) return;
	t->push_down();
	print(t->ch[0]);
	if (t->key[0]!='!'){
	    for (int i=0;i<t->keysize;++i) cout << t->key[i];
	    cout << endl;
	}
	print(t->ch[1]);
    }
}spt;
int main(){
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i=1;i<=n;++i){
	cin >> a[i];
    }
    spt.init(); 
    spt.keyTree = spt.build(1,n);
    if (spt.keyTree!=spt.null) spt.keyTree->pre = spt.root->ch[1];
    if (spt.keyTree!=spt.null) spt.splay(spt.keyTree,spt.null);
    for (int i=1;i<=m;++i){
	cin >> s;
	switch (s[0]){
	case 'A':spt.insert();break;
	case 'R':spt.reverse();break;
	}
    }spt.print(spt.root);
}

