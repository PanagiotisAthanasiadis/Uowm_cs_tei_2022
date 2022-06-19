#include <stdio.h>
#include <stdlib.h>
#define size 50

struct student
{
    int aem;
    float val;
};

struct node {
   int data;
   
   struct node *next;
};



struct node *head = NULL;


void printList() {
   struct node *ptr = head;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("%d,",ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

void insertFirst( int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->data = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}

int binarySearch(struct student arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid].aem == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid].aem > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}


int spbinarySearch(struct student arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid].aem == x)
        {
            insertFirst(mid);
            printf("\nexaming position:%d",mid);
            printf("\nAll the positions that have been examed");
            printList();
            return mid;
        }    
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid].aem > x)
        {
            insertFirst(mid-1);
            printf("\nexaming position:%d",mid-1);
            return spbinarySearch(arr, l, mid - 1, x);
        }
 
        // Else the element can only be present
        // in right subarray
        insertFirst(mid+1);
        printf("\nexaming position:%d",mid+1);
        return spbinarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}


int main()
{
    srand(4003);
    struct student arr[size];
    int aem;
    for(int i=0; i<size; i++)
    {
        arr[i].aem = 2000 + i*4;
        arr[i].val = ((float)rand()/(float)(RAND_MAX)) * 10;
        //printf("%d\n",arr[i].aem); 
    }
    //printf("Insert Aem:\n");
    //scanf("%d",&aem);
    /*if(binarySearch(arr, 0, size - 1, aem) == -1)
    {
        printf("Aem does not exist");
    }
    else {
        printf("\naem:%d val:%f",arr[binarySearch(arr, 0, size - 1, aem)].aem,arr[binarySearch(arr, 0, size - 1, aem)].val);
    }*/

    int val = spbinarySearch(arr, 0, size - 1, 2104);

    if(val == -1)
    {
        printf("Aem does not exist");
    }
    else {
        printf("\naem:%d val:%f",arr[val].aem,arr[val].val);
    }


    int count =0;
    
    for (int i=0; i<size; i++) {
        if(arr[i].val>arr[binarySearch(arr, 0, size - 1, 2112)].val)
        {
            count++;
        }
    }
    printf("\nThe total number of students with higher marks:%d",count);
    printf("Steps 50");

}