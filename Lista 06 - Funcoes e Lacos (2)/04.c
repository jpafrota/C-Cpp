#include <stdio.h>
#include <stdlib.h>

// verifica se um numero é primo
int primo(int entrada){
	
	if(entrada <= 1) return 0;

	for(int i = 2; i <= entrada/2; i++){
		
		if(entrada % i == 0) return 0;
		
	}

	return 1;
	
}

// faz a decomposição do numero em fatores primos
void decompor(int n){

	// caso especial pra quando n == 1
	if(n == 1){
		printf("%d ", n);
		return;
	}

	int i = 2;
	while(n != 1){

		if(primo(i) && n % i == 0){

			printf("%d ", i);
			n /= i; 

		}
		// se nao for primo ou divisor do numero atual, pula pro proximo fator (a decomposição só é feita em valores primos)
		else i++;

	}
}

int main(){
	
	int numero;

	while(scanf("%d", &numero), numero != 0){

		printf("%d: ", numero);
		decompor(numero);
		printf("\n");
		
	}

}