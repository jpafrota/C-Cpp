#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "2-3-4.h"

int main(){

    noArv234 *arvore = malloc(sizeof(noArv234));
    noArv234 *arvore2 = malloc(sizeof(noArv234));
    
    noArv234 *arvore3 = criaVazia();

    //arvore = criaVazia();
    //arvore2 = criaVazia();

    arvore->filhos[0] = arvore2;

    arvore->dados[0] = 8;
    arvore->dados[1] = 16;
    arvore->dados[2] = 20;
    for (int i = 0; i < 5; i++){
        arvore->filhos[i] = NULL; 
    }
    arvore->tamanho = 3;
    
    arvore->filhos[0] = arvore2;

    arvore2->dados[0] = 2;
    arvore2->dados[1] = 3;
    arvore2->dados[2] = 4;
    arvore2->tamanho = 3;

    printf("end arv 1: %p\n", arvore);
    printf("end arv 2: %p\n", arvore2);

    arvore3 = buscaArv(arvore, 22);

    printf("end chave: %p\n", arvore3);

}