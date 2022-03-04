#include<stdio.h>
#include<stdlib.h>
#define STR_MAX 80

struct aluno {
	char nome[STR_MAX + 1];
	char sobrenome[STR_MAX + 1];
	int matricula;
};

struct aluno *ler_aluno(void){

    struct aluno *aluno = (struct aluno*) malloc(sizeof(struct aluno));

    scanf("%s", aluno->nome);
    scanf("%s", aluno->sobrenome);
    scanf("%d", &(aluno->matricula));

    return aluno;

}

void imprimir_aluno(struct aluno *aluno){

    printf("%s %s %d\n", aluno->nome, aluno->sobrenome, aluno->matricula);

}

int main(){

    struct aluno *aluno;
    struct aluno *maior, *menor;

    aluno = ler_aluno();
    maior = aluno;
    menor = aluno;

    while(aluno->matricula != 0){

        aluno = ler_aluno();
        if(aluno->matricula != 0){
            if(aluno->matricula > maior->matricula){
                maior = aluno;
            }
            else if(aluno->matricula < menor->matricula){
                menor = aluno;
            }
        }

    }

    imprimir_aluno(menor);
    imprimir_aluno(maior);

}