#include <stdio.h>
#include <stdlib.h>

int** ler_matriz(int linhas, int colunas);
void somar_matrizes(int** mat1, int** mat2, int linhas, int colunas);
void imprimir_matriz(int** mat, int linhas, int colunas);
void liberar_matriz(int** mat, int linhas);
int menor(int a, int b);

struct matriz {
    int linhas, colunas;
    int** valores;
};

int main(void) {

    struct matriz* cubo;
    int qtd_matrizes;

    scanf("%d", &qtd_matrizes);

    cubo = malloc(sizeof(struct matriz) * qtd_matrizes);

    for (int i = 0; i < qtd_matrizes; i++) {
        scanf("%d%d", &(cubo[i].linhas), &(cubo[i].colunas));
        cubo[i].valores = ler_matriz(cubo[i].linhas, cubo[i].colunas);
    }
    
    int i, j;
    while (scanf("%d%d", &i, &j), !(i == 0 && j == 0)) {
        
        int lin, col;

        lin = menor(cubo[i].linhas, cubo[j].linhas);
        col = menor(cubo[i].colunas, cubo[j].colunas);

        somar_matrizes(cubo[i].valores, cubo[j].valores, lin, col);

    }

    imprimir_matriz(cubo[0].valores, cubo[0].linhas, cubo[0].colunas);

}

int menor(int a, int b) {

    if (a < b) return a;
    return b;

}

int** ler_matriz(int linhas, int colunas) {

    int** nova_matriz = malloc(sizeof(int*) * linhas);

    for (int i = 0; i < linhas; i++) {
        nova_matriz[i] = malloc(sizeof(int) * colunas);
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &nova_matriz[i][j]);
        }
    }

    return nova_matriz;

}

void somar_matrizes(int** mat1, int** mat2, int linhas, int colunas) {

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            mat1[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

}

void imprimir_matriz(int** matriz, int linhas, int colunas) {

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

}

void liberar_matriz(int** matriz, int linhas) {

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }

    free(matriz);

}
