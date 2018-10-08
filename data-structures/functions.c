#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif
#define swap(type, i, j) {type t = i; i = j; j = t;}

int precedence (char c)
{
  switch(c)
  {
    case '^': return 3;
    case '*': return 2;
    case '/': return 2;
    case '+': return 1;
    case '-': return 1;
  }
return 0;
}

bool associativity (char c, bool switchAssociativity)
{ //returning false means associativity is right to left and if switchAssociativity is true means input is reversed so associativity is reversed.
  bool associativity = true;
  switch(c)
  {
      case'^': associativity = false;
  }
  if(switchAssociativity)
  {associativity = !associativity;}
return associativity;
}

bool isAlphabet(char c)
{
  int ascii = (int)c;
  if((ascii >= 65 && ascii <= 90) || (ascii>=97 && ascii<=122))
    return true;
return false;
}

void reverse_charArr(char str[])
{
  int length=0,i;
  for(i=0;str[i]!='\0';i++);
  length = i;
  for(i=0;i<=(length/2)-1;i++)
  {
    swap(char,str[i],str[length-i-1]);
  }
  for(i=0;i<=length-1;i++)
  {
    if(str[i] == '(')
      str[i] = ')';
    else if(str[i] == ')')
      str[i] = '(';
  }
}
