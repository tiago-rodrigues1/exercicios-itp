/* Verifica Triângulo */

#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);

    if (a < b + c && b < a + c && c < a + b) {
        printf("possivel\n");
    } else {
        printf("impossivel\n");
    }
    
    return 0;
}