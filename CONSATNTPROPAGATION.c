#include<stdio.h>
#include<ctype.h>
#include<string.h>
int n;
char prod[10][20];
void input(){
int i;
printf("Enter number of statements:");
scanf("%d",&n);
printf("Enter %d statements:\n",n);
for(i=0;i<n;i++)
scanf("%s",prod[i]);
}
void replace(char c,char num,int no){
int i;
for(i=no+1;i<n;i++){
int j=2;
while(prod[i][j]!='\0'){
if(prod[i][j]==c){
prod[i][j]=num;
break;
}
j++;
}
}
}
void check(){
int i;
for(i=0;i<n;i++){
if(isdigit(prod[i][2])&&prod[i][3]=='\0')
replace(prod[i][0],prod[i][2],i);
}
}
void display(){
int i;
printf("Optimized Code:\n");
for(i=0;i<n;i++)
printf("%s\n",prod[i]);
}
int main(){
input();
check();
display();
return 0;
}


//
Enter number of statements:3
Enter 3 statements:
A=5
B=A
C=B
Optimized Code:
A=5
B=5
C=5
