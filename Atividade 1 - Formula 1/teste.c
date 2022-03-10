#include "stdio.h"
#include "stdlib.h"

typedef struct Node *node;

struct Node{

    int dado;
    node *prox;

};

void imprimeLista(node head){

    //aqui não há necessidade de usar ponteiro para ponteiro pois a variavel local apenas precisa percorrer a lista
    //sem alterar suas caracteristicas.

    if(head != NULL){
        printf("%d ", head->dado);
        imprimeLista(head->prox);
    }

}

void insereInicio(node* head, int valor){

    //se usa dois "*" pois nessa função cria-se um ponteiro q aponta para um ponteiro do tipo node (ponteiro para ponteiro)
    //head vai apontar para o endereço de "lista", e *head representa o conteudo de "lista", ou seja, o nó do início ou NULL

    node novo = malloc(sizeof(node));

    novo->dado = valor;
    novo->prox = *head;
    *head = novo;

}

int main(){

    node lista = NULL;

    insereInicio(&lista, 24);
    insereInicio(&lista, 22);
    insereInicio(&lista, 21);
    insereInicio(&lista, 200);
    imprimeLista(lista);


}