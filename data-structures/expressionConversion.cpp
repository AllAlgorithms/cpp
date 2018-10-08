#include<stdbool.h>
#include "stack.cpp"
#include "functions.cpp"

void infixToPostfix(char str[], char answer[], bool switchAssociativity)
{
  int counter=0;
  char_Stack s;
  s.top = -1;

  int i;
  for(i=0;str[i]!='\0';i++)
  {
    if(isAlphabet(str[i]))
    {
      answer[counter++] = str[i];
    }
    else
    {
      if(str[i] == '(')
      {
        char_push(&s, str[i]);
      }
      else if(str[i] == ')')
      {
        while(true)
        {
          char c = char_pop(&s);
          if(c == '(') { break; }
          answer[counter++] = c;
        }
      }
      else 
      {
        if(associativity(str[i],switchAssociativity))
        {
          if(s.top != -1 && (precedence(s.arr[s.top]) >= precedence(str[i])))
          {
            while(precedence(s.arr[s.top]) >= precedence(str[i]))
            {
              if(s.arr[s.top] == '(')
                break;
              char c = char_pop(&s);
              answer[counter++] = c;
            }
            char_push(&s, str[i]);
          }
          else
          {
              char_push(&s, str[i]);
          }
        }
        else
        {
          if(s.top != -1 && (precedence(s.arr[s.top]) > precedence(str[i])))
          {
            while(s.top != -1 && (precedence(s.arr[s.top]) > precedence(str[i])))
            {
              if(s.arr[s.top] == '(')
                break;
              char c = char_pop(&s);
              answer[counter++] = c;
            }
            char_push(&s, str[i]);
          }
          else
          {
              char_push(&s, str[i]);
          }
        }
      }
    }
  }
  int top = s.top;
  while(top != -1)
  {
    char c = char_pop(&s);
    answer[counter++] = c;
    top--;
  }
  answer[counter] = '\0';
}

void infixToPrefix(char str[], char answer[])
{
  reverse_charArr(str);
  infixToPostfix(str,answer,true);
  reverse_charArr(str); //get back original input string.
  reverse_charArr(answer);
}

void postfixToInfix(char str[], char answer[])
{
  str_Stack s;
  s.top = -1;
  int i;
  for(i=0;str[i]!='\0';i++)
  {
    if(isAlphabet(str[i]))
    {
      char x[2];
      x[0] = str[i]; x[1] = '\0';
      str_push(&s, x);
    }
    else
    {
      int j,k,iter;
      char operand1[stack_size],operand2[stack_size],result[stack_size];
      str_pop(&s);
      for(j=0;s.ans[j]!='\0';j++)
      {
        operand1[j] = s.ans[j];
      } operand1[j] = s.ans[j];
      str_pop(&s);
      for(k=0;s.ans[k]!='\0';k++)
      {
        operand2[k] = s.ans[k];
      } operand2[k] = s.ans[k];
      
      for(iter = 0;iter <= j+k;iter++)
      {
        if(iter<k)
          result[iter] = operand2[iter];
        else if(iter == k)
          result[iter] = str[i];
        else
          result[iter] = operand1[iter-k-1];
      } result[iter] = '\0';
      str_push(&s, result);
    }
  }
  str_pop(&s);
  for(i=0;s.ans[i]!='\0';i++)
    answer[i] = s.ans[i];
  answer[i] = s.ans[i];
}

void prefixToInfix(char str[], char answer[])
{
  reverse_charArr(str);
  postfixToInfix(str,answer);
  reverse_charArr(str);
  reverse_charArr(answer);
}

void postfixToPrefix(char str[], char answer[])
{
  str_Stack s;
  s.top = -1;
  int i;
  for(i=0;str[i]!='\0';i++)
  {
    if(isAlphabet(str[i]))
    {
      char x[2];
      x[0] = str[i]; x[1] = '\0';
      str_push(&s, x);
    }
    else
    {
      int j,k,iter;
      char operand1[stack_size],operand2[stack_size],result[stack_size];
      str_pop(&s);
      for(j=0;s.ans[j]!='\0';j++)
      {
        operand1[j] = s.ans[j];
      } operand1[j] = s.ans[j];
      str_pop(&s);
      for(k=0;s.ans[k]!='\0';k++)
      {
        operand2[k] = s.ans[k];
      } operand2[k] = s.ans[k];
      result[0] = str[i];
      for(iter = 1;iter <= j+k;iter++)
      {
        if(iter<=k)
          result[iter] = operand2[iter-1];
        else
          result[iter] = operand1[iter-k-1];
      } result[iter] = '\0';
      str_push(&s, result);
    }
  }
  str_pop(&s);
  for(i=0;s.ans[i]!='\0';i++)
    answer[i] = s.ans[i];
  answer[i] = s.ans[i];
}

void prefixToPostfix(char str[], char answer[])
{
  reverse_charArr(str);
  postfixToPrefix(str,answer);
  reverse_charArr(str);
  reverse_charArr(answer);  
}
