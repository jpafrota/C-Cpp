#include<stdio.h>
#include<stdlib.h>

int main(){

    int n, m;
    int qtd;

    scanf("%d%d", &n, &m);
    
    qtd = n;

    int *vetor = malloc(sizeof(int) * (n+1));

    for(int i = 0; i < n+1; i++){
        vetor[i] = i;
    }

    for(int k = 0; k < m; k++){
        
        int valor;
        scanf("%d", &valor);

        for(int i = 0; i < n+1; i++){
            if(vetor[i] != 0 && vetor[i] % valor == 0){
                vetor[i] = 0;
                qtd--;
            } 
        }

    }    

    printf("%d", qtd);

}