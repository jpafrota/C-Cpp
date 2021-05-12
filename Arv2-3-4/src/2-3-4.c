#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "2-3-4.h"

noArv234 *criaVazia(){

    return NULL;

}

noArv234 *buscaArv(noArv234 *raiz, int chave){

    if(raiz == NULL){
        printf("No nao existe na arvore!\n");
        return raiz;
    }
    
    int i;
    i = raiz->tamanho - 1;

    while( i >= 0 ){

        if( chave == raiz->dados[i] ) return raiz;

        else if( chave > raiz->dados[i] ){
            return buscaArv(raiz->filhos[i+1], chave);
        }

        else if(i == 0) return buscaArv(raiz->filhos[i], chave);

        i--;

    }

}

noArv234 *insere(noArv234 *raiz, int chave){

    //arvore vazia ou folha = cria novo no
    if(raiz == NULL){

        noArv234 *novo = malloc(sizeof(noArv234));
        novo->tamanho = 1;
        novo->dados[0] = chave;
        for(int i = 0; i < 5; i++){
            novo->filhos[i] = NULL;
        }

        return novo;

    }

    //se o no esta cheio faz split
    if(raiz->tamanho == 3){

        

    }

    //se eh folha e nao ta cheio, insere
    if(ehFolha(raiz) && raiz->tamanho < 3){

        //arvore com pelo menos 1 no:
        int i = raiz->tamanho - 1;

        while(i >= 0){

            if(chave > raiz->dados[i]){
                raiz->dados[i+1] = chave;
                raiz->tamanho++;
                return raiz;
            }

            else if(chave < raiz->dados[i]){
                raiz->dados[i+1] = raiz->dados[i];
                raiz->dados[i] = chave;
            }

            i--;

        }

        raiz->tamanho++;

        return raiz;

    }
    
    //se nao eh folha, busca pelo filho ideal para inserir
    else if(!ehFolha(raiz) && raiz->tamanho < 3){
        for(int j = raiz->tamanho-1; j >= 0; j--){
            if(chave > raiz->dados[j]) return insere(raiz->filhos[j+1], chave);
            else if(j == 0) return insere(raiz->filhos[j], chave);
        }
    }
    
    return raiz;

}