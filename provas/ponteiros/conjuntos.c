#include <stdio.h>
#include <stdlib.h>

typedef struct conjunto {
    int* vetor;
    int tamanho;
} Conjunto;

void instaciar_vetor(Conjunto *c) {
    for (int i = 0; i < c->tamanho; i++) {
        if (i == 0) {
            c->vetor = malloc(sizeof(int));
        } else {
            c->vetor = realloc(c->vetor, sizeof(int) * (i + 1));
        }

        scanf("%d", &c->vetor[i]);
    }
}

int esta_no_conjunto(int chave, Conjunto c) {
    for (int i = 0; i < c.tamanho; i++) {
        if (c.vetor[i] == chave) {
            return 1;
        }
    }

    return 0;
}

Conjunto uniao(Conjunto *A, Conjunto *B) {
    Conjunto U;

    U.vetor = malloc(sizeof(int) * A->tamanho);
    int c = 0;

    for (int i = 0; i < A->tamanho; i++) {
        U.vetor[c++] = A->vetor[i];
    }

    for (int i = 0; i < B->tamanho; i++) {
        if (!esta_no_conjunto(B->vetor[i], *A)) {
            U.vetor = realloc(U.vetor, sizeof(int) * (c + 1));
            U.vetor[c++] = B->vetor[i];
        }
    }

    U.tamanho = c;

    return U;
}

Conjunto intersecao(Conjunto *A, Conjunto *B) {
    Conjunto I;
    I.vetor = malloc(sizeof(int));

    int c = 0;

    for (int i = 0; i < B->tamanho; i++) {
        if (esta_no_conjunto(B->vetor[i], *A)) {
            I.vetor = realloc(I.vetor, sizeof(int) * (c + 1));
            I.vetor[c++] = B->vetor[i];
        }
    }

    I.tamanho = c;

    return I;
}

void imprime_resultado(char op, Conjunto *r) {
    printf("A %s B == {", (op == 'u' ? "união" : "interseção"));

    if (r->tamanho == 0) {
        printf("vazio}\n");
        return;
    }

    for (int i = 0; i < r->tamanho; i++) {
        printf("%d", r->vetor[i]);

        if (i == r->tamanho - 1) {
            printf("}\n");
        } else {
            printf(" ");
        }
    }
}

int main(void) {
    Conjunto A, B;

    scanf ("%d", &A.tamanho);
    instaciar_vetor(&A);

    scanf("%d", &B.tamanho);
    instaciar_vetor(&B);

    Conjunto U = uniao(&A, &B);
    imprime_resultado('u', &U);

    Conjunto I = intersecao(&A, &B);
    imprime_resultado('i', &I);

    return 0;
}