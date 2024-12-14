#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS 20

typedef struct {
    int codigo;
    char descricao[MAX_CHARS];
    float preco;
} Produto;

int read_line(char linha[30], int tam) {
    fgets(linha, tam, stdin);
    if (linha[0] == '\n') {
        return 0;
    }
    if (linha[strlen(linha)-1] == '\n')
        linha[strlen(linha)-1]='\0'; //remove o \n do final
    
    return 1;
}

void imprimeProdutos(Produto prod[], int qtdprod) {
    printf("========================================\n");
    printf("| Código | Descrição       | Preço     |\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < qtdprod; i++) {
        printf("| %6d ", prod[i].codigo);
        printf("| %15s ", prod[i].descricao);
        printf("| R$ %6.2f |\n", prod[i].preco);
    }
    printf("----------------------------------------\n");
}

int esta_no_vetor(Produto* produtos, int tam, int codigo) {
    for (int i = 0; i < tam; i++) {
        if (produtos[i].codigo == codigo) {
            return 1;
        }
    }

    return 0;
}

Produto* inserir(Produto* produtos, int* pos, Produto p) {
    produtos[*pos] = p;

    *pos += 1;
    produtos = realloc(produtos, sizeof(Produto) * (*pos + 1));

    return produtos;
}

int main(void) {
    Produto* produtos = malloc(sizeof(Produto));
    int contador = 0;
    char linha[30];

    while(read_line(linha, 30)) {
        char *str = NULL;
        Produto p;

        str = strtok(linha, ",");
        if (str != NULL) {
            char str_codigo[10];
            strcpy(str_codigo, str);
            p.codigo = atoi(str_codigo);
        }

        str = strtok(NULL, ",");
        if (str != NULL) {
            strcpy(p.descricao, str);
        }

        str = strtok(NULL, ",");
        if (str != NULL) {
            char str_preco[10];
            strcpy(str_preco, str);
            p.preco = atof(str_preco);
        }


        if (contador == 0 || !esta_no_vetor(produtos, contador, p.codigo)) {
            produtos = inserir(produtos, &contador, p);
        }
    }

    imprimeProdutos(produtos, contador);

}