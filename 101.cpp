/*
 *Name: Domino
 *LANG: C++
 *Source: sgu101
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

struct node{
    int v,next;
}e[250];
int v[10],t[10],pre[250];
bool visit[250];
int path[250],pathNum;
int n,x,y,edgeNum;

void insert(int a,int b){
    e[++edgeNum].v=b;e[edgeNum].next=v[a];v[a]=edgeNum;t[a]++;t[b]++;
    e[++edgeNum].v=a;e[edgeNum].next=v[b];v[b]=edgeNum;t[a]++;t[b]++;
}
void dfs(int pos){
    if (t[pos]==0) {path[++pathNum]=pos;return;}
    int j=v[pos];
    while (j!=0){
	if (visit[(j+1)/2]){
	    visit[(j+1)/2]=false;
	    t[pos]--;t[e[j].v]--;
	    dfs(e[j].v);
	}
	j=e[j].next;
    }
    path[++pathNum]=pos;
}
int main(){
    //input
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
	scanf("%d %d",&x,&y);
	insert(x,y);
    }
    //solve
    int tmp=0;int pos=-1,pos1=-1;
    for (int i=0;i<=6;++i) t[i]/=2;
    for (int i=6;i>=0;--i)
	if (t[i] % 2==1) {tmp++;if (t[i]!=0) if (pos==-1) pos=i; else pos1=-1;}
    if (pos==-1)
	for (int i=0;i<=6;++i)
	    if (t[i]!=0) {pos=i;break;}
    if (tmp!=2 && tmp!=0){
	printf("%s\n","No solution");
	return 0;
    }
    else{
	memset(visit,true,sizeof(visit));
	dfs(pos);
    }
    //print
    memset(visit,true,sizeof(visit));
    if (pathNum!=(n+1)) {printf("%s\n","No solution");return 0;}
    for (int i=1;i<pathNum;++i){
	int j=v[path[i]];
	while (j!=0 && (e[j].v!=path[i+1] || visit[(j+1)/2]==false))
	    j=e[j].next;
	visit[(j+1)/2]=false;
	if ((j+1) % 2==0)
	    printf("%d %c\n",(j+1)/2,'+');
	else
	    printf("%d %c\n",(j+1)/2,'-');
    }
    return 0;
}
