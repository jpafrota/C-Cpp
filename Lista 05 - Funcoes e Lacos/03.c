#include<stdio.h>
#include<stdlib.h>

double potencia(double base, int expoente){

	if(expoente == 0) return 1;
	
	double resultado = base;
	int i;
	
	for(i = 1; i < expoente; i++){
		resultado *= base;
	}
	
	return resultado;
	
}

int main(){
	
	double base;
	int expoente;
	
	do{
		
		scanf("%lf", &base);
		scanf("%d", &expoente);
		
		if(base != -1 || expoente != -1){
			printf("%.2f\n", potencia(base, expoente));
		}
		
	}while(base != -1 || expoente != -1);
	
}