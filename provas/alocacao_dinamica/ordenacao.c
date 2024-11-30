#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* ordena(int* numeros, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int trocou = 0;

        for (int j = 0; j < tam - i - 1; j++) {
            if (numeros[j + 1] < numeros[j]) {
                int tmp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = tmp;

                trocou = 1;
            }
        }

        if (trocou == 0) {
            break;
        }
    }

    return numeros;
}

int* get_numeros(int* quantidade, char entrada[]) {
    int* vetor_numeros, i = 0;
    char *str_numero = strtok(entrada, " ");

    while(str_numero != NULL) {
        if (i == 0) {
            vetor_numeros = malloc(sizeof(int));
        } else {
            vetor_numeros = realloc(vetor_numeros, sizeof(int) * (i + 1));
        }

        int numero;
        sscanf(str_numero, "%d", &numero);

        vetor_numeros[i] = numero;
        str_numero = strtok(NULL, " ");

        i += 1;
    }

    *quantidade = i;
    return vetor_numeros;
}

int main(void) {
    int quantidade = 0;
    int* numeros = malloc(sizeof(int));
    char entrada[100];

    fgets(entrada, 100, stdin);

    entrada[strlen(entrada) - 1] = '\0';

    numeros = get_numeros(&quantidade, entrada);
    numeros = ordena(numeros, quantidade);

    for (int i = 0; i < quantidade; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}