#include<stdio.h>
#define N 50

//4.Searching
int Linear_Search(int arr[],int n,int data){
    for (int i = 0; i < n; i++)
        if (arr[i] == data)
        {
            return(i);
        }
        return(-1);
}

void display(int a[],int size) {
   printf("\n");
   for (int i=0; i<size; i++)
      printf("%d ", a[i]);
    printf("\n");
}


int main(){
int arr[N]= {10,20,30,40,45,58,67,70},searching_value1,size=8;
    printf("\n Array Printing\n");
    display(arr,size);

    printf("Enter Element to Search : ");
    scanf("%d",&searching_value1);
    int linear_result = Linear_Search(arr,size,searching_value1);
    (linear_result == -1)?printf("404 Not Found\n"):printf("The Element is Found at Index %d\n",linear_result+1);

   return 0;
}