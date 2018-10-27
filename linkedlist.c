#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
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
struct node *del_node(struct node *);
struct node *del_after(struct node *);
struct node *del_list(struct node *);
struct node *sort_list(struct node *);

int main()
{
	int option;
	do{
		printf("\n MAIN MENU");
		printf("\n 1:  create linked list");
		printf("\n 2:  Display linked list");
		printf("\n 3:  Add a node at beggining");
		printf("\n 4:  Add a node at END");
		printf("\n 5:  Add a node before a given node");
		printf("\n 6:  Add a node after a given node");
		printf("\n 7:  delete a node from beggining");
		printf("\n 8:  Delete a node at END");
		printf("\n 9:  Deletet a given node");
		printf("\n 10:  Delete a node after a given node");
		printf("\n 11:  Delete linked list");
		printf("\n 12:  Sort Linked List");
		printf("\n 13:  EXIT");
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

			case 9 : start = del_node(start);
				break;

			case 10 : start = del_after(start);
				break;

			case 11 : start = del_list(start);
				printf("\n\n Link list deleted");
				break;

			case 12 : start = sort_list(start);
				break;

			}
	}while(option!=13);
	return 0 ;

}
struct node *create_ll(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf("\n Enter -1 to end");
	printf("\n Enter the data");
	scanf("%d",&num);
	while(num != -1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data= num;
		if(start==NULL)
		{
			new_node->next=NULL;
			start= new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next != NULL)
			ptr=ptr->next;
			ptr->next=new_node;
			new_node->next= NULL;
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
	while(ptr->next != NULL)
	{
		printf("\t %d",ptr->data);
		ptr=ptr->next;
	}
	return start;

}
struct node *insert_beg(struct node *start)
{
	struct node *new_node ;
	int num;
	printf("\n Enter the data");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=start;
	start=new_node;
	return start;
}
struct node *insert_before(struct node *start)
{
	struct node *new_node,*ptr,*preptr;
	int num,val;
	printf("\n\n Enter the data");
	scanf("%d",&num);
	printf("\n\n Enter the value before the value has to be inserte");
	scanf("%d",&val);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data != val)
	{
			
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}

struct node *insert_after(struct node *start)
{
	struct node *new_node,*ptr,*preptr;
	int num,val;
	printf("\n\n Enter the data");
	scanf("%d",&num);
	printf("\n\n Enter the value after the value has to be inserte");
	scanf("%d",&val);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(preptr->data != val)
	{
			
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf("\n\n Enter th data");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=NULL;
	ptr=start;
	while(ptr->next != NULL)
	{
		ptr=ptr->next;
	}
	ptr-> next = new_node;
	new_node->next = NULL;
	return start;	
}
struct node *del_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	start=start->next;
	free(ptr);
	return start;
}
struct node *del_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next != NULL)
	{
	preptr=ptr;
	ptr=ptr->next;	
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
	
}
struct node *del_node(struct node *start)
{
	struct node *ptr, *preptr;
	int val;
	printf("\n\n Enter the value of node you want to delete");
	scanf("%d",&val);
	ptr= start;
	if(ptr->data == val)
	{
		start= del_beg(start);
		return start;
	
	}
	else{	
	while(ptr->data != val)
	{	
		preptr= ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
	}
}
struct node *del_after(struct node *start)
{
	struct node *ptr,*preptr;
	int val;
	printf("\n\n Enter the value after which you have to del node");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data != val)
	{	
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;

}
struct node *del_list(struct node *start)
{
	struct node *ptr ;
	if(start != NULL)
	{
		ptr = start;
		while(ptr != NULL)
		{
			printf("\n\n %d is to be deleted next",ptr->data);
			start= del_beg(ptr);
			ptr=start;
		}
	}
	return start;
}
struct node *sort_list(struct node *start)
{
	struct node *ptr1 ,*ptr2;
	int temp ;
	ptr1 = start;
	while(ptr1-> next != NULL)
	{
		ptr2 = ptr1->next;
		while(ptr2 != NULL)
		{
			if(ptr1->data > ptr2->data)
			{
				temp = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data=temp;
			}ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}	
	return start;
}


































































































