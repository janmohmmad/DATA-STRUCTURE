#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int data,pov;
	struct node* link;
};
typedef struct node* Node;
Node poly1=NULL;
Node poly2=NULL;
Node polyyy=NULL;
Node getnode()
{
	Node x;
	x=(Node)malloc(sizeof(struct node));
	return x;
}
void create_pol1()
{
   int i;
   do
   {
   	int x,p;
	Node temp,test;
	temp=getnode();
	 printf("enter the coefficient\n");
	scanf("%d",&x);
   printf("enter the pover\n");
	 scanf("%d",&p);
	temp->data=x;
	temp->pov=p;
	if(poly1==NULL)
	{
		poly1=temp;
		temp->link=NULL;
	}
	test=poly1;
    while(test->link!=NULL)
    {
    	test=test->link;
	}
	test->link=temp;
	temp->link=NULL;
	printf("enter 1 to continue\n");
    scanf("%d",&i);
}while(i==1);
}
void display_pol1()
{
	Node temp;
	temp=poly1;
	if(poly1==NULL)
	{
		printf("The given list is empty\n");
		return ;
	}
    {
    	printf("the polynomial 1 is as : ");
    	while(temp!=NULL)
    	{
    		printf("%dX^%d",temp->data,temp->pov);
    		temp=temp->link;
    		if(temp!=NULL)
    		{
    			printf(" + ");
			}
		}
		printf(" \n");

	}
}
void create_pol2()
{
   int i;
   do
   {
		 int x,p;
    printf("enter the coefficient\n");
    scanf("%d",&x);
    printf("enter the pover\n");
    scanf("%d",&p);
	Node temp,test;
	temp=getnode();
	temp->data=x;
	temp->pov=p;
	if(poly2==NULL)
	{
		poly2=temp;
		temp->link=NULL;
	}
	test=poly2;
    while(test->link!=NULL)
    {
    	test=test->link;
	}
	test->link=temp;
	temp->link=NULL;
   	printf("enter 1 to continue\n");
    scanf("%d",&i);
}while(i==1);
}
void  add()
 {
   Node poly=getnode();
   polyyy=poly;
     while(poly1&&poly2)
	{
	 if(poly1->pov>poly2->pov)
	  {
		poly->data=poly1->data;
		poly->pov=poly1->pov;
		poly1=poly1->link;
	}
	else if(poly1->pov<poly2->pov)
	{

		poly->data=poly2->data;
		poly->pov=poly2->pov;
		poly2=poly2->link;
	}
	else
	{
		poly->data=poly1->data+poly2->data;
		poly->pov=poly1->pov;
		poly1=poly1->link;
		poly2=poly2->link;
	}
       poly->link=getnode();
        poly=poly->link;
	   //poly->link=NULL;
 }
  while(poly1||poly2)
{

	if(poly1->link)
	{
		poly->pov=poly1->pov;
		poly->data=poly1->data;
		poly1=poly1->link;
	}
	else
	{
	  poly->pov=poly2->pov;
		poly->data=poly2->data;
		poly2=poly2->link;
	}
	poly->link=getnode();
	poly=poly->link;

}
poly->link=NULL;
}
void display_pol2()
{
	Node temp;
	temp=poly2;
	if(poly2==NULL)
	{
		printf("The given list is empty\n");
		return ;
	}
    {
    	printf("the polynomial 1 is as : ");
    	while(temp!=NULL)
    	{
    		printf("%dX^%d",temp->data,temp->pov);
    		temp=temp->link;
    		if(temp!=NULL)
    		{
    			printf(" + ");
			}
		}
		printf(" \n");

	}
}
void display()
{
	Node temp;
	temp=polyyy;
	if(polyyy==NULL)
	{
		printf("The polynomail is empyt");
		return;
	}
	printf("The polynomial is as :\n");
	while(temp!=NULL)
	{
		printf("%dX^%d",temp->data,temp->pov);
		temp=temp->link;
		if(temp!=NULL)
		{
			printf(" + ");
		}

	}
		printf("\n");
}
int main()
{
	 int x,p;
	int n;
	for(;;)
	{
		printf("Enter\n1 Insert in poly1\n2 Insert in poly2\n3 Display poly1\n4 Display poly2\n5 ADD 2 ploynomials\n6 Display addition\n7 exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
        create_pol1();
				break;
		    case 2:
				 create_pol2();
				break;
			case 3:
			   display_pol1();
			   break;
			case 4:
			    display_pol2();
			   break;
		    case 5:
		        add();
			 break;
			 case 6:
			    display();
			 break;
			case 7:
			exit(0);
		}

	}
}
