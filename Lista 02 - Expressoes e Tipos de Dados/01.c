#include<stdio.h>

int main(){

	int l1, l2;
	int perimetro;
	int area;
	
	scanf("%d%d", &l1, &l2);
	
	perimetro = 2*l1 + 2*l2;
	area = l1*l2;
	
	printf("%d %d", perimetro, area);
	
	return 0;
}