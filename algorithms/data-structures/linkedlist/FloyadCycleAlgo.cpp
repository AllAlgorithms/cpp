#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

node *create(node *&root)
{
    int x;
    cout << "Enter the data : ";
    cin >> x;
    node *n = new node(x);

    if (root == nullptr)
    {
        n = root;
        return root;
    }
    auto temp = root;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = n;
    return root;
}

bool checkForLoop(node *&root)
{
    auto fast = root;
    auto slow = root;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
void display(node *root)
{
    cout << endl;
    while (root != nullptr)
    {
        cout << root->data << " -> ";
        root = root->next;
    }
}

int main()
{
    int n;
    cout << "enter the number of nodes you want to insert in linked list : ";
    cin >> n;
    cout << endl;

    node *root = new node(0);
    for (int i = 0; i < n; i++)
    {
        create(root);
    }
    display(root);

    if (checkForLoop(root))
    {
        cout << "\n loop is present !!";
    }
    else
    {
        cout << "\n loop is not present !!";
    }
    return 0;
}