#include<stdio.h>
int array_partation(int a[],int low,int high)
{
  int i=low+1,j=high;
  int key=a[low];
  while(1)
  {
    while(i<j&&key>a[i])
    i++;
    while(a[j]>key)
    j--;
    if(i<j)
    {
      int temp;
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
    }
    else
    {
      int temp;
      temp=a[low];
      a[low]=a[j];
      a[j]=temp;
       return j;
    }
    }
}
void quick_sort(int a[],int low,int high)
{
  int j;
  if(low<high)
  {
    j=array_partation(a,low,high);
    quick_sort(a,low,j-1);
    quick_sort(a,j+1,high);
  }
}

int main()
{
  int a[20],n,i;
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
  quick_sort(a,0,n);
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}
