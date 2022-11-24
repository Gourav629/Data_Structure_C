#include<stdio.h>
#include<stdlib.h>
# define k 4;


int main(){
    float *fp, fa[10];
    fp = (float *) malloc(sizeof(fa));
    printf(sizeof(fp));
    int *na,*ab, b = 4;           // Variable initialization
    // ab = malloc(b*sizeof(int));
    // printf(sizeof(fp));
    // int a[k];               // Array Defination
    // na = getarray(a);
    // print_array(na,k);    // Array Printing Function
    return 0;
}