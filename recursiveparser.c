#include <stdio.h>
#include <ctype.h>
#include <string.h>
void Tprime();
void Eprime();
void E();
void check();
void T();
char expression[10];
int count, flag;
void main() {
    count = 0;
    flag = 0;
    printf("An Algebraic Expression: ");
    scanf("%s", expression);
    E();
    if((strlen(expression) == count) && (flag == 0))
        printf("Expression is Valid: %s\n", expression);
    else
        printf("Expression is Invalid: %s\n", expression);
}
void E() {
    T();
    Eprime();
}
void T() {
    check();
    Tprime();
}
void Tprime() {
    if(expression[count] == '*') {
        count++;
        check();
        Tprime();
    }
}
void check() {
    if(isalnum(expression[count]))
        count++;
    else if(expression[count] == '(') {
        count++;
        E();
        if(expression[count] == ')')
            count++;
        else
            flag = 1;
    } else
        flag = 1;
}
void Eprime() {
    if(expression[count] == '+') {
        count++;
        T();
        Eprime();
    }
}


//
An Algebraic Expression: (a+b)*c

Expression is Valid: (a+b)*c


  An Algebraic Expression: a+*b
Expression is Invalid: a+*b
