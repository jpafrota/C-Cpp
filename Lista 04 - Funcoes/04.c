#include<stdio.h>
#include<stdlib.h>

void imprimir(int valor){
	
	int Vg, Vs, Vn;
	
	Vg = valor / 493;
	valor = valor % 493;
	Vs = valor / 29;
	valor = valor % 29;
	Vn = valor;
	
	printf("Seu troco eh %d galeoes, %d sicles e %d nuques, Harry!", Vg, Vs, Vn);
	
}

int leitura_valor(){
	
	int Vg, Vs, Vn;
	
	scanf("%d%d%d", &Vg, &Vs, &Vn);
	
	return Vg*493 + Vs*29 + Vn;
	
}

int main(){
	
	int valorCompra, pagamento;
	
	valorCompra = leitura_valor();
	pagamento = leitura_valor();
	
	imprimir(pagamento - valorCompra);
	
}