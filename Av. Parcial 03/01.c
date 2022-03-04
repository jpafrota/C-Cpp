#include<stdlib.h>
#include<stdio.h>

// implementacao da pilha

typedef struct tipo_no tipo_no;
struct tipo_no {

    int moeda;
    tipo_no* prox;

};

typedef struct tipo_pilha tipo_pilha;
struct tipo_pilha {

    tipo_no* prim;
    int qtd;

};

void criar_pilha(tipo_pilha* l) {

    l->prim = NULL;
    l->qtd = 0;

}

// insere no inicio
void empilhar(tipo_pilha* l, int moeda) {

    tipo_no* novo = malloc(sizeof(tipo_no));

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

int main() {

    tipo_pilha vetor_pilhas[5];

    for (int i = 0; i < 5; i++) {
        criar_pilha(&vetor_pilhas[i]);
    }

    int pilha_atual = 0;
    int moeda;
    int qtd_total = 0;

    while (scanf("%d", &moeda), pilha_atual < 5 && moeda != 0 && qtd_total <= 100) {

        // se a moeda de codibentinho for maior que a moeda da pilha
        while (vetor_pilhas[pilha_atual].prim != NULL
            && moeda > vetor_pilhas[pilha_atual].prim->moeda) {

            pilha_atual++;

        }

        if (pilha_atual < 5){
            empilhar(&vetor_pilhas[pilha_atual], moeda);
            vetor_pilhas[pilha_atual].qtd++;
            pilha_atual = 0;
        }

        qtd_total++;

    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor_pilhas[i].qtd);
    }

}