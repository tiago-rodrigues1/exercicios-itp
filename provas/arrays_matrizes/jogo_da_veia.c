/* Jogo da Véia */

#include <stdio.h>

int is_coluna_vencedora(char tabuleiro[3][3], int linha_jogada, int coluna_jogada, char simbolo) {
    tabuleiro[linha_jogada - 1][coluna_jogada - 1] = simbolo;

    if (
        tabuleiro[0][coluna_jogada - 1] == simbolo &&
        tabuleiro[2][coluna_jogada - 1] == simbolo &&
        tabuleiro[1][coluna_jogada - 1] == simbolo
    ) {
        return 1;
    }

    return 0;
}

int is_linha_vencedora(char tabuleiro[3][3], int linha_jogada, int coluna_jogada, char simbolo) {
    tabuleiro[linha_jogada - 1][coluna_jogada - 1] = simbolo;

    if (
        tabuleiro[linha_jogada - 1][0] == simbolo &&
        tabuleiro[linha_jogada - 1][1] == simbolo &&
        tabuleiro[linha_jogada - 1][2] == simbolo
    ) {
        return 1;
    }

    return 0;
}

int is_diagonal_vencedora(char tabuleiro[3][3], int linha_jogada, int coluna_jogada, char simbolo) {
    tabuleiro[linha_jogada - 1][coluna_jogada - 1] = simbolo;

    int is_diagonal_principal_vencedora = tabuleiro[0][0] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][2] == simbolo;
    int is_diagonal_secundaria_vencedora = tabuleiro[0][2] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][0] == simbolo;

    return is_diagonal_principal_vencedora || is_diagonal_secundaria_vencedora;
}

int is_jogada_vencedora(char tabuleiro[3][3], int linha_jogada, int coluna_jogada, char simbolo) {
    char copia_tabuleiro[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            copia_tabuleiro[i][j] = tabuleiro[i][j];
        }
    }

    return 
    is_coluna_vencedora(copia_tabuleiro, linha_jogada, coluna_jogada, simbolo) ||
    is_linha_vencedora(copia_tabuleiro, linha_jogada, coluna_jogada, simbolo) ||
    is_diagonal_vencedora(copia_tabuleiro, linha_jogada, coluna_jogada, simbolo);
}

int main(void) {
    char tabuleiro [3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf(" %c", &tabuleiro[i][j]);
        }
    }

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int linha, coluna;
        char simbolo;

        scanf("%d %d %c", &linha, &coluna, &simbolo);

        if (tabuleiro[linha - 1][coluna - 1] != '.') {
            printf("Jogada inválida!\n");
        } else if (is_jogada_vencedora(tabuleiro, linha, coluna, simbolo)) {
            printf("Boa jogada, vai vencer!\n");
        } else {
            printf("Continua o jogo.\n");
        }
    }
}