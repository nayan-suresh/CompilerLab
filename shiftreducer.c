#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
char stack[15];
int ip_ptr=0,st_ptr=0,len;
char ip_sym[15];
char act[15];
char temp[2],temp2[2];
void check();
void main()
{
	printf("\n\tSHIFT REDUCE PARSER\n");
	printf("\nGRAMMAR:\n");
	printf("E->E+E\nE->E*E\nE->(E)\nE->a|b\n");
	printf("\n Enter the input Symbol: a+abb\n");
	scanf("%s",ip_sym);
	printf("\n Stack\t\tInput\t\tAction\n");
	printf("\n$ \t\t%s$\t\t--",ip_sym);
	while(ip_sym[ip_ptr]!='\0')
	{
		temp[0]=ip_sym[ip_ptr];
		temp[1]='\0';
		strcpy(act,"SHIFT");
		len=strlen(ip_sym);
		stack[st_ptr]=ip_sym[ip_ptr];
		st_ptr++;
		ip_sym[ip_ptr]=' ';
		ip_ptr++;
		printf("\n$%s\t\t%s$\t\t%s",stack,ip_sym,act);
		check();
	}
	check();
}

void check()
{
	char temp3[15];
	if(strcmp(&stack[st_ptr-1],"a")==0 || strcmp(&stack[st_ptr-1],"b")==0)
	{
		stack[st_ptr-1]='E';
		stack[st_ptr]='\0';
		printf("\n$%s\t\t%s$\tREDUCE E->a|b",stack,ip_sym);
	}
	if(st_ptr>=3)
	{
		if(stack[st_ptr-3]=='E' && stack[st_ptr-2]=='+' && stack[st_ptr-1]=='E')
		{
			st_ptr-=2;
			stack[st_ptr-1]='E';
			stack[st_ptr]='\0';
			printf("\n$%s\t\t%s$\tREDUCE E->E+E",stack,ip_sym);
		}
		else if(stack[st_ptr-3]=='E' && stack[st_ptr-2]=='*' && stack[st_ptr-1]=='E')
		{
			st_ptr-=2;
			stack[st_ptr-1]='E';
			stack[st_ptr]='\0';
			printf("\n$%s\t\t%s$\tREDUCE E->E*E",stack,ip_sym);
		}
	}
	if(strcmp(stack,"E")==0 && ip_sym[ip_ptr]=='\0')
	{
		printf("\n$%s\t\t%s$\tACCEPT",stack,ip_sym);
		exit(0);
	}
}

