/*
*
* Trabalho 1 - Estacionamento Rotativo (Árvores AVL)
* Disciplina: Algoritmos e Estruturas de Dados 2
* Professor: Edson Nascimento
* Abril de 2021
*
* Aluno: Jorge Pablo de Almeida Frota
* Curso: Engenharia da Computação
*
*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "conio.h"

#define MAX_VAGAS 1024

struct tipoCliente{

    char placa[8];
    char classe;
    int entrada;
    int saida;
    float valor;

};
typedef struct tipoCliente TipoCliente;

struct tipoVaga{

    int piso;
    int numero;
    char classe;
    TipoCliente cliente;

};
typedef struct tipoVaga TipoVaga;


//esse tipo é armazenado na árvore AVL
typedef struct avl AVL;
struct avl{

    TipoVaga vaga;

    //essas duas variaveis foram declaradas para facilitar a manipulacao das estatisticas na arvore de registro
    int tempoTotalOcp;
    int qtdRegistros;

    int altura;
    AVL *esq;
    AVL *dir;

};

//cria uma arvore vazia apontando para null
AVL *criaArv(){

    return NULL;

}

//verifica se a arvore esta vazia ou nao
int arvVazia(AVL *arv){

    return (arv == NULL);

}

//imprime os dados de uma arvore em ordem pre-fixada
void imprimeArvore(AVL *raiz){

    if(!arvVazia(raiz)){
        imprimeArvore(raiz->esq);
        printf("Numero da vaga: %03d | Piso: %d | ", raiz->vaga.numero, raiz->vaga.piso);
        printf("Classe: %c | Placa: %s | Entrou: ", raiz->vaga.classe, raiz->vaga.cliente.placa);
        imprimeHorario(raiz->vaga.cliente.entrada);
        imprimeArvore(raiz->dir);
    }

}

//cria um no com a chave especificada e retorna um ponteiro para ele
AVL *criaNo(TipoVaga vaga){

    AVL *novo = malloc(sizeof(AVL));
    novo->vaga = vaga;
    novo->altura = 1;
    novo->qtdRegistros = 1;
    novo->tempoTotalOcp = 0;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;

}


//busca uma vaga de chave "numero" e retorna um ponteiro para aquela vaga (arvore AVL)
AVL *buscaVaga(AVL *raiz, int numero){

    if (raiz == NULL || raiz->vaga.numero == numero) return raiz;

    if (raiz->vaga.numero > numero) return buscaVaga (raiz->esq, numero);

    else return buscaVaga(raiz->dir, numero);

}

//retorna a altura da arvore (definida na struct)
int alturaArv(AVL *raiz){

    if(raiz == NULL) return 0;
    return raiz->altura;

}

//recebe uma arvore e calcula seu fator de balanceamento
int calculaFator(AVL *raiz){

    if(raiz == NULL) return 0;
    return alturaArv(raiz->esq) - alturaArv(raiz->dir);

}

//retorna o maior valor entre dois nos
int maiorValor(int a, int b){

    if(a > b) return a;
    else return b;

}

//faz uma rotacao simples a esquerda em uma arvore AVL
AVL *rotacaoEsquerda(AVL *raiz){

    AVL *ap = raiz;
    AVL *au = ap->dir;

    ap->dir = au->esq;
    au->esq = ap;

    ap->altura = 1 + maiorValor(alturaArv(ap->esq), alturaArv(ap->dir));
    au->altura = 1 + maiorValor(alturaArv(au->esq), alturaArv(au->dir));
    
    return au;

}

//faz uma rotacao simples a direita em uma arvore AVL
AVL *rotacaoDireita(AVL *raiz){

    AVL *ap = raiz;
    AVL *au = ap->esq;

    ap->esq = au->dir;
    au->dir = ap;

    ap->altura = 1 + maiorValor(alturaArv(ap->esq), alturaArv(ap->dir));
    au->altura = 1 + maiorValor(alturaArv(au->esq), alturaArv(au->dir));
    
    return au;

}

//insere um no na arvore AVL
AVL *insereAVL(AVL *raiz, TipoVaga vaga){

    if(arvVazia(raiz)){
        AVL *novo = criaNo(vaga);
        return novo;
    }

    else if(vaga.numero < raiz->vaga.numero){
        raiz->esq = insereAVL(raiz->esq, vaga);
    }

    else if(vaga.numero > raiz->vaga.numero){
        raiz->dir = insereAVL(raiz->dir, vaga);
    }

    else return raiz;

    //atualizando a altura
    raiz->altura = 1 + maiorValor(alturaArv(raiz->esq), alturaArv(raiz->dir));

    //calculando o fator de balanceamento
    int fb;

    fb = calculaFator(raiz);

    //LL 
    if(fb > 1 && vaga.numero < raiz->esq->vaga.numero){
        return rotacaoDireita(raiz);
    }

    //RR
    if(fb < -1 && vaga.numero > raiz->dir->vaga.numero){
        return rotacaoEsquerda(raiz);
    }

    //LR
    if(fb > 1 && vaga.numero > raiz->esq->vaga.numero){
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    //RL
    if(fb < -1 && vaga.numero < raiz->dir->vaga.numero){
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;

}

//retorna o menor valor de uma arvore
AVL *inOrderPredecessor(AVL *raiz){

    AVL* atual = raiz;
  
    //faz um loop até achar o nó mais a esquerda da arvore
    while (atual->dir != NULL){
        atual = atual->dir;
    }

    return atual;

}

//dada uma arvore "raiz" e um valor "chave", esta funçao remove o nó da arvore AVL contendo tal valor.
AVL *removeAVL(AVL* raiz, int chave){

    if (raiz == NULL) return raiz;
  
    if (chave < raiz->vaga.numero) raiz->esq = removeAVL(raiz->esq, chave);
  
    else if(chave > raiz->vaga.numero) raiz->dir = removeAVL(raiz->dir, chave);
    
    //se a chave for igual ao numero armazenado, esse nó vai ser deletado
    else{
        
        //no com um filho ou nenhum filho
        if( (raiz->esq == NULL) || (raiz->dir == NULL) ){

            AVL *temp;
            if(raiz->esq == NULL) temp = raiz->dir;
            else temp = raiz->esq;

            //caso onde nao ha filhos
            if (temp == NULL){
                temp = raiz;
                raiz = NULL;
            }

            //caso onde ha apenas um filho
            else *raiz = *temp;
            
            free(temp);

        }

        //caso onde ha 2 filhos
        //copia o antecessor numerico para esse nó
        //deleta o antecessor
        else{

            AVL* temp = inOrderPredecessor(raiz->esq);
  
            raiz->vaga = temp->vaga;
  
            raiz->esq = removeAVL(raiz->esq, temp->vaga.numero);

        }

    }
    
    //caso a raiz tenha apenas um nó retorna NULL
    if (raiz == NULL) return raiz;

    //após a remoção atualiza a altura e faz as rotações de cada caso novamente
    raiz->altura = 1 + maiorValor(alturaArv(raiz->esq), alturaArv(raiz->dir));
  
    int fb = calculaFator(raiz);

    //LL
    if (fb > 1 && calculaFator(raiz->esq) >= 0) return rotacaoDireita(raiz);
  
    //LR
    if (fb > 1 && calculaFator(raiz->esq) < 0){
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }
  
    //RR
    if (fb < -1 && calculaFator(raiz->dir) <= 0) return rotacaoEsquerda(raiz);
    
    //RL
    if (fb < -1 && calculaFator(raiz->dir) > 0){
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }
  
    return raiz;

}

//imprime o cabeçalho do programa
void imprimeBoasVindas(){

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("                                 ESTACIONAMENTO JP'S                                 \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");

}

void imprimeManual(){

    system("cls");
    printf("BEM-VINDO AO MANUAL DO USUARIO!\n\n");
    printf("1 - Digite a quantidade de elementos a serem INSERIDOS e o programa ira gerar automaticamente\n");
    printf("valores aleatorios para todas as entradas (cliente, vaga, horario de entrada, etc)\n\n");
    printf("2 - Digite a quantidade de elementos a serem REMOVIDOS e o programa ira remover aquela quantidade, \n");
    printf("retirando sempre a vaga armazenada na raiz da arvore AVL do estacionamento.\n\n");
    printf("3 - Essa opcao imprime quantas e quais vagas estao sendo ocupadas em cada horario, bem como a \n");
    printf("taxa de ocupacao (baixa, media, alta) e os dados da vaga e do cliente (piso, classe, horario de entrada)\n\n");
    printf("4 - Essa opcao encerra o expediente do sistema e contabiliza todos os registros de veiculos REMOVIDOS anteriormente\n");
    printf("Apos a remocao, eh feita a analise estatistica dos registros e sao mostradas na tela todas as analises.\n\n");

    printf("* Se nao houverem mais vagas disponiveis para um cliente na classe x, este sera alocado para a proxima vaga disponivel.\n");
    printf("* Caso o programa avance ate a ultima vaga, ocorre uma analise das vagas disponiveis a partir da numero 1.\n");
    printf("* Se o estacionamento estiver cheio, nenhum cliente sera inserido.\n");
    printf("* Se o estacionamento estiver vazio, nenhum cliente sera removido.\n");
    printf("* Se voce entrar uma quantidade de insercao maior do que a capacidade atual do estacionamento, serao inseridas\n");
    printf("apenas a quantidade de vagas suportadas pelo estacionamentos, as demais serao descartadas. A remocao ocorre de forma analoga.\n");
    printf("* O estacionamento so funciona das 06h00 ate as 23h59, entao so serao gerados horarios nesse intervalo.\n\n");
    printf("Divirta-se.\n\n");

}

//calcula e imprime a media de vagas ocupadas por hora
void mediaVagasOcp(int *horaOcp){

    int hora = 0;
    int somaCarros = 0;
    int qtdHoras = 0;
    float media;
    
    //percorre cada hora e verifica quantos carros tem em cada uma
    //gera a soma de carros e a quantidade de horas que receberam pelo menos 1 veiculo
    while(hora < 24){
        if(horaOcp[hora] > 0){
            somaCarros += horaOcp[hora];
            qtdHoras++;
        }
        hora++;
    }

    if(qtdHoras == 0) media = 0;
    else media = (float) somaCarros / (float) qtdHoras;

    printf("\nNumero medio de vagas ocupadas por hora: %d\n", (int) media);

}

//calcula e imprime o horario de pico
void horarioPico(int *horaOcp){

    int hora = 0;
    int maiorQtd = 0;
    int horarioDePico = 0;

    while(hora < 24){
        
        //verifica qual o horario onde houve mais inserçoes
        //o contador "hora" representa a hora atual no vetor horaOcp
        if(horaOcp[hora] > maiorQtd){
            maiorQtd = horaOcp[hora];
            horarioDePico = hora;
        }
        hora++;

    }
    
    if(maiorQtd == 0) printf("Sem horario de pico, pois nao houve carros.\n");
    else printf("Horario de pico: %d horas\nQtd de carros naquele horario: %d carros\n", horarioDePico, maiorQtd);

}

//verifica se ja existe uma vaga com a chave "k" armazenada na arvore
int verificaVaga(AVL *raiz, int k){

    if(raiz == NULL) return 0;

    else if(k == raiz->vaga.numero) return 1;

    else if(k < raiz->vaga.numero) return verificaVaga(raiz->esq, k);

    else return verificaVaga(raiz->dir, k);

}

//atribui o piso automaticamente conforme o numero da vaga recebido, que vai de 1 a 1024.
int geraPiso(int numero){

    return (int) ceil(numero / 128.0);

}

char classeDoNum(int numero){

    if(numero <= 102) return 'A';
    else if(numero <= 306) return 'B';
    else if(numero <= 510) return 'C';
    else return 'D';

}

//gera um numero de vaga de acordo com o piso (sempre do menor para o maior)
TipoVaga geraVaga(AVL *raiz, TipoCliente cliente){

    TipoVaga vaga;

    if(cliente.classe == 'A') vaga.numero = 1;

    else if(cliente.classe == 'B') vaga.numero = 103;

    else if(cliente.classe == 'C') vaga.numero = 307;

    else vaga.numero = 511;

    while(verificaVaga(raiz, vaga.numero)){
        if(vaga.numero > MAX_VAGAS) vaga.numero = 1;
        vaga.numero++;
    }
    
    vaga.classe = classeDoNum(vaga.numero);
    vaga.piso = geraPiso(vaga.numero);
    vaga.cliente = cliente;

    printf("\nVaga gerada com sucesso!");
    printf("\nConfira seus dados abaixo: \n");
    printf("\nNumero da vaga: %d", vaga.numero);
    printf("\nClasse: %c | Piso: %d", vaga.classe, vaga.piso);
    printf("\nPlaca do Carro: %s\nHorario de entrada: ", vaga.cliente.placa);
    imprimeHorario(cliente.entrada);

    return vaga;

}

//recebe uma quantidade x de minutos e imprime esse valor em Hr:Min
int imprimeHorario(int totalMin){

    int hora;
    int min;

    hora = totalMin / 60;
    min = totalMin % 60;

    printf("%02dh%02d\n", hora, min);

}

int geraHrSaida(int tempo){

    int hrEnt, minEnt;
    int hrSaida, minSaida;
    int tempoSaida;

    hrEnt = tempo / 60;
    minEnt = tempo % 60;

    do{
        hrSaida = hrEnt + (rand() % (24 - hrEnt));
        minSaida = minEnt + (rand() % (60 - minEnt));
        tempoSaida = minSaida + (hrSaida * 60);
    }while(tempoSaida < tempo);

    return tempoSaida;

}

//registra a saida de um veiculo do estacionamento rotativo
AVL *regSaida(AVL *raiz, float *tempoMedio, float *valorArrecadado, int *horaOcp){

    if(arvVazia(raiz)) return NULL;

    int num;
    int hr, min;
    int entrada, saida;
    int horaEntrada, horaSaida;

    AVL *noSaida;

    noSaida = raiz;

    entrada = noSaida->vaga.cliente.entrada;

    saida = geraHrSaida(entrada);
    
    printf("\nVaga removida com sucesso. Confira os dados: \n\n");
    printf("Numero da vaga: %d\n", noSaida->vaga.numero);
    printf("Horario de entrada: ");
    imprimeHorario(entrada);
    printf("Horario de saida: ");
    imprimeHorario(saida);
    printf("Tempo ocupado na vaga: %d minutos\n", saida - entrada);
    printf("Valor total pago: R$%.02f\n", (saida - entrada) * 0.05);
    *valorArrecadado = *valorArrecadado + ( (saida-entrada) * 0.05 );

    *tempoMedio = *tempoMedio + (saida - entrada); 

    horaEntrada = entrada/60;
    horaSaida = saida/60;

    //armazenando os horários em que o carro esteve na vaga no vetor "horaOcp", para controlar o horario de pico.
    while(horaEntrada <= horaSaida){
	   horaOcp[horaEntrada]++;
	   horaEntrada++;
	}

    noSaida->vaga.cliente.saida = saida;
    noSaida->vaga.cliente.valor = (saida-entrada)*0.05;
    noSaida->tempoTotalOcp = saida - entrada;

    return noSaida;

}

char geraClasse(){

    char classe;

    classe = 'A' + (char) (rand() % 4);

    return classe;

}

void geraPlaca(TipoCliente *novo){

    int i = 0;
    while(i < 7){
        novo->placa[i] = 'A' + (char) (rand() % 26);
        i++;
    }
    novo->placa[7] = '\0';

}

int geraHrEntrada(){

    int hr, min;

    hr = 6 + (rand() % 18);
    min = rand() % 60;

    return (hr * 60) + min;

}

//registra uma entrada de cliente e retorna uma variavel Cliente contendo os dados gerados
TipoCliente regEntrada(){

    TipoCliente novo;
    int hr;
    int min;

    novo.classe = geraClasse();

    geraPlaca(&novo);

    novo.entrada = geraHrEntrada();

    novo.saida = 0;
    novo.valor = 0;

    return novo;

}

//faz as verificacoes necessarias 
AVL *verificaRegistro(AVL *raiz, AVL *noSaida){

    AVL *ptrVagaRemovida;

    //caso nao encontre a vaga especificada no registro, insere esse no no registro
    if( buscaVaga(raiz, noSaida->vaga.numero) == NULL ){
        raiz = insereAVL(raiz, noSaida->vaga);
        ptrVagaRemovida = buscaVaga(raiz, noSaida->vaga.numero);
    }
    
    //caso contrario identifica o nó onde tem aquela vaga e incrementa a qtd. de registros
    else{
        ptrVagaRemovida = buscaVaga(raiz, noSaida->vaga.numero);
        ptrVagaRemovida->qtdRegistros++;
    }
    
    //soma o tempo total de ocupacao para tirar a media ao final do expediente
    ptrVagaRemovida->tempoTotalOcp += noSaida->tempoTotalOcp;

    return raiz;

}

//imprime as informacoes da arvore de registro e seu tempo medio de ocupacao
void imprimeRegistro(AVL *raiz){

    if(!arvVazia(raiz)){
        imprimeRegistro(raiz->esq);
        printf("\nNumero da vaga: %03d | Piso: %d | Classe: %c\n", raiz->vaga.numero, raiz->vaga.piso, raiz->vaga.classe);
        printf("Tempo medio de Ocupacao: %.02f minutos\n", (float) raiz->tempoTotalOcp / (float) raiz->qtdRegistros);
        imprimeRegistro(raiz->dir);
    }

}

//imprime um relatorio sobre a ocupacao atual do rotativo
void imprimeOcupacao(AVL *raiz){

    if(contaNos(raiz) == MAX_VAGAS) printf("\nEstacionamento lotado\n");
    else if(contaNos(raiz) == 0) printf("\nEstacionamento vazio\n");
    else if(contaNos(raiz) > 716 ) printf("\nOcupacao alta (mais de 70%%)\n");
    else if(contaNos(raiz) >  307) printf("\nOcupacao media (mais de 30%%)\n");
    else printf("\nOcupacao baixa (menos de 30%%)\n");

}

//conta quantos nós ha em uma determinada arvore
int contaNos(AVL *raiz){

    if(!arvVazia(raiz)){
        return 1 + contaNos(raiz->esq) + contaNos(raiz->dir);
    }

    else return 0;

}

int main(){

    srand(time(NULL));
    
    //arvore do estacionamento
    AVL *raizRotativo = criaArv();

    //arvore de controle do registro de entradas
    AVL *raizRegistro = criaArv();
    
    //variavel AVL auxiliar para movimentação de um nó entre as arvores do rotativo e de registro
    AVL *noSaida;

    //variaveis auxiliares para movimentação de informações
    TipoVaga vaga;
    TipoCliente cliente;

    //variaveis gerais para controle de estatisticas pós-expediente
    int horaOcp[24];
    float valorArrecadado = 0.0;
    int qtdEntradas = 0;
    int ocupacaoAtual = 0;

    
    int qtd;
    int op = 0;
    float tempoMedio = 0.0;    

    //cada posicao equivale a uma hora especifica do dia
    //ex: horaOcp[13] é 13hrs
    //aqui é atribuido 0 em todas as posicoes para iniciar o vetor com 0 insercoes durante o dia
    int i = 0;
    while(i < 24){
        horaOcp[i] = 0;
        i++;
    }

    i = 0;
     
    system("cls");

    while(op != 4){
        imprimeBoasVindas();
        printf("-------------------------------------------------------------------------------------\n");
        printf("OBSERVACAO: Veiculos nao removidos apos o fim do expediente nao serao contabilizados.\n");
        printf("-------------------------------------------------------------------------------------\n\n");
        printf("Digite a opcao desejada: \n\n");
        printf("1 - Registrar entrada\n2 - Registrar saida\n3 - Imprimir vagas ocupadas\n");
        printf("4 - Encerrar expediente\n5 - VER MANUAL DE FUNCIONAMENTO\n");
        scanf("%d", &op);
        fflush(stdin);

        switch(op){
            
            //entrada
            case 1:
                if(ocupacaoAtual >= MAX_VAGAS){
                    printf("Estacionamento cheio. Por favor remova um ou mais veiculos\n");
                    qtd = 0;
                }
                else{
                    printf("\nQuantas vagas deseja inserir?\n");
                    scanf("%d", &qtd);
                    while(i < qtd && ocupacaoAtual < MAX_VAGAS){
                        cliente = regEntrada();
                        vaga = geraVaga(raizRotativo, cliente);
                        raizRotativo = insereAVL(raizRotativo, vaga);
                        qtdEntradas++;
                        ocupacaoAtual++;
                        if(ocupacaoAtual == MAX_VAGAS) printf("\n\nESTACIONAMENTO LOTADO. NEM TODAS AS VAGAS FORAM INSERIDAS.\n");
                        i++;
                    }
                }
               
                i = 0;

                getch();
                fflush(stdin);

                system("cls");
                            
            break;

            //saida de veiculos
            //a remocao ocorrera sempre na RAIZ da arvore do rotativo
            case 2:
                
                if(raizRotativo == NULL){
                    printf("Nao ha vagas a remover\n");
                    qtd = 0;
                }
                else{
                    printf("Quantas vagas deseja remover?\n");
                    scanf("%d", &qtd);
                    while(i < qtd){
                        noSaida = regSaida(raizRotativo, &tempoMedio, &valorArrecadado, horaOcp);
                        if(noSaida != NULL){
                            raizRegistro = verificaRegistro(raizRegistro, noSaida);
                            raizRotativo = removeAVL(raizRotativo, noSaida->vaga.numero);
                            ocupacaoAtual--;
                        }
                        i++;
                    }
                }                

                i = 0;
                
                getch();
                fflush(stdin);
                system("cls");

            break;

            //impressao de vagas ocupadas
            case 3:
                if(raizRotativo != NULL) printf("\nVagas ocupadas em ordem crescente:\n\n");
                imprimeArvore(raizRotativo);
                printf("\nQuantidade de vagas ocupadas: %d\n", ocupacaoAtual);
                imprimeOcupacao(raizRotativo);
                getch();
                fflush(stdin);
                system("cls");
            break;

            //encerramento de expediente
            case 4:

                system("cls");
                printf("-------------------------------------------------------------------------------------\n");
                printf("                                   Relatorio do dia\n");
                printf("-------------------------------------------------------------------------------------\n\n");

                printf("-------------------------------------------------------------------------------------");
                imprimeRegistro(raizRegistro);
                printf("-------------------------------------------------------------------------------------\n\n");

                printf("-------------------------------------------------------------------------------------");
                mediaVagasOcp(horaOcp);

                if(qtdEntradas == 0) tempoMedio = 0;
                else tempoMedio = tempoMedio / qtdEntradas;
                printf("Tempo medio de ocupacao (geral): %.02f minutos\n", tempoMedio);
                printf("-------------------------------------------------------------------------------------\n\n");
                printf("-------------------------------------------------------------------------------------\n");
                horarioPico(horaOcp);
                printf("-------------------------------------------------------------------------------------\n\n");
                printf("-------------------------------------------------------------------------------------\n");
                printf("Valor total arrecadado hoje: R$%.02f\n", valorArrecadado);
                printf("-------------------------------------------------------------------------------------\n\n");

            break;

            case 5:
                imprimeManual();
                getch();
                fflush(stdin);
                system("cls");
            break;

            default:
            printf("\nOpcao invalida\n");
            getch();
            fflush(stdin);
            system("cls");
            
        }

    }

}