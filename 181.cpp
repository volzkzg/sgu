#include <iostream>
using namespace std;
 
int main()
{
    long x[1001];
    long A,alpha,beta,gamma,m,k;
    cin>>A>>alpha>>beta>>gamma>>m>>k;
    x[0]=A;
    if (k==0) cout<<x[0];
    else
    {
        long app[1000],i(1);
        fill(app,app+1000,-1);
        app[x[0]%=m]=0;
        for (;app[x[i]=(alpha*x[i-1]*x[i-1]+beta*x[i-1]+gamma)%m]<0;++i) app[x[i]]=i;
        if (k>=app[x[i]]) cout<<x[app[x[i]]+(k-app[x[i]])%(i-app[x[i]])];
        else cout<<x[k];
    }
    cout<<endl;
    return 0;
}
