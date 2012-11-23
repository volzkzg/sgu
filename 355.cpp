#include <iostream>
#define rep(i,j,k) for (int i=j;i<=k;++i)
using namespace std;
int main()
{
    int N,M=1;cin >> N;
    int color[10001];color[1]=1;
    rep(i,2,N){int tmp=0;rep(j,1,i/2) if (i%j==0)tmp = max(tmp,color[j]+1);color[i]=tmp;M = max(color[i],M);}
    cout << M << endl;
    rep(i,1,N-1) cout << color[i] << " " ;cout << color[N] << endl;
    return 0;
}
