#include "stdio.h"
#include "stdlib.h"

#define M 5

typedef struct nodeBTree BTreeNode;
struct nodeBTree{

    //cada nó só pode ter M-1 chaves, mas M será usado para saber quando o limite foi ultrapassado.
    int chaves[M]; 
    int tamanho;
    BTreeNode *filhos[M];

};

int btree_isEmpty();

BTreeNode *btree_create();
BTreeNode *btree_newNode();
BTreeNode *btree_print();
BTreeNode *btree_search();
BTreeNode *btree_insert();
