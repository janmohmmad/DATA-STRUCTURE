#include<stdio.h>
#define max 5
void Breadth_First_search(int adj[][max],int visited[],int start)
{
  int queue[max],i,r=-1,f=-1;
  queue[++r]=start;
  visited[start]=1;
while(r!=f)
{
  start=queue[++f];
  printf("%c\t",start+65);
  /*if(start==5)
  {
    printf("6 \t");
  }
  else
  {
    printf("%c \t",start+65);
  }*/
  for(i=0;i<max;i++)
  {
    if(adj[start][i]==1&&visited[i]==0)
    {
      queue[++r]=i;
      visited[i]=1;
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
  printf("\n BFS : \n");
  Breadth_First_search(adj,visited,0);
}
