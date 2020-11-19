#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int A[10];
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
//reverse with creating an auxilary array
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

void Reverse2(struct Array *arr)
{   int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
    
        swap(&arr->A[i], &arr->A[j]);

    }
}
//left shift
void LeftShift(struct Array *arr)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        arr->A[i]=arr->A[i+1];
    }
}
//left rotate
void LeftRotate(struct Array *arr)
{
    int i;
    arr->A[arr->length]=arr->A[0];
    for(i=0;i<arr->length;i++)
    {
        arr->A[i]=arr->A[i+1];
    }
}
//right shift
//right rotate
//Inserting at the sorted place
void InsertSort(struct Array *arr,int x)
{   int i= arr->length-1;
    if(arr->length==arr->size)
        return;
    while(i>=0 && x<arr->A[i])
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}
int isSorted(struct Array arr)
{
    int i ;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}
//rearranging the negative and positive int in an array
void Rearrange(struct Array *arr)
{
    int i=0;
    int j = arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)
        {
            i++;
        }
        while(arr->A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}
//Merging two arrays
struct Array * Merging(struct Array *arr1 ,struct Array *arr2)
{   int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]= arr1->A[i++];
        }
        else
        {
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i++];
    }
    for(;j<arr2->length;j++)
    {
        arr3->A[k++]=arr2->A[j++];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size=10;
    return arr3;
}
struct Array * Union(struct Array *arr1 ,struct Array *arr2)
{   int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {   //one smaller
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]= arr1->A[i++];
        }
        else if(arr2->A[j]<arr1->A[i])
        {
            arr3->A[k++]=arr2->A[j++];
        }
        // if both are equal copy anyone and increment the other
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i++];
    }
    for(;j<arr2->length;j++)
    {
        arr3->A[k++]=arr2->A[j++];
    }
    arr3->length =k;
    arr3->size=10;
    return arr3;
}
int main()
{
    //struct Array arr={{-2,3,-4,5,6},10,5};
    struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,6,7,15,20},10,5};
    struct Array *arr3;
    
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
    //Reverse(&arr);
    //Reverse2(&arr);
    //LeftShift(&arr);
    //LeftRotate(&arr);
    //InsertSort(&arr,1);
    //printf("%d",isSorted(arr));
    //Rearrange(&arr);
    //arr3= Merging(&arr1, &arr2);
    arr3= Union(&arr1, &arr2);
    Display(*arr3);
    
    return 0;
}
