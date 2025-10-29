%{
#include<stdio.h>
%}

%%
[1-9][0-9]{9}    { printf("Valid\n"); }
.+               { printf("Invalid\n"); }
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
