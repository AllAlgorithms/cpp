#include<iostream>
#include<conio.h>
using namespace std;
int flag = 0, v[3];
struct node_info
{
    int no;
}*q = NULL, *r = NULL;
struct node
{
    node_info *pt;
    node *next;
}*top = NULL, *p = NULL, *np = NULL;
void push(node_info *ptr)
{
    np = new node;
    np->pt = ptr;
    np->next = NULL;
    if (top == NULL)
    {
        top = np;
    }
    else
    {
        np->next = top;
        top = np;
    }
}
 node_info *pop()
{
    if (top == NULL)
    {
        cout<<"underflow\n";
    }
    else
    {
        p = top;
        top = top->next;
        return(p->pt);
        delete(p);
    }
    return 0;
}
int back_edges(int *v,int am[][3],int i,int k)
{
    q = new node_info;
    q->no = i;
    push(q);
    v[i] = 1;
    for (int j = 0; j < 3; j++)
    {
        if (am[i][j] == 1 && v[j] == 0)
        {
            back_edges(v, am, j, i);
        }
        else if (am[i][j] == 0)
            continue;
        else if ((j == k) && (am[i][k] == 1 && v[j] == 1))
            continue;
        else
        {
            flag = -1;
        }
    }
    r = pop();
    return(flag);
}
void init()
{
    for (int i = 0; i < 3; i++)
        v[i] = 0;
    while (top != NULL)
    {
        pop();
    }
}
void kruskals(int am[][3], int wm[][3])
{
    int ve = 1, min, temp, temp1;
    cout<<"/n/nEDGES CREATED AS FOLLOWS:-/n/n";
    while (ve <= 6)
    {
        min = 999, temp = 0, temp1 = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if ((wm[i][j] < min) && wm[i][j]!=0)
                {
                    min = wm[i][j];
                    temp = i;
                    temp1 = j;
                }
                else if (wm[i][j] == 0)
                    continue;
            }
        }
        wm[temp][temp1]=wm[temp1][temp] = 999;
        am[temp][temp1]=am[temp1][temp] = 1;
        init();
        if (back_edges(v, am, temp, 0) < 0)
        {
            am[temp][temp1]=am[temp1][temp] = 0;
            flag = 0;
            continue;
        }
        else
        {
            cout<<"edge created between "<<temp<<" th node and "<<temp1<<" th node"<<endl;
            ve++;
        }
    }
}
int main()
{
    int am[3][3], wm[3][3];
    for (int i = 0; i < 3; i++)
        v[i] = 0;
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            am[i][j] = 0;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<"enter the values for weight matrix row:"<<i + 1<<endl;
        for(int j = 0; j < 3; j++)
        {
            cin>>wm[i][j];
        }
    }
    kruskals(am,wm);
    return 0;
}
