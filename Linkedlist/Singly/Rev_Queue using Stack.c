(LL)REVERSED QUEUE USING STACK
----------------------------------------------------------------------
#include <stdio.h>
#include<stdlib.h>

struct queue
{
  int data;
  struct queue* link;
};
struct queue *front=NULL;
struct queue *rear=NULL;

struct stack
{
  int data;
  struct stack* link;
};
struct stack *top=NULL;

void enqueue(int);
void dequeue();
void push(int);
void pop();
void display();
void reverse();

void main()
{
  int choice=1,item;
  printf("1-Enqueue\n2-Display\n3-Reverse\n");
  do
  {
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:printf("Enter the value to be enqueued: ");
      scanf("%d",&item);
      enqueue(item);
      break;
    
    case 2:display();
         break;
    case 3: printf("Reversed queue is: ");
           reverse();
           break;
    default: printf ("Invalid choice\n");
        break;
    }
  }
  while(choice<=3);
  
}

void enqueue(int item)
{
  struct queue *newnode;
  newnode=(struct queue*)malloc(sizeof(struct queue));
  if((front==NULL)&&(rear==NULL))
  {
    front=rear=newnode;
    rear->data=item;
    rear->link=NULL;
  }
  else
  {
    rear->link=newnode;
    newnode->data=item;
    newnode->link=NULL;
    rear=newnode;
  }
}

void display()
{
  struct queue *ptr;
  if((front==NULL)&&(rear==NULL))
  {
    printf("Queue empty\n");
    return;
  }
  ptr=front;
  while(ptr->link!=NULL)
  {
    printf("%d\t",ptr->data);
    ptr=ptr->link;
  }
  printf("%d\n",ptr->data);
}

void reverse()
{
  while(front!=NULL)
  {
     dequeue();
  }
  
  front=rear=NULL;

  while(top!=NULL)
  {
    pop();
  }

  
  display();
}

void push(int item)
{
  struct stack *newnode;
  newnode=(struct stack*)malloc(sizeof(struct stack));
  
  if(top==NULL)
  {
     top=newnode;
     top->data=item;
     top->link=NULL;
     return;
  }
   newnode->data=item;
   newnode->link=top;
   top=newnode;
}

void dequeue()
{
  struct queue *ptr;
  int item;
  
  if(front==NULL)  
  {
    printf("Queue empty\n");
  }
  else
  {
    item=front->data;
    push(item);
    ptr=front->link;
    free(front);
    front=ptr;
  }
}

void pop()
{
  struct stack *ptr;
  int item;
  if(top==NULL)
  {
     printf("Stack empty\n");
     return;
  }
  item=top->data;
  enqueue(item);
  ptr=top->link;
  free(top);
  top=ptr;
}
