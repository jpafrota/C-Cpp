#include <stdio.h>
#include <stdlib.h>

void multiplicacao(int n, int **A, int **B, int **C){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            int soma = 0;

            for(int k = 0; k < n; k++){
                soma += A[i][k] * B[k][j];
            }
			  
            C[i][j] = soma;

        }
    }

}

void ler_matriz(int n, int **matriz){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

}

int eh_identidade(int ordem, int **matriz){

    for(int i = 0; i < ordem; i++){
        
        if(matriz[i][i] != 1) return 0;
        for(int j = i+1; j < ordem; j++){
            if(matriz[i][j] != 0 || matriz[j][i] != 0) return 0;
        }

    }

    return 1;

}

int main(){

    int n;

    while(scanf("%d", &n), n != 0){

        int **A = malloc(sizeof(int*) * n);
        int **B = malloc(sizeof(int*) * n);
        int **C = malloc(sizeof(int*) * n);

        for(int i = 0; i < n; i++){
            A[i] = malloc(sizeof(int) * n);
            B[i] = malloc(sizeof(int) * n);
            C[i] = malloc(sizeof(int) * n);
        }

        ler_matriz(n, A);
        ler_matriz(n, B);

        multiplicacao(n, A, B, C);
        if(eh_identidade(n, C)) printf("sim\n");
        else printf("nao\n");

        free(A);
        free(B);

    }

}