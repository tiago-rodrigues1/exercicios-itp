#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS 100

char** get_participantes(int* quant_participantes) {
    char** participantes;
    int i = 0;

    char entrada[MAX_CHARS] = {0};

    while (strcmp(entrada, "acabou") != 0) {
        fgets(entrada, MAX_CHARS, stdin);
        entrada[strlen(entrada) - 1] = '\0';

        if (strcmp(entrada, "acabou") != 0) {
            if (i == 0) {
                participantes = malloc(sizeof(char*));
            } else {
                participantes = realloc(participantes, sizeof(char*) * (i + 1));
            }

            participantes[i] = malloc(strlen(entrada) * sizeof(char));
            strcpy(participantes[i], entrada);

            i += 1;
            *quant_participantes = i;
        }
    }

    return participantes;
}

int main(void) {
    int quant_participantes = 0, quant_sorteados = 0;
    char** participantes = get_participantes(&quant_participantes);
    
    int semente;
    scanf("%d", &semente);
    srand(semente);

    int sorteados[quant_participantes];
    memset(sorteados, 0, quant_participantes * sizeof(int)); // Inicializa sorteados com 0

    while (quant_sorteados < quant_participantes) {
        int sorteado = rand();
        int index = sorteado % quant_participantes;

        // sorteados[index] == 0 => participantes[index] não foi sorteado
        if (sorteados[index] == 0) {
            sorteados[index] = 1;
            
            printf("%s\n", participantes[index]);
            quant_sorteados += 1;
        }
    }
    
    free(participantes);
    return 0;
}