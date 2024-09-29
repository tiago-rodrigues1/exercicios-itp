/* O maior entre 4 inteiros */

#include <stdio.h>

int main(void) {
    int a = 0, b = 0, c = 0, d = 0;

    scanf("%i %i %i %i", &a, &b, &c, &d);

    int maior = a;

    if (a > maior) {
        maior = a;
    }

    if (b > maior) {
        maior = b;
    }

    if (c > maior) {
        maior = c;
    }

    if (d > maior) {
        maior = d;
    }

    printf("Maior: %i\n", maior);
    
    return 0;
}