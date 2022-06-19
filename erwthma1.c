#include <stdio.h>
#include <stdlib.h>



int main()
{
    srand(4003);
    int n = (rand() % (8 - 4 + 1)) + 4;
    int d1_size = n + (2 *(n-1));
    int *arr = (int * ) malloc(n * n * sizeof(int)); //2-d array
    int *trans_arr = (int * ) malloc(n * n * sizeof(int)); //transpose array
    int *hor = (int *) malloc(d1_size * sizeof(int)); //1-d array
    int *trans_hor = (int *) malloc(d1_size * sizeof(int)); //transpose 1d array


    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(i-1 <=j && j <=i+1 )
            {
                *(arr + i*n + j) = (rand() % (20 - (-20 + 1))) + -20; //range -20 to 20
            }
            else {
                *(arr + i*n + j) = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) { //Print 2d array 
      for (int j = 0; j < n; j++) {
         printf("%d ", *(arr + i*n + j)); 
      }
      printf("\n");
   }
   
   int counter = 0; //create 1d 
   for (int i = 0; i < n && counter < d1_size; i++) {
      for (int j = 0; j < n && counter < d1_size; j++) {
        if(i-1 <=j && j <=i+1 )
        {
             hor[counter]=*(arr + i*n + j);
             counter++;  
        }
      }
      
   }

    for (int i=0; i<d1_size; i++) { //print 1d array
        printf("%d,",hor[i]);
    }

    int max = 0;
    int min = 0;

    for (int i=0; i<d1_size; i++) { //Find min and max
        if(hor[i]< min)
        {
            min =hor[i];
        }
        if(hor[i] > max)
        {
            max = hor[i];
        }
        
    }
    printf("\nMax:%d Min:%d \n",max,min);

    for (int i = 0; i < n; i++) { //Create 2d transpose
      for (int j = 0; j < n; j++) {
         *(trans_arr + j*n + i)=*(arr + i*n + j);
      }
   }
   


   for (int i = 0; i < n; i++) { //Print 2d array 
      for (int j = 0; j < n; j++) {
         printf("%d ", *(trans_arr + i*n + j)); 
      }
      printf("\n");
   }

  counter = 0; //create 1d transpose
   for (int i = 0; i < n && counter < d1_size; i++) {
      for (int j = 0; j < n && counter < d1_size; j++) {
        if(i-1 <=j && j <=i+1 )
        {
             trans_hor[counter]=*(trans_arr + i*n + j);
             counter++;  
        }
      }
      
   }
   
   for (int i=0; i<d1_size; i++) { //print transpose 1d array
        printf("%d,",trans_hor[i]);
    }

    free(arr);
}