#include <stdio.h>
#include <stdlib.h>
#define size 200


struct car
{
    int pos;
    int plates;
};


void insert(struct car tree[],  struct car element)
{
    if (tree == NULL)
        return;
    
    int pos = 0;
    while (pos < size)
    {
        if (tree[pos].plates)
        {
            if (tree[pos].plates < element.plates)
                pos = 2 * pos + 2;  // right
            else if (tree[pos].plates && tree[pos].plates > element.plates)
                pos = 2 * pos + 1;  // left
            else if (tree[pos].plates == element.plates)
            {
                element.plates++;
            }    
        }
        else
        {
            tree[pos] = element;
            return;
        }
    }
}


int get_left_child(struct car array [],int index)
{
    if(array[index].plates !=0 && (2*index)<=size)
        return 2*index;
    return -1;
}

int get_right_child(struct car array [],int index)
{
    if(array[index].plates != 0 && ((2*index)+1)<=size)
        return (2*index)+1;
    return -1;
}



void inorder(struct car array [],int index)
{
    if(index>0 && array[index].plates != 0)
    {
        inorder(array,get_left_child(array,index));
        printf("\n plate:%d pos:%d",array[index].plates,array[index].pos);
        inorder(array,get_right_child(array,index));
    }
}


int main()
{
    srand(4003);
    struct car array[size] = {0,0};
    for(int i=1; i<=size; i++) //Initialize with cars
    {
        struct car val;
        val.plates = (rand() % (9999 - 1000 + 1)) + 1000;
        val.pos = i;
        insert(array, val);
    }

    inorder(array, 1);
    //Meta bale ton algorithmo gia thn  afairesi
}