#include <iostream>
#include <stdexcept> 
#include "linkedlist_adt.h"
using namespace std;

/*
    Constructor for Node class
*/
Node::Node(int value)
{
    this->data = value;
    this->next = NULL;
}

/*
    Constructor for LinkedList Class
*/
LinkedList::LinkedList()
{
    this->length = 0;
    this->head = NULL;
}

/*
    Destructor for LinkedList class
*/
LinkedList::~LinkedList()
{
    Node *next_node=NULL; 
    for (Node *node_ptr=this->head; node_ptr != NULL; node_ptr=next_node) { 
        next_node = node_ptr->next;
        delete node_ptr; 
    }
}

/*
    Returns curret size of linkedList
*/
int LinkedList::size() const
{
    return(this->length);
}

bool LinkedList::empty() const
{
    return(this->length == 0);
} 

/*  
    Prints content of Linked List
*/
void  LinkedList::print() const
{
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

int& LinkedList::at(int index)
{
    if(index < 0 || index >= this->length) {
        throw out_of_range("index out of bounds"); }
    Node *node_ptr; 
    for (node_ptr=this->head; node_ptr != NULL; node_ptr=node_ptr->next) { 
        if (index == 0) {
            break;
        }
        index--;
    }
    return node_ptr->data; 
}

/*
    Find the node with given value
*/
Node* LinkedList::find(int value) const {
    Node *node_ptr; 
    for (node_ptr=this->head; node_ptr != NULL; node_ptr=node_ptr->next) {
        if (value == node_ptr->data)
            return node_ptr;
    }
    return NULL;
}
 
bool LinkedList::contains(int value) const{
    Node* node_ptr = find(value); 
    return node_ptr != NULL;
}

/*
    Add a node at last in list
*/
void LinkedList::append(int value) {
    Node *new_node = NULL;
    if (this->head == NULL) {
        new_node = new Node(value);
        this->head = new_node;
    }
    else {
        Node *last_node = NULL;
        for (Node *node_ptr=this->head; node_ptr != NULL; node_ptr=node_ptr->next) {
            last_node = node_ptr;
        }
        new_node = new Node(value);
        last_node->next = new_node;
    }
    this->length++;
}

/*
    Add a node in list from head
*/
void LinkedList::prepend(int value) {
        Node *first_node = new Node(value);;
        first_node->next = this->head;
        this->head = first_node;
        this->length++;
}

/*
    Remove target node from linked list
*/
void LinkedList::remove(Node* target_node_ptr) {
    Node* prev_ptr=NULL; 
    Node *node_ptr; 
    for (node_ptr = this->head; node_ptr != NULL && node_ptr != target_node_ptr; node_ptr = node_ptr->next) {
        prev_ptr = node_ptr; 
    }
    if (node_ptr == NULL) { 
        throw target_node_ptr; 
    } 
    else if (prev_ptr == NULL) { 
        this->head = target_node_ptr->next; 
        delete target_node_ptr;
    } 
    else {
        prev_ptr->next = target_node_ptr->next; 
        delete target_node_ptr; 
        Node *prev_ptr = this->head;
    }
}

/*
    Erase node at index from List
*/
void LinkedList::erase(int index){
    if (index < 0 || index >= this->length)
        throw  out_of_range ("index out of bounds");
    Node *prev_ptr = NULL;
    Node *node_ptr; 
    for (node_ptr = this->head; node_ptr != NULL; node_ptr = node_ptr->next) {
        if (index == 0)
            break;
        index--;
        prev_ptr = node_ptr; 
    } 
    if (prev_ptr == NULL) {
        this->head = node_ptr->next;
        delete node_ptr;
    }
    else {
        prev_ptr->next = node_ptr->next;
        delete node_ptr;
    }
}
/*
int main()
{
    LinkedList* list = new LinkedList();
    cout << "Empty = " << boolalpha << list->empty() << endl;
    for(int i=0; i < 6; i++) {
        list->append(i);
        cout << "List size = " << list->size() << endl;
        list->print();
    }
    for(int j=11; j > 6; j--) {
        list->prepend(j);
        cout << "List size = " << list->size() << endl;
        list->print();
    }
    cout << "Empty = " << boolalpha << list->empty() << endl;
    cout << "list->at(5) = " << list->at(5) << endl;
    cout << "list->at(1) = " << list->at(1) << endl;
    cout << "contains(55) = " << list->contains(55) << endl;
    cout << "contains(4) = " << list->contains(4) << endl;
    list->erase(0);
    list->print();
    list->erase(5);
    list->print();
}
*/