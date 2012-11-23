/*
 *NAME:The Book
 *LANG:C++
 *SOURCE:sgu122
 *METHOD:满足ORE条件的哈密顿回路构造.
 *1、任意选取一个点,从这个点向左或者向右一直扩展,直到无法继续扩展,形成了一条链
 *2、可以选取这条链中的某一个点，把从这个点开始到尾部的一泡点全部置换一下，就可以形成一个环
 *3、如果该环中点数满足N个，那么输出，否则从未标记的点里面找一个能接在环中点上的，拉出来，破环成链，返回第二步
 *TIMES:8
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int mn =1100;
int n,k,i,j,listNum;
int L[mn],R[mn],head,tail;
bool adj[mn][mn] ={0};
bool visit[mn];
string s;
void reverse(){//checked
    int tmp[mn],t = head,num=1;
    tmp[num]=head;
    while (t!=tail){
	t=R[t];tmp[++num]=t;
    }tmp[++num]=tail;
    if (adj[head][tail]){
	R[tail] = head;L[head] = tail;
	return ;
    }
    else for (int i=2;i<num-1;++i)
	     if (adj[head][tmp[i+1]] && adj[tail][tmp[i]]){
		 L[head] = R[head];R[head] = tmp[i+1];
		 L[tmp[i+1]] = head;R[tail] = tmp[i];
		 R[tmp[i]]=L[tmp[i]];L[tmp[i]] = tail;
		 for (int j = i-1;j>=2;--j){
		     int p = L[tmp[ j ]];
		     L[tmp[ j ]] = R[tmp[ j ]];R[tmp[ j ]]=p;
		 }
		 return;
	     }
}
void add(){
    int tmp[mn],t = head,num=1;
    tmp[num]=head;
    while (t!=tail){
	t=R[t];tmp[++num]=t;
    }tmp[++num]=tail;int pos;
    for (int i=1;i<=n;++i)
	if (visit[i]){pos = i;visit[i]=false;break;}
    for (int i =1;i<=num;++i)
	if (adj[tmp[i]][pos]){
	    head = R[tmp[i]];tail = pos;
	    R[tmp[i]] = pos;
	    L[pos] = tmp[i];
	    R[pos] = 0;
	    listNum++;
	    return;
	}
}
int findHead(){//checked
    for (int i=1;i<=n;++i)
	if (visit[i] && adj[head][i]){
	    L[head] = i;R[i]=head;L[i]=0;visit[i]=false;
	    return i;
	}
    return 0;
}
int findTail(){//checked
    for (int i=1;i<=n;++i)
	if (visit[i] && adj[tail][i]){
	    R[tail] = i;L[i]=tail;R[i]=0;visit[i]=false;
	    return i;
	}
    return 0;
}
void print(){
    int tmp[mn],t = 1,num=1;
    tmp[num]=1;
    while (R[t]!=1){
	t=R[t];tmp[++num]=t;
    }
    for (int i=1;i<=num;++i) cout << tmp[i] << " " ;
    cout << 1 << " " << endl;
}
void insert(){int v;//checked
    //左右两端进行不断的扩展
    while (v=findHead()) {head = v;listNum ++;}
    while (v=findTail()) {tail = v;listNum ++;}
    reverse();//Let哈密顿路成为哈密顿回路
    if (listNum == n) print();//如果回路中元素满足N个,那么输出
    else{
	int tmp = listNum;
	add();
	insert();
    }
}
void init(){//checked
    cin >> n;getchar();
    for (i = 1;i <= n;++i){
	getline(cin,s);k=0;
	for (int j=0;j<s.size();++j)
	    if (s[j]!=' ') k=k*10+s[j]-'0';
	    else {adj[i][k]=true;k=0;}
	if (k!=0){
	    adj[i][k]=true;k=0;
	}
    }memset(visit,true,sizeof(visit));
    tail = head = listNum = 1;visit[1]=false;
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    init();
    insert();
    return 0;
}
