%{
 #include<stdio.h>
  #include<stdlib.h>
  int i,n,flag=0;
%}
%%
[0-9]+ {
  n=atoi(yytext);
    flag=0;
  if(n==2)
  {
    printf("prime");
  }
  else if(n==0||n==1)
  {
    printf("not prime");
    
  }
  else
  {
    for(i=2;i<n/2;i++)
    {
      if(n%i==0)
      {
        flag=1;
        break;
      }
    }
    if(flag==1)
    {
      printf("not  prime");
    }
    else
    {
      printf("prime");
    }
  }
}
%%
int main()
{
  yylex();
  return 0;
}
int yywrap()
{
  return 1;
}