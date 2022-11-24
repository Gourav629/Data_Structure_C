#include<stdio.h>

void sf(int *p,int *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int main() {   
    int number,number2;
   
    printf("Enter First Number: ");  
    
    scanf("%d", &number);

    printf("Enter Second Number: ");  
    
    scanf("%d", &number2);

    printf("Number Before Swapping : %d %d\n",number,number2);
    sf(&number,&number2);
    printf("Number After Swapping : %d %d\n",number,number2);
    
    return 0;
}

// int main(){
//     int x,y;
//     printf("Enter any two Numbers : ");
//     scanf("%d","%d",&x,&y);
//     printf("Executing");
//     printf("Before Swapping, X=%d, Y=%d",x,y);
//     sf(&x,&y);
//     printf("After Swapping, X=%d, Y=%d",x,y);
//     return 0;
// }