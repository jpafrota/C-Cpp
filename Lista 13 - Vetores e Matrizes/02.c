#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void imprimir_grid(char grid[][15]){

    for(int i = 0; i < 15; i++){
        printf("%2d ", i);
        for(int j = 0; j < 15; j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("   ");
    for(int i = 0; i < 15; i++){
        printf("%d", i%10);
    }

}

void fazer_jogada(char grid[][15], char* palavra, int x, int y, int delta_x, int delta_y){

    int cont = 0;
    while(cont < strlen(palavra)){

        if(palavra[cont] != '.') grid[x+(cont*delta_x)][y+(cont*delta_y)] = palavra[cont];

        cont++;

    }

}

int main(){

    char grid[15][15];

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            grid[i][j] = '.';
        }
    }

    int x, y, delta_x, delta_y;

    while(scanf("%d%d", &x, &y), x != -1 && y != -1){

        scanf("%d", &delta_x);
        scanf("%d", &delta_y);

        char palavra[16];

        scanf("%s", palavra);

        fazer_jogada(grid, palavra, x, y, delta_x, delta_y);

    }

    imprimir_grid(grid);

}