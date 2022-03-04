#include<stdio.h>

int main(){
	
	int n;
	double soma = 0, media, entrada;
	
	int i = 0;
	
	do{
		
		scanf("%d", &n);
		if(n != 0){
			for(i = 0; i < n; i++){
				scanf("%lf", &entrada);
				soma += entrada;
			}

			media = soma / n;

			printf("%.2lf\n", media);

			soma = 0;
		}
		
	}while(n != 0);
	
}