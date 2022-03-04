#include<stdio.h>
#include<stdlib.h>


typedef struct RGB {

    int R;
    int G;
    int B;

}RGB;

double remover_saturacao(RGB cor){

    return (0.3 * cor.R + 0.59 * cor.G + 0.11 * cor.B)/255;

}

int main(){

    RGB cor;

    while(scanf("%d", &cor.R), cor.R != -1){

        scanf("%d", &cor.G);
        scanf("%d", &cor.B);

        printf("%.3f\n", remover_saturacao(cor));

    }

}