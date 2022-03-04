#include<stdio.h>
#include<stdlib.h>

int qtd_primos(int *vetor, int tam){

    int qtd = tam-2;
    int maior = vetor[tam-1];

    for(int i = 2; i < tam; i++){

        if(i * i > maior) return qtd;

        for(int j = i * i; j < tam; j+=i){

            if(vetor[j] != 0){
                vetor[j] = 0;
                qtd--;
            }

        }

    }

    return qtd;

}

int main(){

    int n;

    scanf("%d", &n);

    int tam = n + 1;

    int vetor[tam];

    for(int i = 0; i < tam; i++){
        vetor[i] = i;
    }
    vetor[1] = 0;

    printf("%d", qtd_primos(vetor, tam));
    
}