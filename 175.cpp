/*
 *NAME:Encoding
 *LANG:C++
 *SOURCE:sgu175
 *TIMES:1
 *METHOD:µÝ¹éÄ£Äâ
 */
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,q;
int find(int n,int q){
    if (n==1) return 1;
    int k = n/2;
    if (q>k) return find(n-k,n+1-q);
    else return n-k+find(k,k+1-q);
}
int main(){
    scanf("%d %d\n",&n,&q);
    printf("%d\n",find(n,q));
    return 0;
}
