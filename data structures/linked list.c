#include <stdio.h>
#include <stdlib.h>

struct SLLNode{
	int data;
	struct SLLNode *next;
};

struct DLLNode{
	int data;
	struct DLLNode *prev;
	struct DLLNode *next;
};

typedef struct DLLNode DLL_NODE;
typedef struct SLLNode SLL_NODE;

 SLL_NODE* makeNewSLLNode(int data){
	SLL_NODE *newSLLNode = (SLL_NODE *) calloc(1, sizeof(SLL_NODE));
	newSLLNode->data = data;
	return newSLLNode;
}

void SLLInsert(SLL_NODE **head, int data, int position){
	SLL_NODE *current = *head;
	int k = 1;
	
	SLL_NODE *newSLLNode = makeNewSLLNode(data);
	if(position == 1){
		newSLLNode->next = current;
		(*head) = newSLLNode;
		return;
	}
	
	while((k < position - 1) && (current->next !=NULL)){
		current = current->next;
		k++;
	}
	
	newSLLNode->next = current->next;
	current->next = newSLLNode;
	
}

void SLLDelete(SLL_NODE **head, int position){
	SLL_NODE *temp = *head;
	int k = 1;
	
	SLL_NODE *temp2;
	
	if(position == 1){
		(*head) = (*head)->next;
		free(temp);
		return;
	}
	
	while((k < position) && (temp != NULL)){
		temp2 = temp;
		temp = temp->next;
		k++;
	}
	
	temp2->next = temp->next;
	free(temp);
	
}

void deleteSingleLinkedList(SLL_NODE **head){
	SLL_NODE *current = *head;
	while(current != NULL){
		(*head) = (*head)->next;
		free(current);
		current = *head;
	}
}

void displaySLL(SLL_NODE *head){
	SLL_NODE* curr = head;
	printf("\nPrinting the list : ");
	while(curr != NULL){
		printf("%d -> ", curr->data);
		curr = curr->next;
	}
}

DLL_NODE* makeNewDLLNode(int data){
	DLL_NODE *newNode = (DLL_NODE*) calloc(1, sizeof(DLL_NODE*));
	newNode->data = data;
	return newNode;
}

void DLLInsert(DLL_NODE **head, int data , int position){
	DLL_NODE* newNode = makeNewDLLNode(data);
	DLL_NODE* temp = *head;
	
	int k = 1;
	if(position == 1){
		newNode->prev = NULL;
		newNode->next = *head;
		*head = newNode;	
		return;	
	}
	
	while((k < position - 1) && (temp->next != NULL)){
		temp = temp->next;
		k++;
	}
	
	newNode->next = temp->next;
	newNode->prev = temp;
	if(temp->next){
		temp->next->prev = newNode;
	}
	
	temp->next = newNode;

}

void DLLDelete(DLL_NODE **head, int position){
	DLL_NODE *temp = *head;
	DLL_NODE *temp2;
	
	int k = 1;
	
	 if(*head == NULL){
	 	printf("Empty List");
	 	return;
	 }
	 
	 if(position == 1){
	 	temp = *head;
	 	(*head) = (*head)->next;
	 	free(temp);
	 	return;
	 }
	 
	 while((k < position) && (temp->next != NULL)){
	 	temp = temp->next;
	 	k++;
	 }
	 
	 temp2 = temp->prev;
	 temp->next->prev = temp2;
	 temp2->next = temp->next;
	 free(temp);
	 return; 
	 
}

void displayDLL(DLL_NODE* head){
	DLL_NODE* current = head;
	printf("\n");
	while(current != NULL){
		printf("%d -> ", current->data);
		current = current->next;
	}
}

void singlyLinkedList() {
	SLL_NODE *head = NULL;
	SLLInsert(&head, 7, 1);
	SLLInsert(&head, 6, 1); 
	SLLInsert(&head, 5, 1);
	SLLInsert(&head, 4, 1);
	SLLInsert(&head, 3, 1);
	SLLInsert(&head, 1, 1);
	SLLInsert(&head, 2, 2);
	displaySLL(head);
	
	SLLDelete(&head, 4);
	displaySLL(head);
}

void doublyLinkedList() {
	DLL_NODE* head = NULL;
	DLLInsert(&head, 7, 1);
	DLLInsert(&head, 6, 1);
	DLLInsert(&head, 4, 1);
	DLLInsert(&head, 5, 2);
	DLLInsert(&head, 1, 3);
	DLLInsert(&head, 2, 4);
	DLLInsert(&head, 3, 5);
	displayDLL(head);
	DLLDelete(&head, 3);
	displayDLL(head);
}

int main()
{
    int a;

    printf("Choose the type of list: ");
    printf("\n1. Singly linked list\n2. Doubly linked list\n");
    printf("Your choice:  ");
    scanf("%d", &a);
    switch (a)
    {
      case 1:
           singlyLinkedList();
          break;
      case 2:
          doublyLinkedList();
          break;
      default:
          printf("Invalid choice !!!");
          break;
    }

    return 0;
}