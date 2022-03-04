#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void ler_vetor(char sky[][MAX+1], int linhas){

    for(int i = 0; i < linhas; i++){
        scanf("%s", sky[i]);
    }

}

// verifica se uma determinada posiçao está dentro do range do céu.
int dentro_do_range(int i, int j, int linhas, int colunas){

    return ( (i > 0 && j > 0) && (i < linhas && j < colunas) );

}

// verifica se um elemento do céu é estrela
int eh_estrela(char sky[][MAX+1], int i, int j, int linhas, int colunas){

    // percorre todos os espaços adjacentes de um determinado elemento. (matriz 3x3)
    for(int a = i-1; a <= i+1; a++){
        for(int b = j-1; b <= j+1; b++){
            
            if(dentro_do_range(a,b,linhas,colunas)
					&& (a != i || b != j)
					&& sky[a][b] == '*'){
					 return 0;
            }

        }
    }

    return 1;

}

// retorna a quantidade de estrelas no céu
int conta_estrelas(char sky[][MAX+1], int linhas, int colunas){

    int qtdEstrelas = 0;

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){

            if(sky[i][j] == '*' && eh_estrela(sky, i, j, linhas, colunas)){
					qtdEstrelas++;
				}

		  }
    }

    return qtdEstrelas;

}

int main(){

    char sky[MAX][MAX+1];
    int linhas, colunas;
    int qtdEstrelas;

    while(scanf("%d%d", &linhas, &colunas), linhas != 0 && colunas != 0){

        ler_vetor(sky, linhas);
        qtdEstrelas = conta_estrelas(sky, linhas, colunas);
        printf("%d\n", qtdEstrelas);

    }

}