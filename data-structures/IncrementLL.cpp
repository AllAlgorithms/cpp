#include<bits/stdc++.h>
using namespace std;

/*

Increment Linked List by 1

This program increments the list by 1. The program takes input with one space and when entered -1 at the end, it stops taking more inputs
For example

Input:
3 1 -1

Output:
3 2

Input2:
9 9 -1

Output2:
1 0 0

Idea is to reverse a LL, made some calculations and reverse it again to obtain the answer.

*/

class Node {
	public:
		int data;
		Node *next;
		
		Node(int data) {
			this->data = data;
			this->next = NULL;
		}
};

Node* takeInput() {
	Node* head = NULL;
	Node* prev = NULL;
	int d;
	cin >> d;
	
	while(d != -1) {
		Node* newnode = new Node(d);
		if(head == NULL) {
			head = newnode;
			prev = head;
		}
		else {
			prev->next = newnode;
			prev = newnode;
		}
		cin >> d;
	}
	return head;
}

Node* reverseLL(Node* head) {
	Node* curr = head;
	Node* prev = NULL;
	while(curr != NULL) {
		if(prev == NULL) {
			prev = curr;
			curr = curr->next;
			prev->next = NULL;
		}
		else {
			Node* var = curr;
			curr = curr->next;
			var->next = prev;
			prev = var;
		}
	}
	return prev;
}

void print(Node* head) {
	Node* temp = head;
	while(temp != NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int main() {
	Node* head = takeInput();
	Node *newHead = NULL;
	newHead = reverseLL(head);
	
	bool carry = false;
	
	Node *temp = newHead;
	Node *prev = NULL;
	int digit = temp->data + 1;
	while(temp!= NULL) {
		if(carry) {
			int data = temp->data + 1;
			if(data >= 10) {
				temp->data = (data%10);
				carry = true;	
			}
			else {
				temp->data = data;
				carry = false;
				break;
			}
		}
		else if(digit>=10) {
			temp->data = (digit%10);
			carry = true;	
		}
		else if(digit<10) {
			temp->data = temp->data + 1;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if(carry) {
		Node* newNode = new Node(1);
		prev->next = newNode;
		newNode->next = NULL;
	}
	head = reverseLL(newHead);
	print(head);
}
