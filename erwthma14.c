#include <stdio.h>
#include <stdlib.h>


struct node
{
    int priority;
    int info; //pid
    int arrival_time; //In seconds
    int service_time; //In seconds
    struct node *next;
}*start=NULL,*q,*temp,*new;

typedef struct node N;

int insert(int arrival,int service) //returns priority
{
int itprio;
static int item = 0;
new=(N*)malloc(sizeof(N));
item++; //Every patient get an arrival number
itprio = (rand() % (100 - 1 + 1)) + 1; //priority 1-100
new->info=item;
new->priority=itprio;
new->arrival_time =arrival;
new->service_time = service + 100 + 10 * new->priority;
new->next=NULL;
if(start==NULL )
{
//new->next=start;
start=new;
}
else if(start!=NULL&&itprio>=start->priority)
{  new->next=start;
start=new;
}
else
{
q=start;
while(q->next != NULL && q->next->priority>=itprio)
{q=q->next;}
new->next=q->next;
q->next=new;
}
return new->priority;
}

void del()
{
if(start==NULL)
{
printf("\nQUEUE UNDERFLOW\n");
 
}
else
{
new=start;
printf("\nDELETED ITEM IS %d\n",new->info);
start=start->next;
//free(start);
}
}

void display()
{

temp=start;
if(start==NULL)
    printf("QUEUE IS EMPTY\n");
else
{
    printf("QUEUE IS:\n");
    if(temp!=NULL)
    for(temp=start;temp!=NULL;temp=temp->next)
    {
        printf("\npid:%d priority =%d arrival:%d  mins service:%d mins\n",temp->info,temp->priority,temp->arrival_time / 60,temp->service_time /60);
        //temp=temp->next;
    }
}

}

int main()
{
    srand(4003);
    int real_time=0;
    for(int i=0; i<20; i++)//first 20 patients
    {
        insert(0,1);
    }

    for(int i=1; i<=48; i++) //The total number of patients in the span of 12 hours is 48 if the rate is 4/hr
    {
        insert(i*15 * 60,1);
    }
    temp=start;
    if(start==NULL)
        printf("QUEUE IS EMPTY\n");
    else
    {
    if(temp!=NULL)
    for(temp=start;temp!=NULL;temp=temp->next)
    {
        real_time +=100+10*temp->priority;
        printf("\nReal time:%d",real_time);
        temp->service_time = abs(real_time - temp->arrival_time );
    }
}

    display();


}