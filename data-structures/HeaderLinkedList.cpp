#include <iostream>

using namespace std;

struct HNode {
    int info;
    HNode *next;
};
typedef HNode HNODE;

HNODE *insertEnd(HNODE *head, int val) {
    HNODE *p = (HNODE *)malloc(sizeof(HNODE));
    p->info = val;
    p->next = NULL;
    HNODE *q = head;
    while(q->next != NULL) {
        q = q->next;
    }
    q->next = p;
    head->info++;
    return head;
}

HNODE *insertStart(HNODE *head, int val) {
    HNODE *p = (HNODE *)malloc(sizeof(HNODE));
    p->info = val;
    p->next = head->next;
    head->next = p;
    head->info++;
    return head;
}

HNODE *insertAfter(HNODE *head, int val, int key) {
    if(head->next == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    HNODE *q=head->next;
    while(q->info!=key) {
        q = q->next;
        if(q == NULL) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    HNODE *p = (HNODE *)malloc(sizeof(HNODE));
    p->info = val;
    p->next = q->next;
    q->next = p;
    head->info++;
    return head;
}

HNODE *insertBefore(HNODE *head, int val, int key) {
    if(head->next == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    HNODE *q=head->next,*p=head;
    while(q->info!=key) {
        p = q;
        q = q->next;
        if(q == NULL) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    HNODE *r = (HNODE *)malloc(sizeof(HNODE));
    r->info = val;
    r->next = q;
    p->next = r;
    head->info++;
    return head;
}

HNODE *deletion(HNODE *head, int key, bool isFirst=false) {
    if(head->next == NULL) {
        cout<<"List is already empty."<<endl;
        return head;
    }
    if(key == -1) { //means we want to delete either first or last element of the list
        if(isFirst) {
            HNODE *p = head->next;
            head->next = p->next;
            free(p);
            head->info--;
            return head;
        } else {
            HNODE *q = head->next, *p = head;
            while(q->next != NULL) {
                p = q;
                q = q->next;
            }
            p->next = q->next;
            free(q);
            head->info--;
            return head;
        }
    }
    HNODE *q=head->next,*p=head;
    while(q->info!=key) {
        p = q;
        q = q->next;
        if(q == NULL) {
            cout<<"Element not found, can't perform deletion."<<endl;
            return head;
        }
    }
    p->next = q->next;
    free(q);
    head->info--;
    return head;
}

void display(HNODE *head) {
    if(head->next == NULL) {
        cout<<"Header = "<<head->info<<", list is empty."<<endl;
        return ;
    }
    cout<<"Header = "<<head->info<<", List = ";
    HNODE *q = head->next;
    do {
        cout<<q->info<<" ";
        q = q->next;
    }while(q!=NULL);
}

int main() {
    HNODE *head = (HNODE *)malloc(sizeof(HNODE));
    head->info=0;
    head->next=NULL;
    int input,val,key;
    while(true) {
        cout<<"\nHeader stores the number of elements list has."<<endl;
        cout<<"1. Create a header linked list."<<endl;
        cout<<"2. Insert an element at the start of the header linked list."<<endl;
        cout<<"3. Insert an element at the end of the header linked list."<<endl;
        cout<<"4. Insert an element before an existing element whose information is x in a header linked list."<<endl;
        cout<<"5. Insert an element after an existing element whose information is x in a header linked list."<<endl;
        cout<<"6. Delete the first element of the header linked list."<<endl;
        cout<<"7. Delete the last element of the header linked list."<<endl;
        cout<<"8. Delete the element whose information is x from a header linked list."<<endl;
        cout<<"9. Display list."<<endl;
        cout<<"10. quit."<<endl;
        cout<<"Enter your choice: ";
        cin>>input;
        switch(input) {
            case 1:
                head->info=0;
                head->next=NULL;
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
