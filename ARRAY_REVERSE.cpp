#include<stdio.h>
void reverse(int a[],int n)
{
  int b[20], i,j;
  for(i=0;i<n;i++)
  {
    int temp;
    temp = a[0];
    for(j=0;j<n-1;j++)
    {
      a[j]=a[j+1];
    }
     a[n-1]=temp;
     printf("REVERSE ORDER IS AS : ");
     for(j=0;j<n;j++)
     {
       printf(" %d ",a[j]);
     }
        printf(" \n");
  }
}
int main()
{
  int a[20],n,i;
  printf("Enter the size of the array\n");
  scanf("%d",&n);
  printf("Enter the elements of the array\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
 reverse(a,n);
}
