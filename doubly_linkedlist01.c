#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next, *prev;
};
typedef struct node *Node;
Node start=NULL;
int count=0;
Node getnode()
{
  count++;
  Node x;
  x=(Node)malloc(sizeof(struct node));
  return x;
}
void insert_front()
{
  int i;
  do{
    Node temp,j;
    j=start;
    temp=getnode();
    printf("ENTER THE ITEM\n");
    scanf("%d",&temp->data);
    if(start==NULL)
    {
      start=temp;
      temp->next=NULL;
    //  temp->prev=NULL;
    }
    else
    {
      temp->next=start;
      start->prev=temp;
      start=temp;
    }
    printf("ENTER 1 To CONTINUE\n");
    scanf("%d",&i);
  }while(i==1);
}


void display()
{
  Node temp;
  temp=start;
  if(start==NULL)
  {
    printf("LIST IS EMPTY\n");
    return;
  }
  else
  {
    printf("THE ITEMS IN THE LIST IS AS \n");
    while(temp!=NULL)
    {
      printf("%d ",temp->data);
      temp=temp->next;
    }
    printf("\n");
  }
}

void insert_rear()
{
  int i;
  do{
    Node temp,x;
    x=start;
    temp=getnode();
    printf("ENTER THE ITEM\n");
    scanf("%d",&temp->data);
    if(start==NULL)
    {
      start=temp;
      temp->next=NULL;
      temp->prev=start;
    }
    else
    {
      while(x->next!=NULL)
      {
        x=x->next;
      }
      x->next=temp;
      temp->next=NULL;
      temp->prev=x;
    }
    printf("ENTER 1 To CONTINUE\n");
    scanf("%d",&i);
  }while(i==1);
}
void insert_at_given_adress()
{
  int i,n;
  do{
    Node temp,x;
    x=start;
    temp=getnode();
    printf("ENTER THE ITEM\n");
    scanf("%d",&temp->data);
    printf("ENTER THE LOCATION\n");
    scanf("%d",&n);
    if(n<=count)
    {
    for(i=1;i<n-1;i++)
    {
      x=x->next;
    }
    temp->next=x->next;
    x->next=temp;
    temp->prev=x;
  //  x->next->prev=temp;
    //x->next=temp;
    //temp->prev=x;
    }
    else
    {
      printf("Y ENTERED WRONG LIOCATION\n");
      return;
    }
    printf("ENTER 1 To CONTINUE\n");
    scanf("%d",&i);
  }while(i==1);
}
void delete_front()
{
  int i;
  do{
    Node temp;
    if(start==NULL)
    {
      printf("LIST IS EMPTY\n");
      return;
    }
    else if(start->next==NULL)
    {
      printf("THE ITEM DELETD IS  %d \n ",start->data);
      free(start);
      return;
    }
    else
     {
      temp=start;
      start=temp->next;
      start->prev=NULL;
      printf("THE ITEM DELETD IS %d\n",temp->data);
      free(temp);
    }
    printf("ENTER 1 To CONTINUE\n");
    scanf("%d",&i);
    }while(i==1);
  }
void delete_rear()
{
  int i;
  do{
    Node temp,x;
    temp=start;
    if(start==NULL)
    {
      printf("LIST IS EMPTY\n");
      return;
    }
    else if(start->next==NULL)
    {
      printf("THE ITEM DELETD IS  %d \n ",start->data);
      free(start);
      return;
    }
    else
    {
      while(temp->next->next!=NULL)
      {
        temp=temp->next;
      }
      x=temp->next;
      printf("ITEM DELETED IS %d \n",x->data);
      free(x);
      temp->next=NULL;

    }
    printf("ENTER 1 To CONTINUE\n");
    scanf("%d",&i);
    }while(i==1);

}
void delete_at_location()
{
    int l;
    printf("Enter the location\n");
    scanf("%d",&l);
    if(l<= count)
    {
      Node j;
      j=start;
      int i;
      for(i=1;i<l-1;i++)
      {
        j=j->next;
      }
      Node r;
      r=j->next;
      j->next=j->next->next;
      j->next->next->prev=j;
      printf("item deleted is %d ",r->data);
      free(r);
     }
     else
     {
       printf("Y entered wrong loaction\n");
     }
}
int main()
{
   int choice,n,j;
   for(;;)
   {
   	 printf("ENETER \n1 TO INSERT AT FRONT\n2 TO INSERT AT END \n3 TO INSERT AT A GIVEN LOCATION\n4 TO DISPLAY\n");
     printf("5 DELETE FRONT NODE\n6 DELETE LAST NODE\n7 Exit\n");
   	 scanf("%d",&choice);
   	 switch(choice)
   	 {
   	 	case 1:
   	      insert_front();
   	 		  break;
      case 2:
          insert_rear();
          break;
   	  case 3:
   	      insert_at_given_adress();
   	   	  break;
      case 4:
          display();
          break;
      case 5:
           delete_front();
            break;
      case 6:
            delete_rear();
            break;
   	  case 7:
        delete_at_location();
        break;
		}
}
}
