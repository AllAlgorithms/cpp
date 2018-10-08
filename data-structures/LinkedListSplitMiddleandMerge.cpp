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

NODE *merge(NODE *head){
	if(head==NULL){
		printf("List is empty\n");
		return head;
	}
	if(head->next==NULL){
		return head;
	}
	NODE *p=head,*q=head,*r,*s;
	while(p!=NULL && p->next!=NULL){
		printf("1\n");
		s=q;
		q=q->next;
		r=p->next;
		p=p->next->next;
	}
	printf("display\n");
	display(head);
	if(p==NULL){
		r->next=head;
	}else{
		p->next=head;
	}
	s->next=NULL;
	head=q;
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
	NODE *head = NULL;
	int c = 0;
	int ele, tmp;
	while (1) {
		system("clear");
		printf("1. Insert an element after an existing element whose information is x in a linked list.\n");
		printf("2. Delete the element whose information is x from a linked list.\n");
		printf("3. Display the contents of the linked list.\n");
		printf("4. To split the Linked List at the middle and merge the second half as the first half.\n");
		printf("5. Exit.\n");
		printf("Enter your choice: ");
		scanf("%d", &c);
		switch (c) {
			case 1:
			printf("Enter an element: ");
			scanf("%d", &ele);
			printf("Where to insert after: ");
			scanf("%d", &tmp);
			head = insertAfter(head, tmp, ele);
			break;
			case 2:
			printf("Enter an element: ");
			scanf("%d", &ele);
			head = delete(head, ele);
			break;
			case 3:
			display(head);
			break;
			case 4:
			head = merge(head);
			break;
			case 5:
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
