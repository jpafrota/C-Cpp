#include<stdio.h>
#include<stdlib.h>

void inverte(int *vetor, int n){

    int aux;

    for(int i = 0; i < n/2; i++){
        aux = vetor[i];
        vetor[i] = vetor[n-i-1];
        vetor[n-i-1] = aux;
    }

}

void imprimir(int *vetor, int n){
	
	 for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
	
}

void ler(int *vetor, int n){
	
	 for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
	
}

int main(){

    int n;

    scanf("%d", &n);

    int vetor[n];

	 ler(vetor, n);
    inverte(vetor, n);
	 imprimir(vetor, n);

}