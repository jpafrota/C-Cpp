#include <stdio.h>

int main(){
	
	int a, b;

	int area, perimetro;
	
	do {
		
		scanf("%d%d", &a, &b);
		if(a != 0 && b != 0){
			perimetro = 2*a + 2*b;
			area = (a * b);
			printf("%d %d\n", perimetro, area);
		} 
		
	}while (a != 0 || b != 0);
	
}