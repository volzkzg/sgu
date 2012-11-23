#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 4000010;
typedef pair<int,int> point;
typedef map<point,int>::value_type insert_val;
map<point,int> point_map;
int father[maxn];
int point_num,check_p1,check_p2;

int getfather(int p){
    if (father[p] == p)
	return p;
    return (father[p]=getfather(father[p]));
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int i,j,k,n;
    scanf("%d\n",&n);
    for (i=1;i<=n;++i){
	point p1,p2;
	scanf("%d%d%d%d\n",&p1.first,&p1.second,&p2.first,&p2.second);

	check_p1 = point_map.count(p1);
	check_p2 = point_map.count(p2);
	if (!check_p1){
	    point_map.insert(insert_val(p1,++point_num));
	    father[point_num] = point_num;
	}
	if (!check_p2){
	    point_map.insert(insert_val(p2,++point_num));
	    father[point_num] = point_num;
	}
	
	
	int p1_num = point_map[p1];
	int p2_num = point_map[p2];
	
	int p1_father = getfather(p1_num);
	int p2_father = getfather(p2_num);
	
	if (p1_father == p2_father){
	    printf("%d\n",i);
	    return 0;
	}else
	    father[p1_father] = p2_father;
    }
    printf("0\n");
    return 0;
}
