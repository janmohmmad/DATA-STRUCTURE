// ****infix to prefix**
/*#include<stdio.h>
#include<ctype.h>
#include<string.h>
char s[20];
int top=-1;
void push(char c)
{
  s[++top]=c;
}
char pop()
{
  return(s[top--]);
}
int p(char c)
{
  switch(c)
  {
    case '#':
    return 0;
    case ')':
    return 1;
    case '+':
    case  '-':
    return 2;
    case '*':
    case '/':
    return 3;
    case '^':
    return 4;
  }
}
int main()
{
  char inf[20];
  char pre[20];
  char ch,ele;
  int i=0,k=0;
  printf("ENTER the infix\n");
  scanf("%s",&inf);
  push('#');
  strrev(inf);
  while ((ch=inf[i])!='\0') {
    if(ch==')')
    push(ch);
    else if(isalnum(ch))
    {
      pre[k++]=ch;
    }
    else if(ch=="(")
    {
      while(s[top]!=')')
      {
        pre[k++]=pop();
      }
      ele=pop();
    }
    else
    {
      while(p(s[top])>ch)
      {
        pre[k++]=pop();
      }
      push(ch);
    }
    i++;
    k++;
  }
  while(s[top]!='#')
  {
    pre[k++]=pop();
  }
  pre[k]='\0';
  strrev(pre);
  strrev(inf);
  printf("the prefix of %c is %c\n",inf,pre );
}
