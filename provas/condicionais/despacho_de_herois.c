/* [ITP] Sistema de despacho de heróis */

#include <stdio.h>
#include <string.h>

int main(void) {
    int quantidade_herois, classe_herois, nivel_ameaca;

    scanf("%i %i %i", &quantidade_herois, &classe_herois, &nivel_ameaca);

    if (quantidade_herois > 0) {
        if (classe_herois > nivel_ameaca || (quantidade_herois >= 3 && classe_herois >= nivel_ameaca) || classe_herois == 5) {
            printf("Heróis vencerão!\n");
            return 0;
        }
    }

    printf("Melhor chamar Saitama!\n");

    return 0;
}