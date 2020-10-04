#include<stdio.h>
#include<stdlib.h>
struct tree             //declaring a structure tree
{
    int data;
    struct tree* left;
    struct tree* right;
}*root=NULL;            //creates a root pointer

struct node     //declaring a sructure node
{
    struct tree* link;      //node refering to structure tree
    struct node* next;
}*top=NULL;              //creates a top pointer


void insert_bt(int d)           //Insertion in Binary tree
{
    struct tree* temp;
    temp=(struct tree*)malloc(sizeof(struct tree));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=d;
    if( root == NULL)
        root = temp;
    else
    {
        struct tree* parent,*curr;
        curr=root;
        while(curr)
        {
            parent=curr;
            if(d < curr->data)
                {
                    curr=curr->left;
                }
            else
            {
                curr=curr->right;
            }
            
        }
        if(d < parent->data)
            {
                parent->left=temp;
            }
        else
        {
            parent->right=temp;
        }
        
    }
    
}
//*********************************************************
void inorder(struct tree*t)   // Inorder traversal using recurrsion
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf(" %d",t->data);
        inorder(t->right);
    }
}
//*********************************************************


void push(struct tree* c)                       //Pushing into the stack
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->link=c;

        temp->next=top;
        top=temp;
}
//********************************************************

int pop()             //poping out
{
    if(top == NULL)
        return 0;
    else
    {
        struct node* temp;
        temp=top;
        printf(" %d",temp->link->data);
        top=top->next;
        
       temp->link=NULL;
       temp->next=NULL;
       free(temp);
       temp=NULL;            //assinging the top to the root
       
        
    }
}
//*********************************************************
void display()                  //display function
{
    struct node* t;
    t=top;
    printf("\n");
    while(t!=NULL)
    {
        printf(" %d",t->link->data);
        t=t->next;
    }
}
//***************************************************
int isempty()                   //function to check wheather the function is empty or not
{
    if( top == NULL)
        return 1;
    else return 0;
}
//******************************************************

void iterative(struct tree* t)          // iterative method 
{
    while(1)
    {
        if(t!=NULL)
        {
            push(t);
            t=t->left;
        }
        else
        {
            if(isempty())
                break;
            else
            {
                t=top->link; // before poping we need to initialize the root to 
                                // to the top of the stack
                pop();

                t=t->right;
            }
            
        }
    
    }
}

//*******************************MAIN FUNCTION**************************************
int main()
{
    int n;
    printf("\n Enter how many element you want to enter: ");
    scanf("%d",&n);
    int i,m;
    printf("\n Enter the elements: ");
    for( int i=0; i<n; i++)
    {
        scanf("%d",&m);
        insert_bt(m);
    }
    printf("\n This is the output using recurrsion: ");
    inorder(root);
    printf("\n This is the output witout-using recurrsion: ");
    iterative(root);


    return 0;
}
//***********************************END OF MAIN**********************************************