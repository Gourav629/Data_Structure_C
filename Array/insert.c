#include<stdio.h>
#include<stdlib.h>
#define N 50

//2.Array Insertion
int array_insertion(int a[],int n,int item,int pos)  
{  
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
    for (int i = n; i >= pos-1; i--)
    {
        a[i+1] = a[i];
    }
    a[pos-1] = item;
    
    return(n+1);
}


// 1.Array Treversing

void display(int a[],int size) {
   for (int i=0; i<size; i++)
      printf("%d ", a[i]);
    printf("\n");
}

int main(){
int arr[N]= {10,20,30,40,45,58,67,70},size=8,value,position;
    printf("\n Array Printing Before Insertion\n");
    display(arr,size); 
    printf("\nEnter The Value you want to Insert\n");
    scanf("%d",&value);
    printf("\nEnter The the Position at Which you want to Insert\n");
    scanf("%d",&position);
    size = array_insertion(arr,size,value,position);
    printf("\n Array After Insertion\n");
    display(arr,size);

    return 0;
}