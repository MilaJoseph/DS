2 VARIABLES POLY ADD 
---------------------------
#include<stdio.h>
#include<stdlib.h>

struct node
{
  int coeff;
  int ex1;
  int ex2;
  struct node *link;
};

struct node* insert(struct node *head,int coeff,int ex1,int ex2)
{
  struct node *temp;
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->coeff=coeff;
  newnode->ex1=ex1;
  newnode->ex2=ex2;
  newnode->link=NULL;
  
  if(head==NULL || ex1 > head->ex1)
  {
    newnode->link=head;
    head=newnode;
  }
  else
  {
    temp=head;
    while(temp->link!=NULL && temp->link->ex1>=ex1)
    {
      temp=temp->link;
    }
     newnode->link=temp->link;
     temp->link=newnode;
  }
  return head;
}

struct node* create(struct node *head)
{
  int n,i;
  int coeff;
  int ex1,ex2;
  
  printf("Enter the number of terms: ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Coefficient of term %d: " ,i+1);
    scanf("%d",&coeff);
    printf("Exponent1 of term %d: " ,i+1);
    scanf("%d",&ex1);
    printf("Exponent2 of term %d: "
       ,i+1);
    scanf("%d",&ex2);
    head=insert(head,coeff,ex1,ex2);
  }
  return head;
}

void print(struct node *head)
{
  if(head==NULL)
  {
    printf("No polynomial\n");
  }
  else
  {
    struct node *ptr=head;
    while(ptr!=NULL)
    {
      printf("(%dx^%dy^%d)",ptr->coeff,ptr->ex1,ptr->ex2);
      ptr=ptr->link;
      if(ptr!=NULL)
      {
        printf(" + ");
      }
      else
      {
        printf("\n");
      }
    }
  }
}

void add(struct node *head1,struct node *head2)
{
   struct node *ptr1=head1;
   struct node *ptr2=head2;
   struct node *head3=NULL;
   
   while(ptr1!=NULL && ptr2!=NULL)
   {
     if((ptr1->ex1==ptr2->ex1)&&(ptr1->ex2==ptr2->ex2))
     {
       head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->ex1,ptr1->ex2);
       ptr1=ptr1->link;
       ptr2=ptr2->link;
     }
     else if(ptr1->ex1>ptr2->ex1)
     {
        head3=insert(head3,ptr1->coeff,ptr1->ex1,ptr1->ex2);
        ptr1=ptr1->link;
     }
     else if(ptr1->ex1<ptr2->ex1)
     {
       head3=insert(head3,ptr2->coeff,ptr2->ex1,ptr2->ex2);
       ptr2=ptr2->link;
     }
     else if((ptr1->ex1==ptr2->ex1)&&(ptr1->ex2>ptr2->ex2))
     {
       head3=insert(head3,ptr1->coeff,ptr1->ex1,ptr1->ex2);
       ptr1=ptr1->link;
     }
     else if((ptr1->ex1==ptr2->ex1)&&(ptr1->ex2<ptr2->ex2))
     {
       head3=insert(head3,ptr2->coeff,ptr2->ex1,ptr2->ex2);
       ptr2=ptr2->link;
     }
   }
   while(ptr1!=NULL)
   {
     head3=insert(head3,ptr1->coeff,ptr1->ex1,ptr1->ex2);
     ptr1=ptr1->link;
   }
   while(ptr2!=NULL)
   {
     head3=insert(head3,ptr2->coeff,ptr2->ex1,ptr2->ex2);
     ptr2=ptr2->link;
   }
  printf("Added polynomial is\n");
  print(head3);
}
void main()
{
  struct node *head1=NULL;
  struct node *head2=NULL;
  printf("Enter the first polynomial\n ");
  head1=create(head1);
  printf("Enter second polynomial\n");
  head2=create(head2);
  
  add(head1,head2);
}
