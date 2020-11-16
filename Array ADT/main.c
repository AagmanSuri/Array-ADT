#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int A[20];
    int size;
    int length ;
};

void Display(struct Array arr)
{
    int i;
    printf("\n Elements are\n");
    for(i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}
//append(x)
void Append(struct Array *arr,int x)
{
    if(arr->length<arr->size)
    {
        arr->A[arr->length]=x;
        arr->length++;
    }
}
//insert(index,x)
//delete(index)
//search
//linear search
//Binary search

int main()
{
    struct Array arr={{2,3,4,5,6},20,5};
    
    Append(&arr, 7);
    Display(arr);
    
    return 0;
}











