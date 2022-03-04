#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void preencher_array_str(int qtd, int tam_palavra, char vetor[][tam_palavra]){

    for(int i = 0; i < qtd; i++){
        scanf("%s", vetor[i]);
    }

}

/*void imprimir_array_str(int qtd, int tam_palavra, char dicionario[][tam_palavra]){

    for(int i = 0; i < qtd; i++){
        printf("%s\n", dicionario[i]);
    }

}*/

int esta_no_grid(char *palavra, int n, int m, char grid[][m]){

    int tam_palavra = strlen(palavra);
    int similaridade = 0;
    int similaridade_inverso = 0;
	
    for(int i = 0; i < n; i++){
    
        for(int j = 0; j < m; j++){
				
		    // Encontrou uma letra igual à primeira letra da palavra.
            if(grid[i][j] == palavra[0]){

                // Percorre na horizontal (p/ frente e p/ trás)
                // # OBS: Desta vez cada laço abaixo percorre apenas o tamanho da palavra, evitando conflitos
                // # com o acumulador de similaridade e tomando cuidado para ficar dentro dos limites do GRID.
                for(int k = 0; k < tam_palavra; k++){
                    // Direção > 
                    if(j+k < m 
                    && grid[i][j+k] == palavra[k]){
                        similaridade++;
                    }
                    
                    // Direção <
                    if(j-k >= 0 
                    && grid[i][j-k] == palavra[k]){
                        similaridade_inverso++;
                    }

                    if(similaridade == tam_palavra 
                    || similaridade_inverso == tam_palavra) return 1;
                }

                // Reset no acumulador de similaridade a cada laço.
                similaridade = similaridade_inverso = 0;
                
                // Percorre na vertical (p/ baixo e p/ cima)
                for(int k = 0; k < tam_palavra; k++){
                    if(i+k < n 
                    && grid[i+k][j] == palavra[k]){
                        similaridade++;
                    }
                    
                    if(i-k >= 0 
                    && grid[i-k][j] == palavra[k]){
                        similaridade_inverso++;
                    }

                    if(similaridade == tam_palavra 
                    || similaridade_inverso == tam_palavra) return 1;
                }

                similaridade = similaridade_inverso = 0;
                
                // Percorre na diagonal principal (p/ frente e p/ trás)
                for(int k = 0; k < tam_palavra; k++){

                    if(i+k < n && j+k < m 
                    && grid[i+k][j+k] == palavra[k]){
                        similaridade++;
                    }
                    if(i-k >= 0 && j-k >= 0 
                    && grid[i-k][j-k] == palavra[k]){
                        similaridade_inverso++;
                    }

                    if(similaridade == tam_palavra 
                    || similaridade_inverso == tam_palavra) return 1;
                }

                similaridade = similaridade_inverso = 0;

                // Percorre na diagonal secundária (p/ trás e p/ frente)
                for(int k = 0; k < tam_palavra; k++){

                    if(i+k < n && j-k >= 0 
                    && grid[i+k][j-k] == palavra[k]){
                        similaridade++;
                    }
                    if(i-k >= 0 && j+k < m 
                    && grid[i-k][j+k] == palavra[k]){
                        similaridade_inverso++;
                    }

                    if(similaridade == tam_palavra 
                    || similaridade_inverso == tam_palavra) return 1;
                }

                similaridade = similaridade_inverso = 0;

            }

        }

    }

    return 0;

}

int main(){

    int tam_dic;
    int n, m;

    scanf("%d", &tam_dic);

    char dicionario[tam_dic][101];

    preencher_array_str(tam_dic, 101, dicionario);

    scanf("%d%d", &n, &m);

    // Para suportar o caractere '\0' ao final de cada palavra
	 n++;
    m++;

    char grid[n][m];

    preencher_array_str(n, m, grid);

    // printf("\nPalavras encontradas: \n");

    // int quant = 0;
    for(int i = 0; i < tam_dic; i++){

        if(esta_no_grid(dicionario[i], n, m, grid)){
            printf("%s\n", dicionario[i]);
            // quant++;
        }

    }

    // printf("Quantidade de palavras encontradas: %d\n", quant);

}