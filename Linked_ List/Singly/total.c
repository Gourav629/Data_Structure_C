#include<stdio.h>
#include<malloc.h>

struct node 
{
    int info;
    struct node* link;
} ;
struct node *first;

void create(){
    struct node *ptr,*nptr;
    int choice;
        ptr = (struct node*) malloc(sizeof(struct node));
        printf("Enter value for First Node : ");
        scanf("%d",&ptr->info);
        ptr->link = NULL;
    first = ptr;
    printf("Press 1 to Add a node : ");
    scanf("%d",&choice);
    while (choice == 1)
    {
        nptr = (struct node*) malloc(sizeof(struct node));
        printf("Enter Info of New pointer ");
        scanf("%d",&nptr->info);
        ptr->link = nptr;         
        ptr = nptr;
        ptr->link = NULL;             
        printf("Press 1 to Add : ");
        scanf("%d",&choice);
    }
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

void add_beg(struct node **head, int d)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->info = d; 
    ptr->link = *head;
    *head = ptr;
}

void add_end(struct node** head_ref,int new_data)
{
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
	printf("the given Pointer is Null");	
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
    int data = 80;
    struct node *pointer = first;
    create();
    printf("\nInitial Traversing :\n");
    traversal(first);
    add_beg(&first,data);
    printf("\nAfter Adding New Value at Begining :\n");
    traversal(first);
    add_end(&first,66);
    printf("\nAfter Adding New Value at Ending :\n");
    traversal(first);
    add_to_position(first,3,007);
    printf("\nAfter Adding New Value at Position :\n");
    traversal(first);
    first = del_first(first);
    printf("\nAfter Removing First element :\n");
    traversal(first);
    return 0;
}