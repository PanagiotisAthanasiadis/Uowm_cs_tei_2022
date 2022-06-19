#include <stdio.h>
#include <stdlib.h>

struct song
{
    int ss; //singer
    int cc; //composer
    int ll; //song writer
};

struct Node {
    struct song data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void push(struct Node** head_ref, struct song new_data)
{
    /* 1. allocate node */
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    /* 2. put in the data  */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head and previous as NULL
     */
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    /* 5. move the head to point to the new node */
    (*head_ref) = new_node;
}

void printList(struct Node* node)
{
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf("\n%d%d%d", node->data.ss,node->data.cc,node->data.ll);
        last = node;
        node = node->next;
    }
 
    /* printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }*/
}

int main()
{
    srand(4003);

    for(int i=0; i<1000; i++) //Initializing song list 
    {
        struct song val;
        val.ss = (rand() % (29 - 1 + 1)) + 1;
        val.cc = (rand() % (29 - 1 + 1)) + 1;
        val.ll = (rand() % (29 - 1 + 1)) + 1;
        push(&head, val);     
    }


    printList(head);
    struct Node* node = head;

    int r = (rand() % (1000 - 0 + 1)) + 0;

    for(int i=0; i<r; i++)
    {
        node = node->next;
    }


    for(int i=0; i<100; i++) //Playing 100 songs
    {
        printf("\nNow playing:%d%d%d", node->data.ss,node->data.cc,node->data.ll);
        if(node->next == NULL) { node =head;} //start from the begining
        r = rand() % 2; //Give a random direction of the list 
        if(r == 1)
        {   
            node = node->next;
        }
        else {
            node = node->prev;
        }    
    }

    int i=0;
    while( i<20)  //Playing the next 20 songs of valisi tsitsani
    {
        if(node->data.cc == 26)
        {
            printf("\nNow playing tsitsanis:%d%d%d", node->data.ss,node->data.cc,node->data.ll);
            i++;
        }
        if(node->next == NULL) { node =head;} //start from the begining
        node = node->next;
    }

   

    i=0;
    while( i<20)  //Playing the next 20 songs of lina
    {
        if(node->data.ll == 18)
        {
            printf("\nNow playing lina:%d%d%d", node->data.ss,node->data.cc,node->data.ll);
            i++;
        }
        if(node->next == NULL) { node =head;} //start from the begining
        node = node->next;
    }
    

    for(int i=0; i<200; i++) //Adding 200 songs to  song list 
    {
        struct song val;
        val.ss = (rand() % (29 - 1 + 1)) + 1;
        val.cc = (rand() % (29 - 1 + 1)) + 1;
        val.ll = (rand() % (29 - 1 + 1)) + 1;
        push(&head, val);     
    }
    



}