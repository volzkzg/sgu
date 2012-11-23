/*
 *NAME:Telephone directory
 *LANG:C++
 *Source:sgu127
 */
#include <stdio.h>
int k;
int n;
int hash[10]={0};
int ans=2;
void read()
{
     char s[10];
     int i;
     scanf("%d",&k);
     scanf("%d",&n);
     for(i=1;i<=n;i++)
     {
      scanf("%s",s);
      hash[s[0]-'0']++;
     }
     for(i=0;i<=9;i++)
      ans+=(hash[i]/k+(hash[i]%k!=0));
     printf("%d\n",ans);
}
int main()
{
    read();
    return 0;
}
