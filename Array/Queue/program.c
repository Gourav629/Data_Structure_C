#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,size;
void display(int a[]) {
   for (int i=rear; i>=front; i--)
   {
      if(i == rear)
        printf(" ======");
      printf("\n|| %d ||\n", a[i]);
      printf(" ======");
    }
    printf("\n");
}

void enqueue(int a[],int data){
    if (rear == size-1)
        printf("Stack Overflow");
    else if ((front == -1)&&(rear==-1))
        {
            front++;
            rear++;
            a[rear] = data;
        }
    else{
        rear++;
        a[rear] = data;
    }
}

int dequeue(int a[]){
    int item;
    if ((front == -1)&&(rear == -1))
        printf("Stack Underflow");
    else if (front == rear)
    {
        item = a[rear];
        front =-1;
        rear =- 1;
        return item;
    }
    item = a[front];
    front++;
    return item;
}



void cenqueue(int a[],int data){
    if (rear == (rear+1)%size)
        printf("Stack Overflow");
    else if ((front == -1)&&(rear==-1))
        {
            front++;
            rear++;
            a[rear] = data;
        }
    else{
        rear = (rear+1)%size;
        a[rear] = data;
    }
}






int main(){
    int n=1,*queue,z, cqueue;
    printf("Insert the size of Queue");
    scanf("%d",&size);
    queue = (int*)malloc(size*sizeof(int));
    enqueue(stack,24);
    enqueue(stack,22);
    enqueue(stack,20);
    display(stack);
    z = dequeue(stack);
    printf("%d is Removed \n", z);
    display(stack);
    return 0;
}