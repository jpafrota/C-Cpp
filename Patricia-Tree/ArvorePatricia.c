#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da Árvore Patricia.
typedef struct TrieNode {

    // Nó com a sílaba armazenada.
    char palavra[20];

    // Ponteiros para os filhos
    // Nó abaixo contém todas as palavras que iniciam com a mesma sílaba armazenada no nó em questão
    struct TrieNode* abaixo;

    // Nó à direita contém as palavras completamente diferentes do nó analisado
    struct TrieNode* dir;

    // Variáveis auxiliares para determinar o nível e identificar se uma sílaba consiste em uma palavra ou não.
    int nivel;
    int fimPalavra;

} trieNode;

// Cria uma árvore vazia
trieNode* Trie_create() {

    return NULL;

}

// Cria um novo nó
trieNode* Trie_createNode(char* carga) {

    trieNode* novo = malloc(sizeof(trieNode));
    strcpy(novo->palavra, carga);

    novo->abaixo = NULL;
    novo->dir = NULL;

    novo->fimPalavra = 1;
    novo->nivel = 0;

    return novo;

}

// Verifica se a árvore está vazia
int Trie_isEmpty(trieNode* raiz) {

    return (raiz == NULL);

}

// Recebe uma string e copia para outra variavel uma palavra da posicao determinada em diante
void subPalavra(char* entrada, int pos, char* stringAlvo) {

    int i = 0;
    while (i < strlen(entrada) - 1) {

        stringAlvo[i] = entrada[pos];
        i++;
        pos++;

    }

    stringAlvo[i] = '\0';

}

// Insere uma carga (string) na árvore patrícia
trieNode* Trie_insert(trieNode* raiz, char* carga) {

    // Se a árvore for vazia, retorna a raiz com um novo nó.
    if (Trie_isEmpty(raiz)) {
        raiz = Trie_createNode(carga);
        return raiz;
    }

    int i = 0;
    int cont = 0;
    while (i < strlen(carga) && i < strlen(raiz->palavra) && carga[i] == raiz->palavra[i]) {
        i++;
    }

    // Se a primeira letra for imediatamente diferente do nó
    if (i == 0) {

        // Caso a inicial da carga seja menor que o nó atual, insere a carga antes desse nó
        if (carga[i] < raiz->palavra[i]) {
            trieNode* novo = Trie_createNode(carga);
            novo->nivel = raiz->nivel;
            novo->dir = raiz;
            raiz = novo;
        }

        // Caso contrário analisa o nó à direita
        else {

            // Se o nó contiver uma sílaba e a carga for maior que a primeira letra dessa sílaba, avança para o nó à direita
            if (raiz->dir != NULL && carga[i] >= raiz->dir->palavra[i]) raiz->dir = Trie_insert(raiz->dir, carga);

            // Caso a carga seja menor que o nó à direita, ela será inserida imediatamente após o nó atual.
            else {
                trieNode* novo = Trie_createNode(carga);
                novo->nivel = raiz->nivel;
                novo->dir = raiz->dir;
                raiz->dir = novo;
            }

        }

    }

    // Caso algum caractere seja igual, significa que a carga contém a palavra ou o contrário.
    else {

        char subCarga[20];
        char subNo[20];

        subPalavra(raiz->palavra, i, subNo);
        subPalavra(carga, i, subCarga);

        // Se a carga for igual à sílaba armazenada, simplesmente indica que aquela sílaba forma o fim de uma palavra e encerra a execução.
        if (strcmp(raiz->palavra, carga) == 0) raiz->fimPalavra = 1;

        // Se a carga está contida na sílaba do nó atual, divide o nó e armazena a parte diferente em um novo nó abaixo do atual.
        else if (carga[i] == '\0') {

            raiz->abaixo = Trie_insert(raiz->abaixo, subNo);
            raiz->abaixo->nivel = raiz->nivel + 1;
            raiz->palavra[i] = '\0';

        }

        // Se a sílaba atual está contida na carga, apenas desce um nó com a parte da carga que não estava no nó.
        else if (raiz->palavra[i] == '\0') {

            raiz->abaixo = Trie_insert(raiz->abaixo, subCarga);
            raiz->abaixo->nivel = raiz->nivel + 1;

        }

        // Se nenhuma das duas palavras esta completamente contida na outra, divide o nó e continua percorrendo a árvore com a carga dividida.
        else {

            trieNode* novo = Trie_createNode(subNo);
            novo->abaixo = raiz->abaixo;
            novo->nivel = raiz->nivel + 1;

            // Se a sílaba original não constitui fim de palavra, então o novo nó também não irá ser.
            if (raiz->fimPalavra == 0) novo->fimPalavra = 0;

            // Realiza a inserção abaixo, atualizando o nó atual.
            raiz->abaixo = novo;
            raiz->abaixo = Trie_insert(raiz->abaixo, subCarga);
            raiz->palavra[i] = '\0';
            raiz->fimPalavra = 0;

        }

    }

    // Retorna a raiz.
    return raiz;

}

// Imprime todas as silabas armazenadas na arvore e seus niveis.
void Trie_printNiveis(trieNode* raiz) {

    if (raiz != NULL) {

        printf("nivel: %d | ", raiz->nivel);
        printf(" |%s| \n", raiz->palavra);
        Trie_printNiveis(raiz->dir);
        Trie_printNiveis(raiz->abaixo);

    }

}

// Imprime a árvore em ordem alfabética
void Trie_print(trieNode* raiz, char* prePalavra) {

    if (!Trie_isEmpty(raiz)) {

        // Esta variável é um acumulador para saber em qual posição resetar a string com as sílabas acumuladas.
        int pos = strlen(prePalavra);

        // Caso o conteúdo do nó seja uma palavra, ocorre a impressão
        if (raiz->fimPalavra == 1) {
            printf("%s", prePalavra);
            printf("%s\n", raiz->palavra);
        }

        // Concatena a sílaba atual com as sílabas acumuladas e depois percorre os filhos de baixo.
        strcat(prePalavra, raiz->palavra);
        Trie_print(raiz->abaixo, prePalavra);

        // Após imprimir todos os filhos abaixo de uma sílaba, pula para a sílaba / palavra à direita, zerando o acúmulo até a posição desejada.
        prePalavra[pos] = '\0';

        Trie_print(raiz->dir, prePalavra);

    }

}

int main() {

    trieNode* raiz = Trie_create();

    // Esta variavel vai ser usada como auxiliar para imprimir as palavras da árvore
    char prePalavra[20] = "\0";

    // As entradas do usuario serão armazenadas nesta string.
    char entrada[20] = "\0";

    int qtd;
    int op;

    while (op != 0) {

        printf("\nDigite a opcao desejada: \n\n");
        printf("1 - Inserir Palavras\n2 - Imprimir em ordem alfabetica\n");
        printf("3 - Imprimir todas as silabas armazenadas e seus niveis\n");
        printf("0 - Sair\n\n");
        scanf("%d", &op);
        fflush(stdin);

        switch (op) {

        case 0:
            break;

        case 1:
            printf("Digite a quantidade de palavras a serem inseridas: ");
            scanf("%d", &qtd);
            fflush(stdin);

            int i = 1;
            while (i <= qtd) {
                fgets(entrada, 20, stdin);
                entrada[strcspn(entrada, "\n")] = 0;
                raiz = Trie_insert(raiz, entrada);
                fflush(stdin);
                i++;
            }
            break;

        case 2:

            printf("\nORDEM ALFABETICA: \n\n");
            printf("------------\n");
            Trie_print(raiz, prePalavra);
            printf("------------\n");

            break;

        case 3:
            printf("\nSILABAS POR NIVEL: \n\n");
            Trie_printNiveis(raiz);
            break;

        default:
            printf("opcao invalida.");
            break;

        }
    }

}