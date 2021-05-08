struct Node{

    int valor;
    struct Node *prox;

};
typedef struct Node node;

node* criaLista();
node* liberaLista();
void imprimeLista();
int buscaLista();
node* criaNo();
node* insereInicio();
node* insereFinal();
void insereApos();
node* insercaoOrdenada();
node* deletaNo();
node* removeElemento();