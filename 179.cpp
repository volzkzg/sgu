#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
long n;
char s[25000]={0};
char stack[25000]={0};
long len=0;
long left_l,left_r;     /*左右括号剩余量*/
long cur_l=0,cur_r=0;   /*左右括号当前数量*/

void read()
{
     scanf("%s",s+1);
     n=strlen(s+1);
     left_l=n/2;
     left_r=n/2;
}

void dfs(long step,long sign)   /*sign 表示当前是否踩着树的边界走*/
{
     if(cur_r>cur_l) return;
     if(sign) if(s[step-1]==')'&&stack[step-1]=='(') return;
     if(step>n)
     {
         if(strcmp(stack+1,s+1)!=0)
         {
            printf("%s\n",stack+1);
            exit(0);
         }
     }
     /* go left */
     if(left_l>0)
     {
          left_l--;
          cur_l++;
          stack[step]='(';
          dfs(step+1,sign);
          cur_l--;
          left_l++;
     }
    
     /* go right */
     if(left_r>0)
     {
          left_r--;
          cur_r++;
          stack[step]=')';
          if(sign==1&&s[step]=='(')
            dfs(step+1,0);
          else
            dfs(step+1,sign);
          cur_r--;
          left_r++;
     }
}

int main()
{
    read();
    dfs(1,1);
    printf("No solution\n");
    return 0;
}
