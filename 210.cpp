#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 500

using namespace std;

struct node{
    int v;
    node *next;
}*g[maxn];
struct Nnode{
    int love,num;
}son[maxn];
int girl[maxn],n,m;
bool use[maxn];
int last[maxn];

void insert(int a,int b){
    static node buf[maxn*maxn];
    static int top = 0;
    node *x = &buf[top++];
    x->v =b;x->next = g[a];g[a]=x;
}
bool augment(int x){
    node *t = g[x];
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
    scanf("%d\n",&n);
    for (int i=1;i<=n;++i){
	scanf("%d",&son[i].love);
	son[i].num = i;
    }
    for (int i=1;i<=n;++i){int num,tmp;
	scanf("%d",&num);
	for (int j = 1;j<=num;++j){
	    scanf(" %d",&tmp);
	    insert(i,tmp);
	}
    }
    for (int i=1;i<n;++i)
	for (int j=i+1;j<=n;++j)
	    if (son[i].love<son[j].love){
		int tmp;
		tmp = son[i].num;
		son[i].num = son[j].num;
		son[j].num = tmp;
		tmp = son[i].love;
		son[i].love = son[j].love;
		son[j].love = tmp;
	    }
    for (int i=1;i<=n;++i){int ans = 0;
	memset(use,true,sizeof(use));
	if (augment(son[i].num)) ans++;
    }
    for (int i=1;i<=n;++i)
	girl[last[i]] = i;
    for (int i=1;i<=n;++i)
	printf("%d ",girl[i]);
    return 0;
}
