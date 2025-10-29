%{
#include<stdio.h>
%}

%%
^[0-9]+$    { printf("is digit\n"); }
.*           { printf("is not digit\n"); }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
