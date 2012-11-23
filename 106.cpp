/*
 *NAME:The Equation
 *LANG:C++
 *Source:sgu106
 */
#include <iostream>
using namespace std;
typedef long long LL;
LL a,b,c,x1,x2,y1,y2,x,y,tmp,ans=0;
LL mini = -361168601842738790LL;
LL maxi = 322337203685477580LL;
int extendedGcd(int a,int b){
    if (b==0){
	x=1;y=0;
	return a;
    }
    else{
	int tmp = extendedGcd(b,a%b);
	int t = x;
	x=y;
	y=t-a/b*y;
	return tmp;
    }
}
LL extendedGcd(LL a,LL b){
    if (b == 0){
	x=1;y=0;
	return a;
    }
    else{
	LL TEMP = extendedGcd(b,a%b);
	LL tt=x;
	x=y;
	y=tt-a/b*y;
	return TEMP;
    }
}
LL upper(LL a,LL b){
    if (a<=0)
	return a/b;
    return (a-1)/b + 1;
}
LL lower(LL a,LL b){
    if (a>=0) 
	return a/b;
    return (a+1)/b - 1;
}
void update(LL L,LL R,LL wa){
    if (wa<0){
	L=-L;R=-R;wa=-wa;
	swap(L,R);
    }
    mini=max(mini,upper(L,wa));
    maxi=min(maxi,lower(R,wa));
}
int main(){
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;c=-c;
    if (a==0 && b==0){
	if (c==0) ans = (x2-x1+1) * (y2-y1+1);
    }
    else if (a==0 && b!=0){
	if (c % b==0) {
	    tmp = c/b;
	    if (tmp>=y1 && tmp<=y2) ans = 1;
	}
    }
    else if (a!=0 && b==0){
	if (c % a==0){
	    tmp = c/a;
	    if (tmp>=x1 && tmp<=x2) ans = 1;
	}
    }
    else{
	LL d = extendedGcd(a,b);
	if (c%d == 0){
	    LL p = c/d;
	    update(x1-p*x,x2-p*x,b/d);
	    update(y1-p*y,y2-p*y,-a/d);
	    ans = maxi-mini+1;
	    if (ans<0) ans=0;
	}
    }
    cout << ans << endl;
}
