#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

const int maxn = 1050000;
string s,ans_str;
char str[300];
int L,ans_num;
struct node{
    node *left,*right;
    //    node *parent;
    char c;
    bool cek;
}buf[maxn],*tree,*ans;
int top = 0,n;

inline void init(node *T,int dep,char cc){
    T->c = cc;
    T->cek = false;
    if (dep<L){
	T->left = &buf[top++];
	T->right = &buf[top++];
	init(T->left,dep+1,'a');
	init(T->right,dep+1,'b');
    }else{
	T->left = NULL;
	T->right = NULL;
    }
}
inline void find(node *T,int dep){
    if (T->cek == false && dep<ans_num){
	ans = T;
	ans_num = dep;
	ans_str= "";
	for (int i=1;i<=ans_num;++i)
	    ans_str+=str[i];
    }
    if (T->left!=NULL) {
	str[dep+1] = 'a';
	find(T->left,dep+1);

    }
    if (T->right!=NULL){
	str[dep+1] = 'b';
	find(T->right,dep+1);
    }
    
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);

    cin >> n;
    cin >> s;
    L = ceil(log(n)/log(2));
    node *tree = new node();
    tree->c = ' ';

    init(tree,0,' ');

    for (int i=0;i<s.size()-L+1;++i)
	{
	    node *k = tree;
	    for (int j=0;j<L;++j)
		switch(s[j+i])
		    {
		    case 'a':
			k = k->left;
			k->cek = true;
			break;
		    case 'b':
			k = k->right;
			k->cek = true;
			break;
		    }
	}
    for (int i=s.size()-L+1;i<s.size();++i){
	node * k = tree;
	for (int j=i;j<s.size();++j)
	    switch (s[j])
		{
		case 'a':
		    k = k->left;
		    k->cek = true;
		    break;
		case 'b':
		    k = k->right;
		    k->cek = true;
		    break;
		}
    }
    tree->cek = true;
    ans_num = 0x7FFFFFFF;
    find(tree,0);
    cout << ans_num << endl;
    cout << ans_str << endl;
    return 0;
}
