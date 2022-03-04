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

// insere no inicio
void inserir_na_fila(tipo_fila* l, int num) {

    tipo_no* novo = malloc(sizeof(tipo_no));

    novo->dados = num;
    novo->prox = l->prim;

    l->prim = novo;

}

/* // insercao no final
void inserir_na_fila(tipo_lista* l, int num) {

    tipo_no* novo = malloc(sizeof(tipo_no));
    tipo_no* aux = l->prim;  

    novo->dados = num;
    novo->prox = NULL;

    if (aux == NULL) {
        l->prim = novo;
        return;
    }

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novo;

} */

void imprimir(tipo_no* no){

    if(no != NULL){
        printf("%d ", no->dados);
        imprimir(no->prox);
    }

}

void LE_posicao(tipo_fila* lista, int q){

    tipo_no *aux = lista->prim;

    while (aux != NULL && aux->dados != q) {
        aux = aux->prox;
    } 

    if (aux == NULL) {
        printf("%d: nao existe\n", q);
    }
    else if (aux == lista->prim) {
        printf("%d: inicio\n", q);
    }
    else if (aux->prox == NULL) {
        printf("%d: fim\n", q);
    }
    else {
        printf("%d: existe\n", q);
    }

    return;

}

int main() {

    tipo_fila lista;
    criar_fila(&lista);

    // Inserir elementos, até que x == 0
    int x;
    while (scanf("%d", &x), x != 0) {

        inserir_na_fila(&lista, x);

    }

	 // Realizar consultas até que q == 0
    int q;
    while (scanf("%d", &q), q != 0){

        LE_posicao(&lista, q);

    }


}