#include<stdio.h>
#include<stdlib.h>

struct node{
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
    int i,data,data2;
    printf("Insert the value you want to insert initially: \n");
    scanf("%d",&i);
    create(i);
    printf("Insert the value for first node : \n");
    scanf("%d",&data);
    add_beg(&global,data);
    printf("Insert the value for last node : \n");
    scanf("%d",&data2);
    add_end(&global,data2);
    printf("\nLinked List looks  like  :\n");
    traversal(global);
    return 0;
}