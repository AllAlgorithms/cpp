#include <iostream>

using namespace std;

struct CDNode {
    int info;
    CDNode *next;
    CDNode *prev;
};
typedef CDNode CDNODE;

CDNODE *insert(CDNODE *head, int val, bool isStart) {
    CDNODE *p = (CDNODE *)malloc(sizeof(CDNODE));
    p->info = val;
    p->next = p;
    p->prev = p;
    if(head == NULL) {
        head = p;
        return head;
    }
    p->prev = head->prev;
    p->next = head;
    p->prev->next = p;
    head->prev= p;
    if(isStart)
        head = head->prev;
    return head;
}

CDNODE *insertAfter(CDNODE *head, int val, int key) {
    if(head == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    CDNODE *q=head;
    while(q->info!=key) {
        q = q->next;
        if(q == head) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    CDNODE *p = (CDNODE *)malloc(sizeof(CDNODE));
    p->info = val;
    p->prev = q;
    p->next = q->next;
    p->next->prev = p;
    q->next = p;
    return head;
}

CDNODE *insertBefore(CDNODE *head, int val, int key) {
    if(head == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    CDNODE *q=head;
    while(q->info!=key) {
        q = q->next;
        if(q == head) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    CDNODE *p = (CDNODE *)malloc(sizeof(CDNODE));
    p->info = val;
    p->prev = q->prev;
    p->next = q;
    p->prev->next = p;
    q->prev = p;
    return head;
}

CDNODE *deletion(CDNODE *head, int key, bool isFirst=false) {
    if(head == NULL) {
        cout<<"List is already empty."<<endl;
        return head;
    }
    if(key == -1) { //means we want to delete either first or last element of the list
        if(head->next == head) {
            free(head);
            return NULL;
        }
        if(isFirst) {
            CDNODE *p = head;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            p->next = p->prev = NULL;
            free(p);
            return head;
        } else {
            CDNODE *q = head->prev;
            q->prev->next = head;
            head->prev = q->prev;
            free(q);
            return head;
        }
    }
    CDNODE *q=head;
    while(q->info!=key) {
        q = q->next;
        if(q == head) {
            cout<<"Element not found, can't perform deletion."<<endl;
            return head;
        }
    }
    if(q->next == q) {
        free(q);
        return NULL;
    }
    q->prev->next = q->next;
    q->next->prev = q->prev;
    if(q==head)
        head = q->next;
    free(q);
    return head;
}

void display(CDNODE *head) {
    if(head == NULL) {
        cout<<"List is empty."<<endl;
        return ;
    }
    cout<<"List = ";
    CDNODE *q = head;
    do {
        cout<<q->info<<" ";
        q = q->next;
    }while(q!=head);
}

int main() {
    CDNODE *head = NULL;
    int input,val,key;
    while(true) {
        cout<<"\n1. Create a circular doubly linked list."<<endl;
        cout<<"2. Insert an element at the start of the circular doubly linked list."<<endl;
        cout<<"3. Insert an element at the end of the circular doubly linked list."<<endl;
        cout<<"4. Insert an element before an existing element whose information is x in a circular doubly linked list."<<endl;
        cout<<"5. Insert an element after an existing element whose information is x in a circular doubly linked list."<<endl;
        cout<<"6. Delete the first element of the circular doubly linked list."<<endl;
        cout<<"7. Delete the last element of the circular doubly linked list."<<endl;
        cout<<"8. Delete the element whose information is x from a circular doubly linked list."<<endl;
        cout<<"9. Display list."<<endl;
        cout<<"10. quit."<<endl;
        cout<<"Enter your choice: ";
        cin>>input;
        switch(input) {
            case 1:
                head = NULL;
                cout<<"New list is created."<<endl;
                break;
            case 2:
                cout<<"Enter element to insert: ";
                cin>>val;
                head = insert(head,val,true);
                break;
            case 3:
                cout<<"Enter element to insert: ";
                cin>>val;
                head = insert(head,val,false);
                break;
            case 4:
                cout<<"Enter element to insert: ";
                cin>>val;
                cout<<"Enter key before you want to insert: ";
                cin>>key;
                head = insertBefore(head,val,key);
                break;
            case 5:
                cout<<"Enter element to insert: ";
                cin>>val;
                cout<<"Enter key after you want to insert: ";
                cin>>key;
                head = insertAfter(head,val,key);
                break;
            case 6:
                cout<<"Action performed"<<endl;
                head = deletion(head,-1,true);
                break;
            case 7:
                cout<<"Action performed"<<endl;
                head = deletion(head,-1,false);
                break;
            case 8:
                cout<<"Enter key which you want to delete: ";
                cin>>key;
                head = deletion(head,key);
                break;
            case 9:
                display(head);
                break;
            case 10:
                return 0;
            default:
                cout<<"Enter number in between 1 to 10."<<endl;
        }
    }
}
