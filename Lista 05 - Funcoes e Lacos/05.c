#include <stdio.h>
#include <stdlib.h>

int main(){
	
	double depositoInicial;
	double juros = 0.012;
	int mesesAplic;
	
	scanf("%lf%d", &depositoInicial, &mesesAplic);
	
	double valorFinal = depositoInicial;
	
	int i;
	for(i = 1; i <= mesesAplic; i++){
		
		valorFinal += valorFinal*juros;
		printf("%.2f\n", valorFinal);
		
	}
	
}