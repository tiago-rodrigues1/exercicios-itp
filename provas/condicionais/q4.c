/* [ITP] Bucho Burger */

#include <stdio.h>

int main(void) {
    int combo, dinheiro, troco, valor_combo;

    scanf("%i %i", &combo, &dinheiro);

    switch (combo) {
    case 1:
        valor_combo = 12;
        break;
    
    case 2:
        valor_combo = 23;
        break;

    case 3:
        valor_combo = 31;
        break;

    case 4:
        valor_combo = 28;
        break;

    case 5:
        valor_combo = 15;
        break;
    }

    troco = dinheiro - valor_combo;

    if (troco == 0) {
        printf("Deu certim!\n");
    } else if (troco > 0) {
        printf("Troco = %i reais\n", troco);
    } else {
        printf("Saldo insuficiente! Falta %i reais\n", (troco * -1));
    }
}