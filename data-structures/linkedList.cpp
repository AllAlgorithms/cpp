#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        this->head = NULL;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            return;
        }
        Node* currentNode = this->head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }

    void printList() {
        Node* currentNode = this->head;
        while (currentNode != NULL) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.printList();
    return 0;
}