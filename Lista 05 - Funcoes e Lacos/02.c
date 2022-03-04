#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	
	char op;
	
	do{
		
		op = getchar();
		if(isalpha(op) || isdigit(op) || op == ' ' || op == '?' || op == '.' || op == ',' || op == ';' || op == '!') printf("%c", op);
		
	}while(op != EOF);
	
}