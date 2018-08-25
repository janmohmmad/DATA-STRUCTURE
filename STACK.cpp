#include<stdio.h>
#define stacksize 5
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
}
