/* Separação numérica */

#include <stdio.h>

int main(void) {
    int num;
    scanf("%i", &num);

    int unidades, dezenas, centenas, milhares, dezenas_de_milhares, centenas_de_milhares;

    centenas_de_milhares = num / 100000;
    num -= centenas_de_milhares * 100000;

    dezenas_de_milhares = num / 10000;
    num -= dezenas_de_milhares * 10000;

    milhares = num / 1000;
    num -= milhares * 1000;

    centenas = num / 100;
    num -= centenas * 100;

    dezenas = num / 10;
    num -= dezenas * 10;

    unidades = num;

    if (centenas_de_milhares) {
        printf("%i\n", centenas_de_milhares);
    }

    if (dezenas_de_milhares) {
        printf("%i\n", dezenas_de_milhares);
    }
    
    if (milhares) {
        printf("%i\n", milhares);
    }

    if (centenas) {
        printf("%i\n", centenas);
    }

    if (dezenas) {
        printf("%i\n", dezenas);
    }

    printf("%i\n", unidades);
    
    return 0;
}