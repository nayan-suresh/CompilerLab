%{
int pos=0,neg=0;
%}

%%
[0-9]+ { pos++; printf("Positive no=%s",yytext);}

-[0-9]+ { neg++; printf("NEgative no=%s",yytext);}
%%
 int main()
{
  yylex();
  printf("count of positive no=%d \n",pos);
  printf("Count of negative no=%d\n",neg);
  return 0;
}
int yywrap()
{
  return 1;
}