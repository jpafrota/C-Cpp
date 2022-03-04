#include<stdio.h>
#include<stdlib.h>

int primo(int entrada){
	
	for(int i = entrada-1; i >= 2; i--){
		
		if(entrada % i == 0) return 0;
		
	}
	
	return 1;
	
}

int main(){
	
	int entrada;
	
	do{
		
		scanf("%d", &entrada);
		if(entrada != 0 && entrada != 1){
			if(primo(entrada)){
				printf("%d\n", entrada);
			}
		}
		
	}while(entrada != 0);
	
}