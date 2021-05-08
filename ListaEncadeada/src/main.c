#include "stdio.h"
#include "stdlib.h"
#include "listaencadeada.h"

int main(){

    node *li;

    li = criaLista();

    li = insereInicio(li, 6);
    li = insereInicio(li, 7);
    li = insereInicio(li, 8);
    li = insereInicio(li, 10);

    imprimeLista(li);
    printf("\n");

    li = liberaLista(li);

    imprimeLista(li);
    printf("\n");

    li = insercaoOrdenada(li, 56);
    li = insercaoOrdenada(li, 7);
    li = insercaoOrdenada(li, 1);
    li = insercaoOrdenada(li, 100);

    imprimeLista(li);
    printf("\n");

    li = removeElemento(li, 1);
    li = insercaoOrdenada(li, 12);

    imprimeLista(li);
    printf("\n");

}