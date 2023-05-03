#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* link;
};

struct node* global;
struct node* front;
struct node* rear;

void create(int data){
    struct node *ptr;
        ptr = (struct node*) malloc(sizeof(struct node));
        ptr->info = data;
        ptr->link = NULL;
    front = ptr;
    rear = ptr;
}

void insert(struct node **head, int d){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->info = d; 
    ptr->link = *head;
    *head = ptr;
}

void traversal(){
    if ((front == NULL)&&(rear == NULL))
        printf("Linked List is empty \n");
    else if (front == rear)
    {
        printf("\n ======\n");
        printf("\n|| %d ||",front->info);
        printf("\n ======\n");

    }
    else
    {
    struct node *ptr = NULL;
    ptr = front;
    printf("\n ======\n");
    while (ptr!= rear->link)
    {
        printf("\n|| %d ||",ptr->info);
        printf("\n ======\n");
        ptr = ptr->link;
    }
    }
    
}


int main(){
    int i,data,data2,data3;
    printf("Insert the value you want to insert initially: \n");
    scanf("%d",&i);
    create(i);
    printf("Insert the value for first node : \n");
    scanf("%d",&data);
    insert(&front,data);
    printf("Rear value %d",rear->info);
    printf("\tFront value %d",front->info);
    printf("\nInsert the value for 2nd node : \n");
    scanf("%d",&data2);
    insert(&front,data2);
    printf("Rear value %d",rear->info);
    printf("\tFront value %d",front->info);
    printf("\nInsert the value for 3rd node : \n");
    scanf("%d",&data3);
    insert(&front,data3);
    printf("Rear value %d",rear->info);
    printf("\tFront value %d",front->info);
    printf("\nQueue looks  like  :\n");
    traversal();
    return 0;
}