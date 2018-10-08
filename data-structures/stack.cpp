#define stack_size 100

struct char_stack
{
  char arr[stack_size];
  int top;
};
typedef struct char_stack char_Stack;

void char_push (char_Stack *s,char c)
{
  if(s->top == stack_size-1)
  {
    printf("\n Stack overflow");
    return ;
  }
  s->arr[++s->top] = c;
return ;
}

char char_pop(char_Stack *s)
{
  if(s->top == -1)
  {
    printf("\nStack underflow");
    return '#';
  }
return s->arr[s->top--];
}


struct int_stack
{
  int arr[stack_size];
  int top;
};
typedef struct int_stack int_Stack;

void int_push (int_Stack *s,int c)
{
  if(s->top == stack_size-1)
  {
    printf("\n Stack overflow");
    return ;
  }
  s->arr[++s->top] = c;
return ;
}

int int_pop(int_Stack *s)
{
  if(s->top == -1)
  {
    printf("\nStack underflow");
    return '#';
  }
return s->arr[s->top--];
}


struct float_stack
{
  float arr[stack_size];
  int top;
};
typedef struct float_stack float_Stack;

void float_push (float_Stack *s,float c)
{
  if(s->top == stack_size-1)
  {
    printf("\n Stack overflow");
    return ;
  }
  s->arr[++s->top] = c;
return ;
}

float float_pop(float_Stack *s)
{
  if(s->top == -1)
  {
    printf("\nStack underflow");
    return '#';
  }
return s->arr[s->top--];
}


struct double_stack
{
  double arr[stack_size];
  int top;
};
typedef struct double_stack double_Stack;

void double_push (double_Stack *s,double c)
{
  if(s->top == stack_size-1)
  {
    printf("\n Stack overflow");
    return ;
  }
  s->arr[++s->top] = c;
return ;
}

double double_pop(double_Stack *s)
{
  if(s->top == -1)
  {
    printf("\nStack underflow");
    return '#';
  }
return s->arr[s->top--];
}

struct str_stack
{
  char arr[stack_size][stack_size];
  int top;
  char ans[stack_size];
};
typedef struct str_stack str_Stack;

void str_push(str_Stack *s, char *c)
{ 
  if(s->top == stack_size-1)
  {
    printf("\n Stack overflow");
    return ;
  }
  int i;
  s->top++;
  for(i=0;c[i]!='\0';i++)
  {
    s->arr[s->top][i] = c[i];
  } s->arr[s->top][i] = c[i];
return ;
}

void str_pop(str_Stack *s)
{
  if(s->top == -1)
  {
    printf("Stack underflow");
  }
  int i;
  for(i=0;s->arr[s->top][i]!='\0';i++)
  {
    s->ans[i] = s->arr[s->top][i];
  } s->ans[i] = s->arr[s->top][i];
  s->top--;
return ;
}
