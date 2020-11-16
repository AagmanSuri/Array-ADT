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
void Insert(struct Array *arr, int index,int x)
{
    if(arr->length<arr->size)
    {
    for(int i=arr->length;i>index;i--)
    {
        arr->A[i]=arr->A[i-1];
    }
        arr->A[index]=x;
        arr->length++;
        
    }
}
//delete(index)
void Delete(struct Array *arr,int index)
{
    if(index>=0 && index<arr->length)
    {
    for(int i=index;i<arr->length-1;i++)
    {
        arr->A[i]=arr->A[i+1];
    }
    arr->length--;
    }
}

//search
//linear search
//Binary search

int main()
{
    struct Array arr={{2,3,4,5,6},20,5};
    
    //Append(&arr, 7);
    //Insert(&arr,0,1);
    Delete(&arr,2);
    Display(arr);
    
    return 0;
}











