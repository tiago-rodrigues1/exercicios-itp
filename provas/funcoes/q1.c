/* Declarando Funções */

#include <stdio.h>

int ehPar (int numero) {
    return numero % 2 == 0;
}

int main(void) {
    int numero;

    scanf("%d", &numero);
    printf("%s\n", ehPar(numero) ? "true" : "false");

    return 0;
}