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

int main(){
    int data, data1,data2,p,data3;
    printf("Enter the value for the first Node : ");
    scanf("%d",&data);
    struct node * head = NULL;
    head = create(head,data);
    printf("Enter the value for the Node you want to insert at beg : ");
    scanf("%d",&data1);
    head = add_beg(head,data1);
    printf("\nAfter Insertion of %d at Begining Position:\n",data1);
    printf("Enter the value for the Node you want to insert at End : ");
    scanf("%d",&data2);
    head = add_end(head,data2);
    // printf("\nAfter Insertion of %d at End Position:\n",data2);
    // front_traversal(head);
    printf("Enter the value for the Node you want to : ");
    scanf("%d",&data3);
    printf("Enter the position of the Node : ");
    scanf("%d",&p);
    head = add_after(head,data3,p);
    printf("\nInsertion of %d after %d Position:\n",data3,p);
    front_traversal(head);
    return 0;
}