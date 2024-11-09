#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct time {
    char nome[50];
    int gols_marcados;
    int gols_sofridos;

} Time;


void ordenar_times(Time* arr, int tam) {
    Time aux;
    for (int i = 0; i < tam - 1; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (arr[i].gols_marcados < arr[j].gols_marcados) {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }   
}

int main(void) {
    int quant_times;
    scanf("%d", &quant_times);
    getchar();

    Time times[quant_times];

    for (int i = 0; i < quant_times; i++) {
        scanf(" %[^\n]", times[i].nome);
        scanf("%d", &times[i].gols_marcados);
        scanf("%d", &times[i].gols_sofridos);

        getchar();
    }

    ordenar_times(times, quant_times);

    for (int i = 0; i < quant_times; i++) {
        int rank = i + 1;

        printf("%d - %s\n", rank, times[i].nome);
        printf("Gols marcados: %d\n", times[i].gols_marcados);
        printf("Gols sofridos: %d\n", times[i].gols_sofridos);
    }

    return 0;
}