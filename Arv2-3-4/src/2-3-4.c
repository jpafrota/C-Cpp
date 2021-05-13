#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "2-3-4.h"

noArv234 *criaVazia(){

    return NULL;

}

int arvVazia(noArv234 *raiz){

    return (raiz == NULL);

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

        if( chave > raiz->dados[i] ){
            return buscaArv(raiz->filhos[i+1], chave);
        }

        if(i == 0) return buscaArv(raiz->filhos[i], chave);

        i--;

    }

    return raiz;

}

int ehFolha(noArv234 *raiz){

    if(arvVazia(raiz)) return 0;

    int i = 0;
    int contador = 0;

    while (i < 4){
        if(raiz->filhos[i] != NULL) contador++;
        i++;
    }

    if(contador > 0) return 1;
    else return 0;

}

noArv234 *criaNo(int chave, noArv234 *pai){

    noArv234 *novo = malloc(sizeof(noArv234));
    novo->tamanho = 1;
    novo->dados[0] = chave;
    novo->pai = pai;

    for(int i = 0; i < 5; i++){
        novo->filhos[i] = NULL;
    }

    return novo;

}

/* void insereNo(noArv234 *raiz, noArv234 *filho){

    for(int i = raiz->tamanho - 1; i >= 0; i--){
        if(filho->dados[0] > raiz->dados[i]){
            raiz->filhos[i+1] = filho;
            return;
        }

        else if(filho->dados[0] < raiz->dados[i] && i == 0){

        }
    }

}

noArv234 *split(noArv234 *raiz){

    // pai é NULL, cria novo no
    if(raiz->pai == NULL){
        raiz->pai = criaNo(raiz->dados[1], raiz->pai);
    }

    // pai nao e NULL, insere a chave nele.
    else{
        raiz->pai = insere(raiz->pai, raiz->dados[1]);
    }

    // pai ja foi modificado, agora falta dividir o no
    // cria o irmao esquerdo
    noArv234 *novoEsq = criaNo(raiz->dados[0], raiz->pai);

    //conectar o pai aos novos irmaos

    insereNo(raiz->pai, novoEsq);
    insereNo(raiz->pai, raiz);
    

} */

noArv234 *insere(noArv234 *raiz, int chave){

    //arvore vazia = cria novo no
    if(arvVazia(raiz)){

        return criaNo(chave, raiz);

    }

    //se o no esta cheio faz split
    if(raiz->tamanho == 3){

        raiz = split(raiz);

    }

    //se eh folha e nao ta cheio, insere
    if(ehFolha(raiz)){

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
    else{

        for(int j = raiz->tamanho-1; j >= 0; j--){

            if(chave > raiz->dados[j]) return insere(raiz->filhos[j+1], chave);

            else if(j == 0) return insere(raiz->filhos[j], chave);
        }

    }
    
    return raiz;

}