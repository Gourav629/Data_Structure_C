#include<stdlib.h>
#include<stdio.h>

struct node {
int info;
struct node* link;
};

struct node* global;

void create(int data){
    struct node *ptr;
        ptr = (struct node*) malloc(sizeof(struct node));
        ptr->info = data;
        ptr->link = NULL;
    global = ptr;
}

void traversal(struct node *head){
    if (head == NULL)
        printf("Linked List is empty \n");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        (ptr->link == NULL)?printf("%d",ptr->info):printf("%d ==>",ptr->info);
        ptr = ptr->link;
    }
}

int main(){
    int input;
    printf("Insert the value you want to insert: ");
    scanf("%d",&input);
    create(input);
    traversal(global);
    printf("\nLiked list is created !!\n");
    return 0;
}