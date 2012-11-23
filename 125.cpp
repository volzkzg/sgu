#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int b[5][5];
int a[5][5];
int c[5][5];
int t[5];
int n;
void get(int k,int k1,int k2,int &l,int &r){
    if (k==0) {l=max(k1,k2),r=9;}
    else if (k==1) {l=min(k1,k2),r=max(k1,k2)-1;}
    else if (k==2) {l=1,r=min(k1,k2)-1;}
}
bool check(){
    for (int i=1;i<=3;++i)
	for (int j=1;j<=3;++j){
	    int w=0;
	    if (a[i-1][j]>a[i][j]) w++;
	    if (a[i+1][j]>a[i][j]) w++;
	    if (a[i][j-1]>a[i][j]) w++;
	    if (a[i][j+1]>a[i][j]) w++;
	    if (w!=b[i][j]) return false;
	}
    return true;
}
int main(){
    cin >> n;int i,j;
    for (i=1;i<=n;++i)
	for (j=1;j<=n;++j)
	    cin >> b[i][j];
    if (n==1){
	if (b[1][1]==0)
	    cout << 1 << endl;
	else
	    cout << "NO SOLUTION" << endl;
	return 0;
    }
    else if (n==2){
	for (int i1=1;i1<=9;++i1)
	    for (int i2=1;i2<=9;++i2)
		for (int i3=1;i3<=9;++i3)
		    for (int i4=1;i4<=9;++i4){
			int j1,j2,j3,j4;
			j1=j2=j3=j4=0;
			if (i2>i1) ++j1;if (i1>i2) ++j2;
			if (i3>i1) ++j1;if (i1>i3) ++j3;
			if (i2>i4) ++j4;if (i4>i2) ++j2;
			if (i3>i4) ++j4;if (i4>i3) ++j3;
			if (j1==b[1][1] && j2==b[1][2] && 
			    j3==b[2][1] && j4==b[2][2]){
			    cout << i1 << " " << i2 << endl;
			    cout << i3 << " " << i4 << endl;
			    return 0;
			}
		    }
    }
    else if (n==3){
	for (int i2=1;i2<=9;++i2)
	    for (int i4=1;i4<=9;++i4)
		for (int i6=1;i6<=9;++i6)
		    for (int i8=1;i8<=9;++i8){
			t[0]=1;t[1]=i2;t[2]=i4;t[3]=i6;t[4]=i8;t[5]=9;
			sort(t,t+6);
			for (int i5=t[4-b[2][2]];i5<t[4-b[2][2]+1];++i5){
			    int l1,r1;
			    get(b[1][1],i2,i4,l1,r1);
			    for (int i1=l1;i1<=r1;++i1){
				int l3,r3;
				get(b[1][3],i2,i6,l3,r3);
				for (int i3=l3;i3<=r3;++i3){
				    int l7,r7;
				    get(b[3][1],i4,i8,l7,r7);
				    for (int i7=l7;i7<=r7;++i7){
					int l9,r9;
					get(b[3][3],i6,i8,l9,r9);
					for (int i9=l9;i9<=r9;++i9){
					    a[1][1]=i1;a[1][2]=i2;a[1][3]=i3;
					    a[2][1]=i4;a[2][2]=i5;a[2][3]=i6;
					    a[3][1]=i7;a[3][2]=i8;a[3][3]=i9;
					    if (check()){
						for (int i=1;i<=3;++i){
						    for (int j=1;j<=3;++j){
							cout << a[i][j];
							if (j!=3) cout << " ";
							else cout << endl;
						    }
						}
						return 0;
					    }
					}
				    }
				}
			    }
			}
		    }
    }
    cout << "NO SOLUTION" << endl;
    return 0;
}
