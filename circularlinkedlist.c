#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;

};

struct node *start=NULL;
struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

int main()
{
int option;
do

{

		printf("\n MAIN MENU");
		printf("\n 1:  create circular linked list");
		printf("\n 2:  Display circular linked list");
		printf("\n 3:  Add a node at beggining");
		printf("\n 4:  Add a node at END");
		printf("\n 5:  delete a node from beggining");
		printf("\n 6:  Delete a node at END");
		printf("\n 7:  Delete a node after a given node");
		printf("\n 8:  Delete linked list");
		printf("\n 9:  EXIT");
		printf("\n Enter your option");
		scanf("%d",&option);
		switch(option)
		{
			case 1 : start = create_cll(start);
				printf("\n\n Linked List created");
				break;
			case 2 : start = display(start);
				break;	
			case 3 : start = insert_beg(start);
				break;
			case 4 : start = insert_end(start);
				break;

			case 5 : start = delete_beg(start);
				break;

			case 6 : start = delete_end(start);
				break;

			case 7 : start = delete_after(start);
				break;

			case 8 : start = delete_list(start);
				printf("\n\n Link list deleted");
				break;

			}
	}while(option!=9);
	return 0 ;
}

struct node *create_cll(struct node *start)
{
	struct node *newnode,*ptr;
	int number;
	printf("\n\n Enter -1 to END");
	printf("\n Enter the data :");
	scanf("%d",&number);
	while(number != -1)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = number;
		if(start == NULL)
		{
			newnode->next=newnode;
			start = newnode ;	
		}
		else
			{

			ptr = start;
			while(ptr->next != start )
				ptr = ptr->next;  
			ptr->next = newnode;
			newnode->next = start ;
			}
		//printf("\n Enter the data :");
		scanf("%d",&number);
	}
	return start;

}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr->next != start)
		{
		printf("\t%d",ptr->data);
		ptr = ptr->next;
		}
	printf("\t%d",ptr->data);
	return start;
}

struct node *insert_beg(struct node *start)
{
	struct node *newnode,*ptr ;
	int value ;
	printf("\n\n Enter the data :");
	scanf("%d",&value);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = value;
	ptr = start; 
	while(ptr->next != start)
		{
			ptr = ptr->next;
		}
	ptr->next = newnode;
	newnode->next = start;
	start = newnode;

return start;
	

}


struct node *insert_end(struct node *start)
{
	struct node *newnode,*ptr ;
	int value ;
	printf("\n\n Enter the data :");
	scanf("%d",&value);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = value;
	ptr = start; 
	while(ptr->next != start)
		{
			ptr = ptr->next;
		}
	ptr->next = newnode;
	newnode->next = start;
	
return start;
	

}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr->next != start)
		ptr = ptr -> next;
	ptr->next = start->next;
	free(start);
	start = ptr->next;
return start;
		
}

struct node *delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr = start;
	while(ptr->next != start)
		{
		preptr = ptr;
		ptr = ptr -> next;
		}
	preptr->next = ptr->next;
	free(ptr);
	return start;
		
}



struct node *delete_after(struct node *start)
{
	struct node *ptr, *preptr;
	int value;
	printf("\n Enter the data after which you have to delete node :");
	scanf("%d",&value);
	ptr = start;
	while(ptr->data != value)
		{
		preptr = ptr;
		ptr = ptr -> next;
		}
	preptr->next = ptr->next;
	if(ptr == start)
		start= ptr -> next;
	free(ptr);
return start;
		
}

struct node *delete_list(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr->next != start)
		ptr = ptr -> next;
	start = delete_end(start);
	free(start);
return start;
		
}


































































