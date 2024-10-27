/* Diferença simétrica */

#include <stdio.h>

// Como as entradas são arrays ordenados, podemos usar Busca Binária
int pertence_ao_array (int valor, int* vetor, int tamanho_vetor) {
    int min = 0, max = tamanho_vetor - 1;

    while (min <= max) {
        int palpite = (min + max) / 2;

        if (vetor[palpite] == valor) {
            return 1;
        } else if (vetor[palpite] < valor) {
            min = palpite + 1;
        } else {
            max = palpite - 1;
        }
    }

    return 0;
}

void ordena_vetor(int tam, int* vetor) {
    int aux[tam];
    int menor, maior, menor_pos, pos = 0, i, j;

    maior = vetor[0];
    menor_pos = 0;

    for (i = 0; i < tam; i++) {
        menor = maior;

        for (j = 0; j < tam; j++) {
            if (vetor[j] < menor) {
                menor = vetor[j];
                menor_pos = j;
            } else if (vetor[j] > maior) {
                maior = vetor[j];
            }
        }

        aux[pos] = menor;
        pos += 1;

        vetor[menor_pos] = maior + 1;
    }

    for (i = 0; i < tam; i++) {
        vetor[i] = aux[i];
    }
}

void uniao_simetrica(int* arr_a, int tam_a, int* arr_b, int tam_b) {
    int tam_resultado = tam_a + tam_b;
    int resultado[tam_resultado];
    int resultado_index = 0;

    for (int i = 0; i < tam_a; i++) {
        if (!pertence_ao_array(arr_a[i], arr_b, tam_b)) {
            resultado[resultado_index] = arr_a[i];
            resultado_index += 1;
        }
    }

    for (int j = 0; j < tam_b; j++) {
        if (!pertence_ao_array(arr_b[j], arr_a, tam_a)) {
            resultado[resultado_index] = arr_b[j];
            resultado_index += 1;
        }
    }

    ordena_vetor(resultado_index, resultado);

    for (int i = 0; i < resultado_index; i++) {
        printf("%d ", resultado[i]);
    }

    printf("\n");
}

int main(void) {
    int tamanho_a, tamanho_b;
    scanf("%d %d", &tamanho_a, &tamanho_b);

    int arr_a[tamanho_a], arr_b[tamanho_b];

    for (int i = 0; i < tamanho_a; i++) {
        scanf("%d", &arr_a[i]);
    }

    for (int i = 0; i < tamanho_b; i++) {
        scanf("%d", &arr_b[i]);
    }

    uniao_simetrica(arr_a, tamanho_a, arr_b, tamanho_b);

    return 0;
}