#include <iostream>

using namespace std;

struct HCDNode {
    int info;
    HCDNode *next;
    HCDNode *prev;
};
typedef HCDNode HCDNODE;

HCDNODE *insert(HCDNODE *head, int val, bool isStart) {
    HCDNODE *p = (HCDNODE *)malloc(sizeof(HCDNODE));
    p->info = val;
    p->next = p;
    p->prev = p;
    if(head->next == NULL) {
        head->next = p;
        head->info++;
        return head;
    }
    HCDNODE *q = head->next;
    p->next = q;
    p->prev = q->prev;
    p->prev->next = p;
    q->prev = p;
    if(isStart)
        head->next = head->next->prev;
    head->info++;
    return head;
}

HCDNODE *insertAfter(HCDNODE *head, int val, int key) {
    if(head->next == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    HCDNODE *q=head->next;
    while(q->info!=key) {
        q = q->next;
        if(q == head->next) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    HCDNODE *p = (HCDNODE *)malloc(sizeof(HCDNODE));
    p->info = val;
    p->prev = q;
    p->next = q->next;
    p->next->prev = p;
    q->next = p;
    head->info++;
    return head;
}

HCDNODE *insertBefore(HCDNODE *head, int val, int key) {
    if(head->next == NULL) {
        cout<<"List is already empty, can't perform insertion."<<endl;
        return head;
    }
    HCDNODE *q=head->next;
    while(q->info!=key) {
        q = q->next;
        if(q == head->next) {
            cout<<"key "<<key<<" not found, can't perform insertion."<<endl;
            return head;
        }
    }
    HCDNODE *p = (HCDNODE *)malloc(sizeof(HCDNODE));
    p->info = val;
    p->prev = q->prev;
    p->next = q;
    p->prev->next = p;
    q->prev = p;
    if(q == head->next)
        head->next = p;
    head->info++;
    return head;
}

HCDNODE *deletion(HCDNODE *head, int key, bool isFirst=false) {
    if(head->next == NULL) {
        cout<<"List is already empty."<<endl;
        return head;
    }
    if(key == -1) { //means we want to delete either first or last element of the list
        if(head->next->next == head->next) {
            free(head->next);
            head->next = NULL;
            head->info--;
            return head;
        }
        if(isFirst) {
            HCDNODE *p = head->next;
            head->next->prev->next = head->next->next;
            head->next->next->prev = head->next->prev;
            head->next = head->next->next;
            free(p);
            head->info--;
            return head;
        } else {
            HCDNODE *q = head->next->prev;
            q->prev->next = q->next;
            q->next->prev = q->prev;
            free(q);
            head->info--;
            return head;
        }
    }
    HCDNODE *q=head->next;
    while(q->info!=key) {
        q = q->next;
        if(q == head->next) {
            cout<<"Element not found, can't perform deletion."<<endl;
            return head;
        }
    }
    if(q->next == q) {
        free(q);
        head->next = NULL;
        head->info--;
        return head;
    }
    q->prev->next = q->next;
    q->next->prev = q->prev;
    if(q==head->next)
        head = q->next;
    free(q);
    head->info--;
    return head;
}

void display(HCDNODE *head) {
    if(head->next == NULL) {
        cout<<"List is empty."<<endl;
        return ;
    }
    cout<<"Header = "<<head->info<<", List = ";
    HCDNODE *q = head->next;
    do {
        cout<<q->info<<" ";
        q = q->next;
    }while(q!=head->next);
}

int main() {
    HCDNODE *head = (HCDNODE *)malloc(sizeof(HCDNODE));
    head->info = 0;
    head->next = head->prev = NULL;
    int input,val,key;
    while(true) {
        cout<<"\n1. Create a header circular doubly linked list."<<endl;
        cout<<"2. Insert an element at the start of the header circular doubly linked list."<<endl;
        cout<<"3. Insert an element at the end of the header circular doubly linked list."<<endl;
        cout<<"4. Insert an element before an existing element whose information is x in a header circular doubly linked list."<<endl;
        cout<<"5. Insert an element after an existing element whose information is x in a header circular doubly linked list."<<endl;
        cout<<"6. Delete the first element of the header circular doubly linked list."<<endl;
        cout<<"7. Delete the last element of the header circular doubly linked list."<<endl;
        cout<<"8. Delete the element whose information is x from a header circular doubly linked list."<<endl;
        cout<<"9. Display list."<<endl;
        cout<<"10. quit."<<endl;
        cout<<"Enter your choice: ";
        cin>>input;
        switch(input) {
            case 1:
                head->info = 0;
                head->next = head->prev = NULL;
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
