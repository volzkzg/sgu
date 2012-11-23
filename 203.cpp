#include <cstdio>
#include <iostream>
#include <queue>
#define rep(i,j,k) for (int i=j;i<=k;++i)

using namespace std;

priority_queue<long long> huffman;
long long x,ans;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i,1,n){
	cin >> x;
	huffman.push(-x);
    }rep(i,1,n-1){
	x = huffman.top();huffman.pop();
	x+= huffman.top();huffman.pop();
	huffman.push(x);
	ans+=x;
    }cout << -ans << endl;
    return 0;
}
