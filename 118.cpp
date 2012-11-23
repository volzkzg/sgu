#include <iostream>
#include<cstdio>
#define N 1005
using namespace std;
int n_case;
int fig[N];
int main()
{
    //freopen("in.txt","r",stdin);
    int t1,t2;   int n_fig;
    scanf("%d",&n_case);
    for(int i=0;i<n_case;i++){
        t1=1; t2=0;
        scanf("%d",&n_fig);
        for(int j=0;j<n_fig;j++){
            scanf("%d",&fig[j]);
            fig[j]%=9;
        }
        for(int j=0;j<n_fig;j++){
            t1*=fig[j];
            t2+=t1;
        }
        t2%=9;
        if(t2==0)
        t2=9;
        cout<<t2<<endl;
    }
}
