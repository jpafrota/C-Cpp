#include "stdio.h"
#include "stdlib.h"
#include "btree.h"

BTreeNode *btree_create(){

    return NULL;

}

BTreeNode *buscaArv(BTreeNode *raiz, int chave){

    if(raiz == NULL){
        printf("No nao existe na arvore!\n");
        return raiz;
    }
    
    int i;
    i = raiz->tamanho - 1;

    while( i >= 0 ){

        if( chave == raiz->chaves[i] ) return raiz;

        else if( chave > raiz->chaves[i] ){
            return buscaArv(raiz->filhos[i+1], chave);
        }

        else if(i == 0) return buscaArv(raiz->filhos[i], chave);

        i--;

    }

    return raiz;

}

int btree_isEmpty(BTreeNode *raiz){

    return (raiz == NULL);

}

int btree_isLeaf(BTreeNode *raiz){

    if(raiz == NULL) return 0;

    else{

        for(int i = 0; i < raiz->tamanho; i++){
            if(raiz->filhos[i] != NULL) return 0;
        }

        return 1;

    }

}

BTreeNode *btree_insert(BTreeNode *raiz, int chave){



}
