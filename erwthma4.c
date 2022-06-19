#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "set.h"



void print_set(simple_set a,char name)
{   
    uint64_t n = set_length(&a);

    char** results = (char**)calloc(n+1, sizeof(char*)); //Print Set
    results =set_to_array(&a, &n);
     printf("\n Set %c: ",name);
    for(int i=0; i<n; i++)
    {
        printf("%s,",results[i]);
    }
    free(results);
}


int main()
{
    simple_set a,b,c,d,e,g;
    set_init(&a);
    set_init(&b);
    set_init(&c);
    set_init(&d);
    set_init(&e);
    set_init(&g);
    srand(4003);
    uint64_t n = (rand() % (8 - 3 + 1)) + 3; //size of set a
    uint64_t n1 = (rand() % (8 - 3 + 1)) + 3; //size of set b
    for(int i=0; i<n; i++) //initialize set a
    {
        int r = (rand() % (8 - 1 + 1)) + 1;
        char x[2] ;
        x[0] = r + '0';
        x[1] = '\0'; 
        while (set_contains(&a,x) == SET_TRUE) { //To get diffrent values every time
            r = (rand() % (8 - 1 + 1)) + 1;
            x[0] = r + '0';
            x[1] = '\0'; 
        }
        

        set_add(&a, x);
    }
    


    for(int i=0; i<n1; i++) //initialize set a
    {
        int r = (rand() % (8 - 1 + 1)) + 1;
        char x[2] ;
        x[0] = r + '0';
        x[1] = '\0'; 
        while (set_contains(&b,x) == SET_TRUE) { //To get unique values every time
            r = (rand() % (8 - 1 + 1)) + 1;
            x[0] = r + '0';
            x[1] = '\0'; 
        }

        set_add(&b, x);
    }
      
    print_set(a, 'A');
    
    print_set(b, 'B');

    
    set_union(&c,&a,&b); //Union of a and b to c

    print_set(c, 'C');

    printf("\n Length of set C:%lu",set_length(&c));

    set_intersection(&d, &a, &b);

    print_set(d, 'D');

    set_difference(&e, &c, &d);

    print_set(e, 'E');

    if(set_cmp(&e,&a) == SET_EQUAL) 
    {
        printf("\nThey are equal");
    }
    else {
        printf("\nThey are NOT equal");
    }

    if(set_cmp(&e,&b) == SET_EQUAL) 
    {
        printf("\nThey are equal");
    }
    else {
        printf("\nThey are NOT equal");
    }

    if(set_is_subset(&c, &b) == SET_TRUE)
    {
        printf("\nC is subset of B");
    }
    else {
        printf("\nC is Not subset of B");
    }

    if(set_is_subset(&a, &c) == SET_TRUE)
    {
        printf("\n A is subset of C");
    }
    else {
        printf("\n A is Not subset of C");
    }

    set_intersection(&g, &e, &b);

    printf("\nIntersection E and B:");
    print_set(g,'G');



    uint64_t n4 = set_length(&a);

    int max= 0;
    char** results = (char**)calloc(n4+1, sizeof(char*)); 
    results =set_to_array(&a, &n);
    
    for(int i=0; i<n4; i++)
    {
       if(atoi(results[i]) > max)
       {
           max = atoi(results[i]);
       }
    }
    char x[2] ;
        x[0] = max + '0';
        x[1] = '\0'; 
    set_remove(&a, x);
    printf("\nSet A after removal of max:");
    print_set(a, 'A');

}