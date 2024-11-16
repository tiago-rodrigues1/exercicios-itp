#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_NOME 200

typedef struct time {
    char nome[TAM_NOME];
    int vitorias;
    int derrotas;
    int empates;
    int gols_marcados;
    int gols_sofridos;
    int pontos;
    int saldo;
} Time;

Time cria_time(char time_str[100]) {
    Time t = {0};
    char *str = NULL;

    str = strtok(time_str, ";");
    if (str != NULL) {
        strcpy(t.nome, str);
    }

    str = strtok(NULL, ";");
    if (str != NULL) {
        sscanf(str, "%d %d %d %d %d",&t.vitorias, &t.empates, &t.derrotas, &t.gols_marcados, &t.gols_sofridos);
    }

    t.pontos = (t.vitorias * 3) + t.empates;
    t.saldo = t.gols_marcados - t.gols_sofridos;

    return t;
}

void ordena_times(Time times[], int quant_times) {
    int troca = 1;

    while (troca) {
        troca = 0;

        for (int i = 0; i < quant_times - 1; i++) {
            int criterio_pontos = times[i].pontos < times[i + 1].pontos;

            int criterio_vitorias = (times[i].pontos == times[i + 1].pontos) && 
                (times[i].vitorias < times[i + 1].vitorias);

            int criterio_saldo = (times[i].pontos == times[i + 1].pontos) && 
                (times[i].vitorias == times[i + 1].vitorias) &&
                (times[i].saldo < times[i + 1].saldo);

            int pode_trocar = criterio_pontos || criterio_vitorias || criterio_saldo;

            if (pode_trocar) {
                Time tmp = times[i];
                times[i] = times[i + 1];
                times[i + 1] = tmp;

                troca = 1;
            }
        }
    }
}

void imprime_tabela(Time times[], int quant_times) {
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");

    for (int i = 0; i < quant_times; i++) {
        printf("%s| ", times[i].nome);
        printf("%d| ", times[i].pontos);
        printf("%d| ", times[i].vitorias+times[i].empates+times[i].derrotas);
        printf("%d| ", times[i].vitorias);
        printf("%d| ", times[i].empates);
        printf("%d| ", times[i].derrotas);
        printf("%d| ", times[i].gols_marcados);
        printf("%d| ", times[i].gols_sofridos);
        printf("%d\n", times[i].saldo);
    }

    printf("\nTimes na zona da libertadores:\n");
    for (int i = 0; i < 6; i++) {
        printf("%s\n", times[i].nome);
    }

    printf("\nTimes rebaixados:\n");
    for (int i = quant_times - 1; i > quant_times - 5; i--) {
        printf("%s\n", times[i].nome);
    }
}

int main (void) {
    int n;

    scanf("%d", &n);
    getchar();

    Time times[n];
    char linha[100];

    for (int i = 0; i < n; i++) {
        fgets(linha, 100, stdin);
        times[i] = cria_time(linha);
    }

    ordena_times(times, n);

    imprime_tabela(times, n);
    
    return 0;
}