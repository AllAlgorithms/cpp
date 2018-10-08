#include <iostream>

using namespace std;

struct HCNode {
    int info;
    HCNode *next;
};
typedef HCNode HCNODE;

HCNODE *insert(HCNODE *head, int val, bool isStart) {
    HCNODE *p = (HCNODE *)malloc(sizeof(HCNODE));
    p->info = val;
    p->next = p;
    if(head->next == NULL) {
        head->next = p;
        head->info++;
        return head;
    }
    HCNODE *q = head->next;
    while(q->next != head->next) {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
    head->info++;
    if(isStart)
        head->next = p;
    return head;
}

HCNODE *insertAfter(HCNODE *head, int val, int key) {
    if(head->next == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    HCNODE *q=head->next;
    while(q->info!=key) {
        q = q->next;
        if(q == head->next) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    HCNODE *p = (HCNODE *)malloc(sizeof(HCNODE));
    p->info = val;
    p->next = q->next;
    q->next = p;
    head->info++;
    return head;
}

HCNODE *insertBefore(HCNODE *head, int val, int key) {
    if(head->next == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    HCNODE *q=head->next,*p=head->next;
    while(q->info!=key) {
        p = q;
        q = q->next;
        if(q == head->next) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    HCNODE *r = (HCNODE *)malloc(sizeof(HCNODE));
    r->info = val;
    if(p == q) {
        while (q->next != p)
            q = q->next;
        r->next = p;
        q->next = r;
        head->next = r;
    } else {
        r->next = q;
        p->next = r;
    }
    head->info++;
    return head;
}

HCNODE *deletion(HCNODE *head, int key, bool isFirst=false) {
    if(head->next == NULL) {
        cout<<"List is already empty."<<endl;
        return head;
    }
    if(key == -1) { //means we want to delete either first or last element of the list
        if(isFirst) {
            HCNODE *p = head->next,*q = head->next->next;
            if(p->next == p) {
                free(p);
                head->next = NULL;
                head->info--;
                return head;
            }
            while(q->next != p) {
                q = q->next;
            }
            head->next = p->next;
            q->next = p->next;
            free(p);
            head->info--;
            return head;
        } else {
            HCNODE *p = head->next,*q = head->next->next;
            if(p->next == p) {
                free(p);
                head->next = NULL;
                head->info--;
                return head;
            }
            while(q->next != head->next) {
                p = q;
                q = q->next;
            }
            p->next = q->next;
            free(q);
            head->info--;
            return head;
        }
    }
    HCNODE *q=head->next,*p=head->next;
    while(q->info!=key) {
        p = q;
        q = q->next;
        if(q == head->next) {
            cout<<"Element not found, can't perform deletion."<<endl;
            return head;
        }
    }
    if(p == q) {
        while(p->next != q)
            p = p->next;
        p->next = q->next;
        head->next->next = q->next;
    }
    p->next = q->next;
    free(q);
    head->info--;
    return head;
}

void display(HCNODE *head) {
    if(head->next == NULL) {
        cout<<"Header = "<<head->info<<", list is empty."<<endl;
        return ;
    }
    cout<<"Header = "<<head->info<<", List = ";
    HCNODE *q = head->next;
    do {
        cout<<q->info<<" ";
        q = q->next;
    }while(q!=head->next);
}

int main() {
    HCNODE *head = (HCNODE *)malloc(sizeof(HCNODE));
    head->info=0;
    head->next=NULL;
    int input,val,key;
    while(true) {
        cout<<"\nHeader stores the number of elements list has."<<endl;
        cout<<"1. Create a header circular linked list."<<endl;
        cout<<"2. Insert an element at the start of the header circular linked list."<<endl;
        cout<<"3. Insert an element at the end of the header circular linked list."<<endl;
        cout<<"4. Insert an element before an existing element whose information is x in a header circular linked list."<<endl;
        cout<<"5. Insert an element after an existing element whose information is x in a header circular linked list."<<endl;
        cout<<"6. Delete the first element of the header circular linked list."<<endl;
        cout<<"7. Delete the last element of the header circular linked list."<<endl;
        cout<<"8. Delete the element whose information is x from a header circular linked list."<<endl;
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
