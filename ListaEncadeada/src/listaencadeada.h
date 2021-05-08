struct Node{

    int valor;
    struct Node *prox;

};
typedef struct Node node;

//cria uma lista inicialmente vazia
node* criaLista();

//libera todos os nós de uma lista e retorna uma lista vazia
node* liberaLista();

//imprime todos os nós de uma lista
void imprimeLista();

//retorna 1 se o elemento está na lista e 2 se ele não está
int buscaLista();

//cria um novo nó com a chave correspondente
node* criaNo();

//insere um nó no inicio da lista
node* insereInicio();

//insere um nó no final da lista
node* insereFinal();

//insere um nó após um determinador nó na lista
void insereApos();

//faz a insercao ordenada de um novo nó
node* insercaoOrdenada();

//deleta (libera) um determinado nó
node* deletaNo();

//remove um elemento "chave"
node* removeElemento();