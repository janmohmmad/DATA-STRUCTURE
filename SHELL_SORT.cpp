#include<stdio.h>
void shell_sort(int a[],int n)
{
  int i,j,gap,key;
  for(gap=(n-1)/2;gap>0;gap=gap/2)
  {
    for(i=0;i<n;i=i+gap)
    {
      key=a[i];
      j=i-gap;
      while(j>=0&&a[j]>key)
      {
        a[j+gap]=a[j];
        j=j-gap;
      }
      a[j+gap]=key;
    }
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
  shell_sort(a,n);
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}
