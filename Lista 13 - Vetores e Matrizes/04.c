#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int eh_substring(char* substring, char* string){

    int tam = strlen(substring);
    int similaridade = 0;

    for(int i = 0; i < strlen(string); i++){
        if(string[i] == substring[similaridade]){
            similaridade++;
            if(similaridade == tam) return 1;
        }

        else similaridade = 0;
    }

    return 0;

}

int main(){

    char string[201], substring[201];

    while(scanf("%s", substring), strcmp(substring, "FIM") != 0){

        scanf("%s", string);
        if(eh_substring(substring, string)){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }

    } 

}