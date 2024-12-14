#include <stdio.h>

void pintar(
    char cor_inicial,
    char cor,
    int pos_linha,
    int pos_coluna,
    int linhas,
    int colunas,
    char canvas[linhas][colunas]
) {
    if (canvas[pos_linha][pos_coluna] == cor_inicial) {
        canvas[pos_linha][pos_coluna] = cor;
    }

    // pixel de cima
    if (pos_linha > 0 && canvas[pos_linha - 1][pos_coluna] == cor_inicial) {
        pintar(cor_inicial, cor, pos_linha - 1, pos_coluna, linhas, colunas, canvas);
    }

    // pixel da direita
    if (pos_coluna < colunas - 1 && canvas[pos_linha][pos_coluna + 1] == cor_inicial) {
        pintar(cor_inicial, cor, pos_linha, pos_coluna + 1, linhas, colunas, canvas);
    }

    // pixel de baixo
    if (pos_linha < linhas - 1 && canvas[pos_linha + 1][pos_coluna] == cor_inicial) {
        pintar(cor_inicial, cor, pos_linha + 1, pos_coluna, linhas, colunas, canvas);
    }

    // pixel da esquerda
    if (pos_coluna > 0 && canvas[pos_linha][pos_coluna - 1] == cor_inicial) {
        pintar(cor_inicial, cor, pos_linha, pos_coluna - 1, linhas, colunas, canvas);
    }
}

int main(void) {
    int m, n, pos_x, pos_y;
    char cor, cor_pos_inicial;

    scanf("%d %d", &m, &n);
    getchar();

    char canvas[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &canvas[i][j]);
        }

        getchar();
    }

    scanf("%d %d %c", &pos_x, &pos_y, &cor);
    cor_pos_inicial = canvas[pos_x][pos_y];

    pintar(cor_pos_inicial, cor, pos_x, pos_y, m, n, canvas);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", canvas[i][j]);
        }

        printf("\n");
    }
    
    return 0;
}