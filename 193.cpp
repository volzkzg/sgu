#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

typedef int digit;
class bigNum{
public:
    vector <digit> a;
    int n;
public:
    bigNum(){//构造函数 
	n=0;
    }
    int make (int c){//将数字转化为向量 
	int l=0;
	a.resize(30);
	while (c>0){
	    a[l++]=c%10;
	    c/=10;
	}
	--l;
	while (l>0 && a[l]==0) --l;
	n=l+1;
	return l+1;
    }
    int make (string c){//将字符数组转化为向量 
	int l=c.size();
	a.resize(l);
	n=l;
	for (int i=0;i<l;++i){
	    a[i]=c[l-i-1]-'0';
	}
	--l;
	while (l>0 && a[l]==0) --l;
	n=l+1;
	return l+1;
    }
    void pout(){//输出 
	for (int i=n-1;i>-1;--i)
	    printf("%d",a[i]);
	printf("\n");
    }
    friend bigNum operator+(bigNum &a,bigNum &b){//重载+ 
	bigNum r;
	int m=a.n>b.n?a.n:b.n;
	r.n=m;
	r.a.resize(m+10);
	for (int i=0;i<m;++i){
	    if (a.n>i) r.a[i]+=a.a[i];
	    if (b.n>i) r.a[i]+=b.a[i];
	    r.a[i+1]+=r.a[i]/10;
	    r.a[i]%=10;
	}
	++r.n;
	while (r.n>0 && r.a[r.n]==0) --r.n;
	++r.n;
	return r;
    }
    friend bigNum operator -(bigNum &a,bigNum &b){//默认传入a>b 重载- 	
	bigNum r=a;
	int m=r.n;
	for (int i=0;i<m;++i){
	    if (b.n>i) r.a[i]-=b.a[i];int j=i;
	    while (r.a[j]<0){
		r.a[j]+=10;
		--r.a[j+1];
	    }
	}
	--m;
	while (m>0 && r.a[m]==0) --m;
	r.n=m+1;
	return r;
    }
    friend bool operator >(bigNum &a,bigNum &b){//重载> 比较大小 
	if (a.n>b.n) return 1;
	if (a.n<b.n) return 0;
	for (int i=a.n-1;i>=0;--i){
	    if (a.a[i]>b.a[i]) return 1;
	    if (a.a[i]<b.a[i]) return 0;
	}
	return 0;
    }
    friend bool operator >=(bigNum &a,bigNum &b){//重载>= 比较大小 
	if (a.n>b.n) return 1;
	if (a.n<b.n) return 0;
	for (int i=a.n-1;i>=0;--i){
	    if (a.a[i]>b.a[i]) return 1;
	    if (a.a[i]<b.a[i]) return 0;
	}
	return 1;
    }
    friend bool operator <(bigNum &a,bigNum &b){//重载< 比较大小
	if (a.n<b.n) return 1;
	if (a.n>b.n) return 0;
	for (int i=a.n-1;i>=0;--i){
	    if (a.a[i]>b.a[i]) return 0;
	    if (a.a[i]<b.a[i]) return 1;
	}
	return 0;
    }
    friend bool operator <=(bigNum &a,bigNum &b){//重载< 比较大小
	if (a.n<b.n) return 1;
	if (a.n>b.n) return 0;
	for (int i=a.n-1;i>=0;--i){
	    if (a.a[i]>b.a[i]) return 0;
	    if (a.a[i]<b.a[i]) return 1;
	}
	return 1;
    }
    friend bool operator ==(bigNum &a,bigNum &b){//重载== 
	if (a.n!=b.n) return 0;
	for (int i=0;i<a.n;++i)
	    if (a.a[i]!=b.a[i]) return 0;
	return 1;
    }
    friend bigNum operator * (bigNum &a,int b){//重载* 高精度*低精度 
	bigNum r=a;
	r.a.resize(r.n+100);
	int m=r.n;
	for (int i=0;i<m;++i)
	    r.a[i]*=b;
	for (int i=0;i<m;++i){
	    r.a[i+1]+=r.a[i]/10;
	    r.a[i]%=10;
	}
	while (r.a[m]>=10) {r.a[m+1]+=r.a[m]/10;r.a[m++]%=10;}
	r.n=m+1;while (r.a[r.n-1]==0) --r.n;
	return r;
    }
    friend bigNum operator * (bigNum &a,bigNum &b){//重载* 高精度*高精度 
	bigNum r,temp;
	if (a.n<b.n) {temp = a;a = b;b = temp;}
	r.a.resize(a.n+b.n);
	int k;
	for (int i=0;i<a.n;++i){
	    if (b.n<=i) continue;
	    temp=a*b.a[i];
	    temp=temp<<i;
	    r=r+temp;
	}
	r.n=a.n+b.n-1;
	for (int i=0;i<r.n;++i){
	    r.a[i+1]+=r.a[i]/10;
	    r.a[i]%=10;
	}
	while (r.n>0 && r.a[r.n]==0) --r.n;
	++r.n;
	return r;
    }
    friend bigNum operator / (bigNum &a,int b){
	bigNum r,rr;
	r.a.resize(a.n);r.n = 0;
	rr.a.resize(a.n);rr.n = 0;
	int p = 0,pos= a.n-1;
	while (p<b)
	    p = p*10+a.a[pos--];
	for (int i = pos+1;i>=0;--i){
	    r.a[r.n++] = p/b;
	    p = p % b;
	    p = p*10+a.a[i-1];
	}
	for (int i=0;i<r.n;++i)
	    rr.a[i] = r.a[r.n-i-1];
	rr.n = r.n;
	return rr;
    }
    friend bigNum operator % (bigNum &a,int b){
	bigNum r;
	r.a.resize(a.n);r.n = 0;
	int p = 0,pos= a.n-1;
	while (p<b)
	    p = p*10+a.a[pos--];
	for (int i = pos;i>=0;--i){
	    p = p % b;
	    p = p*10+a.a[i];
	}
	r.n = 1;
	r.a[0] = p%b;
	return r;
    }
    friend bigNum operator << (bigNum &a,int b){//重载左移运算符，扩大10倍 
	bigNum r;
	r.a.resize(a.n+b);
	for (int i=0;i<a.n;++i)
	    r.a[i+b]=a.a[i];
	r.n=a.n+b;
	return r;
    }
};
string s;
bigNum MOD,DIV,one;
int a[11] = {0,0,0,1,1,2,1,3,3,4,3};
int main(){
#ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif
    cin >> s;
    if (s.size() == 1){
	cout << a[s[0]-'0'] << endl ;
	return 0;
    }
    MOD.make(s);DIV.make(s);one.make(1);
    MOD = MOD % 4;
    DIV = DIV / 4;
    switch(MOD.a[0]){
    case 0:DIV = DIV*2;DIV = DIV-one;break;
    case 1:DIV = DIV*2;break;
    case 2:DIV = DIV*2;DIV = DIV-one;break;
    case 3:DIV = DIV*2;DIV = DIV+one;break;
    }
    DIV.pout();
    return 0;
}
