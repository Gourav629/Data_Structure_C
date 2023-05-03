#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};

struct node* global;


struct node*  remove_last(struct node* head)
{
    if(head==NULL){
      return NULL;
   }
    struct node *ptr = head->link;
    struct node* nptr = head;

    while(ptr->link!=NULL)
    {
        nptr = ptr;
        ptr = ptr->link;
    }
    nptr->link = NULL;
    free(ptr);
    return head;
}




void create(int data){
    struct node *ptr;
        ptr = (struct node*) malloc(sizeof(struct node));
        ptr->info = data;
        ptr->link = NULL;
    global = ptr;
}
void add_beg(struct node **head, int d){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->info = d; 
    ptr->link = *head;
    *head = ptr;
}

void add_end(struct node** head_ref,int new_data){
	struct node* new_node =(struct node*) malloc(sizeof(struct node));
	struct node *last = *head_ref;
	new_node->info = new_data;
	new_node->link = NULL;
	if (*head_ref == NULL)
	{
	*head_ref = new_node;
	return;
	}
	while (last->link != NULL)
		last = last->link;
	last->link = new_node;
	return;
}

void add_to_position(struct node* prev_node,int pos,int new_data)
{
	if (prev_node == NULL)
	{
	printf("the given Pointer is Null");    //linked list is null	
	return;
	}
  struct node *ptr = prev_node;
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->info = new_data;
	new_node->link = NULL;
  pos--;
  while(pos!=1){
    ptr =ptr->link;
    pos--;
  }
  new_node->link =ptr->link;
  ptr->link = new_node;
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

struct node* del_first(struct node* head){
       if(head==NULL){
      return NULL;
   }
    struct node* ptr = head;
    head = head->link;
    free(ptr);
    ptr = NULL;
    return head;
}


int main(){
    int i,j,data,data2,data3;
    printf("Insert the value you want to insert initially: \n");
    scanf("%d",&i);
    create(i);
    printf("Insert the value for first node : \n");
    scanf("%d",&data);
    add_beg(&global,data);
    printf("Insert the value for last node : \n");
    scanf("%d",&data2);
    add_end(&global,data2);
    printf("Insert the value you want to add :\n");
    scanf("%d",&data3);
    printf("Insert the position :\n");
    scanf("%d",&j);
    add_to_position(global,j,data3);
    printf("\nLinked List Before Deletion  :\n");
    traversal(global);
    global = remove_last(global);
    printf("\nLinked List After Deletion  :\n");
    traversal(global);
    return 0;
}