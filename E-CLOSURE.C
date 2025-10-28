#include <stdio.h>
#include <string.h>
char eclosure[20][20], states[10], st[20][20];
int n, nt;
int checkstate(char x[][20], int i, char y) {
    for (int a = 0; a < strlen(x[i]); a++)
        if (x[i][a] == y) return 0;
    return 1;
}
void findclosure(int i, char state) {
    for (int j = 0; j < nt; j++) {
        char s1 = st[j][0], input = st[j][1], s2 = st[j][2];
        if (s1 == state && input == 'e') {
            if (checkstate(eclosure, i, s2)) {
                int len = strlen(eclosure[i]);
                eclosure[i][len] = s2;
                eclosure[i][len + 1] = '\0';
                findclosure(i, s2);
            }
        }
    }
}
int main() {
    int i, j;
    printf("Enter number of states: ");
    scanf("%d", &n);
    printf("Enter the states: ");
    scanf("%s", states);
    printf("Enter number of transitions: ");
    scanf("%d", &nt);
    printf("Enter the transitions in format <state input nextstate> (ex: AeB):\n");
    for (i = 0; i < nt; i++) scanf("%s", st[i]);
    for (i = 0; i < strlen(states); i++) {
        eclosure[i][0] = states[i];
        eclosure[i][1] = '\0';
        findclosure(i, states[i]);
    }
    printf("\n--- Epsilon Closures ---\n");
    for (i = 0; i < strlen(states); i++) {
        printf("ε-closure(%c) = { ", states[i]);
        for (j = 0; j < strlen(eclosure[i]); j++)
            printf("%c ", eclosure[i][j]);
        printf("}\n");
    }
    return 0;
}

//
Enter number of states: 3
Enter the states: ABC
Enter number of transitions: 6
Enter the transitions in format <state input nextstate> (ex: AeB):
AeB
AeC
BeA
B1B
CeA
C0C

--- Epsilon Closures ---
ε-closure(A) = { A B C }
ε-closure(B) = { B A C }
ε-closure(C) = { C A B }
