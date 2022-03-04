#include <stdio.h>
#include <stdlib.h>

void ler_vetor(int n, int vetor[][n]) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &vetor[i][j]);
        }
    }

}

int quadrado_magico(int n, int vetor[][n]) {

    int somaLinha = 0, somaColuna = 0;
    int somaDiagonais = 0;
    int soma = 0;

    for (int i = 0; i < n; i++) {
        // somando os elementos das diagonais
        somaDiagonais += vetor[i][i];
        somaDiagonais += vetor[i][n - i - 1];

        for (int j = 0; j < n; j++) {
            // percorre a linha atual
            somaLinha += vetor[i][j];

            // percorre a coluna correspondente
            somaColuna += vetor[j][i];
        }

        // caso seja a primeira iteração, inicializa a variável soma.
        if (i == 0) {
            soma = somaLinha;
        }

        else if (somaLinha != soma || somaColuna != soma) {
            return 0;
        }

        somaLinha = 0;
        somaColuna = 0;

    }

    // ao final das iterações, compara a metade da soma das diagonais.
    // a variável "somaDiagonais" faz a soma das diagonais principal e secundária ao mesmo tempo
    // logo, é necessário dividir por 2, para saber se o valor corresponde à soma geral
    if (somaDiagonais / 2 != soma) return 0;

    return 1;

}

int main() {

    int n;

    while (scanf("%d", &n), n != 0) {

        int vetor[n][n];

        ler_vetor(n, vetor);

        if (quadrado_magico(n, vetor)) {
            printf("sim\n");
        }
        else {
            printf("nao\n");
        }

    }

}