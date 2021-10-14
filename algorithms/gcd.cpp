#include<bits/stdc++.h>
using namespace std;
char c[250];
int rem(int a)
{
    int t=0,b=0;
    while(c[t]!='\0')
    {
        b=(b*10)+c[t]-48;
        b=b%a;
        t++;
    }
return b;
}
int main()
{
   int t,a;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&a);
       scanf("%s",&c);
       if(!a)
            printf("%s\n",c);
       else
       printf("%d\n",__gcd(a,rem(a)));
   }
}
