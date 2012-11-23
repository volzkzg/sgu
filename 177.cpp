#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int limx,limy,limc,ans;
int x1[5010],x2[5010],y1[5010],y2[5010],color[5010];
char c;
void cover(int dx,int ux,int dy,int uy,int floor,int c){
    //cout << dx << " " << dy << " " << ux << " " << uy << " " <<floor <<" " << c <<  endl;
    while((floor<=limc) && ((dx>x2[floor]) || (ux<x1[floor]) || (dy>y2[floor]) || (uy<y1[floor])))
        floor ++; 
    if(floor>limc && c==1) {ans+=(ux-dx+1)*(uy-dy+1);return;}
    else if (floor>limc) return;
    if(dx<x1[floor]) {cover(dx,x1[floor]-1,dy,uy,floor+1,c); dx = x1[floor];}
    if(ux>x2[floor]) {cover(x2[floor]+1,ux,dy,uy,floor+1,c); ux = x2[floor];}
    if(dy<y1[floor]) {cover(dx,ux,dy,y1[floor]-1,floor+1,c); dy = y1[floor];}
    if(uy>y2[floor]) {cover(dx,ux,y2[floor]+1,uy,floor+1,c); uy = y2[floor];}
}
int main(void){
    cin >> x2[0] >> limc;
    y2[0]=x2[0];
    x1[0] = y1[0] = 1; color[0] = 0;
    for(int i=1 ; i<=limc ; i++){
	cin >> x1[i] >> y1[i] >> x2[i] >> y2[i] >> c;
	if (x1[i]>x2[i]){
	    swap(x1[i],x2[i]);
	}
	if (y1[i]>y2[i]){
	    swap(y1[i],y2[i]);
	}
	if (c=='w') color[i]=0;else if (c=='b') color[i]=1;
    }
    for(int i=limc ; i>=0 ; i--){
	//cout << 'a' << endl;
        cover(x1[i],x2[i],y1[i],y2[i],i+1,color[i]);
    }
    cout << x2[0]*x2[0]-ans << endl;
    return 0;
}
