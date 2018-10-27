#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	struct node *previous;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *del_beg(struct node *);
struct node *del_end(struct node *);
struct node *del_after(struct node *);
struct node *del_before(struct node *start);
struct node *del_list(struct node *);

int main()
{
	int option;
	do{
		printf("\n MAIN MENU");
		printf("\n 1:  create doubly linked list");
		printf("\n 2:  Display linked list");
		printf("\n 3:  Add a node at beggining");
		printf("\n 4:  Add a node at END");
		printf("\n 5:  Add a node before a given node");
		printf("\n 6:  Add a node after a given node");
		printf("\n 7:  delete a node from beggining");
		printf("\n 8:  Delete a node at END");
		printf("\n 9:  Deletet a node before a given node");
		printf("\n 10:  Delete a node after a given node");
		printf("\n 11:  Delete linked list");
		printf("\n 12:  EXIT");
		printf("\n Enter your option");
		scanf("%d",&option);
		switch(option)
		{
			case 1 : start = create_ll(start);
				printf("\n\n Linked List created");
				break;
			case 2 : start = display(start);
				break;	
			case 3 : start = insert_beg(start);
				break;
			case 4 : start = insert_end(start);
				break;

			case 5 : start = insert_before(start);
				break;

			case 6 : start = insert_after(start);
				break;

			case 7 : start = del_beg(start);
				break;

			case 8 : start = del_end(start);
				break;

			case 9 : start = del_before(start);
				break;

			case 10 : start = del_after(start);
				break;

			case 11 : start = del_list(start);
				printf("\n\n Link list deleted");
				break;


			}
	}while(option!=12);
	return 0 ;

}
struct node *create_ll(struct node *start)
{
	struct node *newnode,*ptr;
	int num;
	printf("\n Enter -1 to end");
	printf("\n Enter the data");
	scanf("%d",&num);
	while(num != -1)
	{
		
		if(start==NULL)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			newnode->previous=NULL;
			newnode->data= num;
			newnode->next=NULL;
			start= newnode;
			
		}
		else
		{
			ptr=start;
			newnode=(struct node*)malloc(sizeof(struct node));
			newnode->data= num;
			while(ptr->next != NULL)
				ptr=ptr->next;
			ptr->next=newnode;
			newnode->previous = ptr;
			newnode->next= NULL;
		}	
		printf("\n\n Enter the data:");
		scanf("%d",&num);	

	}
	return start;

}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr != NULL)
	{
		printf("\t %d",ptr->data);
		ptr=ptr->next;
	}
	return start;

}
struct node *insert_beg(struct node *start)
{
	struct node *newnode ;
	int num;
	printf("\n Enter the data");
	scanf("%d",&num);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data= num;
	start->previous = newnode;
	newnode->next = start;
	newnode->previous = NULL;
	start = newnode ;
	
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *ptr,*newnode;
	int num;
	printf("\n\n Enter th data");
	scanf("%d",&num);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=NULL;
	ptr=start;
	while(ptr->next != NULL)
	{
		ptr=ptr->next;
	}
	ptr-> next = newnode;
	newnode->previous= ptr;
	newnode->next = NULL;
	return start;	
}
struct node *insert_before(struct node *start)
{
	struct node *newnode,*ptr;
	int num,val;
	printf("\n\n Enter the data");
	scanf("%d",&num);
	printf("\n\n Enter the value before the value has to be insert");
	scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->data != val)
	{
		ptr=ptr->next;
	}
	newnode->next = ptr;
	newnode->previous = ptr->previous;
	ptr->previous->next = newnode;
	ptr->previous = newnode;

	return start;
}

struct node *insert_after(struct node *start)
{
	struct node *newnode,*ptr;
	int num,val;
	printf("\n\n Enter the data");
	scanf("%d",&num);
	printf("\n\n Enter the value after the value has to be inserte");
	scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->data != val)
	{
			
		ptr=ptr->next;
	}
	newnode->previous = ptr;
	newnode->next = ptr->next;
	ptr->next->previous = newnode;
	ptr->next = newnode;
	
	
	return start;
}

struct node *del_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	start=start->next;
	start->previous = NULL;
	free(ptr);
	return start;
}
struct node *del_end(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next != NULL)
	{
	ptr=ptr->next;	
	}
	ptr->previous->next=NULL;
	free(ptr);
	return start;
	
}
struct node *del_after(struct node *start)
{
	struct node *ptr,*temp;
	int val;
	printf("\n\n Enter the value after which you have to del node");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data != val)
	{	
		
		ptr = ptr->next;
	}
	temp = ptr->next;
	ptr->next = temp->next;
	temp->next->previous= ptr;
	free(temp);
	return start;

}
struct node *del_before(struct node *start)
{
	struct node *ptr,*temp;
	int val;
	printf("\n\n Enter the value before which you have to del node");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data != val)
	{	
		ptr = ptr->next;
	}
	temp = ptr->previous;
	if(temp == start)
		start = del_beg(start);
	else
	{
	ptr->previous = temp->previous;
	temp->previous->next= ptr;
	}
	free(temp);
	return start;

}


struct node *del_list(struct node *start)
{

	while(start != NULL)
	{
		start= del_beg(start);
	}
	
	return start;
}


