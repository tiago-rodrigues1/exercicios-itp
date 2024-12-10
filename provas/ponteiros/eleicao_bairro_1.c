#include <stdio.h>

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted) {
    int votos_chapa[10] = {0};

    for (int i = 0; i < n; i++) {
        int pos = votes[i] - 1;
        votos_chapa[pos] += 1;
    }

    int maior = 0;

    for (int i = 0; i < 10; i++) {
        if (votos_chapa[i] > maior) {
            maior = votos_chapa[i];
            *most_voted = i + 1;
        }
    }

    int menor_diferenca = maior - votos_chapa[0];
    *second_most_voted = 1;

    for (int i = 0; i < 10; i++) {
        if ((maior - votos_chapa[i]) < menor_diferenca && i != (*most_voted - 1)) {
            menor_diferenca = maior - votos_chapa[i];
            *second_most_voted = i + 1;
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    int votos[n];
    for (int i = 0; i <n; i++) {
        scanf("%d", &votos[i]);
    }

    int mais_votado, segundo_mais_votado;
    compute_votes(n, votos, &mais_votado, &segundo_mais_votado);

    printf("%d %d\n", mais_votado, segundo_mais_votado);
}