#include <iostream>

using namespace std;

struct HDNode {
    int info;
    HDNode *next;
    HDNode *prev;
};
typedef HDNode HDNODE;

HDNODE *insertEnd(HDNODE *head, int val) {
    HDNODE *p = (HDNODE *)malloc(sizeof(HDNODE));
    p->info = val;
    p->next = NULL;
    p->prev = NULL;
    HDNODE *q = head;
    while(q->next != NULL) {
        q = q->next;
    }
    q->next = p;
    p->prev = q;
    head->info++;
    return head;
}

HDNODE *insertStart(HDNODE *head, int val) {
    HDNODE *p = (HDNODE *)malloc(sizeof(HDNODE));
    p->info = val;
    p->next = head->next;
    p->prev = head;
    if(head->next != NULL)
        head->next->prev = p;
    head->next = p;
    head->info++;
    return head;
}

HDNODE *insertAfter(HDNODE *head, int val, int key) {
    if(head->next == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    HDNODE *q=head->next;
    while(q->info!=key) {
        q = q->next;
        if(q == NULL) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    HDNODE *p = (HDNODE *)malloc(sizeof(HDNODE));
    p->info = val;
    p->next = q->next;
    if(q->next != NULL)
        q->next->prev = p;
    q->next = p;
    p->prev = q;
    head->info++;
    return head;
}

HDNODE *insertBefore(HDNODE *head, int val, int key) {
    if(head->next == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    HDNODE *q=head->next;
    while(q->info!=key) {
        q = q->next;
        if(q == NULL) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    HDNODE *p = (HDNODE *)malloc(sizeof(HDNODE));
    p->info = val;
    p->prev = q->prev;
    p->next = q;
    p->prev->next = p;
    q->prev = p;
    head->info++;
    return head;
}

HDNODE *deletion(HDNODE *head, int key, bool isFirst=false) {
    if(head->next == NULL) {
        cout<<"List is already empty."<<endl;
        return head;
    }
    if(key == -1) { //means we want to delete either first or last element of the list
        if(isFirst) {
            HDNODE *p = head->next;
            head->next = p->next;
            if(p->next != NULL)
                p->next->prev = head;
            free(p);
            head->info--;
            return head;
        } else {
            HDNODE *q = head;
            while(q->next != NULL) {
                q = q->next;
            }
            q->prev->next = q->next;
            free(q);
            head->info--;
            return head;
        }
    }
    HDNODE *q=head->next;
    while(q->info!=key) {
        q = q->next;
        if(q == NULL) {
            cout<<"Element not found, can't perform deletion."<<endl;
            return head;
        }
    }
    if(q->next != NULL)
        q->next->prev = q->prev;
    q->prev->next = q->next;
    free(q);
    head->info--;
    return head;
}

void display(HDNODE *head) {
    if(head->next == NULL) {
        cout<<"List is empty."<<endl;
        return ;
    }
    cout<<"header = "<<head->info<<", list = ";
    HDNODE *q = head->next;
    while(q!=NULL) {
        cout<<q->info<<" ";
        q = q->next;
    }
}

int main() {
    HDNODE *head = (HDNODE *)malloc(sizeof(HDNODE));
    head->next = head->prev = NULL;
    head->info = 0;
    int input,val,key;
    while(true) {
        cout<<"\nHeader stores the number of elements list has."<<endl;
        cout<<"1. Create a header doubly linked list."<<endl;
        cout<<"2. Insert an element at the start of the header doubly linked list."<<endl;
        cout<<"3. Insert an element at the end of the header doubly linked list."<<endl;
        cout<<"4. Insert an element before an existing element whose information is x in a header doubly linked list."<<endl;
        cout<<"5. Insert an element after an existing element whose information is x in a header doubly linked list."<<endl;
        cout<<"6. Delete the first element of the header doubly linked list."<<endl;
        cout<<"7. Delete the last element of the header doubly linked list."<<endl;
        cout<<"8. Delete the element whose information is x from a header doubly linked list."<<endl;
        cout<<"9. Display list."<<endl;
        cout<<"10. quit."<<endl;
        cout<<"Enter your choice: ";
        cin>>input;
        switch(input) {
            case 1:
                head->next = head->prev = NULL;
                head->info = 0;
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
