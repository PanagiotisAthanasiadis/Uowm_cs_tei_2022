#include <stdio.h>
#include <stdlib.h>


struct graph
{
    int **array;
    int n;
};


void graph_init(struct graph *l,int n)
{
    l->n = n;
    l->array = (int**)malloc(sizeof(int*) * n);
    
    for (int i=0; i<n; i++)
    {
        l->array[i] = (int*)malloc(sizeof(int*) * n); 
        for(int j=0; j<n; j++)
        {
            l->array[i][j] = 0; 
        }
    }
}


void graph_add_edge(struct graph l,int vertex1,int vertex2)
{
    if(vertex1 < 0 || vertex2 < 0 || vertex1 > l.n || vertex2 > l.n)
    {
        printf("Out of bounds");
        return;
    }
    l.array[vertex1][vertex2] = 1;
    l.array[vertex2][vertex1] = 1;
}

void graph_print(struct graph l)
{
    int i,j;
    printf("    ");
    for(i=0; i<l.n; i++)
    {
        printf("%3d",i);
    }
    printf("\n");


    printf("    ");
    for(i=0; i<l.n; i++)
    {
        printf("---");
    }
    printf("\n");

    
    for(i=0; i<l.n; i++)
    {
        printf("%3d|",i);
        for (j=0; j<l.n; j++) 
        {
           printf("%3d",l.array[i][j]);     
        }
    
        printf("\n");
    }    

}


int main()
{
    srand(4003);
    int n=(rand() % (10 - 6 + 1)) + 6;

    struct graph l;
    graph_init(&l, n);
    
    int x1= (rand() % (10 - 6 + 1)) + 6; //How many vertices are going to be added
    for(int i=0; i<n; i++)
    {
        int x2 =(rand() % ( (n-(i+1))- 0 + 1)) + 0;
        for(int j=0; j<x2; j++)
        {
            int x3= rand() % n;
            while(x3 == i) //To get a simple graph
            {
                x3= rand() % n;
            }
            graph_add_edge(l,i,x3);
        }
    }

    graph_print(l);

}

