#include<stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node NODE;

void display(NODE *head) {
    if(head == NULL){
        printf("LIST IS EMPTY\n");
        return;
    }
    NODE *p = head;
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->next;
    }
}

NODE *merge(NODE *head1,NODE *head2) {
    NODE *head=NULL,*p=head1,*q=head2,*r=head;
    while(p!=NULL && q!=NULL){
        if(p->info < q->info){
            NODE *x = (NODE *)malloc(sizeof(NODE));
            x->info = p->info;
            x->next=NULL;
            if(r==NULL){
                head=x;
            }
            else{
                r->next=x;
            }
            r=x;
            p=p->next;
        }
        else if(p->info > q->info){
            NODE *x = (NODE *)malloc(sizeof(NODE));
            x->info = q->info;
            x->next=NULL;
            if(r==NULL){
                head=x;
            }
            else{
                r->next=x;
            }
            r=x;
            q=q->next;
        }
        else{
            NODE *x = (NODE *)malloc(sizeof(NODE));
            x->info = q->info;
            x->next=NULL;
            if(r==NULL){
                head=x;
            }
            else{
                r->next=x;
            }
            r=x;
            q=q->next;
            p=p->next;
        }
    }
    while(p!=NULL){
        NODE *x = (NODE *)malloc(sizeof(NODE));
        x->info = q->info;
        x->next=NULL;
        if(r==NULL){
            head=x;
        }
        else{
            r->next=x;
        }
        r=x;
        p=p->next;
    }
    while(q!=NULL){
        NODE *x = (NODE *)malloc(sizeof(NODE));
        x->info = q->info;
        x->next=NULL;
        if(r==NULL){
            head=x;
        }
        else{
            r->next=x;
        }
        r=x;
        q=q->next;
    }
    printf("List are merged\n");
    return head;
}

NODE *insertAfter(NODE *head, int x, int y) {
    NODE *p = head, *q;
    q = (NODE *) malloc(sizeof(NODE));
    q->info = y;
    if (x == -1 || head == NULL) {
        q->next = head;
        return q;
    }
    while (p != NULL && p->info != x)
        p = p->next;
    if (p == NULL) {
        printf("Element not found\n");
        return head;
    }
    q->next = p->next;
    p->next = q;
    return head;
}

NODE *delete(NODE *head, int x) {
    NODE *p = head;
    NODE *q = head;
    while (p != NULL && p->info != x) {
        q = p;
        p = p->next;
    }
    if (p != NULL) {
        if (head->info == x) {
            q = head;
            head = head->next;
            free(q);
            return head;
        }
        q->next = p->next;
        free(p);
    } else {
        printf("Element not found or List is empty");
    }
    return head;
}

int main() {
    NODE *head1 = NULL, *head2 = NULL, *head3 = NULL;
    int c = 0;
    int ele, tmp,no;
    while (1) {
        system("clear");
        printf("1. Insert an element after an existing element whose information is x in a linked list.\n");
        printf("2. Delete the element whose information is x from a linked list.\n");
        printf("3. Display the contents of the linked list.\n");
        printf("4. Merge two Linked Lists to list1.\n");
        printf("5. Display the contents of the merged linked list.\n");
        printf("6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter an element: ");
                scanf("%d", &ele);
                printf("Enter the list number to insert into: ");
                scanf("%d", &no);
                printf("Where to insert after: ");
                scanf("%d", &tmp);
                if(no==1){
                    head1 = insertAfter(head1, tmp, ele);
                }
                else{
                    head2 = insertAfter(head2, tmp, ele);
                }
                break;
            case 2:
                printf("Enter an element: ");
                scanf("%d", &ele);
                printf("Enter the list number to delete from: ");
                scanf("%d", &no);
                if(no==1){
                    head1 = delete(head1, ele);
                }
                else{
                    head2 = delete(head2, ele);
                }
                break;
            case 3:
                printf("Enter the list number to display: ");
                scanf("%d", &no);
                display(no==1?head1:head2);
                break;
            case 4:
                head3=merge(head1,head2);
                break;
            case 5:
                display(head3);
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
        getchar();
        getchar();
    }
    return 0;
}

