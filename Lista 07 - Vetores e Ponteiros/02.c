#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void palindromo(char *string){

	 int i;
	 int n = strlen(string);
    for(i = 0; i < n/2; i++){

        if(string[i] != string[n-i-1]){
            printf("%s: normal\n", string);
            return;  
        }
        
    }

    printf("%s: palindromo\n", string);

}

int main(){

    int n;
	 int i;
    char string[41];
    
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        
        scanf("%40s", string);
        palindromo(string);

    }

}