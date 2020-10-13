#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node(int x){
		this->data = x;
		this->left = this->right = NULL;
	}
};


pair<int,int> minTime(Node* node, int *result){
	if(node->left == NULL && node->right == NULL)
		return {0,1};
	cout << "Node " << node->data << endl;
	pair<int,int> ansl={0,-1},ansr={0,-1};
	if(node->left)
		ansl = minTime(node->left,result);
	if(node->right)
		ansr = minTime(node->right,result);
	if(ansl.second == -1)
		return {ansr.first+1,ansr.second+1};
	if(ansr.second == -1)
		return {ansl.first+1,ansl.second+1};
	if(ansl.first<ansr.first){
		if(*result<ansl.first+1+ansr.second)
			*result = ansl.first+1+ansr.second;
		return {ansl.first+1, ansr.second+1};
	}
	else{
		if(*result<ansr.first+1+ansl.second)
			*result = ansr.first+1+ansl.second;
		return {ansr.first+1, ansl.second+1};
	}

}

int main()
{
	Node *root = new Node(0);
	root->left = new Node(1);
	root->right = new Node(2);
	root->left->left = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->left->left->left = new Node(10);
	root->left->right->left = new Node(9);
	root->right->right->left = new Node(7);
	root->right->right->right = new Node(8);
	
	cout << "Exec Start" << endl;
	int *result = new int;
	minTime(root,result);
	cout << *result << endl;

	return 0;
}