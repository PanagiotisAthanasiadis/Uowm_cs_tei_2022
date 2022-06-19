#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000
#define G 200003
#define prime 30011
#define hashone(v) (v % G)
#define hashtwo(v) (prime-(v%prime))


struct customer 
{
  int key;
  double balance;
};

int firstDigit(int n)
{
    // Remove last digit from number
    // till only one digit is left
    while (n >= 10) 
        n /= 10;
      
    // return the first digit
    return n;
}

int secondDigit(int n)
{
    return (n / (int) pow(10, 5)) % 10;
}


int main()
{
    srand(4003);
    struct customer arr[N];
    struct customer arr2[G];

    for(int i=0; i<N; i++) //Initialization
    {
        arr[i].key = 100000*(10+rand()%60)+1000*(rand()%100)+rand()%1000 ;
        arr[i].balance = 500.0 + (rand()%14500)/10.0;
        //printf("rec:%d bal:%lf \n",arr[i].key,arr[i].balance);
    }

    for(int i=0; i<G; i++)
    {
        arr2[i].key =-1;
        arr2[i].balance = 0;
    }


    for(int i=0; i<N; i++)
    {
        int index = hashone(arr[i].key);
        if(arr2[index].key != -1)
        {
            int index2 = hashtwo(arr[i].key);
            int f = 1 ;
            while(1)
            {
                 int newIndex = (index + f * index2) % G;
                 if(arr2[newIndex].key == -1)
                 {
                     arr2[newIndex].key = arr[i].key;
                     arr2[newIndex].balance = arr[i].balance;
                     break;
                 }
                f++;
            }
        }
        else
        {
            arr2[index].key = arr[i].key;
            arr2[index].balance = arr[i].balance;
        }
        
    }
    
    for(int i=0; i<G; i++)
    {
        if(arr2[i].key != -1)
        {
            printf("\n index:%d val:%d bal:%lf ",i,arr2[i].key,arr2[i].balance);
        }
    }

    int search;
    printf("Insert the AM:");
    scanf("%d",&search);
    int i1 = hashone(search);
    int i2 = hashtwo(search);
    int g=0;
    while(arr2[(i1 + g * i2) % G].key != search)
    {
        if(arr2[(i1 + g * i2) % G].key == -1)
        {
            printf("\nThis AM does not exists,adding to the database now...");
            arr2[(i1 + g * i2) % G].key = search;
            arr2[(i1 + g * i2) % G].balance = 537.5;
            break;
        }
        g++;
    }
    printf("\n Found in position %d and with balance:%lf",(i1 + g * i2) % G,arr2[(i1 + g * i2) % G].balance);


    int area;
    printf("\nInsert the area Code [10-62]:");
    scanf("%d",&area);

    int area1 =firstDigit(area);
    int area2 = secondDigit(area);
    

    double total =0;

    for(int i=0; i<G; i++)
    {
        int key1= firstDigit(arr2[i].key);
        int key2 = secondDigit(arr2[i].key);
        if(key1 == area1 && key2 == area2)
        {
            total += arr2[i].balance;
        }
    }
    printf("\nTotal:%lf",total);
    





}