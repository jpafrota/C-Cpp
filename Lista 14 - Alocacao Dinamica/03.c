#include <stdio.h>
#include <stdlib.h>

int** ler_matriz(int linhas, int colunas);
void somar_matrizes(int** mat1, int** mat2, int linhas, int colunas);
void imprimir_matriz(int** mat, int linhas, int colunas);
void liberar_matriz(int** mat, int linhas);

int main(void) {

    int linhas, colunas;

    int*** cubo;
    int qtd_matrizes;

    scanf("%d", &qtd_matrizes);
    scanf("%d%d", &linhas, &colunas);

    cubo = malloc(sizeof(int**) * qtd_matrizes);

    for (int i = 0; i < qtd_matrizes; i++) {
        cubo[i] = ler_matriz(linhas, colunas);
    }

    int i, j;
    while (scanf("%d%d", &i, &j), i != 0 || j != 0) {
        somar_matrizes(cubo[i], cubo[j], linhas, colunas);
    }

    imprimir_matriz(cubo[0], linhas, colunas);

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
