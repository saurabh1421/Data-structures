#include<stdio.h>
#include<stdlib.h>
#define MAX 20 // you can alter size of queue by changing this

int queue[MAX];
int front = -1 , rear = -1;

void insert(void);
int delete_element(void);
int peek(void);
void display(void);

int main()
{
	int option ,value;
	do
	{	
		printf("\n--- MAIN MENU ---");
		printf("\n 1 : insert element");
		printf("\n 2 : Delete element");
		printf("\n 3 : peek");
		printf("\n 4 : dipslay queue");
		printf("\n 5 : exit");
		printf("\n Enter your option");
		scanf("%d",&value);
		switch(option)
		{	
			case 1 :
				insert();
				break;
			case 2 :
				value = delete_element();
				if(value != -1)
				printf("\n The element deleted from the queue is %d",value);
				break;
			case 3 : 
				value = peek();
				if(value != -1 )
				printf("\n The first element of the queue is %d",value);
				break;
			case 4 :
				display();
				break ;
		}
	}while(option != 5);
return 0;
}

void insert()
{
	int number ;
	printf("\n Enter the no. you want to insert in your queue");
	scanf("%d",&number);
	if(rear == MAX-1)
	printf("\n OVERFLOW");
	else if(front == -1 && rear == -1)
	front=rear=0;
	else 
	rear++;
	queue[rear] = number;
}

int delete_element()
{
	int value;
	if(front == -1 || front > rear)
	 {
		printf("\n UNDERFLOW");
		return -1;
		}
	else{
		value = queue[front];
		front++;
		//if(front > rear)
		//front = rear = -1;
		return value;
              }
			
}

int peek()
{
	int val;
	if(front != -1 || front > rear)
	printf("\n QUEUE IS EMPTY");
	else
		return queue[front];

}

void display()
{
	int i;
	if(front != -1 || front > rear)
	printf("\n QUEUE IS EMPTY");	
	else {
		for(i=front;i<=rear;i++)
		printf("\t %d",queue[i]);
	      }
}






















