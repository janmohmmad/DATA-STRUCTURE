#include<stdio.h>
#include<malloc.h>
struct node{
  int data;
  struct node *link;
};
typedef struct node *Node;
Node start=NULL;
int count=0;
int ele;
Node getnode()
{
  count++;
  Node temp;
  temp=(Node)malloc(sizeof(struct node));
  return temp;

}
 void insert_rear()
{
  int i;
  do{
    Node temp;
    temp=getnode();
    printf("ENTER THE ELEMENT TO INSERT AT REAR END\n");
    scanf("%d",&temp->data);
    if(start==NULL)
    {
      start=temp;
      temp->link=NULL;
    }
    else
    {
      Node j;
      j=start;
      while (j->link!=NULL) {
       j=j->link;
      }
      j->link=temp;
      temp->link=NULL;
    }
    printf("ENTER 1 TO CONTINUE\n");
    scanf("%d",&i);
  }while(i==1);
}
void display()
{
  Node temp;
  temp=start;
  if(temp==NULL)
  {
    printf("TE LIST IS EMPTY\n");
    return;
  }
  else
  {
    while(temp!=NULL)
    {
      printf(" %d ",temp->data);
      temp=temp->link;
    }
  }
}
void delete_rear()
{
  Node temp;
  temp=start;
  if(start==NULL)
  {
    printf("LIST IS EMPTY\n");
  }
  if(temp->link==NULL)
  {
    printf("ITEM DELETED IS %d \n",temp->data);
    ele=temp->data;
    free(temp);
  }
else
  {
    while(temp->link->link!=NULL)
    {
      temp=temp->link;
    }
    Node j;
    j=temp->link;
    ele=j->data;
    printf("ITEM DELETED IS %d \n",j->data);
    free(j);
    temp->link=NULL;
      Node tempr;
      tempr=getnode();
    //  printf("ENTER THE ELEMENT TO INSERT AT REAR END\n");
      //scanf("%d",&temp->data);
      tempr->data=ele;
      if(start==NULL)
      {
        start=tempr;
        tempr->link=NULL;
      }
      else
      {
        Node j;
        j=start;
        tempr->link=start;
        start=tempr;
    }
  }
  }

int main()
{
   int choice,n,j;
   for(;;)
   {
   	 printf("enetr \n1 for insert \n2 for display \n3 for delete node\n");
   	 scanf("%d",&choice);
   	 switch(choice)
   	 {
   	 	case 1:
   	 	insert_rear();
   	 		break;
   	    case 2:
   	    	display();
   	    	break;
   	    case 3:
   	        delete_rear();
   	    	break;

		}
	}}
