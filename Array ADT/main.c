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
//swap
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

//search
//linear search
int LinearSearch(struct Array *arr,int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==key)
        { //transposition
          //swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}
//Binary search
int BinarySearch(struct Array arr,int key)
{
int l=0, h=arr.length-1;
    while(l<h){
    int mid=(l+h)/2;
    if(arr.A[mid]==key)
    {
        return mid;
    }
    else if(arr.A[mid]>key)
    {
        h=mid-1;
    }
    else if(arr.A[mid]<key)
    {
        l=mid+1;
    }
    
    }
    return -1;
}
//get(index)
int get(struct Array arr,int index)
{   if(index>0 && index<arr.length)
        return arr.A[index];
    return -1;
}

//set(index,x)
int set(struct Array *arr,int index,int x)
{   if(index>0 && index<arr->length)
     return arr->A[index]=x;
    return -1;
}
//max
int max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    return max;
}
//min
int min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
        {
            min=arr.A[i];
        }
    }
    return min;
}
//sum
int sum(struct Array arr)
{
    int total=0;
    for(int i=0;i<arr.length;i++)
    {
        total=total+arr.A[i];
    }
    return total;
}
//avg
float avg(struct Array arr)
{
    int total=0;
    for(int i=0;i<arr.length;i++)
    {
        total=total+arr.A[i];
    }
    return (float)total/arr.length;
}
//reverse
void Reverse(struct Array *arr)
{
    int *B;
    B=(int *)malloc(arr->length*sizeof(int));
    int i,j;
    for(i=arr->length-1,j=0;i>=0;i--,j++)
    {
        B[j]=arr->A[i];
    }
    for(i=0;i<arr->length;i++)
    {
    arr->A[i]=B[i];
    }
    
}
//left shift
//left rotate
//right shift
//right rotate


int main()
{
    struct Array arr={{2,3,4,5,6},20,5};
    
    //Append(&arr, 7);
    //Insert(&arr,0,1);
    //Delete(&arr,2);
    //printf("%d",LinearSearch(&arr, 4));
    //printf("%d",BinarySearch(arr,4));
    //printf("%d",get(arr, 3));
    //printf("%d",set(&arr,3,1));
    //printf("%d",max(arr));
    //printf("%d",min(arr));
    //printf("%d",sum(arr));
    //printf("%f",avg(arr));
    Reverse(&arr);
    Display(arr);
    
    return 0;
}











