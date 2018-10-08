#include<stdio.h>
#include <stdlib.h>
struct node {
	int info;
	struct node *next;
};
typedef struct node NODE;

void display(NODE *head) {
	if(head == NULL){
		printf("Stack is empty\n");
	}
	NODE *p = head;
	while (p != NULL) {
		printf("%d ", p->info);
		p = p->next;
	}
}
NODE *insertStart(NODE *head, int y) {
	NODE *q;
	q = (NODE *) malloc(sizeof(NODE));
	q->info = y;
	q->next = head;
	return q;
}

NODE *deleteStart(NODE *head) {
	if (head == NULL) {
		printf("Stack is empty");
		return NULL;
	}
	NODE *p = head;
	head = head->next;
	printf("Delete element is: %d\n",p->info);
	free(p);
	return head;

}

int main() {
	NODE *head=NULL;
	int c = 0;
	int ele, tmp;

	while (1) {
		system("clear");
		printf("1. Insert an element in Stack.\n");
		printf("2. Delete an element from Stack.\n");
		printf("3. Display the elements of Stack.\n");
		printf("4. Exit.\n");
		printf("Enter your choice: ");
		scanf("%d", &c);
		switch (c) {
			case 1:
				printf("Enter a element to insert:");
				scanf("%d",&tmp);
				head=insertStart(head,tmp);
			break;
			
			case 2:
				head=deleteStart(head);
			break;
			
			case 3:
				display(head);
			break;
			
			case 4:
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
