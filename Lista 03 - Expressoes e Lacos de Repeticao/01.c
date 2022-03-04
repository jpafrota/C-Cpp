#include<stdio.h>

int main(){
	
	int horas, minutos, segundos;
	int inc_horas, inc_minutos, inc_segundos;
	
	scanf("%d", &horas);
	scanf("%d", &minutos);
	scanf("%d", &segundos);
	scanf("%d", &inc_horas);
	scanf("%d", &inc_minutos);
	scanf("%d", &inc_segundos);
	
	horas += inc_horas;
	minutos += inc_minutos;
	segundos += inc_segundos;
	
	horas = (horas + minutos/60) % 24;
	minutos = minutos % 60 + segundos/60;
	segundos = segundos % 60;
	
	printf("%02d:%02d:%02d", horas, minutos, segundos);
	
}