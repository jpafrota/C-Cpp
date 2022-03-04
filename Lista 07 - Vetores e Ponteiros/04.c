#include<stdio.h>
#include<stdlib.h>

int juntar_moedas(int g, int s, int n){

    return g*493 + s*29 + n;

}

int separar_moedas(int total, int *g, int *s, int *n){

   *g = total / 493;
	total = total % 493;
	*s = total / 29;
	total = total % 29;
	*n = total;

}

int main(){

    int qtdProdutos;
    int Vg, Vs, Vn;
    int valorCompra = 0, pagamento;
    int troco;
    int qtdProdutoAtual;

    while(scanf("%d", &qtdProdutos), qtdProdutos != 0){

        for(int i = 0; i < qtdProdutos; i++){
            scanf("%d", &qtdProdutoAtual);
            scanf("%d%d%d", &Vg, &Vs, &Vn);
            valorCompra += juntar_moedas(Vg, Vs, Vn) * qtdProdutoAtual;
        }

        scanf("%d%d%d", &Vg, &Vs, &Vn);
        pagamento = juntar_moedas(Vg, Vs, Vn);

        troco = pagamento - valorCompra;

        separar_moedas(valorCompra, &Vg, &Vs, &Vn);
        printf("Valor da compra: %d galeoes, %d sicles, %d nuques\n", Vg, Vs, Vn);

        separar_moedas(pagamento, &Vg, &Vs, &Vn);
        printf("Pagamento: %d galeoes, %d sicles, %d nuques\n", Vg, Vs, Vn);

        separar_moedas(troco, &Vg, &Vs, &Vn);
        printf("Troco: %d galeoes, %d sicles, %d nuques\n", Vg, Vs, Vn);

        printf("\n");
   valorCompra = 0;
     

    }

}