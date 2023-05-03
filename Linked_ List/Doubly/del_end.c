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
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->prev->next = NULL;
    ptr->prev = NULL;
    free(ptr);
    return head;

}

int main(){
    int data, data1,data2,data3,data4,p,p1;
    printf("Enter the value for the first Node : ");
    scanf("%d",&data);
    struct node * head = NULL;
    head = create(head,data);
    printf("Enter the value for the Node you want to insert at beg : ");
    scanf("%d",&data1);
    head = add_beg(head,data1);
    printf("Enter the value for the Node you want to insert at End : ");
    scanf("%d",&data2);
    head = add_end(head,data2);
    printf("Enter the value for the Node you want to : ");
    scanf("%d",&data3);
    printf("Enter the position of the Node : ");
    scanf("%d",&p);
    head = add_after(head,data3,p);
    printf("Enter the value for the Node you want to : ");
    scanf("%d",&data4);
    printf("Enter the position of the Node : ");
    scanf("%d",&p1);
    head = add_before(head,data4,p1);
    printf("\n List Before Deletion of first element\n");
    front_traversal(head);
    printf("\n List After Deletion of first element\n");
    head = remove_first(head);
    front_traversal(head);
    printf("\n List Before Deletion of Last element\n");
    front_traversal(head);
    printf("\n List After Deletion of Last element\n");
    head = remove_last(head);
    front_traversal(head);
    return 0;
}