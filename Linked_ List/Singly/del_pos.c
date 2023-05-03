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
    struct node *ptr = head;
    while(head->link!=NULL)
        head=head->link;
    free(head);
    head = NULL;
    return ptr;
}




void create(int info){
    struct node *ptr;
        ptr = (struct node*) malloc(sizeof(struct node));
        ptr->info = info;
        ptr->link = NULL;
    global = ptr;
}
void add_beg(struct node **head, int d){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->info = d; 
    ptr->link = *head;
    *head = ptr;
}

void add_end(struct node** head_ref,int new_info){
	struct node* new_node =(struct node*) malloc(sizeof(struct node));
	struct node *last = *head_ref;
	new_node->info = new_info;
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

void add_to_position(struct node* prev_node,int pos,int new_info)
{
	if (prev_node == NULL)
	{
	printf("the given Pointer is Null");    //linked list is null	
	return;
	}
  struct node *ptr = prev_node;
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->info = new_info;
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


struct node* remove_pos(struct node* head, int pos)
{
    struct node* ptr = head;
    struct node* nptr = NULL;
    if(pos == 1)
    {
        head =  del_first(head);
        return head;
    }
    while(pos>1)
    {

        nptr = ptr;
        ptr = ptr->link;
        pos--;
    }
     nptr->link = ptr->link;
        free(ptr);
        ptr = NULL;
    return head;
}



int main(){
    int i,j,k,info,info2,info3;
    printf("Insert the value you want to insert initially: \n");
    scanf("%d",&i);
    create(i);
    printf("Insert the value for first node : \n");
    scanf("%d",&info);
    add_beg(&global,info);
    printf("Insert the value for last node : \n");
    scanf("%d",&info2);
    add_end(&global,info2);
    printf("Insert the value you want to add :\n");
    scanf("%d",&info3);
    printf("Insert the position :\n");
    scanf("%d",&j);
    add_to_position(global,j,info3);
    printf("\nLinked List Before Deletion  :\n");
    traversal(global);
    printf("\nInsert the position You want to delete :\n");
    scanf("%d",&k);
    global = remove_pos(global,k);
    printf("\nLinked List After Deletion  :\n");
    traversal(global);
    return 0;
}