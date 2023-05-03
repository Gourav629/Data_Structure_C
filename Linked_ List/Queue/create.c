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
    global = ptr;
    front = ptr;
    rear = ptr;
}

void traversal(struct node *head){
    if (head == NULL)
        printf("Linked List is empty \n");
    struct node *ptr = NULL;
    ptr = head;
    printf("\n ======");
    while (ptr != NULL)
    {
        printf("\n|| %d ||",ptr->info);
        printf("\n ======\n");
        ptr = ptr->link;
    }
}


int main(){
    int i,data,data2,data3;
    printf("Insert the value you want to insert initially: \n");
    scanf("%d",&i);
    create(i);
    printf("Queue after Creation : \n");
    traversal(global);
    // printf("Front data = %d",front->info);
    // printf("Rear data = %d",rear->info);
    return 0;
}