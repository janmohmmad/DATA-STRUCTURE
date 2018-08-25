#include<stdio.h>
#include<string.h>
char s[20];
int top=-1;
void push(char x)
{
  s[++top]=x;
}
char pop()
{
  if(top==-1)
  {
    return -1;
  }
  else
  {
    return s[top--];
  }
}
int proirity(char x)
{
  if(x=='(')
  return 0;
  if(x=='+'||x=='-')
  return 1;
  if(x=='*'||x=='/'||x=='%')
  return 2;
}
int main()
{
  char inf[20],post[20];
  char ch,ele;
  int i,k;
  i=k=0;
  printf("ENter the infix expression \n");
  scanf("%c",inf);
  push('#');
  while((ch=inf[i])!='\0')
  {
    if(ch=='(')
    {
      push(ch);
    }
    else if(islanum(ch))
    {
      post[k++]=ch;
    }
    else if(ch==')')
    {
      while(s[top]!='(')
      {
        post[k++]=pop()
      }
      ele=pop();
    }
    else
    {
      while(proirity(s[top])>=proirity(ch))
      {
        post[k++]=pop();
      }
      push(ch);
    }
    i++;
}
while(s[top]!='#')
post[k++]=pop();
post[k]='\0';
printf("THE POST FIX OF %c IS %c",inf,post);
}
