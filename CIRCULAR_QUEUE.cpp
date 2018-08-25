//*******circular queue using  array****
#include<stdio.h>
#define size 5
int front=0;
int rear=0;
int q[20];
void enqueue()
{
  int i;
  printf("ENTER THE ITEM\n");
  scanf("%d",&i);
  rear=(rear+1)%size;
  if(rear==front)
  {
    printf("queue is full\n");
    if(rear==0)
    rear=size-1;
    else
    rear=rear-1;
    return;
  }
  else
  {
    q[rear]=i;
    return;
  }

}
void dequeue()
{
  if(front==rear)
  {
    printf("queue is empty\n");
    return;
  }
  else
  {
    int j;
    front=(front+1)%size;
    j=q[front];
    printf("item deleted is %d ",j);
  }

}
void display()
{
  if(front==rear)
  {
    printf("queue is empty\n");
    return;
  }
  else
  {
    int i;
    for(i=front+1;i<=rear;i++)
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
       enqueue();
       break;
       case 2:
       dequeue();
        break;
        case 3:
        display();
        break;
}} }
