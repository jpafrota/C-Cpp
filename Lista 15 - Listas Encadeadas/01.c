#include<stdio.h>
#include<stdlib.h>

typedef struct tipo_no tipo_no;
struct tipo_no {

    int dados;
    tipo_no* prox;

};

typedef struct tipo_fila tipo_fila;
struct tipo_fila {

    tipo_no* prim;

};

void criar_fila(tipo_fila* l) {

    l->prim = NULL;

}

void inserir_na_fila(tipo_fila* l, int num) {

    tipo_no* novo = malloc(sizeof(tipo_no));

    novo->dados = num;
    novo->prox = l->prim;

    l->prim = novo;

}

void LE_remover(tipo_fila* l, int chave) {

    tipo_no* aux = l->prim;
    tipo_no* anterior;

    while(aux != NULL){

        // Caso o atual seja a "cabeça" da lista
        if (aux == l->prim && aux->dados == chave) {
            l->prim = aux->prox;
            free(aux);
            aux = l->prim;
        }

        // Caso o próximo contenha a chave a ser removida
        else if (aux->prox != NULL && aux->prox->dados == chave) {

            anterior = aux;
            aux = aux->prox;
            anterior->prox = aux->prox;

            free(aux);
            
            aux = anterior;

        }

        else {
            aux = aux->prox;
        }

    }

}

void LE_conta_elementos(tipo_fila lista) {

    tipo_no* n = lista.prim;
    tipo_no* anterior = n;

    int cont = 1;

    while (n != NULL) {

        n = n->prox;
        if (n != NULL && n->dados == anterior->dados) cont++;
        else cont = 1;

        if(cont == 3){
            printf("tripla\n");
            return;
        }

        anterior = n;

    }

    printf("nada\n");

}

int main() {

    // lista de inteiros
    int novo;
    while (scanf("%d", &novo), novo != -1) {

        tipo_fila lista;
        criar_fila(&lista);
        inserir_na_fila(&lista, novo);

        // Inserir demais elementos, até que x == 0
        int x;
        while (scanf("%d", &x), x != 0) {

            inserir_na_fila(&lista, x);

        }

        // Remoção de ocorrências de 'q'
        int q;
        scanf("%d", &q);
        LE_remover(&lista, q);

        LE_conta_elementos(lista);

    }

}