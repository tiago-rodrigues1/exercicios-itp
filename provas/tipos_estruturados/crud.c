#include <stdio.h>
#include <string.h>

#define TAM_NOME 50

typedef struct pessoa {
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

int compara_pessoas (Pessoa p1, Pessoa p2) {
    return strcmp(p1.nome, p2.nome) == 0 && p1.idade == p2.idade && p1.sexo == p2.sexo;
}

int inserir(Pessoa p, Pessoa pessoas[], int quant_pessoas) {
    pessoas[quant_pessoas] = p;

    return ++quant_pessoas;
}

int deletar(Pessoa p, Pessoa pessoas[], int quant_pessoas) {
    int i;

    for (i = 0; i < quant_pessoas; i++) {
        if (compara_pessoas(p, pessoas[i])) {
            break;
        }
    }

    if (i < (quant_pessoas - 1) && quant_pessoas > 0) {
        for (int j = i; j < quant_pessoas; j++) {
            pessoas[j] = pessoas[j + 1];
        }

        quant_pessoas -= 1;
    }

    if (quant_pessoas == 1 && i == 0) {
        quant_pessoas -= 1;
    }

    return quant_pessoas;
}

void imprimir_pessoa(Pessoa p) {
    printf("%s,%d,%c\n", p.nome, p.idade, p.sexo);
}

int main(void) {
    char cmd = ' ';
    int quant_pessoas = 0;
    Pessoa pessoas[20];

    while (cmd != 'p') {
        fflush(stdin);
        scanf(" %c", &cmd);
        getchar();

        if (cmd == 'p') {
            break;
        }

        Pessoa pessoa = criar_pessoa();

        if (cmd == 'i') {
            quant_pessoas = inserir(pessoa, pessoas, quant_pessoas);
        } else if (cmd == 'd') {
            quant_pessoas = deletar(pessoa, pessoas, quant_pessoas);
        }  
    }

    for (int i = 0; i < quant_pessoas; i++) {
        imprimir_pessoa(pessoas[i]);
    }
    
    return 0;
}