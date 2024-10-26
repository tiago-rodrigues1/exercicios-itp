/* [ITP] Triângulo de Floyd */

#include <stdio.h>

int main(void) {
    int numero, contador = 1;

    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Você entrou com %d, tente de novo na próxima\n", numero);
    } else {
        for (int i = 0; i < numero; i++) {
            for (int j = 0; j < numero; j++) {
                if (j <= i) {
                    printf("%*d ", 2, contador);
                    contador += 1;
                } else {
                    printf(" ");
                }
            }

            printf("\n");
        }
    }
    
    return 0;
}