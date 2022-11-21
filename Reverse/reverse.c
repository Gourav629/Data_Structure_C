#include<stdio.h>
#define n 10
void print_array(int *array, int length)
{
    for (int i = 0; i < length; i++)printf("%d,", array[i]);
}

int main(){
    int arr[n] = {1,9,8,2,7,3,4,6,5,10};
    int temp;
    printf("Array Before Reverse\n");
    print_array(arr,n);
    for (int i = 0; i < n/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    printf("\n Array After Reversing\n");
    print_array(arr,n);
    return 0;
}
