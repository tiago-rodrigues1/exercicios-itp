#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50

typedef struct {
    char nome[TAM_NOME];
    int idade;
    char sexo;
} Pessoa;

Pessoa criar_pessoa() {
    Pessoa p;

    fflush(stdin);
    fgets(p.nome, TAM_NOME, stdin);

    if (p.nome[strlen(p.nome) - 1] == '\n') {
        p.nome[strlen(p.nome) - 1] = '\0';
    }

    scanf("%d", &p.idade);
    scanf(" %c", &p.sexo);

    return p;
}

int compara_pessoas(Pessoa p1, Pessoa p2) {
    return strcmp(p1.nome, p2.nome) == 0 && p1.idade == p2.idade && p1.sexo == p2.sexo;
}

Pessoa* inserir(Pessoa p, Pessoa* vetor_pessoas, int* ultimo_add) {
    vetor_pessoas[*ultimo_add] = p;

    *ultimo_add += 1;
    vetor_pessoas = realloc(vetor_pessoas, sizeof(Pessoa) * (*ultimo_add + 1));

    return vetor_pessoas;
}

Pessoa* deletar(Pessoa p, Pessoa* vetor_pessoas, int* ultimo_add) {
    int index_del;

    for (index_del = 0; index_del < *ultimo_add; index_del++) {
        if (compara_pessoas(p, vetor_pessoas[index_del])) {
            break;
        }
    }

    if (index_del < (*ultimo_add - 1) && *ultimo_add > 0) {
        for (int j = index_del; j < *ultimo_add; j++) {
            vetor_pessoas[j] = vetor_pessoas[j + 1];
        }

        *ultimo_add -= 1;
    }

    if (*ultimo_add == 1 && index_del == 0) {
        *ultimo_add -= 1;
    }

    vetor_pessoas = realloc(vetor_pessoas, sizeof(Pessoa) * (*ultimo_add + 1));

    return vetor_pessoas;
}

void imprimir(Pessoa* vetor_pessoas, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("%s,", vetor_pessoas[i].nome);
        printf("%d,", vetor_pessoas[i].idade);
        printf("%c\n", vetor_pessoas[i].sexo);
    }
}

int main(void) {
    int ultimo_add = 0;
    Pessoa* lista_pessoas = malloc(sizeof(Pessoa) * (ultimo_add + 1));
    char cmd = ' ';

    while (cmd != 'p') {
        fflush(stdin);
        scanf(" %c", &cmd);
        getchar();

        if (cmd == 'i') {
            Pessoa pessoa = criar_pessoa();
            lista_pessoas = inserir(pessoa, lista_pessoas, &ultimo_add);
        } else if (cmd == 'd') {
            Pessoa pessoa = criar_pessoa();
            lista_pessoas = deletar(pessoa, lista_pessoas, &ultimo_add);
        }
    }

    imprimir(lista_pessoas, ultimo_add);
    
    return 0;
}