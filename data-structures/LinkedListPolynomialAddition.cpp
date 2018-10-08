#include<stdio.h>
#include<stdlib.h>


struct node{
  int info, degree;
  struct node *next;
};
typedef struct node NODE;

NODE *insert(NODE *head, int val, int _degree){
  NODE *p = (NODE *)malloc(sizeof(NODE *)), *q = head;
  p->info = val;
  p->degree = _degree;
  p->next = NULL;
  if(head == NULL)
    return p;
  while(q->next != NULL)
    q = q->next;
  q->next = p;
  return head;
}

NODE *ployadd(NODE *head1, NODE *head2){
  if(head1 == NULL)
    return head2;
  if(head2 == NULL)
    return head1;
  NODE *ans = NULL;
  NODE *p = head1,*q = head2;
  while(p!=NULL && q!=NULL){
    if(p->degree == q->degree){
      if((p->info + q->info) != 0)
        ans = insert(ans, p->info + q->info, p->degree);
      p = p->next;
      q = q->next;
    }
    else if(p->degree < q->degree){
      ans = insert(ans, p->info, p->degree);
      p = p->next;
    }
    else if(p->degree > q->degree){
      ans = insert(ans, q->info, q->degree);
      q = q->next;
    }
  }
  while(p != NULL){
      ans = insert(ans, p->info, p->degree);
      p = p->next;

  }
  while(q != NULL){
      ans = insert(ans, q->info, q->degree);
      q = q->next;
  }
  return ans;
}

void display(NODE *head){
  if(head==NULL){
    printf("List is empty\n");
    return;
  }
  NODE *p = head;
  while(p != NULL){
    printf("%dx^%d ",p->info, p->degree);
    p = p->next;
  }
  printf("\n");
}

int main()
{
  NODE *head1 = NULL, *head2 = NULL, *ans_head = NULL;
  int c,val,deg;
  while(1){
    printf("1. Insertion in first polynomial.\n");
    printf("2. Insertion in second polynomial.\n");
    printf("3. Display first polynomial.\n");
    printf("4. Display second polynomial.\n");
    printf("5. Add both polynomial.\n");
    printf("6. Display result.\n");
    printf("10. Quit.\n");
    printf("Enter your choice: ");
    scanf("%d",&c);
    switch(c){
      case 1:
      	printf("Enter integer to insert: ");
        scanf("%d",&val);
        printf("Enter degree to insert: ");
        scanf("%d",&deg);
      	head1 = insert(head1, val, deg);
      	break;
      case 2:
        printf("Enter integer to insert: ");
        scanf("%d",&val);
        printf("Enter degree to insert: ");
        scanf("%d",&deg);
        head2 = insert(head2, val, deg);
        break;
      case 3:
      	display(head1);
      	break;
      case 4:
      	display(head2);
      	break;
      case 5:
      	ans_head = ployadd(head1,head2);
        display(ans_head);
        break;
      case 6:
      	display(ans_head);
      	break;
      case 10:
        return 0;
      default:
        ;
    }
  }
}
