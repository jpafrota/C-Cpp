#include <stdio.h>

int main(void)
{
	int num;
	int *p1 = NULL;
	int **p2;
	
	scanf("%d", &num);
	p2 = &p1;
	
	// Modifique APENAS o lado direito da atribuição abaixo
	*p2 = &num;
	// Modifique APENAS o lado direito da atribuição acima
	
	printf("O numero digitado foi %d\n", **p2);
    
}