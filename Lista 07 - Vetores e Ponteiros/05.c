#include<stdio.h>
#include<stdlib.h>

int main(){

    int n;
    int vetor[100];

    int soma = 0;
    double media;

    int higher_than_average = 0, less_then_average = 0;

    scanf("%d", &n);

	for(int i = 0; i < n; i++){

		scanf("%d", &vetor[i]);
		soma += vetor[i];

	}

	media = (double) soma / n;

	for(int i = 0; i < n; i++){

		if(vetor[i] > media) higher_than_average++;
		else if(vetor[i] < media) less_then_average++;

	}

	printf("%d %d", less_then_average, higher_than_average);

}