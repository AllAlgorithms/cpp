#include <iostream>
#include <stack>

using namespace std;

/* Structure of node */
struct node {
    int data;
    node *left, *right;

    node(int p) {
        this->data = p;
        this->left = this->right = NULL;   
    }
};

/* Insert a new Node in BST */
node *insert(node *root, int p) {
    if(root == NULL) {
        return new node(p);
    }
    if(root->data > p) {
        root->left = insert(root->left, p);
    }
    else {
        root->right = insert(root->right, p);
    }
    return root;
}

/* Display BST */
void display(node *root) {
    if(root !=  NULL) {
        cout << root->data << " ";	//Pre-Order
        display(root->left);
        // cout<<root->data<<" ";
        display(root->right);
    }
}

/* Return node with the minimum value */
node *minvalue(node *root) {
    node *curr = root;
    
    while(curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

/* Delete node with given key value in BST */
node *del(node* root, int key) {
    //Base case for root
    if(root == NULL) return root;
    if(root->data > key) {
        root->left = del(root->left, key);
    }
    else if(root->data < key) {
        root->right = del(root->right, key);
    }
    else {
        //node has either zero or one child
        if(root->left == NULL) {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            node *temp = root->left;
            delete root;
            return temp;
        }
        //two children
        node *temp = minvalue(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }
    return root;
}

/* Return the height of the BST */
int maxheight(node *node) {
    if(node == NULL) {
        return 0;
    }
    int lh = maxheight(node->left);
    int rh = maxheight(node->right);
    
    if(lh>rh)   return (lh+1);
    else    return (rh+1);
}

/* Return the search value for given key */
int search(node* temp, int key){
    int p=key;
    while(1) {
        if(temp->data == key) {
            return p;
        }
        else if(temp->data > key) {
            p = max(p, temp->data);
            temp = temp->left;
        }
        else if(temp->data < key) {
            temp = temp->right;
        }
    }
    return p;
}

/* Print BST in zigzag Pattern */
void zigzag(node* root) {
    stack<int> s[2];
    int curr = 0;
    int oth = 1;
    s[curr].push(root->data);
    node* temp1 = root;
    node* temp2 = root;
    while( (!s[curr].empty()) || (!s[oth].empty()) ) {
        if(curr == 0) {
            int p = s[curr].top();
            s[curr].pop();
            s[oth].push(temp1->left->data);
            s[oth].push(temp1->right->data);
            temp1 = temp1->right;
            cout << p << " ";
        }
        else {
            int p = s[oth].top();
            s[oth].pop();
            s[curr].push(temp1->right->data);
            s[curr].push(temp1->left->data);
            temp1 = temp1->left;
            cout << p << " ";
        }
        if(s[curr].empty()) {
            swap(curr, oth);
        }
    }
}

// Driver program to test BST.
int main() {
    node *root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);
    insert(root, 45);
    display(root);
    cout << endl;
    cout << "Height of tree is: " << maxheight(root) << endl;
    zigzag(root);
    return 0;
}
