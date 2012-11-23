#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int STL[20][20];
int test[20];
int ans[20];
int n,m;
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for (int i=1;i<=n;++i){
	scanf("%d",&STL[i][0]);
	for (int j=1;j<=STL[i][0];++j)
	    scanf("%d",&STL[i][j]);
    }
    for (int i=1;i<=m;++i){
	memset(ans,0,sizeof(ans));
	scanf("%d",&test[0]);
	for (int j=1;j<=test[0];++j)
	    scanf("%d",&test[j]);
	for (int j=1;j<=n;++j){
	    bool ff = true;
	    for (int k=1;k<=test[0];++k){
		if (test[k]>0){
		    bool f = false;
		    for (int kk=1;kk<=STL[j][0];++kk)
			if (test[k] == STL[j][kk]){
			    f = true;
			    break;
			}
		    if (!f) {ff = false;break;}
		}
		if (test[k]<0){
		    bool f = true;
		    for (int kk=1;kk<=STL[j][0];++kk)
			if (-test[k] == STL[j][kk]){
			    f = false;
			    break;
			}
		    if (!f) {ff = false;break;}
		}
	    }
	    if (ff) {ans[++ans[0]] = j;}
	}
	printf("%d\n",ans[0]);
	for (int j=1;j<=ans[0];++j){
	    printf("%d ",STL[ans[j]][0]);
	    for (int k=1;k<STL[ans[j]][0];++k)
		printf("%d ",STL[ans[j]][k]);
	    printf("%d\n",STL[ans[j]][STL[ans[j]][0]]);
	}
    }
    return 0;
}
