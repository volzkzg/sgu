#include <cstdio>
#include <cstdlib>
#include <cmath>
#define maxn 1001
#define getI() (sa12[q]<n0 ? sa12[q]*3+1 : (sa12[q]-n0)*3+2)

using namespace std;

int c[maxn],sa[maxn],s[maxn],_s[maxn],_sa[maxn];

inline bool leq(int a1,int a2,int b1,int b2){
    return (a1<b1 || (a1 == b1 && a2<=b2));
}
inline bool leq(int a1,int a2,int a3,int b1,int b2,int b3){
    return (a1<b1 || (a1 == b1 && leq(a2,a3,b2,b3)));
}
inline void radix_pass(int *a,int *b,int *r,int n,int k){
    int sum,t,i;
    for (i=0;i<=k;++i) c[i] = 0;
    for (i=0;i<n;++i) c[r[a[i]]]++;
    for (i=sum=0;i<=k;++i){
	t=  c[i];
	c[i] = sum;
	sum += t;
    }
    for (i=0;i<n;++i) b[c[r[a[i]]]++] = a[i];
}
inline void suffix_array(int *s,int *sa,int n,int k){
    int n0 = (n+2)/3,n1 = (n+1)/3,n2 = n/3,n02 = n0+n2,i,j;
    int *s0 = new int[n0+10],*sa0 = new int[n0+10];
    int *s12 = new int[n02+3],*sa12 = new int[n02+3];
    for (i = n02;i<n02+3;++i) s12[i] = sa12[i] = 0;
    j = 0;
    for (i=0;i<n+(n0-n1);++i) if (i%3!=0) s12[j++] = i;
    radix_pass(s12,sa12,s+2,n02,k);
    radix_pass(sa12,s12,s+1,n02,k);
    radix_pass(s12,sa12,s,n02,k);
    int name = 0,c0,c1,c2;c0 =c1 = c2 = -1;
    for (i=0;i<n02;++i){
	if (s[sa12[i]]!=c0 || s[sa12[i]+1]!=c1 || s[sa12[i]+2]!=c2){
	    name ++;
	    c0 = s[sa12[i]];
	    c1 = s[sa12[i]+1];
	    c2 = s[sa12[i]+2];
	}
	if (sa12[i]%3 == 1)
	    s12[sa12[i]/3] = name;
	else
	    s12[sa12[i]/3+n0] = name;
    }
    if (name<n02){
	suffix_array(s12,sa12,n02,name);
	for (i=0;i<n02;++i) s12[sa12[i]] = i+1;
    }else
	for (i=0;i<n02;++i) sa12[s12[i]-1] = i;
    for (i=j=0;i<n02;++i) if (sa12[i]<n0) s0[j++] = 3*sa12[i];
    radix_pass(s0,sa0,s,n0,k);
    for (int p =0 ,q = n0-n1,k =0 ;k<n;++k){
	i = getI();
	j = sa0[p];
	if (sa12[q]<n0?
	    leq(s[i],s12[sa12[q]+n0],s[j],s12[j/3]):
	    leq(s[i],s[i+1],s12[sa12[q]-n0+1],s[j],s[j+1],s12[j/3+n0])){
	    sa[k] = i;q++;
	    if (q == n02) for (k++;p<n0;k++,p++) sa[k] = sa0[p];
	}else{
	    sa[k] = j;p++;
	    if (p == n0) for (k++;q<n02;k++,q++) sa[k] = getI();
	}
    }
}
int rank[maxn],height[maxn];
inline void calc_height(int n,int *r,int *sa){
    int i,j,k = 0;
    for (i=0;i<n;++i) rank[sa[i]] = i;
    for (i=0;i<n;height[rank[i++]] = k){
	if (rank[i] == 0) continue;
	for (k?k--:0,j = sa[rank[i]-1];r[i+k] == r[j+k];k++);
    }height[0] = 0;
}
int in,times = 0,maxLen;
inline void dfs(int pos){
    int i,tmp = pos+1;
    if (pos>maxLen) return;

    for (i=0;i<pos;++i) _s[i] = s[i];
    for (i=pos;i<maxLen;++i) _s[i] = tmp++;
    for (i=maxLen;i<maxLen+3;++i) _s[i] = 0;
    suffix_array(_s,_sa,maxLen,100);
    calc_height(maxLen,_s,_sa);
    int p = 0;
    for (i=0;i<maxLen;++i)
	p+=maxLen-_sa[i]-height[i];
    if (p<in) return;

    if (pos == maxLen){
	for (i=0;i<pos;++i) _s[i] = s[i];
	for (i=pos;i<pos+3;++i) _s[i] = 0;
	suffix_array(_s,_sa,pos,100);
	calc_height(pos,_s,_sa);
	int p = 0;
	for (i=0;i<pos;++i)
	    p+=pos-_sa[i]-height[i];
	if (p>in) return;
	if (p==in){
	    for (i=0;i<pos;++i)
		printf("%c",(char)(_s[i]+'a'-1));
	    printf("\n");
	    exit(0);
	}
    }
    for (i=1;i<=pos+1;++i){
	s[pos] = i;
	dfs(pos+1);
    }
}
int main(){
    int i,j;
    scanf("%d\n",&in);
    if (in == 1){printf("%c\n",'a');return 0;}
    for (maxLen=1;maxLen<=sqrt(in*2*2)+1;++maxLen)
	dfs(0);
}
