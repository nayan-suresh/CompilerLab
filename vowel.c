%{
 #include<stdio.h> 
  int vow=0,cons=0;
%}

%%
[aeiouAEIOU] { vow++;}
[a-zA-Z]  {cons++;}
%%
  int main()
{
  printf("Enter a string:");
  yylex();
  printf("No of vowels=%d",vow);
  printf("No of Cinsoants=%d",cons);
  return 0;
}
int yywrap()
{
  return 1; 
}

