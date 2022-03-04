#include<stdio.h>
#include<stdlib.h>

double fatorial(int valor){

    if(valor <= 1) return 1;
    else return valor * fatorial(valor-1);

}

double potencia(double base, int expoente){

    double resultado = base;

    int i;
    for(i = 1; i < expoente; i++){

        resultado *= base;

    }

    return resultado;

}

double seno(double entrada, int n){
	
    if(n == 0) return 0;

    double resultado = entrada;
    int cont = 2;

    int i;
    for(i = 3; cont <= n; i += 2){

		 if(cont % 2 == 0) resultado -= (potencia(entrada, i) / fatorial(i));
		 else resultado += (potencia(entrada, i) / fatorial(i));

       cont++;
    }	

    return resultado;

}

int main(){
	
    
	double entrada;
   int n;
	
	do{
		
		scanf("%lf%d", &entrada, &n);
		if(entrada != 0 || n != 0){
			printf("%.10f\n", seno(entrada, n));
		}
		
	}while(entrada != 0 || n != 0);
	

}