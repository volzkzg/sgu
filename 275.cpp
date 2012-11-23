#include <iostream>
#include <cstring>
#define rep(i,j,k) for (int i=j;i<=k;++i)

using namespace std;

int a[105][205],aa[105][205],n,row,watch,ans[205];
long long x;

void swapa(int u,int v){
    int t;
    rep(i,1,n+1) t=a[u][i],a[u][i]=a[v][i],a[v][i]=t;
}

void swapaa(int u,int v){
    int t;
    rep(i,1,n+1) t=aa[u][i],aa[u][i]=aa[v][i],aa[v][i]=t;
}

void Xor(int i,int j,int k){
    rep(pos,k,n+1) aa[j][pos] ^= aa[i][pos];
}

void init(){
    int pos,re;
    cin >> n;
    rep(i,1,n){
	cin >> x;pos = 0;
	while (x){
	    re = x%2;x/=2;pos++;
	    a[pos][i] = re;
	}if (pos>row) row = pos;
    }
    rep(i,1,row/2) swapa(i,row-i+1);
    /*
    rep(i,1,row){
	rep(j,1,n) cout << a[i][j] << " " ;
	cout << endl;
    }
    */
}

bool check(int r){
    memset(aa,0,sizeof(aa));

    //cout << "chek module" << endl;
    rep(i,1,r){
	rep(j,1,n+1) aa[i][j] = a[i][j];
	//cout << aa[i][j] << " ";
	//cout << endl;
    }//cout << endl;

    int k = 1;
    rep(i,1,n){
	if (k>r) break;
	if (!aa[k][i])
	    rep(j,k+1,r) 
		if (aa[j][i]){
		    /*
		    if (watch == k) watch = j;
		    else if (watch == j) watch = k;
		    */
		    swapaa(k,j);
		    break;
		}
	if (aa[k][i]){
	    rep(j,k+1,r)
		if (aa[j][i])
		    Xor(k,j,i);
	    k++;
	}
    }
    rep(i,k,r) if (aa[i][n+1]) return false;
    return true;
}

void solve(){
    rep(i,1,row){
	a[i][n+1] = 1;
	//watch = i;
	if (!check(i)) a[i][n+1] = 0;
	ans[i] = a[i][n+1];
	/*	
	rep(pos,1,i){
	    rep(j,1,n+1) cout << a[pos][j] << " ";
	    cout << endl;
	}cout << endl;
	*/
    }
}

void print(){
    long long maxi = 0;
    rep(i,1,row) maxi = (maxi<<1)|ans[i];
    cout << maxi << endl;
}

int main(){
    ios::sync_with_stdio(false);
    init();
    solve();
    print();
}
