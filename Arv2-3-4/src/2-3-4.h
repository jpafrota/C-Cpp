typedef struct NoArv noArv234;
struct NoArv{
    
    int dados[2];
    int tamanho;
    noArv234 *pai;
    noArv234 *filhos[4];

};

noArv234 *criaVazia();
noArv234 *buscaArv();
