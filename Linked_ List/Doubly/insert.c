#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node 
{
    int info;
    struct node* next;
    struct node* prev;
} ;

struct node *first;


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
    temp->info =data;
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

struct node* add_end(struct node* head,int data){
    struct node* ptr,*nptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->info = data;
    ptr->next = NULL;
    nptr = head;
    while(nptr->next != NULL)
        nptr = nptr->next;
    nptr->next=ptr;
    ptr->prev = nptr;
    return head;

}

struct node* add_after(struct node* head,int data, int pos)
{
    struct node* newP = NULL;
    struct node* ptr = head;
    struct node* nptr = NULL;
    newP = create(newP,data);

    while(pos != 1){
        ptr = ptr->next;
        pos--;
    }
    if(ptr->next == NULL){
        ptr->next = newP;
        newP->prev = ptr;
    }
    nptr = ptr->next;
    ptr->next = newP;
    nptr->prev = newP;
    newP->next = nptr;
    newP->prev = ptr;
    return head;
}

struct node* add_before(struct node* head, int data, int pos)
{
    struct node* newptr = NULL;
    struct node* ptr = head;
    struct node* nptr = NULL;
    newptr = create(newptr,data);
    int p = pos;
    while(p>2){
        ptr = ptr->next;
        p--;
    }
    if(pos == 1)
        head = create(head,data);
    nptr = ptr->next;
    ptr->next = newptr;
    nptr->prev = newptr;
    newptr->next = nptr;
    newptr->prev = ptr;
    return head;
}

struct node* remove_first(struct node* head){
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    ptr = NULL;
    head->prev = NULL;
    return head;
}

struct node*  remove_last(struct node* head)
{
    struct node * ptr = head;
    struct node * nptr;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    nptr = ptr->prev;
    nptr->next = NULL;
    free(ptr);
    return head;

}

struct node* remove_the(struct node* head, int pos)
{
    struct node* ptr = head;
    struct node* nptr = NULL;
    if(pos == 1)
    {
        head =  remove_first(head);
        return head;
    }
    while(pos>1)
    {
        ptr = ptr->next;
        pos--;
    }
    if(ptr->next == NULL)
        head = remove_last(head);
    else{
        nptr =ptr->prev;
        nptr->next = ptr->next;
        ptr->next->prev = nptr;
        free(ptr);
        ptr = NULL;
    }
    return head;
}


int main(){
    int data = 80;
    struct node * head = NULL;
    struct node *pointer;
    head = create(head,45);
    head = add_beg(head,40);
    printf("\nAfter Insertion of 40 at Begining Position:\n");
    front_traversal(head);
    head = add_beg(head,50);
    printf("\nAfter Insertion of 50 at Begining Position:\n");
    front_traversal(head);
    head = add_end(head,99);
    printf("\nAfter Insertion of 99 at End Position:\n");
    front_traversal(head);
    head = add_after(head,11,2);
    printf("\nInsertion of 11 after 2nd Position:\n");
    front_traversal(head);
    head = add_before(head,1,2);
    printf("\nInsertion of 1 before 2nd Position:\n");
    front_traversal(head);
    printf("\n List After Deletion of first element\n");
    head = remove_first(head);
    front_traversal(head);
    printf("\n List After Deletion of Last element\n");
    head = remove_last(head);
    front_traversal(head);
    printf("\n List After Deletion of 3rd element\n");
    head = remove_the(head,3);
    front_traversal(head);
    return 0;
}