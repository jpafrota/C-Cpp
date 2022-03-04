#include<stdio.h>

int main(){
	
	int entrada;
	int horas, minutos, segundos;
	
	scanf("%d", &entrada);
	
	horas = entrada/3600;
	minutos = (entrada % 3600) / 60;
	segundos = entrada % 60;
	
	printf("%02d:%02d:%02d", horas, minutos, segundos);
	
}