//   BINARY SEARCH TREES   //
#include<stdio.h>
#include<malloc.h>

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
  Node cur,prev,temp;
  cur=root;
  prev=NULL;
  temp=getnode();
  printf("ENTER THE ELEMENT\n");
  scanf("%d",&temp->data);
  temp->llink=temp->rlink=NULL;
  if(root==NULL)
  return temp;
  while(cur)
  {
    prev=cur;
    if(temp->data==cur->data)
    {
      printf("ELEMENT IS ALREADY PRESENT IN THE LIST \n");
      free(temp);
      return root;
    }
    if(temp->data<cur->data)
    {
      cur=cur->llink;
    }
    else
    {
      cur=cur->rlink;
    }
  }
  if(temp->data<prev->data)
  {
    prev->llink=temp;
  }
  else
  {
    prev->rlink=temp;
  }
  return root;
}
Node minvaluednode(Node jan)
{
  Node cur=jan;
  while(cur->llink!=NULL)
  {
   cur=cur->llink;
  }
  return cur;
}
Node delete_(Node root,int key)
{
  Node jan;
  jan=root;
  if(root==NULL)
  {
    return root;
  }
  else if(key<root->data)
  {
    root->llink=delete_(root->llink,key);
  }
  else if(key>root->data)
  {
    root->rlink=delete_(root->rlink,key);
  }
  else
  {
    if(root->llink==NULL)
    {
      Node temp;
      temp=root->rlink;
      free(root);
      return temp;
    }
    if(root->rlink==NULL)
    {
      Node temp;
      temp=root->llink;
      free(root);
      return temp;
    }
    Node temp;
    temp=minvaluednode(root->rlink);
    root->data=temp->data;
    root->rlink=delete_(root->rlink,temp->data);
  }


}
void largest()
{
  Node cur,prev;
  cur=root;
  if(root==NULL)
  {
    printf("TREE IS EMPTY\n");
    return;
  }
  while(cur->rlink!=NULL)
  {
    cur=cur->rlink;
  }
  printf("THE LAST NODE IS %d ",cur->data);
  printf("\n");
}
void Smallest()
{
  Node cur;
  if(root==NULL)
  {
    printf("TREE IS EMPTY\n");
    return;
  }
  cur=root;
  while(cur->llink!=NULL)
  {
    cur=cur->llink;
  }
  printf("THE LAST NODE IS %d ",cur->data);
  printf("\n");
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
void search()
{
  int item;
  printf("ENTER THE SERACHING ELMENT\n");
  scanf("%d",&item);
  Node cur;
  cur=root;
  while(cur!=NULL)
  {
    if(item==cur->data)
    return;
    if(item<cur->data)
    {
      cur=cur->llink;
    }
     else
     {
       cur=cur->rlink;
     }
  }
  if(cur==NULL)
  {
    printf("ELEMENT NOT FOUND\n");
    return;
  }
  else
  {
    printf("ELEMENT FOUND\n");
  }
}
int max(int a,int b)
{
  return(a>=b)?a:b;
}
int height(Node root)
{
  Node jan;
  jan=root;
  if(root=NULL)
  return -1;
  return 1+max(height(jan->llink),height(jan->rlink));
}
void display(Node root,int level)
{ int i;
  if(root==NULL)
  return;
  display(root->rlink,level+1);
  for(i=0;i<level;i++) printf("  ");
  printf("%d\n",root->data);
  display(root->llink,level+1);

}
int main()
{
  for(;;)
  {
  int choice,ja,j;
  printf("ENTER \n1 INSERT\n2 DELETE\n3 Display\n4 SMALLEST\n");
  printf("5 Largest\n7 SEARCH\n");
  printf("8 PREORDER\n9 INORDER\n10 POSTORDER\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
      root=insert();
      break;
    case 2:
    printf("ENTRE THE ELEMENT HAT U WANT TO DELTE\n");
    scanf("%d",&ja);
      root=delete_(root,ja);
      break;
    case 3:
      display(root,0);
      break;
    case 4:
      Smallest();
      break;
    case 5:
       largest();
       break;
    case 7:
       search();
       break;
    case 8:
         preorder(root);
         printf("\n");
         break;
    case 9:
           inorder(root);
           printf("\n");
           break;
    case 10:
            postorder(root);
            printf("\n");
            break;
  }
}
}
