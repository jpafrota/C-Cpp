#include<stdio.h>
#include<stdlib.h>

void multiplicacao(int La, int Ca, double **A, int Lb, int Cb, double **B){

    for(int i = 0; i < La; i++){

        for(int j = 0; j < Cb; j++){

            double soma = 0;

            for(int k = 0; k < Ca; k++){
                soma += A[i][k] * B[k][j];
            }
            printf("%.2f ", soma);

        }
        printf("\n");
    }

}

void ler_matriz(int linhas, int colunas, double **matriz){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }

}

int main(){

    int La, Ca;
    int Lb, Cb;
    int contador = 1;

    while(scanf("%d%d", &La, &Ca), La != 0 && Ca != 0){

        double **A = malloc(sizeof(double*) * La);
        for(int i = 0; i < La; i++){
                A[i] = malloc(sizeof(double) * Ca);
        }
        ler_matriz(La, Ca, A);
        //imprimir_matriz(La, Ca, A);

        scanf("%d%d", &Lb, &Cb);

        double **B = malloc(sizeof(double*) * Lb);
        for(int i = 0; i < Lb; i++){
            B[i] = malloc(sizeof(double) * Cb);
        }
        ler_matriz(Lb, Cb, B);

        printf("Caso #%d\n", contador);
        if(Ca == Lb){
            multiplicacao(La, Ca, A, Lb, Cb, B);
        }

        free(A);
        free(B);
        contador++;

    }

}