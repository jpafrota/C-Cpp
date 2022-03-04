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

void criar_fila(tipo_fila* fila) {

    fila->prim = NULL;

}

void inserir_na_fila(tipo_fila* fila, int num) {

    tipo_no* novo = malloc(sizeof(tipo_no));

    novo->dados = num;
    novo->prox = NULL;

    if(fila->prim == NULL) {
        fila->prim = novo;
        return;
    }

    tipo_no* temp = fila->prim;

    while (temp->prox != NULL) {
        temp = temp->prox;
    }

    temp->prox = novo;

}

void imprimir_fila(tipo_fila *fila){

    tipo_no* temp = fila->prim;

    while(temp != NULL){
        printf("%d ", temp->dados);
        temp = temp->prox;
    }

}

int calcular_tempo(tipo_fila* fila, int q){

    tipo_no* temp = fila->prim;

    int tempo_gasto = 0;

    while (temp != NULL) {

        if (temp->dados > q) {

            inserir_na_fila(fila, temp->dados - q);

        }

        if(temp->dados < q && temp->prox == NULL) tempo_gasto += temp->dados;
        else tempo_gasto += q;

        // removendo o atual;
        tipo_no* aux = temp;
        temp = temp->prox;
        free(aux);
        fila->prim = temp;

    }

    return tempo_gasto;

}

int main() {

    tipo_fila fila;
    criar_fila(&fila);

    int q;

    scanf("%d", &q);

    int tempo;
    
    while (scanf("%d", &tempo) != EOF) {
        
        inserir_na_fila(&fila, tempo);

    }

    // imprimir_fila(&fila);

    printf("%d\n", calcular_tempo(&fila, q));

}