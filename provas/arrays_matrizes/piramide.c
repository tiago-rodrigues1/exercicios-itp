/* Pirâmide */

#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);

    int matriz[n][n];

    int contador = 0, index_inicial = 0, index_final = n;

    do {
        contador += 1;

        for(int i = index_inicial; i < index_final; i++) {
            for (int j = index_inicial; j < index_final; j++) {
                matriz[i][j] = contador;
            }
        }

        index_inicial += 1;
        index_final -= 1;
    }
    while (contador <= n - 2);
        

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }
    
    return 0;
}