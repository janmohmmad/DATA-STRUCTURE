#include<stdio.h>
void  combine(int a[],int low,int mid,int high);
 void merge(int a[],int low,int high)
 {
   int mid;
   mid=(low+high)/2;
   if(low<high)
   {
     merge(a,low,mid); //to sort left part
     merge(a,mid+1,high); //to sort right part
     combine(a,low,mid,high); //to cobine left and right part
   }
 }
 void combine(int a[],int low,int mid,int high)
 {
   int i=low;
   int j=mid+1;
   int k=low;
   int c[20];
   while(i<=mid&&j<=high)
   {
     if(a[i]<a[j])
     c[k++]=a[i++];
    else
    {
      c[k++]=a[j++];
     }
   }
    while(i<=mid)
    c[k++]=a[i++];
    while(j<=high)
    c[k++]=a[j++];
   for(i=low;i<=high;i++)
   {
     a[i]=c[i];
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
    merge(a,0,n);
    for(i=0;i<n;i++)
    {
      printf("%d ",a[i]);
    }
  }
