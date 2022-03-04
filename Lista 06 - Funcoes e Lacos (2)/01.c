#include <stdio.h>
#include <stdlib.h>

int parar(int a, int b, int criterio){

	switch(criterio){
		case 1:
			if(a < 0 || b < 0) return 1;
		break;
		
		case 2:
			if(a < 0 && b < 0) return 1;
		break;

		case 3:
			if(a > b) return 1;
		break;
		
	}

	return 0;

}

int main(){

	int a, b, n;

	scanf("%d", &n);
	while(scanf("%d%d", &a, &b), 
			!parar(a, b, n) ){

		printf("%d + %d = %d\n", a, b, a + b);

	}

}