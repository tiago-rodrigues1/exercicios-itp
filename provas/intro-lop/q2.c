/* [ITP] Letra popular */

#include <stdio.h>

int main (void) {
    char letra;
    int quantidade;
    float indice;
    
    scanf("%c %i %f", &letra, &quantidade, &indice);
    
    float pop = indice * quantidade;
    
    printf("A popularidade de %c é %.1f", letra, pop);
    return 0;
}
