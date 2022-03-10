#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUALIFY1 10
#define QUALIFY2 8
#define QUALIFY3 5
#define NUMERO_PILOTOS 24

struct Pilotos
{
    float  tempo;
    int    numero;
	char   equipe;
    struct Pilotos *proximo;
};

typedef struct Pilotos piloto;

//cria um novo nó do tipo 'piloto' apontando para NULL e retorna seu endereço
piloto* criaPiloto(int valor, char equipe, float tempo){

    piloto *novo = malloc(sizeof(piloto));

    novo->numero = valor;
    novo->equipe = equipe;
    novo->tempo = tempo;
    novo->proximo = NULL;

    return novo;

}

//insere um nó do tipo piloto no final da lista
void inserePilotoFinal(piloto** head, piloto* novo){

    piloto *aux = *head;

    if(*head == NULL){
        *head = novo;
        return;
    }
    
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }

    aux->proximo = novo;

}

//percorre uma certa lista e retorna a quantidade de elementos presentes nela
int contaElementos(piloto *head){

    int elementos = 0;

    while(head != NULL){

        elementos++;
        head = head->proximo;

    }

    return elementos;

}

//faz uma busca na lista para descobrir se uma equipe 'chave' ainda tem direito a mais pilotos no campeonato
int buscaEquipe(piloto *head, char chave){

    int contador = 0;

    while(head != NULL && contador < 2){
        if(head->equipe == chave) contador++;
        head = head->proximo;
    }

    return contador;

}

//gera uma equipe aleatoria para tomar posse de um piloto n
char geraEquipe(piloto* lista){

    char equipe;
    int contador = 1;

    equipe = 'A' + (char)(rand() % 12);

    if(buscaEquipe(lista, equipe) > 1){
        geraEquipe(lista);
    }

    else return equipe;

}

//cria a lista inicial de pilotos no percurso, com equipes aleatorias e numeros ordenados de 1 a 24
void criaListaInicial(piloto **lista){

    int totalCarros = 1;
    int numero = 1;
    char equipe;
    piloto *novo = NULL;

    while(totalCarros <= NUMERO_PILOTOS){
        numero = totalCarros;
        equipe = geraEquipe(*lista);
        novo = criaPiloto(numero, equipe, 5);
        inserePilotoFinal(lista, novo);
        totalCarros++;
    }

}

//faz uma busca na lista pra saber se aquele tempo já foi gerado anteriormente
int buscaTempo(int tempo, piloto* lista){

    if(lista == NULL) return 0;

    else if(tempo == lista->tempo) return 1;

    else buscaTempo(tempo, lista->proximo);

}

//gera um valor de tempo aleatório entre 1.5000 e 5.0000
float gerarTempo(piloto *lista){

    float tempo;

    do{
        tempo = (15000.0 + (float) (rand() % 35000)) / 10000.0;
    }while(buscaTempo(tempo, lista));
    
    return tempo;

}

//percorre a lista ate achar o piloto desejado, e se o tempo atual for menor que o armazenado, substitui
//caso contrário, não se altera o tempo armazenado
void guardaMenorTempo(int carro, float tempo, piloto* listaCompleta){

    if(listaCompleta == NULL) return;
    
    if(listaCompleta->numero == carro){
        if(tempo < listaCompleta->tempo) listaCompleta->tempo = tempo;
    }

    else guardaMenorTempo(carro, tempo, listaCompleta->proximo);

}

//insere um carro na lista da volta atual
void insereCarro(int carro, piloto **listaVolta, piloto *listaCompleta){

    if(listaCompleta->numero == carro){
        piloto *novo = NULL;
        novo = criaPiloto(carro, listaCompleta->equipe, gerarTempo(listaCompleta));
        guardaMenorTempo(carro, novo->tempo, listaCompleta);
        inserePilotoFinal(listaVolta, novo);
    }

    else insereCarro(carro, listaVolta, listaCompleta->proximo);

}

//busca uma lista para saber se já há um carro de numero "n" armazenado nela
int buscaCarro(piloto* head, int n){

    if(head == NULL) return 0;
    
    if(head->numero == n) return 1;

    else buscaCarro(head->proximo, n);

}

//gera um valor aleatorio contanto q o carro ainda nao tenha feito nenhuma volta
//e contanto que o carro esteja na lista de corredores da qualificatória atual
int geraCarro(piloto *listaVolta, piloto *listaCompleta){

    int carro = 0;

    do{
        carro = 1 + (rand() % 24);
    }while((buscaCarro(listaVolta, carro)) || (!(buscaCarro(listaCompleta, carro))));

    return carro;

}

//imprime a lista desejada com posicao, piloto, equipe e o melhor tempo ate o momento (em milissegundos)
void imprimeTempo(piloto *lista){

    int posicao = 1;

    printf("| pos. | plto |  eqp.  |    tempo    |\n");

    while(lista != NULL){
        printf("|  %02d  |  %02d  |    %c   |    %.0f    |\n", posicao, lista->numero, lista->equipe, lista->tempo * 10000);
        lista = lista->proximo;
        posicao++;
    }

}

//gera uma lista com os pilotos da volta atual
int gerarVolta(piloto **listaVolta, piloto *listaCompleta, int qtdCarros){

    int carro = 1;
    int tempo = 0;
    int contador = 1;

    while(contador <= qtdCarros){
        carro = geraCarro(*listaVolta, listaCompleta);
        insereCarro(carro, listaVolta, listaCompleta);
        contador++;
    }

}

//função que deleta uma lista
void deletaLista(piloto **lista){

    piloto* atual = *lista;
    piloto* prox = NULL;

    while (atual != NULL){
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }

    *lista = NULL;

}

//função primária de qualificatória, recebe a lista de carros que irão correr e o total de voltas a serem dadas
void qualify(piloto* listaCompleta, int totalVoltas){
    
    int volta = 1;
    int qtdCarros = 1;
    piloto *listaVolta = NULL;

    while(volta <= totalVoltas){
        qtdCarros = 1 + (rand() % contaElementos(listaCompleta));
        gerarVolta(&listaVolta, listaCompleta, qtdCarros);
        deletaLista(&listaVolta);
        volta++;
    }

}

//insere um elemento do tipo piloto em uma determinada lista de maneira ordenada
void insereOrdenado(piloto **lista, piloto *novo){

   piloto *atual = NULL;

    // Caso a lista esteja vazia ou o novo piloto tenha um tempo menor que o primeiro da lista, insere no inicio

    if (*lista == NULL || (*lista)->tempo >= novo->tempo){
        novo->proximo = *lista;
        *lista = novo;
    }

    else {
        atual = *lista;
        // Localiza o nó antes do ponto de inserção

        while (atual->proximo != NULL && atual->proximo->tempo < novo->tempo) {
            atual = atual->proximo;
        }

        //encadeia o nó
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

}

//cria uma cópia ordenada da lista recebida como parâmetro e retorna um ponteiro para ela
piloto *ordenarLista(piloto *listaCompleta){

    piloto *listaOrdenada = NULL;

    while(listaCompleta != NULL){
        piloto *novo = NULL;
        novo = criaPiloto(listaCompleta->numero, listaCompleta->equipe, listaCompleta->tempo);
        insereOrdenado(&listaOrdenada, novo);
        listaCompleta = listaCompleta->proximo;
    }

    return listaOrdenada;

}

//desata um nó de uma determinada posiçao na lista, e retorna um ponteiro para aquele nó (com todos os seguintes incluidos)
//basicamente separa a lista de entrada em duas a partir do nó do entrada
piloto *desata_no(int qtdEliminados, piloto *lista){

    int contador = 1;
    int posicao_desate = contaElementos(lista) - qtdEliminados;
    piloto *aux = NULL;

    while(contador < posicao_desate){
        lista = lista->proximo;
        contador++;
    }

    aux = lista->proximo;
    lista->proximo = NULL;

    return aux;

}

//esta função cria a lista de eliminados de cada etapa qualificatória
void eliminadosDasEtapas(piloto *listaCompleta, piloto** listaEliminados, int qtdEliminados){

    *listaEliminados = desata_no(qtdEliminados, listaCompleta);

}

//função responsável por juntar duas listas, conectando a "cauda" da primeira à "cabeça" da segunda
void juntarListas(piloto *lista1, piloto *lista2){

    while(lista1->proximo != NULL){
        lista1 = lista1->proximo;
    }

    lista1->proximo = lista2;
	
	 lista2 = NULL;

}

int main(){

    srand(time(NULL));

    piloto *listaCompleta = NULL;
    piloto *listaAntiga = NULL;

    //as listas abaixo contém os pilotos mais lentos de cada Qualify
    piloto *listaEliminadosQ1 = NULL;
    piloto *listaEliminadosQ2 = NULL;
    piloto *listaEliminadosQ3 = NULL;

    criaListaInicial(&listaCompleta);

    qualify(listaCompleta, QUALIFY1);
    
    listaAntiga = listaCompleta;
    listaCompleta = ordenarLista(listaCompleta);
    deletaLista(&listaAntiga);

    printf("\n------------- QUALIFY 1 --------------\n");
    imprimeTempo(listaCompleta);

    eliminadosDasEtapas(listaCompleta, &listaEliminadosQ1, 7);

    qualify(listaCompleta, QUALIFY2);

    listaAntiga = listaCompleta;
    listaCompleta = ordenarLista(listaCompleta);
    deletaLista(&listaAntiga);

    printf("\n------------- QUALIFY 2 --------------\n");
    imprimeTempo(listaCompleta);

    eliminadosDasEtapas(listaCompleta, &listaEliminadosQ2, 7);

    qualify(listaCompleta, QUALIFY3);

    listaAntiga = listaCompleta;
    listaCompleta = ordenarLista(listaCompleta);
    deletaLista(&listaAntiga);

    printf("\n------------- QUALIFY 3 --------------\n");
    imprimeTempo(listaCompleta);

    eliminadosDasEtapas(listaCompleta, &listaEliminadosQ3, 9);

    juntarListas(listaCompleta, listaEliminadosQ3);
    juntarListas(listaCompleta, listaEliminadosQ2);
    juntarListas(listaCompleta, listaEliminadosQ1);

    printf("\n------------- GRID DE LARGADA --------------\n");   
    imprimeTempo(listaCompleta);

}