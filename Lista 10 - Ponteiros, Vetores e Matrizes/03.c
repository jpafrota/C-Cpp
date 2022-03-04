#include<stdio.h>
#include<stdlib.h>

void ler_vetor(int *vetor, int tam){

    for(int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }

}

void imprimir_vetor(int *vetor, int tam){

    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void mesclar_vetores(int *vetor, int *vetor1, int *vetor2, int n, int m){

    int cont1 = 0, cont2 = 0;

    // percorre o vetor alvo até o final, atribuindo os valores de acordo com as condições
    for(int cont3 = 0; cont3 < n+m; cont3++){
        
		// caso ambos os vetores 1 e 2 ainda possuam valores a serem comparados
        if(cont1 < n && cont2 < m){

            if(vetor1[cont1] <= vetor2[cont2]){
                vetor[cont3] = vetor1[cont1];
                cont1++;
            }
            else{
                vetor[cont3] = vetor2[cont2];
                cont2++;
            }
        }

		// caso chegue ao final do vetor 2
        else if(cont2 >= m){
            vetor[cont3] = vetor1[cont1];
            cont1++;
        }
		  
		// caso chegue ao final do vetor 1
        else {
            vetor[cont3] = vetor2[cont2];
            cont2++;
        }

    }

}

int main(){

    int n, m;
    int qtdCasos;

    scanf("%d", &qtdCasos);

    for(int i = 0; i < qtdCasos; i++){

        // lendo o primeiro vetor
        scanf("%d", &n);
        int vetor1[n];
        ler_vetor(vetor1, n);

        // lendo o segundo vetor    
        scanf("%d", &m);
        int vetor2[m];
        ler_vetor(vetor2, m);

        // mesclando os dois vetores em um terceiro
        int vetor3[n+m];
        mesclar_vetores(vetor3, vetor1, vetor2, n, m);
        imprimir_vetor(vetor3, n+m);

    }

}