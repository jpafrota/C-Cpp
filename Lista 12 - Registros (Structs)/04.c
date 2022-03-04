#include <stdio.h>
#include <stdlib.h>
#define STR_MAX 80

struct aluno {
    char nome[STR_MAX + 1];
    char sobrenome[STR_MAX + 1];
    int matricula;
};

// Prototipo para a funcao que le os dados de um aluno
// e retorna um ponteiro para uma struct alocada dinamicamente
struct aluno* ler_aluno(void) {

    struct aluno* aluno = (struct aluno*)malloc(sizeof(struct aluno));

    scanf("%s", aluno->nome);
    scanf("%s", aluno->sobrenome);
    scanf("%d", &(aluno->matricula));

    return aluno;

}

// Prototipo para a funcao que recebe um ponteiro para uma
// struct de um aluno e imprime seus dados
void imprimir_aluno(struct aluno* aluno) {

    printf("%s %s %d\n", aluno->nome, aluno->sobrenome, aluno->matricula);

}

// Sugestao: faca essa funcao auxiliar que pesquisa um aluno
// por um dado numero de matricula. A funcao retorna um ponteiro
// para o registro desse aluno se ele for encontrado e NULL
// caso contrario
struct aluno* buscar_matricula(struct aluno** turma, int n, int matricula) {

    for (int i = 0; i < n; i++) {
        
        if (turma[i]->matricula == matricula) {
            return turma[i];
        }

    }

    return NULL;

}

int main(void) {
	
    struct aluno** turma;
    // complete o programa

    int n;
    scanf("%d", &n);

    turma = malloc(sizeof(struct aluno*) * n);

    for (int i = 0; i < n; i++) {

        turma[i] = ler_aluno();

    }

    int chave;
    while(scanf("%d", &chave), chave != 0){

        struct aluno *aluno = buscar_matricula(turma, n, chave);
        if (aluno != NULL) {
            imprimir_aluno(aluno);
        }
        else {
            printf("Matricula %d nao encontrada\n", chave);
        }

    }

}