#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

const int MAX=1000+10;

struct bign
{
    int a[200],num;
    const static int base=10000;
    bign(){}
    friend bign operator + (const bign &a,const bign& b)
    {
        bign c;
        c.num=max(a.num,b.num);
        int i;
        for(i=1;i<=c.num;++i)
        {
            c.a[i]=0;
            if(i<=a.num)c.a[i]+=a.a[i];
            if(i<=b.num)c.a[i]+=b.a[i];
        }
        c.a[c.num+1]=0;
        for(i=1;i<=c.num;++i)
        {
            c.a[i+1]+=c.a[i]/base;
            c.a[i]%=base;
        }
        if(c.a[c.num+1])++c.num;
        return c;
    }
    bign(int t)
    {
        if(!t)
        {
            num=1,a[1]=0;
            return;
        }
        num=0;
        while(t)
        {
            a[++num]=t%base;
            t/=base;
        }
    }
    void print()const
    {
        int i;
        printf("%d",a[num]);
        for(i=num-1;i>=1;--i)printf("%04d",a[i]);
        printf(" ");
    }
    void init()
    {
        char c[501];
        scanf("%s",c);
        int k=strlen(c),i,j,now;
        num=0;
        for(i=k-1;i>=0;i-=4)
        {
            ++num;
            now=0;
            j=3;
            while(i-j<0)--j;
            for(;j>=0;--j)now=now*10+c[i-j]-'0';
            a[num]=now;
        }
    }
    friend bool operator < (const bign& a,const bign& b)
    {
        int i;
        if(a.num!=b.num)return a.num<b.num;
        for(i=a.num;i>=1;--i)
            if(a.a[i]!=b.a[i])return a.a[i]<b.a[i];
        return 0;
    }
}seg[MAX];

int n;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        seg[i].init();
    sort(seg+1,seg+n+1);
    for(i=1;i<=n-2;++i)
        if(seg[i+2]<seg[i]+seg[i+1])
        {
            seg[i].print();
            seg[i+1].print();
            seg[i+2].print();
            printf("\n");
            return 0;
        }
    printf("0 0 0\n");
}
