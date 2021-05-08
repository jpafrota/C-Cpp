#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "listaencadeada.h"

node* criaLista(){

    return NULL;
    
}

node* liberaLista(node *head){

    if(head != NULL){
        liberaLista(head->prox);
        free(head);
    }
    
    return NULL;

}

void imprimeLista(node *head){

    if(head != NULL){
        printf("%d ", head->valor);
        imprimeLista(head->prox);
    }

}

int buscaLista(node *head, int chave){

    if(head == NULL) return 0;

    if(head->valor == chave) return 1;

    return buscaLista(head->prox, chave);

}

node* criaNo(int chave){

    node *novo = (node*) malloc(sizeof(node));

    novo->valor = chave;
    novo->prox = NULL;

    return novo;

}

node* insereInicio(node *head, int chave){
    
    node *aux = NULL;

    if(head != NULL){
        aux = head;
        head = criaNo(chave);
        head->prox = aux;
        return head;
    }
    
    return criaNo(chave);

}

node* insereFinal(node* head, int chave){

    if(head == NULL){
        return criaNo(chave);
    }

    else if(head->prox == NULL){
        head->prox = criaNo(chave);
    }

    else insereFinal(head->prox, chave);

    return head;

}


void insereApos(node *atual, int chave){

    if(atual != NULL){
        node *novo = criaNo(chave);
        novo->prox = atual->prox;
        atual->prox = novo;
    }

}

node *insercaoOrdenada(node *lista, int chave){

    //caso a lista esteja vazia
    if(lista == NULL){
        return criaNo(chave);
    }    

    //caso o novo elemento seja menor que o primeiro elemento da lista
    else if(lista->valor >= chave){
        return insereInicio(lista, chave);
    }

    //aqui o programa está no último elemento, significa que não achou nenhum numero maior que o novo
    //logo o novo será inserido no final
    else if(lista->prox == NULL){
        return insereFinal(lista, chave);
    }

    //se chegou aqui é porque o primeiro elemento é menor que o novo, estamos em um nó no meio da lista
    //então só resta saber se será inserido após o nó atual ou não. se não, chama a função recursivamente
    else if(lista->prox->valor >= chave){
        insereApos(lista, chave);
    }

    //chama a função recursivamente
    else insercaoOrdenada(lista->prox, chave);

    //retorna a cabeça atualizada da lista
    return lista;

}

//Deleta o nó especificado e retorna um ponteiro para o proximo nó
node* deletaNo(node *head){

    node *aux = head;
    head = head->prox;
    free(aux);
    return head;

}

//Remove um elemento chave da lista recursivamente
node* removeElemento(node* head, int chave){
    
    if(head == NULL) return NULL;

    if(head->valor == chave){
        head = deletaNo(head);
    }

    else if(head->prox == NULL) return NULL;

    else if(head->prox->valor == chave){
        head->prox = deletaNo(head->prox);
    }

    else removeElemento(head->prox, chave);

    return head;

}