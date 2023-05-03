#include<stdio.h>
#include<stdlib.h>

struct bst{
    struct bst *left;
    int data;
    struct bst *right;
};

struct bst *root;

struct bst *create(struct bst *bst, int data){
  bst->left = NULL;
  bst->right = NULL;
  bst->data = data;
  return bst;
}

// struct bst* insertLeft(struct bst* r, int value) {
//   r->left = create(r,value);
//   return r->left;
// }

// struct bst* insertRight(struct bst* r, int value) {
//   r->right = create(r,value);
//   return r->right;
// }



struct bst* insert(int item)  
{  
    struct bst *ptr, *parentptr , *bstptr;  
    ptr = (struct bst *) malloc(sizeof (struct bst));  
    if(ptr == NULL)  
    {  
        printf("can't insert");  
    }  
    else   
    {  
    ptr -> data = item;  
    ptr -> left = NULL;  
    ptr -> right = NULL;   
    if(root == NULL)  
    {  
        root = ptr;  
        root -> left = NULL;  
        root -> right = NULL;  
    }  
    else   
    {  
        parentptr = NULL;  
        bstptr = root;   
        while(bstptr != NULL)  
        {  
            parentptr = bstptr;   
            if(item < bstptr->data)  
            {  
                bstptr = bstptr -> left;   
            }   
            else   
            {  
                bstptr = bstptr -> right;  
            }  
        }  
        if(item < parentptr -> data)  
        {  
            parentptr -> left = ptr;   
        }  
        else   
        {  
            parentptr -> right = ptr;   
        }  
    }  
    printf("bst Inserted");  
    }  
    return ptr;
}  







// struct bst *insert(struct bst *bst, int data){
//     struct bst * ptr = (struct bst *) malloc(sizeof(struct bst));
//     if(bst == NULL){
//         return create(bst, data);
//     }
//     else if(data < bst->data){
//             bst->right = ptr;
//             ptr->left = bst;
//             return bst;
//     }
//     else{
//             bst->left = ptr;
//             ptr->right = bst;
//             return bst;
//     }
// }

// void bst_preorder(struct bst* d){
//     if(d == NULL) return;
//    else if(d!= NULL){
//         bst_preorder(d->left);
//         printf("%d ->", d->data);
//         bst_preorder(d->right);
//     }
//     printf("\n");
// }


void bst_inorder(struct bst* r) {
   if(r != NULL) {
      bst_inorder(r->left);
      printf("%d ",r->data);          
      bst_inorder(r->right);
   }
}

void bst_postorder(struct bst* d){
    if(d == NULL) return;
    else if(d!= NULL){
        bst_postorder(d->left);
        bst_postorder(d->right);
        printf("%d ->", d->data);
    }
    printf("\n");
}

int main(){
    int choice,item;  
do   
    {  
        printf("\nEnter the item which you want to insert?\n");  
        scanf("%d",&item);  
        root = insert(item);  
        printf("\nPress 0 to insert more ?\n");  
        scanf("%d",&choice);  
    }while(choice == 0);  
    bst_inorder(root);
    return 0;
}