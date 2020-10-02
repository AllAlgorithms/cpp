#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a[n],b[n],c[n]={0},f;
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
        }
        for(int j=0;j<m;j++)
        {
            cin>>f;
            int flag1=0;
            for(int k=0;k<n;k++)
            {
                if(f>=a[k]&&f<b[k])
                { cout<<0<<"\n";
                 flag1=1;
                 break;}
                else
                {
                    c[k]=a[k]-f;
                }

            }
            if(flag1==0)
            {
            int flag=0;
            sort(c,c+n);
            for(int k=0;k<n;k++)
            if(c[k]>=0)
            {cout<<c[k]<<"\n";flag=1;
             break;}
             if(flag==0)
             cout<<-1;
            }

        }
    }
}
