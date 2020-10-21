// Stack is a data structure based on the "last in, first out" (LIFO) method
// This code implements stack functions using linked list

#include <cstdio>
#include <cstdlib>

void pop(bool print);
void push();
void display();

struct node {
  int value;
  struct node *prev;
};
node* DUMMY = NULL;
node* top = NULL;

void push() {
        int n;
        node* ptr = (node*)malloc(sizeof(node));
        if (!ptr) {
                printf("\nStack Overflow");
                return;
        }
        printf("\nEnter the number to be pushed:\t");
        scanf("%d", &n);
        ptr->value = n;
        ptr->prev = top;
        top = ptr;
        printf("\nElement pushed successfully");
}

void pop(bool print) {
        node* ptr = top;
        if(!top || top==DUMMY) {
                if(print)
                        printf("\nStack Underflow");
                return;
        }
        top = top->prev;
        free(ptr);
        if(print)
                printf("\nElement popped successfully");
}

void display() {
        node* ptr = top;
        printf("\n");
        if(!top || top==DUMMY) {
                printf("\nThe stack is Empty");
                return;
        }
        printf("Top: ");
        while(ptr && ptr!=DUMMY) {
                printf("%d", ptr->value);
                if(ptr->prev!=DUMMY) {
                        printf(" <- ");
                }
                ptr = ptr->prev;
        }
}

void freeAll() {
        while(top!=DUMMY) {
                pop(false);
        }
}

int main() {
        DUMMY = (node *)malloc(sizeof(node));
        DUMMY->prev = NULL;
        top = DUMMY;
        int choice;
        bool EXIT = false;
        do {
                printf("\n\n*****Operations*****");
                printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
                printf("\nEnter your choice number:\t");
                scanf("%d", &choice);
                switch(choice) {
                        case 1: push();
                                break;
                        case 2: pop(true);
                                break;
                        case 3: display();
                                break;
                        case 4: freeAll();
                                EXIT = true;
                                break;
                        default: printf("\nInvalid choice, Try entering again");
                }
        } while(!EXIT);
}
