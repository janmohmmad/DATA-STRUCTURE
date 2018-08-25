#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *llink;
  struct node *rlink;
};
typedef struct node* Node;
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
void  preorder(Node root)
{
  if(root==NULL)
  return;
  printf(" %d ",root->data);
  preorder(root->llink);
  preorder(root->rlink);
}
void  inorder(Node root)
{
  if(root==NULL)
  return ;
  inorder(root->llink);
  printf(" %d ",root->data);
  inorder(root->rlink);
}
void  postorder(Node root)
{
  if(root==NULL)
  return ;
  postorder(root->llink);
  postorder(root->rlink);
  printf(" %d ",root->data);
}
void display(Node root,int level)
{
  int i;
  if(root==NULL)
  return;
  display(root->rlink,level+1);
  for(i=0;i<level;i++)
  printf("  ");
    printf("%d\n",root->data);
    display(root->llink,level+1);
}
void search_inorder(int item, Node root,int *flag)
{
 if(root==NULL)
 return;
  search_inorder(item,root->llink,flag);
  if(item==root->data)
  {
    *flag=1;
    return;
  }
  search_inorder(item,root->rlink,flag);
}
void mirror(Node root)
{
  Node jan,temp;
  jan= root;
  if(jan==NULL)
  return;
   mirror(root->llink);
   mirror(root->rlink);
   temp=jan->llink;
   jan->llink=jan->rlink;
   jan->rlink=temp;

}
int main()
{
  int choice;
  for(;;)
  {
  printf("ENTER\n1 INSERT\n2 PREORDER TRAVERSAL\n3 INORDER TRAVERSAL\n4\ POSTORDER TRAVERSAL");
  printf("\n5 GRAPHIC VIEW\n6 SERACH GIVEN ELEMENT\n7 MIRROR IMAGE ID TREE\n");
  scanf("%d",&choice);
    switch(choice)
  {
    case 1:
      root=insert();
      break;
    case 2:
      preorder(root);
      printf("\n");
      break;
    case 3:
        inorder(root);
        printf("\n");
        break;
   case 4:
         postorder(root);
         printf("\n");
         break;
    case 5:
          printf("GRAPHIC VIEW IS AS : \n");
          display(root,1);
          break;
    case 6:
          int item;
          int flag;
          flag=0;
          printf("ENTER THE ITEM THAT U WANT TO SERACH\n");
          scanf("%d",&item);
          search_inorder(item,root,&flag);
          if(flag==1)
          {
            printf("MUBARAK MUBARAK YEH NUMBER AAP KA TREE MA HA\n");
          }
          else
          {
            printf("MAZRAT YE NUMBER AIS TREE MA NAHI MAJODD HA \n");
          }
          break;
     case 7:
          mirror(root);
          break;
  }
}
}
