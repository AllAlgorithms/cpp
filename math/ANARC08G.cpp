#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n,count=1;
    cin>>n;
    while(n!=0)
    {  int sum=0;
       int a[n][n];
       for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
           {scanf("%d",&a[i][j]);
             sum+=a[i][j];
           }
       int finalans[n]={0},sum1=0,sum2=0;
       for(int i=0;i<n;i++)
            {   sum1=0;
                sum2=0;
                for(int j=0;j<n;j++)
            {
                sum1+=a[i][j];
                sum2+=a[j][i];

            }
            if(sum1>=sum2)
                finalans[i]=sum1-sum2;
            else
                finalans[i]=sum2-sum1;
            }
            int ans=0;
          for(int i=0;i<n;i++)
            ans+=finalans[i];

          printf("%d. %d %d\n",count,sum,ans/2);
          cin>>n;count++;
    }
}
