#include "stdio.h"
#include "stdlib.h"

#define M 5

typedef struct btreenode BTreeNode;
struct BTreeNode{

    int chaves[M];
    int tamanho;
    BTreeNode *filhos[M];

};