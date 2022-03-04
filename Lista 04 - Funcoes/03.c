#include<stdio.h>

int ler_horario(void){
	
	int horas, minutos, segundos;
	int resultado;
	
	scanf("%d", &horas);
	scanf("%d", &minutos);
	scanf("%d", &segundos);
	
	resultado = horas*3600 + minutos*60 + segundos;
	
	return resultado;
	
}

void imprimir_horario(int horario){
	
	int horas, minutos, segundos;
	
	horas = (horario/3600) % 24;
	minutos = (horario % 3600) / 60;
	segundos = horario % 60;
	
	printf("%02d:%02d:%02d\n", horas, minutos, segundos);
	
}

int main(){
	
	int horarioEntrada, horarioFinal;
	
	int n;
	scanf("%d", &n);
	do{
		
		horarioEntrada = ler_horario();

		horarioFinal = ler_horario();

		horarioFinal = horarioEntrada + horarioFinal;

		imprimir_horario(horarioFinal);
	
		n--;
		
	}while(n != 0);
	
}