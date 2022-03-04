#include "stdio.h"
#include "stdlib.h"

int verificaPrimo(int numero){
	
	if(numero < 2) return 0;
	
	for(int i = 2; i < numero; i++){
		if(numero % i == 0) return 0;
	}
	
	return 1;
	
}

int main(){
	
	int a, b;
	
	do{
		
		scanf("%d %d", &a, &b);
		if(a != 0 || b != 0){
			if(verificaPrimo(a) && verificaPrimo(b)){
				if(a == b+2 || b == a+2) printf("%d e %d sao gemeos\n", a, b);
				else printf("%d e %d nao sao gemeos\n",a ,b);
			}
			else printf("%d e %d nao sao gemeos\n",a ,b);
		}
		
	}while(a != 0 || b != 0);
	
}