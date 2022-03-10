#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define QUALIFY1 10
#define QUALIFY2 8
#define QUALIFY3 5
#define NUMERO_PILOTOS 24

struct Pilotos
{
    float  tempo;
    int    numero;
	char   equipe;
    //int vaicorrer;
    struct Pilotos *prox;
};

typedef struct Pilotos piloto;

piloto *criaLista(){

    return NULL;

}

piloto *criaNo(float tempo, int numero, char equipe){

    piloto *novo = malloc(sizeof(piloto));

    novo->equipe = equipe;
    novo->tempo = tempo;
    novo->numero = numero;

    novo->prox = NULL;

    return novo;

}

piloto *insereInicio(piloto *head, piloto *novo){

    novo->prox = head;
    head = novo;

    return head;

}

piloto *insereFinal(piloto *head, piloto *novo){
    
    if(head == NULL) head = novo;

    else if(head->prox == NULL) head->prox = novo;

    else insereFinal(head->prox, novo);

    return head;

}

void *insereApos(piloto *atual, piloto *novo){

    if(atual != NULL){
        novo->prox = atual->prox;
        atual->prox = novo;
    }

}


piloto *buscaLista(piloto *lista, int numero){

    if(lista == NULL) return NULL;

    else if(lista->numero <= numero){
        return lista;
    }

    else buscaLista(lista->prox, numero);

}

piloto *insercaoOrdenada(piloto *lista, piloto *novo){

    //caso a lista esteja vazia
    if(lista == NULL){
        return novo;
    }    

    //caso o novo elemento seja menor que o primeiro elemento da lista
    else if(lista->numero >= novo->numero){
        return insereInicio(lista, novo);
    }

    //aqui o programa está no último elemento, significa que não achou nenhum numero maior que o novo
    //logo o novo será inserido no final
    else if(lista->prox == NULL){
        return insereFinal(lista, novo);
    }

    //se chegou aqui é porque o primeiro elemento é menor que o novo, estamos em um nó no meio da lista
    //então só resta saber se será inserido após o nó atual ou não. se não, chama a função recursivamente
    else if(lista->prox->numero >= novo->numero){
        insereApos(lista, novo);
    }

    //chama a função recursivamente
    else insercaoOrdenada(lista->prox, novo);

    //retorna a cabeça atualizada da lista
    return lista;

}

void imprime(piloto *lista){

    if(lista != NULL){
        printf("%d \n", lista->numero);
        imprime(lista->prox);
    }

}

int buscaEquipe(piloto *head, char chave){

    int contador = 0;

    //precisei usar o while pq preciso ver se tem pelo menos 2 elementos 'chave' na lista
    //pra isso preciso de um contador, o while evita parametro desnecessario

    while(head != NULL && contador < 2){
        if(head->equipe == chave) contador++;
        head = head->prox;
    }

    return contador;

}

char geraEquipe(piloto* lista){

    char equipe;
    int contador = 1;

    equipe = 'A' + (char)(rand() % 12);

    if(buscaEquipe(lista, equipe) > 1){
        geraEquipe(lista);
    }

    else return equipe;

}

piloto *criaGridInicial(piloto *lista){

    int contador = 1;
    float tempo = 5.0;
    int numero;
    char equipe;
    piloto *novo = NULL;

    while(contador <= NUMERO_PILOTOS){
        numero = contador;
        equipe = geraEquipe(lista);
        novo = criaNo(tempo, numero, equipe);
        lista = insereFinal(lista, novo);
        contador++;
    }

}

//essa lista não é recursiva pois trabalha com um contador
int contaElementos(piloto *head){

    int elementos = 0;

    while(head != NULL){

        elementos++;
        head = head->prox;

    }

    return elementos;

}

int buscaNum(piloto* head, int n){

    if(head == NULL) return 0;
    
    if(head->numero == n) return 1;

    else buscaNum(head->prox, n);

}

int geraNumero(piloto *listaVolta, piloto *listaCompleta){

    int numero = 0;

    do{
        numero = 1 + (rand() % 24);
    }while((buscaNumero(listaVolta, numero)) || (!(buscaNumero(listaCompleta, numero))));

    return numero;

}

piloto *geraPiloto(piloto *listaVolta, piloto *listaCompleta){

    int numero;
    float tempo;
    char equipe;

    numero = geraNumero(listaVolta, listaCompleta);
    

}

piloto *geraVolta(int qtdCarros, piloto *listaVolta, piloto *listaCompleta){

    int contador = 1;
    int numero = 0;
    float tempo = 5.0;
    piloto *novo;

    while(contador <= qtdCarros){
        novo = geraPiloto(listaVolta, listaCompleta);

        contador++;
    }

}

void qualify(piloto *listaCompleta){

    int volta = 1;
    int qtdCarros = 1;
    piloto *listaVolta;



    while(volta <= QUALIFY1){
        qtdCarros = 1 + (rand() % contaElementos(listaCompleta));
        listaVolta = criaLista();
        listaVolta = geraVolta(qtdCarros, listaCompleta, listaVolta);
        listaVolta = apagaListaVolta(listaVolta);
    }

}

int main(){

    srand(time(NULL));

    piloto *listaInicial;

    piloto *listaEliminadosQ1;
    piloto *listaEliminadosQ2;
    piloto *listaEliminadosQ3;



    listaInicial = criaLista();

    listaInicial = criaGridInicial(listaInicial);

    imprime(listaInicial);

}