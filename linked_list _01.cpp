#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
	int data;
 struct node *link;
};
 typedef struct node *NODE;
  NODE first=NULL;
 int count=0;
 NODE getnode()
 {
 	   count++;
   NODE x;
   x=(NODE)malloc(sizeof(struct node));
   if(x==NULL)
    {
   printf("out of memory\n");
   exit(0);
    }
   else
   return x;

  }
	void boss()
	{
		NODE temp;
		temp=first;
		while(temp->link->link!=NULL)
		{
			temp=temp->link;
		}
		printf("ELEMENT deleted id %d ",temp->link->data);
		free(temp->link);
		temp->link=NULL;
	}
  NODE insert_font(int item)
  {
  	NODE temp;
  	temp=getnode();
  	temp->data=item;
  	temp->link=first;
  	return temp;
  }
  NODE reverse_list()
  {
  	NODE nextnode,prev,cur;
  	nextnode=NULL;
  	prev=NULL;
  	cur=first;
  	while(cur)
  	{
  		nextnode=cur->link;
  		cur->link=prev;
  		prev=cur;
  		cur=nextnode;
	  }
	  return prev;
  }
  NODE  insert_at_anyplace(int b)
  { NODE j;
  j=getnode();
    int n;
  	printf("enetr the no\n");
	scanf("%d",&n);
     j->data=n;
  	  NODE  temp;
  	  temp=first;
  	  while(temp->data!=b)
  	  {
  	  	temp=temp->link;
		}
	j->link=temp->link;
	temp->link=j;
	return first;

  }
  void display()
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
  void delete_at_given_location()
  {
  	int l,i;
  	NODE temp,p;
  	temp=first;
  	printf("ENTER THE LOCATION WHERE U WANT TO DELETE\n");
  	scanf("%d",&l);
  	if(l<=count)
  	{

  	for(i=1;i<l-1;i++)
  	{
  		temp=temp->link;
	  }
	  p=temp->link;
	  temp->link=temp->link->link;
	  printf("THE DELETED ITEM IS %d",p->data);
	  free(p);
}
   else
    {
    	printf("YOU ENTERED WRONG LOCATION\n");
	}
}
 void  deleteN_front()
  {
  	 NODE temp;
  	if(first==NULL)
  	{
  		printf("list is empty\n");
  		exit;
	  }
	  else
	  {

     	temp=first;
	    first=first->link;
	    printf("the item deleted is %d\n",temp->data);
	    free(temp);
	  }
  }
 void  delete_at_location()
  {
  	int n;
  	NODE temp,t;
  	temp=first;
  	printf("Enetr the data of the particular node that i wnt to delete\n");
  	scanf("%d",&n);
  	while(temp->link->data!=n)
  	{
  		temp=temp->link;
	  }
	  t=temp->link;
	  temp->link=temp->link->link;
	  printf("the item deleted is %d ",t->data);
	  free(t);
  }
 void delete_rear()
  {
  	NODE temp=first;
  	if(first==NULL)
  	{
  	  printf("the list is empty"); }
	 else if(temp->link==NULL)
	 {
	 	printf(" THE ELEMENT DELETED IS %d \n",temp->data);
	 	free(temp);
	 }
	  else
	  {
	  	while(temp->link->link!=NULL)
	  	{
	  		temp=temp->link;
		  }
		  free(temp->link->link);
		  temp->link=NULL;
	  }
  }
  void sort()
  {
  	NODE p,q;
  	for(p=first;p!=NULL;p=p->link)
  	 for(q=p;q!=NULL;q=q->link)
	  {
  	    if(p->data>q->data)
  		{
  			int temp;
  			temp=p->data;
  			p->data=q->data;
  			q->data=temp;
		  }

	  }
  }
void  insert_rear()
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
 //		return;
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
 NODE insert_at_given_adress()
 {
    NODE temp,N;
    temp=first;
    int l,i,item;
 	printf("Enetr the valies location\n");
 	scanf("%d",&l);
 	for(i=1;i<l-1;i++)
     {
     	temp=temp->link;
	 }
	 printf("Enter the Data that u want to enter in this location\n");
	 scanf("%d",&item);
	 N=getnode();
	 N->data=item;
	 N->link=temp->link;
	 temp->link=N;
	 return first;
 }
  NODE insert_increasing()
{
	int i;
	do{
		int d;
		printf("Eneter the data\n");
		scanf("%d",&d);
		NODE j,prev;
		j=getnode();
		j->data=d;
		NODE temp;
		temp=first;
		if(d<temp->data)
		{
			j->link=first;
			return j;
		}
		 while(temp!=NULL&&temp->data<d)
		{
			prev = temp;
			temp=temp->link;
		}
		j->link=temp;
		prev->link=j;
		return first;
	printf("TO continue PRESS 1\n");
	scanf("%d",i);
}while(i==1);
}

int main()
{
   int choice,n,j;
   for(;;)
   {
   	 printf("enetr \n1 INSERT AT FRONT \n2 DISPLAY \n3 DELETE FRONT NODE");
		 printf("\n4INSERTION AT ANY POSITION\n5 DELETE FROM REAR END");
		 printf("\n6 INSERT AT REAR END\n7 INSERT AT A PARTICULAR LOCATION");
		 printf("\n8 DELETE A PARTICULAR DATA ITEM\n9 INSERT INCREASING\n10 sort");
		 printf("\n11 DELETE AT A GIVEN LIOCATION\n12 REVERSE THE LIST\n");
   	 scanf("%d",&choice);
   	 switch(choice)
   	 {
   	 	case 1:
   	 		printf("enetr the no\n");
   	 		scanf("%d",&n);
   	 		first=insert_font(n);
   	 		break;
   	    case 2:
   	    	display();
   	    	break;
   	    case 3:
   	        deleteN_front();
   	    	break;
   	    case 4:
   	    	printf("enetr the no\n");
   	 		scanf("%d",&n);
		   first=insert_at_anyplace(n);
		   break;
		case 5:
		boss();
		   break;
		case 6:

		 insert_rear();
		 break;
		 case 7:
		 	first=insert_at_given_adress();
		 	break;
		case 8:
		  delete_at_location();
		  break;
		case 9:
		  first= insert_increasing();
			break;
		case 10:
		   sort();
		    break;
		case 11:
		delete_at_given_location();
		break;
   	    case 12:
		  first=reverse_list();
		}


	}


}
/*#define stacksize 5
        //-------------------------------
void push(int item,int*top,int s[] );
int pop(int *top,int s[]);
void display(int,int s[]);
int main()
{
	int s[10];
	int n,del,choice,top;
	printf("enetr \n1 push\n2 pop\n3 delete\n4 exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
	  case 1:
	  	printf("enter the  no\n");
	  	scanf("%d",&n);
	  	push(n,&top,s);
	  	break;
	  case 2:
	    del=pop(&top,s);
		printf("element deleted is : %d",del);
		break;
	   case 3:
	   display(top,s);
	   break;
	   case 4:
	   exit(0);
	}
}

 void push(int item,int *top,int s[])
 {
 	if(*top==stacksize-1)
 	printf("stack overflow\n");
 	else
 	*top=*top+1;
 	s[*top]=item;
 }
int  pop(int *top,int s[])
{ int item_del;
	if(*top==-1)
	printf("stack is empty\n");
	else
	item_del=s[*top];
	*top=*top--;
	return item_del;
}
void dispaly(int top,int s[])
{ int i;
	if(top==-1)
	printf("stack is empty\n");
	else
	for(i=0;i<=top;i++)
	{
		printf("elements in the stack are as : %d ",s[i]);
	}
}*/
