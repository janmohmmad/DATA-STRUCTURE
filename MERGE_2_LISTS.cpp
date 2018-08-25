#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* link;
};
typedef struct node* NODE;
NODE start=NULL;
NODE first=NULL;
NODE second=NULL;
NODE getnode()
{
  NODE x;
  x=(NODE)malloc(sizeof(struct node));
  return x;
}
void  insert_ist()
 {
 	int i;
 	do{
 	int l;
	printf("enetr the no\n");
  scanf("%d",&l);
 	NODE temp,end;
 	end=getnode();
 	end->data=l;
 	temp=first;
 	if(first==NULL)
 	{
 		first=end;
 		end->link=NULL;
	 }
	 else{
 	while(temp->link!=NULL)
 	{
 		temp=temp->link;
	 }
	 temp->link=end;
	 end->link=NULL;
}
	printf("ENTER 1 TO CONTINUE\n ");
	scanf("%d",&i);
 }while(i==1);
}
void  insert_2nd()
 {
 	int i;
 	do{
 	int l;
  printf("ENTER THE DATA IN DISENDING ORDER\n");
	printf("enetr the no\n");
  scanf("%d",&l);
 	NODE temp,end;
 	end=getnode();
 	end->data=l;
 	temp=second;
 	if(second==NULL)
 	{
 		second=end;
 		end->link=NULL;
	 }
	 else{
 	while(temp->link!=NULL)
 	{
 		temp=temp->link;
	 }
	 temp->link=end;
	 end->link=NULL;
}
	printf("ENTER 1 TO CONTINUE\n ");
	scanf("%d",&i);
 }while(i==1);
}
void display_ist()
{
  NODE temp;
  if(first==NULL){
    printf("empty\n");
    return;
  }
  printf("elements in the list are as : ");
  temp=first;
  while(temp!=NULL)
  {
    printf("%d",temp->data);
    temp=temp->link;
    printf(" ");
  }
  printf("\n");
}
void display_2nd()
{
  NODE temp;
  if(second==NULL){
    printf("empty\n");
    return;
  }
  printf("elements in the list are as : ");
  temp=second;
  while(temp!=NULL)
  {
    printf("%d",temp->data);
    temp=temp->link;
    printf(" ");
  }
  printf("\n");
}
void  merge()
{
  NODE temp;
  NODE x;
  NODE y;
  temp=getnode();
  start=temp;
  x=first;
  y=second;
  while(x!=NULL && y!=NULL)
  {

    if(x->data>y->data)
    {
      temp->data=x->data;
      x=x->link;
    }
    else
    {
      temp->data=y->data;
      y=y->link;
    }
    temp->link=getnode();
    temp=temp->link;
  }
 while(x!=NULL||y!=NULL)
  {
    if(x !=NULL)
    {
      temp->data=x->data;
      x=x->link;
    }
  else
    {
      temp->data=y->data;
       y=y->link;
    }
    temp->link=getnode();
    temp=temp->link;
  }
 temp->link=NULL;
}
void display_merge_list()
{
  NODE x;
  if(start==NULL)
  {
    printf("empty\n");
    return;
  }
  printf("elements in the list are as : ");
  x=start;
  while(x!=NULL)
  {
    printf("%d",x->data);
    x=x->link;
    printf(" ");
  }
  printf("\n");
}
void sort_ist()
{
  NODE i,j;
  int temp;
  for(i=first;i!=NULL;i=i->link)
  {
    for(j=i->link;j!=NULL;j=j->link)
    {
      if(i->data>j->data)
      {
        temp=i->data;
        i->data=j->data;
        j->data=temp;
      }
    }
  }
}
void sort_2nd()
{
  NODE i,j;
  int temp;
  for(i=second;i!=NULL;i=i->link)
  {
    for(j=i->link;j!=NULL;j=j->link)
    {
      if(i->data>j->data)
      {
        temp=i->data;
        i->data=j->data;
        j->data=temp;
      }
    }
  }
}
int main()
{
  int choice;
  for(;;)
  {
    printf("ENTER\n1 INSERT IN FIRST\n2 INSERT IN 2ND\n3 DISPLAY IST\n4 DISPLAY 2ND\n5 ");
    printf("MERGE TWO  LISTS \n6 DISPLAY MERGED LIST\n7 SORT IST LIST\n8 SORT 2ND\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
       insert_ist();
       break;
      case 2:
       insert_2nd();
       break;
      case 3:
       display_ist();
       break;
      case 4:
         display_2nd();
         break;
      case 5:
        merge();
         break;
      case 6:
         display_merge_list();
         break;
      case 7:
         sort_ist();
         break;
      case 8 :
       sort_2nd();
       break;

        }
  }
}
