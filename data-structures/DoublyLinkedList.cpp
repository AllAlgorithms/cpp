#include <iostream>

using namespace std;

struct DNode {
    int info;
    DNode *next;
    DNode *prev;
};
typedef DNode DNODE;

DNODE *insertEnd(DNODE *head, int val) {
    DNODE *p = (DNODE *)malloc(sizeof(DNODE));
    p->info = val;
    p->next = NULL;
    p->prev = NULL;
    if(head == NULL) {
        head = p;
        return head;
    }
    DNODE *q = head;
    while(q->next != NULL) {
        q = q->next;
    }
    q->next = p;
    p->prev = q;
    return head;
}

DNODE *insertStart(DNODE *head, int val) {
    DNODE *p = (DNODE *)malloc(sizeof(DNODE));
    p->info = val;
    p->next = head;
    p->prev = NULL;
    head = p;
    return head;
}

DNODE *insertAfter(DNODE *head, int val, int key) {
    if(head == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    DNODE *q=head;
    while(q->info!=key) {
        q = q->next;
        if(q == NULL) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    DNODE *p = (DNODE *)malloc(sizeof(DNODE));
    p->info = val;
    p->next = q->next;
    if(q->next != NULL)
        q->next->prev = p;
    q->next = p;
    p->prev = q;
    return head;
}

DNODE *insertBefore(DNODE *head, int val, int key) {
    if(head == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    DNODE *q=head;
    while(q->info!=key) {
        q = q->next;
        if(q == NULL) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    DNODE *p = (DNODE *)malloc(sizeof(DNODE));
    p->info = val;
    p->next = q;
    p->prev = q->prev;
    q->prev = p;
    if(p->prev != NULL)
        p->prev->next = p;
    else
        head = p;
    return head;
}

DNODE *deletion(DNODE *head, int key, bool isFirst=false) {
    if(head == NULL) {
        cout<<"List is already empty."<<endl;
        return head;
    }
    if(key == -1) { //means we want to delete either first or last element of the list
        if(isFirst) {
            DNODE *p = head;
            head = head->next;
            if(head != NULL)
                head->prev = NULL;
            free(p);
            return head;
        } else {
            DNODE *q = head;
            while(q->next != NULL) {
                q = q->next;
            }
            if(q->prev != NULL)
                q->prev->next = q->next;
            free(q);
            return head;
        }
    }
    DNODE *q=head;
    while(q->info!=key) {
        q = q->next;
        if(q == NULL) {
            cout<<"Element not found, can't perform deletion."<<endl;
            return head;
        }
    }
    if(q->next != NULL)
        q->next->prev = q->prev;
    if(q->prev != NULL)
        q->prev->next = q->next;
    else
        head = q->next;
    q->next = q->prev = NULL;
    free(q);
    return head;
}

void display(DNODE *head) {
    if(head == NULL) {
        cout<<"List is empty."<<endl;
        return ;
    }
    cout<<"List = ";
    DNODE *q = head;
    while(q!=NULL) {
        cout<<q->info<<" ";
        q = q->next;
    }
}

int main() {
    DNODE *head = NULL;
    int input,val,key;
    while(true) {
        cout<<"\n1. Create a doubly linked list."<<endl;
        cout<<"2. Insert an element at the start of the doubly linked list."<<endl;
        cout<<"3. Insert an element at the end of the doubly linked list."<<endl;
        cout<<"4. Insert an element before an existing element whose information is x in a doubly linked list."<<endl;
        cout<<"5. Insert an element after an existing element whose information is x in a doubly linked list."<<endl;
        cout<<"6. Delete the first element of the doubly linked list."<<endl;
        cout<<"7. Delete the last element of the doubly linked list."<<endl;
        cout<<"8. Delete the element whose information is x from a doubly linked list."<<endl;
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
                head = insertStart(head,val);
                break;
            case 3:
                cout<<"Enter element to insert: ";
                cin>>val;
                head = insertEnd(head,val);
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
