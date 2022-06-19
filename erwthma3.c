#include <stdio.h>
#include <stdlib.h>

struct student
{
  unsigned short int aem;
  char lname[16];
  char fname[16];
  unsigned short int year;

};




int main()
{
  srand(4003); //Bale to aem tou padioy
  struct student arr[100];

  for(int i=0; i<90; i++)
  {
      arr[i].aem = (rand() % (4000 - 3000 + 1)) + 3000;
      arr[i].lname[0] = (rand() % (90 - 65 + 1)) + 65;
      arr[i].fname[0] = (rand() % (122 - 97 + 1)) + 97;
      arr[i].year = (rand() % (2020 - 2014 + 1)) + 2014;
  }

  for(int i=0; i<90; i++)
  {
      if(2021 - arr[i].year > 4)
      {
        printf("\n aem:%hu lname:%c fname:%c year:%hu",arr[i].aem,arr[i].lname[0],arr[i].fname[0],arr[i].year);
      }
  } 

  



}