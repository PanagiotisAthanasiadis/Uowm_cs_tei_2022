#include <stdio.h>
#include <stdlib.h>



int main()
{
   srand(4003); //bale to aem tou paidiou 
   //int n = 8 ;
   unsigned short int n = (rand() % (200 - 100 + 1)) + 100;
   int *array= (int *) malloc(sizeof(int) * n);

   //int array[ ] ={1,2,3,4,5,5,5,5};
   for(int i=0; i<n; i++)
   {
       int r= (rand() % (500 - 400 + 1)) + 400;
       while (r % 2 != 0) {
           r= (rand() % (500 - 400 + 1)) + 400;
       }
       array[i] = r ;
   }

   /*for(int i=0; i<n; i++)
   {
       printf("\narr[%d]=%d",i,array[i]);
   }*/
   
    int i, j, maxElement, count;
    int maxCount = 0;
    
    for(i = 0; i< n; i++)   
    {
        count = 1;
        for(j = i+1; j < n; j++)  
        {
            if(array[j] == array[i])
            {
                count++;   
                //printf("\n count:%d maxcount:%d",count,maxCount);
                if(count > maxCount)
                {
                    maxCount = count;
                    maxElement = array[j];
                }
            }
        }
    }


   printf("element:%d  times:%d",maxElement,maxCount);


}

