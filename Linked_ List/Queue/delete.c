#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* link;
};

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

int delete()
{
    if((front==NULL)&&(rear == NULL)){
      printf("No element for removal\n");
      return -1;
   }
   else if (front == rear)
   {
    front = NULL;
    rear = NULL;
    return front->info;
   }
   else
   {
    
    struct node *ptr = front->link;
    struct node* nptr = front;

    while(ptr->link!=rear->link)
    {
        nptr = ptr;
        ptr = ptr->link;
    }
    int z =nptr->link->info;
    nptr->link = NULL;
    free(ptr);
    rear = nptr;
    return z;

   }
    
}

int main(){
        int i,data,data2,data3,j;
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
    j = delete();
    printf("Element deleted %d",j);
    traversal();
    return 0;
}