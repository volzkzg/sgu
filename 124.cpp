#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

struct point{
    double x,y;
};
struct edge{
    point a,b;
}e[10101];
int n;
point p1;
int main(){
    //init
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i=1;i<=n;++i){
	cin >> e[i].a.x >> e[i].a.y
	    >> e[i].b.x >> e[i].b.y;
	if (e[i].a.x==e[i].b.x && 
	    e[i].a.y>e[i].b.y) swap(e[i].a.y,e[i].b.y);
	if (e[i].a.y==e[i].b.y &&
	    e[i].a.x>e[i].b.x) swap(e[i].a.x,e[i].b.x);
    }
    cin >> p1.x >> p1.y;
    //solve
    for (int i=1;i<=n;++i){
	if (e[i].a.x==e[i].b.x && e[i].a.x==p1.x &&
	    e[i].a.y<=p1.y && e[i].b.y>=p1.y){
	    cout << "BORDER" << endl;
	    return 0;
	}
	else if (e[i].a.y==e[i].b.y && e[i].a.y==p1.y &&
		 e[i].a.x<=p1.x && e[i].b.x >=p1.x){
	    cout << "BORDER" << endl;
	    return 0;
	}
    }

    int k=0;
    for (int i=1;i<=n;++i){
	if ((e[i].a.y == e[i].b.y) && (e[i].a.y>p1.y) &&
	    (e[i].a.x<p1.x) && (e[i].b.x>=p1.x))
	    k++;
    }
    //print
    if (k & 1==1) cout << "INSIDE" << endl;
    else cout << "OUTSIDE" << endl;
    return 0;
}
