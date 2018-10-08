#include <stdio.h>

#define stack_size 10000

struct int_stack
{
    int arri[stack_size], arrj[stack_size];
    int top;
};
typedef struct int_stack int_Stack;

void int_push (int_Stack *s,int x,int y)
{
    if(s->top == stack_size-1)
    {
        printf("\n Stack overflow");
        return ;
    }
    s->arri[++s->top] = x;
    s->arrj[s->top] = y;
    return ;
}

void int_pop(int_Stack *s,int *x,int *y)
{
    if(s->top == -1)
    {
        printf("\nStack underflow");
    }
    *x = s->arri[s->top];
    *y = s->arrj[s->top--];
}

void display(int_Stack s){
    printf("STACK");
    if(s.top==-1) {
        printf("NULL");
        return;
    }
    for (int i = 0; i < s.top; ++i) {
        printf("||%d%d||\n",s.arri[i],s.arri[i]);
    }
}
int main(){
    int arr[10][10];
    int x,y,p,q;
    int_Stack s;
    s.top = -1;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    scanf("%d%d%d%d",&x,&y,&p,&q);
    int_push(&s,x,y);
    //display(s);
    while(1) {
        if(s.top==-1) {
            printf("\nnot possible\n");
            return 0;
        }
        int j,k;
        int_pop(&s,&j,&k);
        arr[j][k]=2;
        if(j == p && k == q){
            printf("\n©∆flag{cheese_mil_gaya}∆©\n");
            return 0;
        }
        //printf("%d,%d\n",j,k);
        if(j+1<10){
            if(arr[j+1][k] == 1){
                int_push(&s,j+1,k);
                arr[j+1][k]=2;
            }
        }
        if(k-1>=0){
            if(arr[j][k-1] == 1){
                int_push(&s,j,k-1);
                arr[j][k-1]=2;
            }
        }
        if(j-1>=0){
            if(arr[j-1][k] == 1){
                int_push(&s,j-1,k);
                arr[j-1][k]=2;
            }
        }
        if(k+1<10){
            if(arr[j][k+1] == 1){
                int_push(&s,j,k+1);
                arr[j][k+1]=2;
            }
        }
    }
}
