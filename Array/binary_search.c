#include<stdio.h>
#include<stdlib.h>
#define N 50


// 1.Array Treversing

void display(int a[],int size) {
   for (int i=0; i<size; i++)
      printf("%d ", a[i]);
    printf("\n");
}



// 5.Searching
int Binary_Search(int arr[], int left, int right, int value)
{
	if (right >= left) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == value)
			return mid;
		if (arr[mid] > value)
			return Binary_Search(arr, left, mid - 1, value);
		return Binary_Search(arr, mid + 1, right, value);
	}
	return -1;
}

int main(){
int arr[N]= {10,20,30,40,45,58,67,70},size=8, searching_value2;
    printf("\n Array Printing\n");
    display(arr,size); 

    printf("\nEnter Searching Value :\n");
	scanf("%d",&searching_value2);
	int result = Binary_Search(arr, 0, size, searching_value2);
	(result == -1)?printf("Element is not present in array\n"): printf("Element is present at position %d\n", result+1);

    return 0;
}