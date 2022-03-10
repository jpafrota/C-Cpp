#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "time.h"
#include "conio.h"
#include "trabalho1arvoreavl.h"

#define MAX_VAGAS 1024

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