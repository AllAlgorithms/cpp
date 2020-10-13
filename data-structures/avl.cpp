#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data, height;
	node *left, *right;
};

class avl
{
	node* root=NULL;
public:
	int height(node* root){
		if(root)
			return root->height;
		return 0;
	}
	node* rotateLeft(node* root){
		node* newroot = root->right;
		root->right = newroot->left;
		newroot->left = root;
		return newroot;
	}
	node* rotateRight(node* root){
		node* newroot = root->left;
		root->left = newroot->right;
		newroot->right = root;
		return newroot;
	}
	void insert(int x){
		this->root = insert(this->root, x);
	}
	node* insert(node* root, int x){
		if(root==NULL){
			root = new node;
			root->data = x;
			root->height = 1;
			root->left = NULL;
			root->right = NULL;
			return root;
		}
		if(x < root->data)
			root->left = insert(root->left,x);
		else if(x > root->data)
			root->right = insert(root->right,x);
		else
			return root;

		int lh = height(root->left), rh = height(root->right);
		root->height = 1 + max(lh,rh);

		lh -= rh;
		if(lh>1){
			if(x > root->left->data)
				root->left = rotateLeft(root->left);
			return rotateRight(root);
		}
		else if(lh<-1){
			if(x < root->right->data)
				root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
		return root;
	}
	int minValue(node* root){
		while(root->left)
			root = root->left;
		return root->data;
	}
	void remove(int x){
		this->root = remove(this->root, x);
	}
	node* remove(node* root, int x){
		if(root == NULL)
			return NULL;
		if(x < root->data)
			root->left = remove(root->left, x);
		else if(x > root->data)
			root->right = remove(root->right, x);
		else{
			if(root->left == NULL && root->right == NULL){
				delete root;
				return NULL;
			}
			else if(root->right == NULL){
				node* temp = root;
				root = root->left;
				delete temp;
				return root;
			}
			else if(root->left == NULL){
				node* temp = root;
				root = root->right;
				delete temp;
				return root;
			}
			else{
				root->data = minValue(root->right);
				root->right = remove(root->right, root->data);
			}
		}

		int lh = height(root->left), rh = height(root->right);
		root->height = 1 + max(lh,rh);

		lh -= rh;
		if(lh>1){
			if(x > root->left->data)
				root->left = rotateLeft(root->left);
			return rotateRight(root);
		}
		else if(lh<-1){
			if(x < root->right->data)
				root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
		return root;
	}
	void printLevel(){
		printLevel(this->root);
	}
	void printLevel(node* root){
		if(root){
			queue<node*> q;
			q.push(root);
			q.push(NULL);
			node* temp;
			while(!q.empty()){
				temp = q.front();
				q.pop();
				if(temp){
					cout << temp->data << " ";
					if(temp->left)
						q.push(temp->left);
					if(temp->right)
						q.push(temp->right);
				}
				else if(q.front()){
					cout << endl;
					q.push(NULL);
				}
			}
		}
	}
	void print(){
		print(this->root);
	}
	void print(node* root){
		if(root){
			print(root->left);
			cout << root->data << " ";
			print(root->right);
		}
	}
};

int main()
{
	avl a;
	a.insert(5);
	a.insert(6);
	a.insert(7);
	a.insert(8);
	a.insert(9);
	a.insert(4);
	a.printLevel();
	a.remove(7);
	a.remove(5);
	cout << endl;
	a.printLevel();
	
	return 0;
}