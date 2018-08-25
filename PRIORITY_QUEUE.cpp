//            ******priority queue***
#include<stdio.h>
#define size 5
int q[20];
int f=-1;
int r=-1;
void insert()
{
 int i;
 do{
   int e,j;
   printf("Enter the element\n");
   scanf("%d",&e);
   if(r==-1)
   {
     f=0;
   }
   if(r==size-1)
   {
     printf("STACK OVERFLOW\n");
     return;
   }
   else
   {
     j=r;
     while(j>=0&&e>q[j])//desending order
     {
       q[j+1]=q[j];
       j--;
     }
     q[j+1]=e;
        r=r+1;
   }
 printf("ENTER 1 TO CONTINUE\n");
 scanf("%d",&i);
}while(i==1);
}
void delete_()
{
  if(f==-1)
  {
    printf("STACK UNDERFLOW\n");
    retu#include<stdio.h>
rn;
  }
  else if(f>r)
  {
    f=-1;
    r=-1;
  }
  else
  {
    printf(" item deleted id %d at %d location \n",q[f++],f);
  }
}
void display()
{
  if(f>r)
  {
    printf("stack is empty\n");
    return;
  }
  else
  {
    int i;
    printf("elements in the stack are as : ");
    for(i=f;i<=r;i++)
    {
      printf("%d ",q[i]);
    }
  }
}
int main()
{
   int choice,n,j;
   for(;;)
   {
     printf("enetr \n1 INSERT \n2 DELETE \n3 DISPLAY\n");
     scanf("%d",&choice);
     switch(choice)
     {
       case 1:
       insert();
       break;
       case 2:
       delete_();
        break;
        case 3:
        display();
        break;
}} }
