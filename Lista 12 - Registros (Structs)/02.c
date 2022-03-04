#include<stdio.h>
#include<stdlib.h>

typedef struct registro{

    int umInt;
    double umFloat;

} reg;

int main(){

    int n;

    scanf("%d", &n);

    reg vetor[n];

    for(int i = 0; i < n; i++){

        scanf("%d", &vetor[i].umInt);
        scanf("%lf", &vetor[i].umFloat);

    }

    double soma = 0;

    for(int i = n - 1; i >= 0; i--){
        printf("%d ", vetor[i].umInt);
        soma += vetor[i].umFloat;
    }

    printf("\n%.4f", soma);

}