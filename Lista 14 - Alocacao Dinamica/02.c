#include <stdio.h>
#include <stdlib.h>

int** ler_matriz(int linhas, int colunas);
void somar_matrizes(int** mat1, int** mat2, int linhas, int colunas);
void imprimir_matriz(int** mat, int linhas, int colunas);
void liberar_matriz(int** mat, int linhas);

int main(void) {

    int linhas, colunas;

    scanf("%d%d", &linhas, &colunas);

    int** m1 = ler_matriz(linhas, colunas);
    int** m2 = ler_matriz(linhas, colunas);

    somar_matrizes(m1, m2, linhas, colunas);

    imprimir_matriz(m1, linhas, colunas);
    liberar_matriz(m1, linhas);

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
