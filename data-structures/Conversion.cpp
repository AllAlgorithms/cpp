#include<stdlib.h>
#include<stdio.h>
#include "expressionConversion.c"

int main()
{
  char answer[stack_size];
  char str[stack_size];
  char temp;
  int Input;
  clrscr();
  while(true)
  {
    printf("\n1.Infix to Postfix.");
    printf("\n2.Infix to Prefix.");
    printf("\n3.Postfix to Infix.");
    printf("\n4.Postfix to Prefix.");
    printf("\n5.Prefix to Infix.");
    printf("\n6.Prefix to Postfix.");
    printf("\nPress 0 for exit.\t\t\tEnter your choice: ");
    scanf("%d",&Input);
    switch(Input)
    {
      case 1:
        printf("Enter infix expression: ");
        scanf("%s",str);
        
        printf("corresponding Postfix expression:");
        infixToPostfix(str, answer,false);
        printf(" %s",answer);
        
        break;
      case 2:
        printf("Enter infix expression: ");
        scanf("%s",str);
        
        printf("corresponding Prefix expression:");
        infixToPrefix(str,answer);
        printf(" %s",answer);

        break;
      case 3:
        printf("Enter postfix expression: ");
        scanf("%s",str);
  
        printf("corresponding Infix expression:");
        postfixToInfix(str, answer);
        printf(" %s",answer);

        break;
      case 4:
        printf("Enter postfix expression: ");
        scanf("%s",str);

        printf("corresponding Prefix expression:");
        postfixToPrefix(str, answer);
        printf(" %s",answer);

        break;
      case 5:
        printf("Enter prefix expression: ");
        scanf("%s",str);
        
        printf("corresponding Infix expression:");
        prefixToInfix(str, answer);
        printf(" %s",answer);

        break;
      case 6:
        printf("Enter prefix expression: ");
        scanf("%s",str);
        
        printf("corresponding Postfix expression:");
        prefixToPostfix(str, answer);
        printf(" %s",answer);

        break;
      case 0:
          exit(0);
      default: ;
    }
  }
printf("\n");
return 0;
}
