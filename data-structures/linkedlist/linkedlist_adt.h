/*  
    @Gaurav YadavCS-11 Asn 2, linkedlist_adt.h
    Purpose: Implements Linkedlist class

    @author Gaurav Yadav
    @email gauravyug@gmai.com
    @version 1.1 
    @date 13-Oct-18 
*/

#ifndef ADT_LINKEDLIST_H_
#define ADT_LINKEDLIST_H_

/*
    Linked List Node
*/
class Node
{
    public:
        int data;
        Node* next;
    public:
        Node(int value);
};

class LinkedList
{
    private:
    Node* head;
    int length;
    public:
    LinkedList();
    ~LinkedList();
    int size() const;
    bool empty() const;
    void print() const;
    int& at(int index);
    Node* find(int value) const;
    bool contains(int value) const;
    void append(int value);
    void prepend(int value);
    void remove(Node* node_ptr); void erase(int index);
};
#endif