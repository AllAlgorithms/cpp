#include <iostream>
using namespace std;

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
};

void Inorder(BSTNode* root)
{
    if(root)
    {
        Inorder(root->left);
        cout<<"Key = "<<root->data<<", ";
        if(!(root->parent))
            cout<<"Parent = NULL"<<", ";
        else
            cout<<"Parent = "<<root->parent->data<<", ";
        if(!(root->left))
            cout<<"Left = NULL"<<", ";
        else
            cout<<"Left = "<<root->left->data<<", ";
        if(!(root->right))
            cout<<"Right = NULL"<<endl;
        else
            cout<<"Right = "<<root->right->data<<endl;

        Inorder(root->right);
    }

}

BSTNode* getNodeData(int data)
{
    BSTNode* root=new(BSTNode);
    root->data=data;
    root->left=root->right=NULL;
    root->parent=NULL;
    return root;
}

BSTNode* InsertData(BSTNode* root,int data)
{

    if(root==NULL)
        return getNodeData(data);
    else if(data<=root->data)
    {
        BSTNode* lchild;
        lchild=InsertData(root->left,data);
        root->left=lchild;
        lchild->parent=root;
    }
    else
    {
        BSTNode* rchild;
        rchild=InsertData(root->right,data);
        root->right=rchild;
        rchild->parent=root;
    }
    return root;
}

bool BSTSearch(BSTNode* node,int key)
{
    if(!node) return false;
    if(node->data==key) return true;
    else if(key<=node->data) BSTSearch(node->left,key);
    else BSTSearch(node->right,key);
}
BSTNode* MinBST(BSTNode* root)
{
    if(root->left==NULL) return root;
    else
        return MinBST(root->left);
}
BSTNode* NodeDelete(BSTNode* root,int key)
{
    if(root==NULL)return root;
    else if(root->data>key)
        root->left=NodeDelete(root->left,key);
    else if(root->data<key)
        root->right=NodeDelete(root->right,key);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete(root);
            root=NULL;
        }
        else if(root->left==NULL)
        {
            BSTNode* t=root;
            root=root->right;
            root->parent=t->parent;
            delete(t);
        }
        else if(root->right==NULL)
        {
            BSTNode* t=root;
            root=root->left;
            root->parent=t->parent;
            delete(t);
        }
        else
        {
            BSTNode* t =MinBST(root->right);
            root->data=t->data;
            root->right=NodeDelete(root->right,t->data);
        }
    }
    return root;
}
int main() {
    BSTNode *root = NULL;

    while (1) {
        cout
                << "Enter 1 to Add Element\nEnter 2 to Delete Element\nEnter 3 to Display All Elements Inorder Traversal\nEnter 0 to Exit"
                << endl;
        int c;
        cin >> c;
        switch (c) {
            case 0:
                cout << "Ended";
                return 0;
            case 1:
                cout << "Enter Element to add" << endl;
                int x;
                cin >> x;
                root=InsertData(root, x);
                break;
            case 2:
                cout << "Enter Element to delete" << endl;
                cin >> x;
                NodeDelete(root, x);
                break;
            case 3:
                cout << "Elements are" << endl;
                Inorder(root);
                break;
            default:
                cout << "Wrong Choice" << endl;
        }


    }
    return 0;
}