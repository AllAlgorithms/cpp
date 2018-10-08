#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define chunk 4

struct node {
    int info;
    struct node *next;
};
typedef struct node NODE;

NODE *insert(NODE *head, int val) {
    NODE *p = (NODE *) malloc(sizeof(NODE *)), *q = head;
    p->info = val;
    p->next = NULL;
    if (head == NULL)
        return p;
    while (q->next != NULL)
        q = q->next;
    q->next = p;
    return head;
}

NODE *addList(NODE *head1, NODE *head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    NODE *head = NULL;
    int carry = 0;
    while(head1!=NULL && head2!=NULL){
        head = insert(head,((carry + head1->info + head2->info)%10000));
        carry = (head1->info + head2->info) / 10000;
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1!=NULL){
        head = insert(head, ((head1->info+carry)%10000));
        carry = (head1->info+carry)/10000;
        head1 = head1->next;
    }
    while(head2!=NULL) {
        head = insert(head, ((head2->info+carry)%10000));
        carry = (head2->info+carry)/10000;
        head2 = head2->next;
    }
    if(carry!=0){
        head = insert(head, carry);
    }
    return head;
}

NODE *add(char *str1, char *str2) {
    NODE *head1 = NULL, *head2 = NULL;
    int str1_len = 0, str2_len = 0, temp, i, j, count = chunk, number;

    for (str1_len = 0; *(str1 + str1_len) != '\0'; str1_len++);
    printf("%d\n", str1_len);

    for (str2_len = 0; *(str2 + str2_len) != '\0'; str2_len++);
    printf("%d\n", str2_len);

    for (i = str1_len - 1; i >= -1; i--, count--) {
        if (count == 0 || i == -1) {
            count = chunk;
            head1 = insert(head1, number);
            number = 0;
            if(i == -1)
                continue;
        }
        number = number * 10 + (*(str1 + i)-0x30);
    }
    count = chunk;
    for (j = str2_len - 1; j >= -1; j--, count--) {
        if (count == 0 || j == -1) {
            count = chunk;
            head2 = insert(head2, number);
            number = 0;
            if(i == -1)
                continue;
        }
        number = number * 10 + (*(str2 + j)-0x30);
    }
    return addList(head1,head2);
}

void display(NODE *head) {
    if (head == NULL) {
        return;
    }
    NODE *p = head;
    display(head->next);
    printf("%d",head->info);
}

int main() {
    NODE *head = NULL;
    char str1[1000], str2[1000], temp;
    int c, counter = 0, i;
    while (1) {
        printf("1. Enter first number.\n");
        printf("2. Enter second number.\n");
        printf("3. Add them.\n");
        printf("4. Show result.\n");
        printf("10. Quit.\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter length of number: ");
                scanf("%d\n", &counter);
                for (i = 0; i < counter; i++) {
                    scanf("%c", &str1[i]);
                }
                str1[i] = '\0';
                break;
            case 2:
                printf("Enter length of number: ");
                scanf("%d\n", &counter);
                for (i = 0; i < counter; i++) {
                    scanf("%c", &str2[i]);
                }
                str2[i] = '\0';
                break;
            case 3:
                head = add(str1, str2);
                break;
            case 4:
                display(head);
                printf("\n");
                break;
            case 10:
                return 0;
            default:;
        }
    }
}
