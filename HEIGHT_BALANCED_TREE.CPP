#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
# define bool int
struct node{
  int data;
  struct node *llink;
  struct node *rlink;
};
typedef struct node *Node;
Node root=NULL;
Node getnode()
{
   return((Node)malloc(sizeof(struct node)));
}
Node insert()
{
  Node prev;
  Node cur;
  Node temp;
  int i,J;
  char direction[10];
  temp=getnode();
  printf("ENTER THE DATA\n");
  scanf("%d",&J);
  temp->data=J;
  temp->llink=temp->rlink=NULL;
  if(root==NULL)
  return temp;
  //strupr(direction);
  printf("ENTER THE DIRECTION IN WHICH U WANT TO INSERT THE DATA BUT IN UPPERCASE\n");
  scanf("%s",direction);
  cur=root;
  prev=NULL;
  for(i=0;i<strlen(direction);i++)
  {
    if(cur==NULL)
    break;
    prev=cur;
    if(direction[i]=='L')
    cur= cur->llink;
    else
    cur=cur->rlink;
  }
  if(cur!=NULL||i!=strlen(direction))
  {
    printf("INSERTION IS NOT POSSIBLE\n");
    free(temp);
    return root;
  }
  if(direction[i-1]=='L')
    prev->llink=temp;
  else
   prev->rlink=temp;
   return root;
}
int max(int a,int b)
{
  return (a>=b)?a:b;
}
int height(Node root)
{
  if(root==NULL)
  return 0;
  return 1+max(height(root->llink),height(root->rlink));
}
bool isbalanced(Node root)
{
  int lh,rh;
  if(root==NULL)
  return 1;
  lh=height(root->llink);
  rh=height(root->rlink);
  if(abs(lh-rh)<=1&&isbalanced(root->llink)&&isbalanced(root->rlink))
  return 1;
  return 0;
}

int main()
{
  for(;;)
  {
  int choice;
  printf("ENTER \n1 INSERT\n2 height\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
      root=insert();
      break;
    case 2:
      if(isbalanced(root))
      {
        printf("TREE IS BALANCED\n");
      }
      else
      {
        printf("TREE IS NOT BALANCED\n");
      }
      break;
  }
}
}
