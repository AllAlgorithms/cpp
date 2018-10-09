#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
        char str1[50], str2[50];
        cout<<"\n Enter First String : ";
        gets(str1);
        cout<<"\n Enter Second String : ";
        gets(str2);
        strcat(str1, str2);
        cout<<"\n String After Concatenation is : "<<str1;
        return 0;
}
