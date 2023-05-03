#include<stdio.h>
#include<stdlib.h>

struct node{
    int id;
    struct Node* left;
    struct Node* right;
    int height;
};


struct node* create(int a){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->id = a;
    ptr->height = 1;
}

int getH(struct node* a){
    if(a==NULL)
            return 0;
    return a->height;
}

int getBF(struct node* a){
    if(a==NULL)
        return 0;
    return getH(a->left)-getH(a->right);
}

int main(){
    return 0;
}