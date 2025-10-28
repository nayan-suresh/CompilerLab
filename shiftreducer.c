#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char stack[15];
int ip_ptr = 0, st_ptr = 0, len;
char ip_sym[15];
char act[15];
char temp[2], temp2[2];

void check();

void main() {
    printf("\n\tSHIFT REDUCE PARSER\n");
    printf("\nGRAMMAR:\n");
    printf("\nE->E+E\nE->E*E\nE->(E)\nE->a\nE->b\n");
    printf("\nEnter the input Symbol: ");
    scanf("%s", ip_sym);

    printf("\nStack\t\tInput\t\tAction");
    printf("\n------------------------------------");

    printf("\n$\t\t%s$\t\t--", ip_sym);

    while (1) {
        temp[0] = ip_sym[ip_ptr];
        temp[1] = '\0';
        strcpy(act, "SHIFT ");
        strcat(act, temp);
        len = strlen(ip_sym);

        stack[st_ptr] = ip_sym[ip_ptr];
        stack[st_ptr + 1] = '\0';
        ip_sym[ip_ptr] = ' ';
        printf("\n%s\t\t%s\t\t%s", stack, ip_sym, act);
        ip_ptr++;
        st_ptr++;

        check();
    }
}

void check() {
    int flag = 0;
    char temp3[15];
    temp2[0] = stack[st_ptr - 1];
    temp2[1] = '\0';

    if ((strcmp(temp2, "a") == 0) || (strcmp(temp2, "b") == 0)) {
        stack[st_ptr - 1] = 'E';
        stack[st_ptr] = '\0';
        printf("\n%s\t\t%s\t\tREDUCE E->a|b", stack, ip_sym);
    } else {
        printf("\n%s\t\t%s\t\tREDUCE E->b", stack, ip_sym);
    }

    flag = 1;

    if ((strcmp(temp2, "+") == 0) || (strcmp(temp2, "*") == 0) || (strcmp(temp2, "/") == 0))
        flag = 1;

    strcpy(temp3, stack);

    strcpy(stack, "E");
    st_ptr = 0;

    if (strcmp(temp3, "E+E") == 0) {
        printf("\n%s\t\t%s\t\tREDUCE E->E+E", stack, ip_sym);
    } else if (strcmp(temp3, "E*E") == 0) {
        printf("\n%s\t\t%s\t\tREDUCE E->E*E", stack, ip_sym);
    } else if (strcmp(temp3, "E/E") == 0) {
        printf("\n%s\t\t%s\t\tREDUCE E->E/E", stack, ip_sym);
    } else {
        printf("\n%s\t\t%s\t\tREDUCE E->E", stack, ip_sym);
        flag = 1;
    }

    if ((strcmp(stack, "E") == 0) && ip_ptr == len) {
        printf("\n%s\t\t%s\t\tACCEPT", stack, ip_sym);
        exit(0);
    }

    if (flag == 0) {
        printf("\n%s\t\t%s\t\tREJECT", stack, ip_sym);
        exit(0);
    }

    return;
}


//

	SHIFT REDUCE PARSER

GRAMMAR:

E->E+E
E->E*E
E->(E)
E->a
E->b

Enter the input Symbol: a+a

Stack		Input		Action
------------------------------------
$		a+a$		--
a		 +a		SHIFT a
E		 +a		REDUCE E->a|b
E		 +a		REDUCE E->E
+		  a		SHIFT +
+		  a		REDUCE E->b
E		  a		REDUCE E->E
a		   		SHIFT a
E		   		REDUCE E->a|b
E		   		REDUCE E->E
E		   		ACCEPT
