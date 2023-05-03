#include<stdio.h>
#include<stdlib.h>

struct root{
  int data;
  struct root* left;  
  struct root* right;
};

struct root* tree;

struct root* create(struct root* head, int data){
    struct root* temp = (struct root*)malloc(sizeof(struct root));
    temp->left = NULL;
    temp->data = data;
    temp->right = NULL;
    head = temp;
    printf("Created !!");
    return head;
}

struct root* insert_left(struct root *head, int d)
{
    struct root *ptr = (struct root*)malloc(sizeof(struct root));
    ptr->left = NULL;
    ptr->data = d; 
    ptr->right = NULL;
    ptr->right = head;
    head->left = ptr;
    head = ptr;
    return head;
}


int main(){
    int data;
    printf("Enter the value for the first root : ");
    scanf("%d",&data);
    struct root * tree = NULL;
    tree = create(tree,data);
    return 0;
}