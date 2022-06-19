#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define total_capacity 10


struct customer
{
    unsigned short int pid;
    unsigned short int products;
};

struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct customer *array;
};

struct Queue* createQueue()
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = total_capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = total_capacity - 1;
    queue->array = (struct customer*)malloc(
        queue->capacity * sizeof(struct customer));
    return queue;
}


int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity); //des edw ama theli bool
}

int isEmpty(struct Queue* queue)
{
    return (queue->size == 0); //des edw ama theli bool
}

void enqueue(struct Queue* queue, struct customer item)
{
    if (isFull(queue))
    {
        printf("Cannot add anymore items");
        return;
    }
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    //printf("%d enqueued to queue\n", item);
}

struct customer dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        struct customer empty = {-1,-1}; //return an object with illegal values 
        return empty;
    }    
    struct customer item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

struct customer front(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        struct customer empty = {-1,-1}; //return an object with illegal values 
        return empty;
    }    
    return queue->array[queue->front];
}

struct customer rear(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        struct customer empty = {-1,-1}; //return an object with illegal values 
        return empty;
    }    
    return queue->array[queue->rear];
}


int main()
{
    srand(4003);
    struct Queue* queue= createQueue();
    struct Queue* queue1= createQueue();
    struct Queue* queue2= createQueue();//Create 3 queues
    unsigned short int dice = (rand() % (6 - 1 + 1)) + 1; //dice
    unsigned short int total_customers =0;
    
    //printf("%d %d %d",queue->size,queue1->size,queue2->size);

    /*if(queue->size == queue1->size && queue1->size  == queue2->size)
    {
        printf("it works");
    } */

    
    while (total_customers <60) //End the program if 60 customers have been serviced
    { 
        printf("\n In the first queue are waiting:%d",queue->size);
        printf("\n In the second queue are waiting:%d",queue1->size);
        printf("\n In the thrid queue are waiting:%d",queue2->size);
        printf("\nTotal Customers that have serviced :%d",total_customers);
        dice = (rand() % (6 - 1 + 1)) + 1; //roll the dice
        if(dice < 3)
        {
            struct customer val;
            val.pid = (rand() % (9999 - 1000 + 1)) + 1000;
            val.products = (rand() % (17 - 2 + 1)) + 2;
            if (queue->size == queue1->size && queue1->size  == queue2->size)
            { //if queues have the same size
                int r = (rand() % (3 - 1 + 1)) + 1;
                switch (r) {
                    case 1:
                        enqueue(queue, val);
                        break;
                    case 2:
                        enqueue(queue1, val);
                        break;
                    case 3:
                        enqueue(queue2, val);
                        break;  
                    default:
                        printf("Error in r");
                        break;         
                }

            }
            else { //find the queue with the min size 
                if(queue->size < queue1->size && queue->size < queue2->size)
                {
                    enqueue(queue, val);
                }
                else if (queue1->size < queue->size && queue1->size < queue2->size) {
                    enqueue(queue1, val);
                }
                else if (queue2->size < queue1->size && queue2->size < queue->size)
                {
                    enqueue(queue2, val);
                }
            }
        }
        else if(dice > 2) //Service customer 
        {
            queue->array[queue->front].products -= 3; //First cashier
            if(queue->array[queue->front].products <= 0)
            {
                dequeue(queue);
                total_customers++;
            }

            queue1->array[queue1->front].products -= 3; //Second Cashier
            if(queue1->array[queue1->front].products <= 0)
            {
                dequeue(queue1);
                total_customers++;
            }

            queue2->array[queue2->front].products -= 3; //Thrird Cashier
            if(queue2->array[queue2->front].products <= 0)
            {
                dequeue(queue2);
                total_customers++;
            }
        }


        
    }
    
    
    


}