#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void imprimir_strings(int n, int m, char grid[][m], int x, int y){

    printf("(%d, %d)\n", x, y);
    x--;
    y--;
    m--;

    for(int cont = x; cont >= 0; cont--){
        printf("%c", grid[cont][y]);
    }
    printf("\n");

    for(int cont = 0; y+cont < m; cont++){
        printf("%c", grid[x][y+cont]);
    }
    printf("\n");

    for(int cont = 0; x+cont < n; cont++){
        printf("%c", grid[x+cont][y]);
    }
    printf("\n");

    for(int cont = y; cont >= 0; cont--){
        printf("%c", grid[x][cont]);
    }
    printf("\n");

}

int main(){

    int n, m;

    scanf("%d%d", &n, &m);

    // se der erro, aumentar o N
    m++;
    char grid[n][m];

    for(int i = 0; i < n; i++){
        scanf("%s", grid[i]);
    }

    int x, y;
    while(scanf("%d%d", &x, &y), x != 0 && y != 0){

        imprimir_strings(n, m, grid, x, y);

    }

}