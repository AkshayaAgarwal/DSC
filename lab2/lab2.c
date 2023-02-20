#include<stdio.h>
#include<stdlib.h>
#include <time.h>

struct node
{
int data;
struct node *next;
};
struct node *front;
struct node *rear;
struct node *middle;
void insertNode(struct node *ptr, int item)
{

ptr = (struct node *) malloc(sizeof(struct node));
if (ptr == NULL)
	{
	printf("\nOVERFLOW\n");
	return;
	}
else
	{
ptr -> data = item;
if (front == NULL)
	{
	front = ptr;
	rear = ptr;
	front -> next = NULL;
	rear -> next = NULL;
	}
else
	{
	rear -> next = ptr;
	rear = ptr;
	rear -> next = NULL;
	}
}
}
void deleteNode()
{
if (front == NULL)
{
printf("Underflow");
return;
}
else
{
printf("Element deleted : %d", front -> data);
front = front -> next;
}
}
void displayNode()
{
int i=1;
if (front == NULL)
{
printf("Underflow");
return;
}
else
{
middle = front;
printf("The elements are: ");
while(i>0)
{
printf("\n%d-> %d", i, middle->data);
if(middle==rear)
{
break;
}
i++;
middle = middle -> next;
}
}
}
void main()
{
struct node *head = NULL;
int ch=1, val;
srand(time(NULL));
val=rand()%10;

while(ch!=0)
{
printf("\nAkshaya Agarwal\n2247207\nChoose from the following: \n1. Insert data into queue\n2. Delete data from queue\n3. View the Queue \n0.Exit\nEnter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 0:
printf("Ok Bye! Take care");
break;
case 1:
//printf("Enter the value you want to insert: ");
srand(time(NULL));
val=rand()%10;
//scanf("%d", &val);
insertNode(head, val);
printf("Inserted value is %d", val);
break;
case 2:
deleteNode();
break;
case 3:
displayNode();
break;
default:
printf("Invalid Input. Please try again.");
}
}
}
