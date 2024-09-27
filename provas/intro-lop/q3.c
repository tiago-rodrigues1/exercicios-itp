/* [ITP] Tá na validade. */

#include <stdio.h>

int main (void) {
    int dias;
    scanf("%i", &dias);

    int anos = dias / 365;
    dias -= anos * 365;

    int meses = dias / 30;
    dias -= meses * 30;

    printf("%i ano(s)\n", anos);
    printf("%i mes(es)\n", meses);
    printf("%i dia(s)\n", dias);
    
    return 0;
}