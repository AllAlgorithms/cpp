#include <iostream>

using namespace std;

struct CNode {
    int info;
    CNode *next;
};
typedef CNode CNODE;

CNODE *insert(CNODE *head, int val, bool isStart) {
    CNODE *p = (CNODE *)malloc(sizeof(CNODE));
    p->info = val;
    p->next = p;
    if(head == NULL) {
        head = p;
        return head;
    }
    CNODE *q = head;
    while(q->next != head) {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
    if(isStart)
        head = p;
    return head;
}

CNODE *insertAfter(CNODE *head, int val, int key) {
    if(head == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    CNODE *q=head;
    while(q->info!=key) {
        q = q->next;
        if(q == head) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    CNODE *p = (CNODE *)malloc(sizeof(CNODE));
    p->info = val;
    p->next = q->next;
    q->next = p;
    return head;
}

CNODE *insertBefore(CNODE *head, int val, int key) {
    if(head == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    if(head->next == head && head->info == key) {
        CNODE *p = (CNODE *)malloc(sizeof(CNODE));
        p->info = val;
        p->next = head;
        head->next = p;
        return head;
    }
    CNODE *q=head,*p=head;
    while(q->info!=key) {
        p = q;
        q = q->next;
        if(q == head) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    CNODE *r = (CNODE *)malloc(sizeof(CNODE));
    r->info = val;
    if(q == head) {
        while(q->next != head)
            q = q->next;
        r->next = head;
        q->next = r;
        return r;
    }
    r->next = q;
    p->next = r;
    return head;
}

CNODE *deletion(CNODE *head, int key, bool isFirst=false) {
    if(head == NULL) {
        cout<<"List is already empty."<<endl;
        return head;
    }
    if(key == -1) { //means we want to delete either first or last element of the list
        if (head->next == head) {
            free(head);
            return NULL;
        }
        if (isFirst) {
            CNODE *q = head, *p;
            while (q->next != head)
                q = q->next;
            p = head;
            head = head->next;
            q->next = head;
            free(p);
            return head;
        } else {
            CNODE *q = head, *p = head;
            while (q->next->next != head)
                q = q->next;
            p = q->next;
            q->next = head;
            free(p);
            return head;
        }
    }
    CNODE *q=head,*p=head;
    if(head->next == head && head->info == key) {
        free(head);
        return NULL;
    }
    while(q->info!=key) {
        p = q;
        q = q->next;
        if(q == head) {
            cout<<"Element not found, can't perform deletion."<<endl;
            return head;
        }
    }
    if(p == q) {
        while(p->next != head)
            p = p->next;
        p->next = q->next;
        head = q->next;
        free(q);
        return head;
    }
    p->next = q->next;
    free(q);
    return head;
}

void display(CNODE *head) {
    if(head == NULL) {
        cout<<"list is empty."<<endl;
        return ;
    }
    CNODE *q = head;
    do {
        cout<<q->info<<" ";
        q = q->next;
    }while(q!=head);
}

int main() {
    CNODE *head = NULL;
    int input,val,key;
    while(true) {
        cout<<"\n1. Create a circular linked list."<<endl;
        cout<<"2. Insert an element at the start of the circular linked list."<<endl;
        cout<<"3. Insert an element at the end of the circular linked list."<<endl;
        cout<<"4. Insert an element before an existing element whose information is x in a circular linked list."<<endl;
        cout<<"5. Insert an element after an existing element whose information is x in a circular linked list."<<endl;
        cout<<"6. Delete the first element of the circular linked list."<<endl;
        cout<<"7. Delete the last element of the circular linked list."<<endl;
        cout<<"8. Delete the element whose information is x from a circular linked list."<<endl;
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
