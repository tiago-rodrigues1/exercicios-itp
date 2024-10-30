#include <stdio.h>

int is_repetido(int* vetor, int tam, int alvo) {
    int repetidos[tam];
    int ocorrencias = 0;

    for (int i = 0; i < tam; i++) {
        if (alvo == vetor[i]) {
            ocorrencias += 1;
        }
    }

    return ocorrencias > 1;
}

void ordena(int tam, int* arr) {
    for (int i = 0; i < tam - 1; i++) {
        int trocou = 0;

        for (int j = 0; j < tam - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;

                trocou = 1;
            }
        }

        if (trocou == 0) {
            break;
        }
    }
}

int main(void) {
    int tam, contador = 0;
    scanf("%d", &tam);

    int arr[tam];
    int repetidos[tam];

    for (int i = 0; i < tam; i++) {
        int x;
        scanf("%d", &x);

        arr[i] = x;

        if (is_repetido(arr, tam, x)) {
            repetidos[contador] = x;

            contador += 1;
        }
    }

    ordena(contador, repetidos);

    for (int i = 0; i < contador; i++) {
        printf("%d ", repetidos[i]);
    }

    printf("\n");
    
    return 0;
}