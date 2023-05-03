#include<stdio.h>
#include<stdlib.h>

struct node{

struct node *prev;
int info;
struct node *next;

};

struct node *global;


void front_traversal(struct node *head){
    if (head == NULL)
        printf("\n List is empty \n");
    while (head != NULL)
    { 
        (head->next == NULL)?printf("%d",head->info):printf("%d <==>",head->info);
        head = head->next;
    }
}

struct node* create(struct node* head, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->info = data;
    temp->next = NULL;
    head = temp;
    return head;
}


struct node* add_beg(struct node *head, int d)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->info = d; 
    ptr->next = NULL;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    return head;
}


int main(){
    int data, data1;
    printf("Enter the value for the first Node : ");
    scanf("%d",&data);
    struct node * head = NULL;
    head = create(head,data);
    printf("Enter the value for the Node you want to insert at beg : ");
    scanf("%d",&data1);
    head = add_beg(head,data1);
    printf("\nAfter Insertion of %d at Begining Position:\n",data1);
    front_traversal(head);
    return 0;
}