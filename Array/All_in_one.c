#include<stdio.h>
#include<stdlib.h>
#define N 50

// 1.Array Treversing

void display(int a[],int size) {
   for (int i=0; i<size; i++)
      printf("%d ", a[i]);
    printf("\n");
}

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




//4.Linear Searching
int Linear_Search(int arr[],int n,int data){
    for (int i = 0; i < n; i++)
        if (arr[i] == data)
        {
            return(i);
        }
        return(-1);
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
    // --------------------------- Definition --------------------------------- //
int arr1[N] = {21,2,43,14,-5,46,87,8},size=8,value,position,removed,delposition,deleted_item,az;
int arr2[N]= {10,20,30,40,45,58,67,70},searching_value1, searching_value2;
    printf("\n Array Printing Before Insertion\n");
    display(arr1,size); 
    //--------------------------------- Insertion ----------------------------//
    printf("\nEnter The Value you want to Insert\n");
    scanf("%d",&value);
    printf("\nEnter The the Position at Which you want to Insert\n");
    scanf("%d",&position);
    size = array_insertion(arr1,size,value,position);
    printf("\n Array After Insertion\n");
    display(arr1,size);
    //---------------------------------- Deletion -------------------------//
    printf("\nEnter Position which you want to delete :\n");
    scanf("%d",&delposition);
    size = array_deletion(arr2,size,delposition);
    printf("\n Array After Deletion Looks like\n");
    display(arr2,size);

    //----------------------------------- Searching Linear -------------------//
    printf("Enter Element to Search : ");
    scanf("%d",&searching_value1);
    int linear_result = Linear_Search(arr1,size,searching_value1);
    (linear_result == -1)?printf("404 Element Not Found\n"):printf("The Element is Found at %d Index\n",linear_result+1);

    //----------------------------------- Searching Binary ------------------ //
    printf("\nEnter Searching Value :\n");
	scanf("%d",&searching_value2);
	int result = Binary_Search(arr2, 0, size, searching_value2);
	(result == -1)?printf("Element is not present in array\n"): printf("Element is present at position %d\n", result+1);

    return 0;
}