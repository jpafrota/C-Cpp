#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// implementacao da pilha

typedef struct tipo_no tipo_no;
struct tipo_no {

    int posX;
    int posY;
    int moeda;
    tipo_no* prox;

};

typedef struct tipo_pilha tipo_pilha;
struct tipo_pilha {

    tipo_no* prim;

};

void criar_pilha(tipo_pilha* l) {

    l->prim = NULL;

}

// insere no inicio
void empilhar(tipo_pilha* l, int x, int y, int moeda) {

    tipo_no* novo = malloc(sizeof(tipo_no));

    novo->posX = x;
    novo->posY = y;
    novo->moeda = moeda;
    novo->prox = l->prim;

    l->prim = novo;

}

void desempilhar(tipo_pilha* l) {

    tipo_no* temp = l->prim;

    l->prim = temp->prox;

    free(temp);

}

// fim implementacao pilha

void ler_matriz(int linhas, int colunas, int matriz[][colunas]) {

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            scanf("%d", &matriz[i][j]);

        }
    }

}

void fazer_jogadas(int linhas, int colunas, int matriz[][colunas], int* posX, int* posY, int* moedas, int* vida, char* seq, tipo_pilha* l) {

    int moeda = 0;

    for (int i = 0; i < (int)strlen(seq); i++) {

        if (seq[i] == 'D') *posX = *posX + 1;
        else if (seq[i] == 'A') *posX = *posX - 1;
        else if (seq[i] == 'W') *posY = *posY - 1;
        else if (seq[i] == 'S') *posY = *posY + 1;

        if (seq[i] == 'Z') {

            if(l->prim == NULL) return;

            // se a posicao atual estiver vazia, verificar se tinha moeda amtes
            if (matriz[*posY][*posX] == 0
                && l->prim != NULL && l->prim->moeda == 1) {

                // devolve a moeda para o tabuleiro e diminui de Joe
                matriz[*posY][*posX] = 11;
                (*moedas)--;

            }

            // se era um zumbi, remove o dano
            else if (matriz[*posY][*posX] == 22) (*vida) += 5;

            desempilhar(l);

            // atualiza a posicao
            if(l->prim != NULL){
                *posX = l->prim->posX;
                *posY = l->prim->posY;
            }
            else {
                *posX = 0;
                *posY = 0;
            }

        }

        // se foi uma jogada e não um "refazer", atualiza as posições e empilha a jogada
        else {

            if (matriz[*posY][*posX] == 11) {
                (*moedas)++;
                matriz[*posY][*posX] = 0;
                moeda = 1;
            }
            else if (matriz[*posY][*posX] == 22) {
                (*vida) -= 5;
                moeda = 0;
            }
            else moeda = 0;
            empilhar(l, *posX, *posY, moeda);

        }

    }

}

int main() {

    char sequencia[201];
    tipo_pilha pilha;
    criar_pilha(&pilha);

    int linhas, colunas;
    int posicaoX = 0, posicaoY = 0, moedas = 0, vida = 100;

    scanf("%d%d", &linhas, &colunas);

    int matriz[linhas][colunas];

    ler_matriz(linhas, colunas, matriz);

    scanf("%s", sequencia);

    fazer_jogadas(linhas, colunas, matriz, &posicaoX, &posicaoY, &moedas, &vida, sequencia, &pilha);

    printf("posicao x: %d\n", posicaoX);
    printf("posicao y: %d\n", posicaoY);
    printf("moedas: %d\n", moedas);
    printf("life: %d\n", vida);

}