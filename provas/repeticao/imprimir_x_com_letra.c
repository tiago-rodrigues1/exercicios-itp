/* ITP Imprimir X com uma letra */

#include <stdio.h>

int main(void) {
    int tamanho;
    char letra;

    scanf("%d %c", &tamanho, &letra);

    int linhas = tamanho - 1;
    int colunas = tamanho - 1;
    int meio = linhas / 2;

    int direita = 0, esquerda = colunas - 1;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            if (j == direita || j == esquerda) {
                printf("%c", letra);
            }
            else {
                printf(" ");
            }
        }

        if ((linhas % 2 == 0 && i != meio - 1) || (linhas % 2 == 1)) {
            if (i >= meio) {
                direita -= 1;
                esquerda += 1;
            } else {
                direita += 1;
                esquerda -= 1;
            }
        }

        printf("\n");
    }

    return 0;
}