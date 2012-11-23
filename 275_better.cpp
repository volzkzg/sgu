#include<stdio.h>  
#include<string.h>  
#include<iostream>  
using namespace std ;  
typedef long long LL ;  
int N ;  
const int MAXN = 110 ;  
LL a[MAXN] ;  
int g[70][MAXN] ;  
int NN ;  
      
void gauss(){  
    int row , col ;  
    row = NN - 1 ;  
    LL ans = 0 ;  
    for( ;row>=0 ;row-- ){  
	col = 0 ;  
	ans <<= 1 ;  
	for( ; col<N ;col++){  
	    if( g[row][col] )   break ;  
	}  
	if( col == N ){  
	    if( g[row][N] == 0 ) ans |= 1 ;
	    continue ;  
	}  
	ans |= 1 ;  
	for(int r=row-1;r>=0;r--){  
	    if( g[r][col] == 0 ) continue ;  
	    for(int j=col ; j<=N ; j++){  
		g[r][j] = g[r][j] ^ g[row][j] ;  
	    }  
	}  
    }  
    cout << ans << endl ;  
    //printf("%lld\n",ans) ;  
}  
      
int main(){  
    while(cin >> N){  
	for(int i=0;i<N;i++)   cin >> a[i] ;  
	NN = -1 ;  
	memset(g, 0 , sizeof(g));  
      
	for(int i=0;i<N;i++){  
	    LL nn = a[i] ;  
	    int c = 0 ;  
	    while( nn ){  
		g[c++][i] = (nn&1) ;  
		nn >>= 1 ;  
	    }  
	    if( NN < c )    NN = c ;  
	}  
	for(int i=0;i<NN;i++)   g[i][N] = 1 ;  
	gauss() ;  
    }  
    return 0 ;  
}  
