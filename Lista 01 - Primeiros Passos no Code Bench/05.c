#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int maior, menor, aux;
	int entrada;
	
	scanf("%d", &maior);
	
	scanf("%d", &menor);
	
	if(menor > maior){
		aux = maior;
		maior = menor;
		menor = aux;
	}
	
	scanf("%d", &entrada);
	
	if(entrada > maior) maior = entrada;
	else if(entrada < menor) menor = entrada;
	
	printf("%d", maior-menor);
	
}