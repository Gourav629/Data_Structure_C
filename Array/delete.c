#include<stdio.h>
#include<stdlib.h>
#define N 50


//3.Array Removal 

int array_deletion(int a[],int n,int pos)  
{  int item;
    if (pos>N)
    {
       printf("\nOverflow\n");
       exit;
    }
    else if (pos<0)
    {
        printf("\nUnderFlow\n");
        exit;
    }
    item = a[pos-1];
    for (int i = pos -1; i <= n-1; i++)
    {
        a[i] = a[i+1];
    }
    printf("Element Removed is %d",item);
    return(n-1);
}

// 1.Array Treversing

void display(int a[],int size) {
   for (int i=0; i<size; i++)
      printf("%d ", a[i]);
    printf("\n");
}

int main(){
int arr[N]= {10,20,30,40,45,58,67,70},size=8,delposition;
    printf("\n Array Printing Before Deletion\n");
    display(arr,size);
    printf("\nEnter Position which you want to delete :\n");
    scanf("%d",&delposition);
    size = array_deletion(arr,size,delposition);
    printf("\n Array After Deletion Looks like\n");
    display(arr,size);

    return 0;
}