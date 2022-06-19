#include <stdio.h>
#include <stdlib.h>

struct data
{
    int a;
    int i;
};

struct node {
   struct data value;
   
   struct node *next;
};

struct node *head = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;

void insertFirst(struct data value,struct node** head_ref) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   
   link->value = value; //Mporei na mhn douleuei
	
   //point it to old first node
   link->next = *head_ref;
	
   //point first to new first node
   *head_ref = link;
}

void printList(int n,struct node** head_ref) {
   struct node *ptr = *head_ref;
   printf("\nP%d(x)=%d",n,ptr->value.a);
   //start from the beginning
   ptr = ptr->next; //skip the first
   while(ptr != NULL) {
      if(ptr->value.a >=0) {printf("+");}
      printf("%dx%d",ptr->value.a,ptr->value.i);
      ptr = ptr->next;
   }
	
   
}

void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}



int main()
{
    srand(4003);
    int n = (rand() % (7 - 4 + 1)) + 4; //range 4 to 7 
    for(int i=0; i<n; i++) //initialize first
    {
        struct data val;
        val.a = (rand() % (20 - (-20 + 1))) + -20;
        val.i= i;
        insertFirst(val,&head);
    }
    reverse(&head); //reverse to get the order 
    printList(n,&head);
    for(int i=0; i<n; i++) //initialize second
    {
        struct data val;
        val.a = (rand() % (20 - (-20 + 1))) + -20;
        val.i= i;
        insertFirst(val,&head2);
    }
    reverse(&head2); //reverse to get the order 
    printList(n,&head2);
    
    struct node *ptr1= head;
    struct node *ptr2= head2;
    while(ptr1 != NULL && ptr2 != NULL)
    {
       struct data val;
       //printf("\n1val:%d 2val:%d",ptr1->value.a,ptr2->value.a);
       val.a = ptr1->value.a + ptr2->value.a;
       //printf("\n%d",val.a);
       val.i = ptr1->value.i;
       insertFirst(val, &head3);
       ptr1 = ptr1->next;
       ptr2 = ptr2 -> next;
    }


    reverse(&head3); //reverse to get the order 
    printList(n,&head3);
   

}