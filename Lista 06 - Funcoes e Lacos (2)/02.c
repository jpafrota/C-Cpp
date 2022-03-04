#include <stdio.h>
#include <stdlib.h>

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
	
	int a, b;
	while(scanf("%d%d", &a, &b), 
			a != 0 && b != 0){
		
		printf("%d\n", euclides(a, b));
	}
	
}