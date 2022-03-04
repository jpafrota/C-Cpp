#include<stdio.h>
#include<stdlib.h>

int soma_divisores(int num) {
    
    int soma = 0;

    for (int i = 1; i <= num / 2; i++) {

        if(num % i == 0) {
            soma += i;
            printf("%d\n", i);
        }

    }

    return soma;

}

int main() {

    int numero;

    scanf("%d", &numero);

    if(soma_divisores(numero) == numero) printf("PERFEITO");
    else printf("NAO PERFEITO");

}