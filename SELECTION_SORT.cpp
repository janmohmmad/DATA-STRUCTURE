#include<stdio.h>
void select(int a[],int n)
{
  int i,j,pos,temp;
  for(i=0;i<n-1;i++)
  {
    pos=i;
    for(j=i+1;j<n;j++)
    {
      if(a[j]<a[pos])
      {
        pos=j;
      }
      }
      temp=a[pos];
      a[pos]=a[i];
      a[i]=temp;

  }
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}
int main()
{
  int i,n,a[20];
  printf("ENTER THE SIZE OF THE ARAY\n");
  scanf("%d",&n);
  printf("ENTER THE ELEMENTS\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("THE ARRAY THAT U ENTERED IS AS : ");
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
  printf("\nTHE ARRAY AFTER PERFORMING SORTING IS AS : ");
  select(a,n);
}
