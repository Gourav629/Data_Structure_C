#include<stdio.h>
#define k 6         //Macros

void print_array(int *array, int length)
{
    for (int i = 0; i < length; i++)printf(" %d,", array[i]);
}

int *getarray(int *a)  
{  
    printf("Enter the elements in an array : \n");  
    for(int i=0;i<k;i++)  
    {  
        scanf("%d", &a[i]);  
    }  
    return a;  
}

int *reverse_array(int *z){
    int temp;
    for (int i = 0; i < k/2; i++)
    {
        temp = z[i];
        z[i] = z[k-i-1];
        z[k-i-1] = temp;
    }

    return z;
}

int main(){
    int *na, *ka;  
    int a[k];  
    na = getarray(a);
    printf("Array Before Reverse\n");
    print_array(na,k);          // Array Printing Function
    ka = reverse_array(na) ;    // Array Creation Function
    printf("\n Array After Reversing\n");
    print_array(ka,k);          // Array Printing Function
    return 0;
}
