#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool f[10011][1011];
int pre[10011][1011];
int ans[10011],ans_num;
int n,m,tmp,i,j,k;
int a[10011],max_num=1,max_pos;

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d%d\n",&n,&m);
    memset(f,false,sizeof(f));
    f[0][1] = true;
    for (i=1;i<=n;++i)
	{
	    scanf("%d",&tmp);
	    a[i] = tmp;
	    f[i][1] = true;
	    for (j=1;j<m;++j)
		pre[i][j] = 1;
	    for (j=1;j<m;++j){
		if (f[i-1][j]){
		    k = (j*tmp)%m;
		    if (k>max_num){
			max_num = k;
			max_pos = i;
		    }
		    f[i][k] = true;
		    pre[i][k] = j;
		    //cout << i << " " << k << " " << tmp << " " << j << endl;
		    f[i][j] = true;
		    pre[i][j] = j;
		    //cout << i << " " << j << " " << tmp << " " << j << endl;
		}
	    }
	    f[i][tmp%m] = true;
	    pre[i][tmp%m] = 1;
	}
    if (max_num==1){
	printf("1\n");
	return 0;
    }else{
	tmp = max_num;
	k = max_pos;
	printf("%d\n",tmp);
	while ((tmp != 1 || k==n) && k>=1 ){
	    //cout << pre[k][tmp] << " " << tmp << " " << k <<  endl;
	    if (pre[k][tmp] != tmp){
		ans[ans_num++] = k;
		tmp = pre[k][tmp];
	    }
	    k--;
	}sort(ans,ans+ans_num);
	for (i=0;i<ans_num-1;++i) printf("%d ",ans[i]);
	printf("%d\n",ans[ans_num-1]);
    }return 0;

}
