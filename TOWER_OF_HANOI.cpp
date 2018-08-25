//*******program for tower of hanoi*****
#include<stdio.h>
void tower(int n,int base,int temp,int destination )
{
  if(n==0)
  {
   return;
  }
  else
  {
    tower(n-1,base,destination,temp);
    printf("move %d from %d  to %d \n",n,base,destination );
    tower(n-1,temp,base,destination);
  }
}
int main()
{
  int a[20],i,j,k,n;
  printf("ENTER THE NO OF RINGS\n");
  scanf("%d",&n);
  tower(n,'a','b','c');

}
