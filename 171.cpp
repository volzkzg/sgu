#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
const int MAXK=100+10;  
const int MAXN=16000+10;  
struct Zone  
{  
    int index;//编号  
    int N;//需要的人数  
    int Q;//进入该区域的分数线  
}zone[MAXK];  
struct Stu  
{  
    int index;//编号  
    int P;//水平  
    int w;//重量  
}stu[MAXN];  
int p[MAXN];  
bool cmp1(Zone a,Zone b)//按照Q从大到小排序  
{  
    return a.Q>b.Q;  
}  
bool cmp2(Stu a,Stu b)//按照w从大到小排序  
{  
    return a.w>b.w;  
}  
int main()  
{  
    int k;  
    int i,j;  
    int num=0;  
    scanf("%d",&k);  
       
    for(i=0;i<k;i++)  
	{  
	    zone[i].index=i+1;  
	    scanf("%d",&zone[i].N);  
	    num+=zone[i].N;  
	}  
    for(i=0;i<k;i++)  
        scanf("%d",&zone[i].Q);  
    sort(zone,zone+k,cmp1);  
    for(i=0;i<num;i++)  
	{  
	    stu[i].index=i+1;  
	    scanf("%d",&stu[i].P);  
	}  
    for(i=0;i<num;i++)  
        scanf("%d",&stu[i].w);  
    sort(stu,stu+num,cmp2);  
    memset(p,-1,sizeof(p));  
    for(i=0;i<num;i++)//第一轮先分配成绩达到了的  
	{  
	    for(j=0;j<k;j++)  
		{  
		    if(stu[i].P>zone[j].Q && zone[j].N)//注意：是stu[i].P>zone[j].Q不是>=  
			{  
			    p[stu[i].index]=zone[j].index;  
			    zone[j].N--;  
			    break;//依次对排好序的学生逐个从排好序的区域逐个安排  
			}//也就是说对下一个学生也从第一个区域开始排  
		}  
	}  
    j=0;  
    for(i=0;i<num;i++)//分配剩下的人  
	{  
	    if(p[i+1]!=-1)  
		continue;//表示已经分配  
	    while(zone[j].N==0)  
		j++;//表示当前区域已经招满  
	    p[i+1]=zone[j].index;  
	    zone[j].N--;  
	}  
    for(i=1;i<=num;i++)  
	printf("%d ",p[i]);  
    return 0;  
}  
