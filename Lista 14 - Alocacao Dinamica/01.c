#include<stdio.h>
#include<stdlib.h>

int euclides(int a, int b){
	
	// Se a == b, a é o MDC
	if(a == b) return a;
	
	// Senão, substituir o maior pela diferença dos dois e calcular novamente
	else if(a > b){
		a = a - b;
		return euclides(a, b);
	}
	else{
		b = b - a;
		return euclides(a, b);
	}

}

int main(){

    int* v1 = malloc(sizeof(int));
    int* v2 = malloc(sizeof(int));

    while(scanf("%d%d", v1, v2), *v1 != 1 || *v2 != 1){

        printf("%d\n", euclides(*v1, *v2));

    }

}