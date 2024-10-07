/* [ITP] Prova de 100 metros (Atletismo) */

#include <stdio.h>
#include <math.h>

int main(void) {
    float tempo_max;
    float tempo_corredor = 0;

    float quantidade_aptos = 0;
    int quantidade_series = 0;

    scanf("%f", &tempo_max);

    while (1) {
        scanf("%f", &tempo_corredor);

        if (tempo_corredor == -1) {
            break;
        }

        if (tempo_corredor <= tempo_max) {
            quantidade_aptos += 1;
        }
    }

    if (quantidade_aptos <=1) {
        quantidade_series = 0;
    } else {
        quantidade_series = ceil(quantidade_aptos / 8);
    }

    printf("%.0f %d\n", quantidade_aptos, quantidade_series);
    
    return 0;
}