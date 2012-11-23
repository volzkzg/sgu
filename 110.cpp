/*
 *NAME:Dungeon
 *LANG:C++
 *Source:sgu110
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#define INF 0x7FFFFFFF

using namespace std;

struct node{
    double x,y,z,r;
}g[60];
int hash[100],posTmp;
double times[100];
double xx,zz,xxx,zzz;
double yy,yyy,eps=1e-12;
int n;

void init(){
    cin >> n;
    for (int i=1;i<=n;++i) 
	cin >> g[i].x >> g[i].y >> g[i].z >> g[i].r;
    cin >> xx >> yy >> zz 
	>> xxx >> yyy >> zzz;
    xxx-=xx,yyy-=yy,zzz-=zz;
}
int dblcmp(double x){
    if (x>-eps && x<eps) return 0;
    if (x>0) return 1;
    return -1;
}
void getIt(int x){
    if (x==posTmp) {hash[x]=0;return;}
    double a,b,c,xc=g[x].x,yc=g[x].y,zc=g[x].z;
    a=(xxx*xxx+yyy*yyy+zzz*zzz);
    b=2*(xx*xxx+yy*yyy+zz*zzz-xxx*xc-yyy*yc-zzz*zc);
    c=pow(xx-xc,2)+pow(yy-yc,2)+pow(zz-zc,2)-pow(g[x].r,2);
    int dbl=dblcmp(pow(b,2)-4*a*c);
    if (dbl==-1) {hash[x]=0;return;}
    if (dbl==0){
	hash[x]=1;
	times[x] = 0-(b/(2*a));
	if (times[x]<0) hash[x]=0;
	return ;
    }
    hash[x]=1;
    times[x] =(-b-sqrt(pow(b,2)-4*a*c))/2/a;
    if (times[x]<0) hash[x]=0;
    return ;
    
}
int main(){
    init();
    int t;
    for (t=1;t<=11;++t){
	int pos=0;double tmp=-1,minDist = INF;double x2,y2,z2;
	for (int i=1;i<=n;++i) getIt(i);
	for (int i=1;i<=n;++i)
	    if (hash[i]){//判断该点到编号为i的圆的距离
		if (times[i]<minDist || pos==0){
		    minDist=times[i];
		    pos=i;
		}
	    }
	if (pos==0) break;//如果没能找到一个圆，那么退出
	posTmp=pos;
	if (t==1) cout << pos;
	else if (t==11) cout << " etc." ;
	else cout << " " << pos;
	//更新当前点坐标，以及方向
	xx+=minDist*xxx;yy+=minDist*yyy;zz+=minDist*zzz;//更新坐标
	double vx,vy,vz,alpha,beta,tt;
	vx=xx-g[pos].x;vy=yy-g[pos].y;vz=zz-g[pos].z;
	xxx=0-xxx;yyy=0-yyy;zzz=0-zzz;
	alpha=vx*vx+vy*vy+vz*vz;
	beta=0-2*(xxx*vx+yyy*vy+zzz*vz);
	if (alpha==0) tt=0;else tt=0-beta/alpha;
	xxx=vx*tt-xxx;yyy=vy*tt-yyy;zzz=vz*tt-zzz;
    }
    cout << endl;
    return 0;
}
