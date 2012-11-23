    //Lib  
    #include<cstdio>  
    #include<cstring>  
    //#include<cstdlib>  
    //#include<cmath>  
    //#include<ctime>  
      
    #include<iostream>  
    #include<algorithm>  
    //#include<vector>  
    //#include<string>  
    //#include<queue>  
    using namespace std;  
    //Macro  
    #define rep(i,a,b) for(int i=a,tt=b;i<=tt;++i)  
    #define rrep(i,a,b) for(int i=a,tt=b;i>=tt;--i)  
    #define erep(i,e,x) for(int i=x;i;i=e[i].next)  
    #define irep(i,x) for(__typedef(x.begin()) i=x.begin();i!=x.end();i++)  
    #define read() (strtol(ipos,&ipos,10))  
    #define sqr(x) ((x)*(x))  
    #define pb push_back  
    #define PS system("pause");  
    typedef long long ll;  
    typedef pair<int,int> pii;  
    //const int oo=~0U>>1;  
    //const double inf=1e20;  
    //const double eps=1e-6;  
    string name="",in=".in",out=".out";  
    //Var  
    pii q[5008];  
    int ans[5008],cnt,pos,n,k;  
    char vis[2000000];  
    bool Query(int x)  
    {  
        return (vis[x/8]>>((x-1)%8))&1;  
    }  
    void Modify(int x)  
    {  
        vis[x/8]=vis[x/8]|(1<<((x-1)%8));  
    }  
    int d(int x)  
    {  
        int ret=x;  
        while(x){ret+=x%10;x/=10;}  
        return ret;  
    }  
    void Work()  
    {  
        scanf("%d%d",&n,&k);  
        rep(i,1,k)scanf("%d",&q[i].first),q[i].second=i;  
        sort(q+1,q+1+k); 
	for (int i=1;i<=k;++i) printf("%d %d\n",q[i].first,q[i].second); 
        pos=1;  
        rep(i,1,n)  
        {  
            if(!(Query(i)&1))  
            {  
                for(int j=d(i);j<=n&&!Query(j);j=d(j))  
                    Modify(j);  
                ++cnt;  
                while(q[pos].first==cnt)ans[q[pos++].second]=i;  
            }  
        }  
        cout<<cnt<<endl;  
        rep(i,1,k-1)printf("%d ",ans[i]);  
        cout<<ans[k]<<endl;  
    }  
    int main()  
    {  
    //  freopen((name+in).c_str(),"r",stdin);  
    //  freopen((name+out).c_str(),"w",stdout);  
    //  Init();  
        Work();  
        return 0;  
    }  
