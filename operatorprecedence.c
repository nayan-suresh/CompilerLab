#include <stdio.h>
#include <string.h>
#include <strings.h>
void main() {
	char stack[20], ip[20], opt[10][10][1], ter[10];
	int i, j, k, n, top = 0, row = 0, col = 0;
	for (i = 0; i < 20; i++) {
		stack[i] = 0;
		ip[i] = 0;
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			opt[i][j][0] = 0;
		}
	}
	printf("Enter the number of terminals: ");
	scanf("%d", &n);
	printf("\nEnter the terminals: ");
	scanf("%s", ter);
	printf("Enter the table values:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("Enter the value for %c%c: ", ter[i], ter[j]);
			scanf("%s", opt[i][j]);
		}
	}
	printf("\nOPERATOR PRECEDENCE TABLE:\n\t");
	for (i = 0; i < n; i++) {
		printf("%c\t", ter[i]);
	}
	printf("\n\n");
	for (i = 0; i < n; i++) {
		printf("%c\t", ter[i]);
		for (j = 0; j < n; j++) {
			printf("%c\t", opt[i][j][0]);
		}
		printf("\n");
	}
	stack[top] = '$';
	printf("\n\nEnter the input string (append with $): ");
	scanf("%s", ip);
	i = 0;
	printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
	printf("%s\t\t\t%s\t\t\t", stack, ip);
	while (i <= strlen(ip)) {
		for (k = 0; k < n; k++) {
			if (stack[top] == ter[k])
				row = k;
			if (ip[i] == ter[k])
				col = k;
		}
		if (stack[top] == '$' && ip[i] == '$') {
			printf("String is ACCEPTED\n");
			break;
		} else if ((opt[row][col][0] == '<') || (opt[row][col][0] == '=')) {
			stack[++top] = opt[row][col][0];
			stack[++top] = ip[i];
			printf("Shift %c", ip[i]);
			i++;
		} else if (opt[row][col][0] == '>') {
			while (stack[top] != '<') {
				--top;
			}
			top--;
			printf("Reduce");
		} else {
			printf("\nString is NOT accepted\n");
			break;
		}
		printf("\n");
		for (k = 0; k <= top; k++) {
			printf("%c", stack[k]);
		}
		printf("\t\t\t");
		for (k = i; k < strlen(ip); k++) {
			printf("%c", ip[k]);
		}
		printf("\t\t\t");
	}
}



// OUTPUT:
Enter the number of terminals: 4
Enter the terminals: +*i$
Enter the table values:
Enter the value for ++: >
Enter the value for +*: <
Enter the value for +i: <
Enter the value for +$: >
Enter the value for *+: >
Enter the value for **: >
Enter the value for *i: <
Enter the value for *$: >
Enter the value for i+: >
Enter the value for i*: >
Enter the value for ii: -
Enter the value for i$: >
Enter the value for $+: <
Enter the value for $*: <
Enter the value for $i: <
Enter the value for $$: =
Enter the input string (append with $): i+i*i$

STACK                   INPUT STRING              ACTION
$                       i+i*i$                   Shift i
$<i                     +i*i$                    Reduce
$                       +i*i$                    Shift +
$<+                     i*i$                     Shift i
$<+<i                   *i$                      Reduce
$<+                     *i$                      Shift *
$<+<*                   i$                       Shift i
$<+<*<i                 $                        Reduce
$<+                     $                        Reduce
String is ACCEPTED
