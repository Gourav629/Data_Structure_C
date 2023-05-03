#include<stdio.h>
#define N 50

// 1.Array Treversing

void display(int a[],int size) {
   printf("\n");
   for (int i=0; i<size; i++)
      printf("%d ", a[i]);
    printf("\n");
}


int main(){
int arr[N]= {10,20,30,40,45,58,67,70},size=8;
    printf("\n Array Printing \n");
    display(arr,size); 
    
    return 0;
}