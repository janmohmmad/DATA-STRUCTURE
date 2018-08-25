#include<stdio.h>
#include<malloc.h>
struct node{
  int vertices;
  struct node *link;
};
typedef struct node *Node;
Node Adj[10];
Node getnode()
{
  return (Node)malloc(sizeof(struct node));
}
void create_graph(int no_vertices)
{
  int i, j,k,n;
  Node last,new_node;
  for(i=0;i<no_vertices;i++)
  {
    last=NULL;
    printf("ENTER THE NO OF NEIGHBOURS OF %dTH vertex ",i);
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
      printf("Enter the neighbour %dth of %dTH vertex ",j,i);
      new_node=getnode();
      scanf("%d",&new_node->vertices);
      new_node->link=NULL;
      if(Adj[i]==NULL)
       Adj[i]=new_node;
       else
       last->link=new_node;
       last=new_node;
    }
  }
}
  void display(int no_vertices)
  {
    Node temp,ptr;
   int i;
   for(i=0;i<no_vertices;i++)
   {
     ptr=Adj[i];
     printf("\nTHE NEIGHBOUR OF %dTH VERTICES ARE:",i);
     while(ptr!=NULL)
     {
       printf("\t %d ",ptr->vertices);
       ptr=ptr->link;
     }
   }
  }
int main()
{
  int no_vertices,i,j;
  printf("Enter the no of Vertice of a graph\n");
  scanf("%d",&no_vertices);\
  for(i=0;i<no_vertices;i++)
  {
    Adj[i]=NULL;
  }
  create_graph(no_vertices);
  display(no_vertices);
}
