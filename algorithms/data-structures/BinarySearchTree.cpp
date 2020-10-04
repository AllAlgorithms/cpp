#include<bits/stdc++.h>
#define ll long long int 
#define ull unsigned long long int
#define pb push_back
#define MIN 2
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d",n)
#define gc getchar_unlocked
#define AC 0
#define MOD 1000000007
#define mp make_pair
#define vc vector
#define wh(n) while(n--)
#define ite(type,datatype,name)  type<datatype>::iterator name
#define gt goto

using namespace std;

	/*Structure of node*/
struct node{
    int data;
    struct node *left,*right;
};
	/*Create a new Node*/
struct node *newnode(int p){
    struct node *temp = new node();
    temp->data = p;
    temp->left = temp->right = NULL;
    return temp;
}

	/*Insert a new Node in BST*/
struct node *insert(struct node *root,int p){
    if(root == NULL){
        return newnode(p);
    }
    if(root->data > p){
        root->left = insert(root->left,p);
    }
    else{
        root->right = insert(root->right,p);
    }
    return root;
}
/* Display BST */
void display(struct node *root){
    if(root !=  NULL){
         cout<<root->data<<" ";	//Pre-Order
        display(root->left);
       // cout<<root->data<<" ";
        display(root->right);
        
    }
}
	/*Return node with minimum value*/
struct node *minvalue(struct node *root){
    struct node *curr = root;
    
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

/* Delete node with given key value in BST */
struct node *del(struct node* root,int key){
    //Base case for root
    if(root == NULL) return root;
    if(root->data > key){
        root->left = del(root->left,key);
    }
    else if(root->data < key){
        root->right = del(root->right,key);
    }
    else{
        //noDe has one or nO noDe 
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        //tWo chiLd
        struct node *temp = minvalue(root->right);
        root->data = temp->data;
        root->right = del(root->right,temp->data);
    }
    return root;
}

	/* Return height of BST */
int maxheight(struct node *node){
    if(node == NULL){
        return 0;
    }
    int lh = maxheight(node->left);
    int rh = maxheight(node->right);
    
    if(lh>rh)   return (lh+1);
    else    return (rh+1);
}
/* return the search value for given key */
int search(struct node* temp,int key){
    int p=key;
    while(1){
        if(temp->data == key){
            return p;
        }
        else if(temp->data > key){
            p = max(p,temp->data);
            temp = temp->left;
        }
        else if(temp->data < key){
            temp = temp->right;
        }
    }
    return p;
}

	/*Print BST in zigzag Pattern */
void zigzeg(struct node* root){
    stack<int> s[2];
    int curr = 0;
    int oth = 1;
    s[curr].push(root->data);
    struct node* temp1 = root;
    struct node* temp2 = root;
    while((!s[curr].empty()) || (!s[oth].empty())){
        if(curr == 0){
            int p = s[curr].top();
            s[curr].pop();
            s[oth].push(temp1->left->data);
            s[oth].push(temp1->right->data);
            temp1= temp1->right;
            cout<<p<<" ";
        }
        else{
            int p = s[oth].top();
            s[oth].pop();
            s[curr].push(temp1->right->data);
            s[curr].push(temp1->left->data);
            temp1= temp1->left;
            cout<<p<<" ";
        }
        if(s[curr].empty()){
            swap(curr,oth);
        }
    }
}
// Driver program to test above functions 
int main(){
    struct node *root = NULL;
    root = insert(root,20);
    insert(root,10);
    insert(root,30);
    insert(root,5);
    insert(root,15);
    insert(root,25);
    insert(root,35);
    insert(root,45);
    display(root);
    cout<<endl;
    cout<<"Height of tree is: "<<maxheight(root)<<endl;
    zigzeg(root);
    return 0;
}
