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

struct avl{

    TipoVaga vaga;

    //essas duas variaveis foram declaradas para facilitar a manipulacao das estatisticas na arvore de registro
    int tempoTotalOcp;
    int qtdRegistros;

    int altura;
    struct avl *esq;
    struct avl *dir;

};
typedef struct avl AVL;

//cria uma arvore vazia apontando para null
AVL *criaArv();

//verifica se a arvore esta vazia ou nao
int arvVazia(AVL *arv);

//imprime os dados de uma arvore em ordem pre-fixada
void imprimeArvore(AVL *raiz);

//cria um no com a chave especificada e retorna um ponteiro para ele
AVL *criaNo(TipoVaga vaga);

//retorna a altura da arvore (definida na struct)
int alturaArv(AVL *raiz);

//recebe uma arvore e calcula seu fator de balanceamento
int calculaFator(AVL *raiz);

//retorna o maior valor entre dois nos
int maiorValor(int a, int b);

//faz uma rotacao simples a esquerda em uma arvore AVL
AVL *rotacaoEsquerda(AVL *raiz);

//faz uma rotacao simples a direita em uma arvore AVL
AVL *rotacaoDireita(AVL *raiz);

//insere um no na arvore AVL
AVL *insereAVL(AVL *raiz, TipoVaga vaga);

//retorna o menor valor de uma arvore
AVL *inOrderPredecessor(AVL *raiz);

//dada uma arvore "raiz" e um valor "chave", esta funçao remove o nó da arvore AVL contendo tal valor.
AVL *removeAVL(AVL* raiz, int chave);

//busca uma vaga de chave "numero" e retorna um ponteiro para aquela vaga (arvore AVL)
AVL *buscaVaga(AVL *raiz, int numero);

//conta quantos nós ha em uma determinada arvore
int contaNos(AVL *raiz);;
