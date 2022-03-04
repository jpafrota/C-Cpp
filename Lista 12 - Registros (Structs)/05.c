#include<stdio.h>
#include<stdlib.h>

typedef struct tipo_fracao {

    int numerador;
    int denominador;

}tipo_fracao;

void ler_fracao(tipo_fracao* fracao) {

    scanf("%d", &fracao->numerador);
    scanf("%d", &fracao->denominador);

    if (fracao->denominador < 0) {
        fracao->denominador *= -1;
        fracao->numerador *= -1;
    }

}

tipo_fracao* somar_fracoes(tipo_fracao f1, tipo_fracao f2) {

    tipo_fracao* result = malloc(sizeof(tipo_fracao));

    result->denominador = f1.denominador * f2.denominador;
    result->numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;

    return result;

}

tipo_fracao* subtrair_fracoes(tipo_fracao f1, tipo_fracao f2) {

    tipo_fracao* result = malloc(sizeof(tipo_fracao));

    result->denominador = f1.denominador * f2.denominador;
    result->numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;

    return result;

}

tipo_fracao* multiplicar_fracoes(tipo_fracao f1, tipo_fracao f2) {

    tipo_fracao* result = malloc(sizeof(result));

    result->numerador = f1.numerador * f2.numerador;
    result->denominador = f1.denominador * f2.denominador;

    return result;

}

tipo_fracao* dividir_fracoes(tipo_fracao f1, tipo_fracao f2) {

    tipo_fracao* result = malloc(sizeof(result));

    result->numerador = f1.numerador * f2.denominador;
    result->denominador = f1.denominador * f2.numerador;

    return result;

}

int euclides(int a, int b) {

    // Se a == b, a é o MDC
    if (a == b) return a;

    // Senão, substituir o maior pela diferença dos dois e calcular novamente
    else if (a > b) {
        a = a - b;
        return euclides(a, b);
    }
    else {
        b = b - a;
        return euclides(a, b);
    }

}

void simplificar_fracao(tipo_fracao* fracao) {

    if (fracao->numerador == 0 || fracao->numerador == 1) return;

    int mdc = euclides(abs(fracao->numerador), abs(fracao->denominador));

    fracao->numerador /= mdc;
    fracao->denominador /= mdc;

}

void imprimir_fracao(tipo_fracao fracao) {

    printf("%d ", fracao.numerador);

    if (fracao.numerador != 0 && fracao.denominador != 1) {
        printf("%d", fracao.denominador);
    }

    printf("\n");

}

int main() {

    int operacao;

    while (scanf("%d", &operacao), operacao != 0) {

        tipo_fracao fracao1;
        tipo_fracao fracao2;
        tipo_fracao* resultante = NULL;

        ler_fracao(&fracao1);
        ler_fracao(&fracao2);

        switch (operacao) {
        case 1:
            resultante = somar_fracoes(fracao1, fracao2);
            break;

        case 2:
            resultante = subtrair_fracoes(fracao1, fracao2);
            break;

        case 3:
            resultante = multiplicar_fracoes(fracao1, fracao2);
            break;

        case 4:
            resultante = dividir_fracoes(fracao1, fracao2);
            break;

        default:
            break;
        }

        simplificar_fracao(resultante);
        imprimir_fracao(*resultante);

    }

}