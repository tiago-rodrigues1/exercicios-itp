/* Ordenação (bubble sort) */

#include <stdio.h>

void print_estado_array (int tam , int* arr) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void bubble_sort(int tam, int* arr) {
    print_estado_array(tam, arr);
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

        print_estado_array(tam, arr);

        if (trocou == 0) {
            break;
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubble_sort(n, arr);
}