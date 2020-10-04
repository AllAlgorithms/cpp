#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
char string[100],c;
cout<<"Enter the string:\n";
cin.getline(string,100);
for(int len=0;string[len]!='\0';len++);
int i,j,flag=1;
for(i=0,j=len-1;i<len/2;i++,j--)
{
if(string[i]!=string[j])
 {
  flag=0;
  break;
 }
}
if(flag!=0)
  cout<<"Its a PALINDROME.\n";
else
  cout<<"Its not a PALINDROME.\n";
getch();
return 0;
}