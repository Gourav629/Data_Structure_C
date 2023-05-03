#include<stdio.h>
#include<stdlib.h>

struct node{
struct node* prev;
int info;
struct node* next;

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

int main(){
    int data;
    printf("Enter the value for the first Node : ");
    scanf("%d",&data);
    struct node * head = NULL;
    head = create(head,data);
    front_traversal(head);
    return 0;
}