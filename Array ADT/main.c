//this is the check 
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int *A;
    int size;
    int length ;
};

int Display(struct Array t)
{
    for(int i =0;i<t.length;i++)
    {
        printf("%d",t.A[i]);
    }
    return 0;
}
int main()
{   int n,i ;
    struct Array arr;
    printf("Enter the size of an array");
    scanf("%d",&arr.size);
    arr.A= (int *) malloc(arr.size*sizeof(int));
    arr.length =0;
    
    printf("enter the number of number : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr.A[i]);
    }
    arr.length=n;
    
    Display(arr);
    return 0;
}











