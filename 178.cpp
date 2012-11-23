#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long n;
int ans;

int main(){
    freopen("test.in","r",stdin);
    freopen("test1.out","w",stdout);
    scanf("%I64d\n",&n);
    if (n==1) {printf("0\n");return 0;}
    int l = 0,r = 60;
    while (l<=r){
	int mid = (l+r) >> 1;
	long long pitch = 1;
	long long sum = mid;
	for (int i=0;i<=mid;++i){
	    sum += (mid+1)*pitch;
	    pitch*=2;
	}
	if (sum>=n){
	    r = mid-1;
	    ans = mid;
	}else{
	    l = mid+1;
	}
    }
    printf("%d\n",ans);
    return 0;

}
