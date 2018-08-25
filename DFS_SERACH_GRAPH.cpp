#include<stdio.h>
#define max 5
void depth_first_search(int adj[][max],int visited[],int start)
{
  int stack[max],i;
  int top=-1;
  visited[start]=1;
  stack[++top]=start;
  printf("%c->",start+65);
  while(top!=-1)
  {
    start=stack[top--];
    for(i=0;i<max;i++)
    {
      if(adj[start][i]==1&&visited[i]==0)
      {
        visited[i]=1;
        stack[++top]=i;
        printf("%c->",i+65);
        break;//check it here
      }
    }
  }
}
void display(int adj[max][max])
{
  int i,j;
  for(i=0;i<max;i++)
  {
    for(j=0;j<max;j++)
    {
      printf("%d\t",adj[i][j]);
      if(j==max-1)
      {
        printf("\n");
      }
    }
  }
}
int main()
{
  int visited[max]={0};
  int adj[max][max],i,j;
  printf("Enter the adj MATRIX : \n");
  for(i=0;i<max;i++)
  {
    for(j=0;j<max;j++)
    {
      scanf("%d",&adj[i][j]);
    }
  }
  display(adj);
  printf("\n");
  printf("\n DFS : \n");
  depth_first_search(adj,visited,0);
}
