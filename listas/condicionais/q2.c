/* Divida a por b se for divisível */

#include <stdio.h>

int main(void) {
    int a, b;

    scanf("%i %i", &a, &b);

    if (a % b == 0) {
        printf("Resultado: %i", (a / b));
    }
    
    return 0;
}