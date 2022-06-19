#include <stdio.h>
#define size 6


int stack[size];

int top;

int pallindrome(int loop)
{
	if (loop >= 10)
	{
		int temp, temp1 = 0, sum = 0;
		for(temp = 0; temp < 2;temp++)
		{
			temp1 = loop % 10;
			loop = loop / 10;
			sum = sum * 10 + temp1;
		}
		return(sum);
	}
	else
	{
		return(loop * 10);
	}
}



int firstDigit(int n)
{
    // Remove last digit from number
    // till only one digit is left
    if(n< 10){
        return 0;
    }
    while (n >= 10) 
        n /= 10;
      
    // return the first digit
    return n;
}

int lastDigit(int n)
{
    // return the last digit
    return (n % 10);
}

void push(int n)
 
{
	if(top==size-1)
	{
		printf("\nStack is Full");
	}
	else
	{
		top=top+1;
		stack[top]=n;
    }
}

void pop()
 
{ 
	int item;
	if(top==-1)
	{
		printf("\n Stack is empty");
	}
	else
	{
		item=stack[top];
 
		//printf("\n item popped is=%d", item);
 
		top--;
	}
}

 
void display()
 
{
    
	int i;
 
	printf("\n item in stack are");
 
	for(i=top; i>=0; i--)
 
	printf("%d", stack[i]);
 
}


int main()
{
    int aem = 4003; //Allaxe to edw 
    int seconds = aem * 10 ;
    top=-1; //Empty stack

    push(firstDigit((int)(seconds/3600))); // h
    push(lastDigit((int)(seconds/3600)));  // hh%
    push(firstDigit(((int)(seconds/60))%60)); // hh%m
    push(lastDigit(((int)(seconds/60))%60)); //hh%mm%
    push(firstDigit((int)(seconds%60))); //hh%mm%s
    push(lastDigit((int)(seconds%60))); //hh%mm%ss
    //display();
    printf("%d%d:%d%d:%d%d \n",stack[0],stack[1],stack[2],stack[3],stack[4],stack[5]);


    for(int i=0; i<size; i++)
    {
        pop();
    }
    //display();


    int a=0,b=0;
	int loop=0;
	for (loop=0; loop<=59; loop++) //find all palindrome  times in a day 
	{
	    a = pallindrome(loop);
        b = pallindrome(loop);
	    if (a < 60 && loop < 24)
		{
			printf("\n%.2d:%.2d:%.2d", loop,a,b);	
			printf("\naem:%d", loop * 3600 + a * 60 +b);
		}
		



	}



}