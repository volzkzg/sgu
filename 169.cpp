/*
 *NAME:Numbers
 *LANG:C++
 *SOURCE:sgu169
 *TIMES:1
 *METHOD:Math Mathod.See My Proof
 *Proof:
 *假设存在一个数N，并且它有d位，且P（N）能够整除N，
 *那么显而易见，这个数的前d-1位的乘积也能够整除N，
 *再假设存在数N+1，它有d位，且P（N+1)能够整除N+1
 *那么N+1的前d-1位数字的乘积也能够整除N,
 *又因为P（N)!=0,所以数N的最后一位不为0，
 *并存在一个不为0的数M（就是它们前N-1位的乘积）能够整除N和N+1
 *所以这个M就只能为1
 */
#include <iostream>
using namespace std;
int k;
int main(){
    cin >> k;
    if (k==1)
	cout << 8 << endl;
    else{
	if ((k-1)%6==0) cout << 4 << endl;
	else if ((k-1) % 3==0) cout << 3 << endl;
	else cout << 1 << endl;
    }
    return 0;
}
