/* Número perfeito (função) */

#include <stdio.h>
#include <stdbool.h>

bool ehPerfeito(int numero) {
    int soma = 0;

    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) {
            soma += i;
        }
    }

    return numero == soma;
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        printf("%d %s\n", x, ehPerfeito(x) ? "eh perfeito" : "nao eh perfeito");
    }
    
    return 0;
}