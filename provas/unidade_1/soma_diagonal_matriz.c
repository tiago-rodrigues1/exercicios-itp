#include <stdio.h>

int main() {
    int tamanho;
    scanf("%d", &tamanho);

    int matriz[tamanho][tamanho];
    int soma_diagonal_principal = 0;
    int soma_diagonal_secundaria = 0;

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < tamanho; i++) {
        soma_diagonal_principal += matriz[i][i];
        soma_diagonal_secundaria += matriz[i][tamanho - 1 - i];
    }

    int total = soma_diagonal_principal + soma_diagonal_secundaria;
    printf("%d\n", total);

    return 0;
}