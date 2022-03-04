#include<stdio.h>

int main(){
	
	int h, m, s;
	int resultado;
	
	scanf("%d%d%d", &h, &m, &s);
	
	resultado = h*3600 + m*60 + s;
	
	printf("%d", resultado);
	
	
}