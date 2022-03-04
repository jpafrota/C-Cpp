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
    tipo_no* aux = l->prim;

    novo->dados = num;

    // Caso a lista esteja vazia
    if (l->prim == NULL) {
        novo->prox = novo;
        l->prim = novo;
        return;
    }

    // Procura pelo último elemento
    while (aux->prox != l->prim) {
        aux = aux->prox;
    }

    aux->prox = novo;
    novo->prox = l->prim;

}

void imprimir(tipo_no* no) {

    if (no == NULL) return;

    tipo_no* prim = no;

    do {
        printf("%d ", no->dados);
        no = no->prox;
    } while (no != prim);

}

void remover_first(tipo_fila* lista) {

    if (lista->prim == NULL) return;

    tipo_no* ultimo = lista->prim;
    while (ultimo->prox != lista->prim) {
        ultimo = ultimo->prox;
    }

    tipo_no* temp = lista->prim;

    if (ultimo == lista->prim) {
        lista->prim = NULL;
    }
    else {
        lista->prim = lista->prim->prox;
        ultimo->prox = lista->prim;
    }

    free(temp);

}

tipo_no* procura_menor(tipo_fila* lista) {

    if (lista == NULL) return NULL;

    tipo_no* menor = lista->prim;
    tipo_no* aux = lista->prim;

    do {
        if (aux->dados < menor->dados) {
            menor = aux;
        }
        aux = aux->prox;
    } while (aux != lista->prim);

    return menor;

}

void zerar_lista(tipo_fila* lista) {

    while (lista->prim != NULL) {

        // novo inicio da lista
        tipo_no* menor = procura_menor(lista);

        lista->prim = menor;

        tipo_no* atual = lista->prim;

        int cont = 1;
        while (atual->prox != lista->prim && atual->dados <= atual->prox->dados) {

            cont++;
            atual = atual->prox;

        }

        atual = lista->prim;
        for (int i = 0; i < cont; i++){
            printf("%d ", atual->dados);
            remover_first(lista);
            atual = lista->prim;
        }

    }

}

int main() {

    tipo_fila lista;
    criar_fila(&lista);

    // Inserir elementos, até que x == -1
    int x;
    while (scanf("%d", &x), x != -1) {

        inserir_na_fila(&lista, x);

    }

    // Transformar menor valor no inicio da lista
    zerar_lista(&lista);

}