#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
struct tree
{
    int value;
    tree *left;
    tree *right;
}*root=NULL;
void inserte()
{
    int v,insert_left=0,insert_right=0;
    cout<<"Enter Value To Insert: ";
    cin>>v;
    tree *newnode=(tree*)malloc(sizeof(tree));
    newnode->value=v;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
        root=newnode;
    else
    {
        tree *temp=root;
        while(1)
        {
            if(insert_left==1||insert_right==1)
                break;
            if(v<temp->value)
            {
                if(temp->left!=NULL)
                    temp=temp->left;
                else
                    insert_left=1;
            }
            else
            if(v>temp->value)
            {
                if(temp->right!=NULL)
                    temp=temp->right;
                else
                    insert_right=1;
            }
        }
        if(insert_left==1)
            temp->left=newnode;
        else
        if(insert_right==1)
            temp->right=newnode;
    }
}
void preorder()
{
    tree *temp=root;
    stack <tree*>s;
    repeat:
        while(1)
        {
            if(temp->right!=NULL)
                s.push(temp->right);
            if(temp->left!=NULL)
            {
                cout<<temp->value<<" ";
                temp=temp->left;
            }
            else
            if(temp->left==NULL)
            {
                cout<<temp->value<<" ";
                break;
            }
        }
    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        goto repeat;
    }
}
void inorder()
{
    tree *temp=root;
    stack <tree*>s;
    repeat:
        while(1)
        {
            s.push(temp);
            if(temp->left!=NULL)
            temp=temp->left;
            else
                break;
        }
    while(1)
    {
        repeat1:
            temp=s.top();
            cout<<temp->value<<" ";
            s.pop();
        if(temp->right==NULL)
            goto repeat1;
        else
        if(temp->right!=NULL)
        {
            temp=temp->right;
            goto repeat;
        }
        else
        if(s.empty())
        break;
    }
}

int main()
{
    int ch;
    while(1)
    {
        cout<<endl<<"1.Insert into tree"<<endl;
        cout<<"2.Preorder"<<endl;
        cout<<"3.Inorder"<<endl;
        cout<<"Choice: ";
        cin>>ch;
        if(ch==1)
            inserte();
        else
            if(ch==2)
            {
                preorder();
                cout<<endl;
            }
        else
            if(ch==3)
        {
            inorder();
            cout<<endl;
        }
        else
            return 0;
    }
    return 0;
}

