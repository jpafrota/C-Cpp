#include <stdio.h>
#include <stdlib.h>

int lerSequencia(){

    int atual;
    int anterior = 0;

    int contador = 0;
    int flag = 1;

    do{

        scanf("%d", &atual);

        if(atual >= 0){

            if(atual <= anterior) flag = 0;

            contador++;

            anterior = atual;

        }

    } while (atual >= 0);

    return flag;

}

int main(){

	if(lerSequencia()){
		printf("SIM");
	}
	else{
		printf("NAO");
	}

}