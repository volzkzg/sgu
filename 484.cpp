#include<iostream>
#define REP(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=102;
char map[maxn][maxn]={0};
int main()
{
    int n,m,nowx,nowy;
    cin>>n>>m;
    REP(i,1,n) REP(j,1,m)
	{
	    cin>>map[i][j];   
	    if(map[i][j]=='P')
		nowx=i,nowy=j;
	}
    char old='P';   
    bool fall=false;
    while(true)
	{               
	    if(nowx==n+1)
		{
		    cout<<nowy;
		    break;
		}
	    char t=map[nowx][nowy];
	    map[nowx][nowy]=0;
	    if(!t)
		{
		    cout<<-1;
		    break;
		}           
	    if(t==old&&!fall)
		nowx++,fall=true;
	    else if(t=='/')
		nowy--,fall=false;
	    else if(t=='\\')
		nowy++,fall=false;
	    else nowx++,fall=true;
	    old=t;
	}   
}
