#include <stdio.h>
#include <stdlib.h>

void collatz(int n){

	if(n == 1){
		printf("%d", n);
	}
	else if(n % 2 == 0){
		printf("%d -> ", n);
		collatz(n/2);
	}
	else{
		printf("%d -> ", n);
		collatz(3*n + 1);
	}
	
}

int main(){
	
	int n;

	scanf("%d", &n);

	collatz(n);

}