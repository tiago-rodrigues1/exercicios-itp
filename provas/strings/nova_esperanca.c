#include <stdio.h>
#include <string.h>

#define TAM_MENSAGEM 101
#define TAM_CHAVE 5
#define TAM_DICIONARIO 40

int get_index(char dicionario[], char valor) {
    int pos = -1;
    int tamanho = strlen(dicionario);

    for (int i = 0; i < tamanho; i++) {
        if (valor == dicionario[i]) {
            pos = i;
            break;
        }
    }

    return pos;
}

int main(void) {
    char dicionario[] = {
        '0','1','2','3','4','5','6','7','8','9',
        'A','B','C','D','E','F','G','H','I','J',
        'K','L','M','N','O','P','Q','R','S','T',
        'U','V','W','X','Y','Z','.',',','?',' '
    };

    char chave[TAM_CHAVE];
    char mensagem[TAM_MENSAGEM];

    scanf("%s", chave);
    getchar();

    if (strlen(chave) > TAM_CHAVE - 1) {
        printf("Chave invalida!\n");
        return 0;
    }

    fgets(mensagem, TAM_MENSAGEM, stdin);

    int contador_mensagem = 0;
    int contador_chave = 0;

    int tamanho_mensagem = strlen(mensagem);
    mensagem[tamanho_mensagem - 1] = '\0';

    char cifrada[TAM_MENSAGEM] = {0};

    int tem_invalido = 0;

    while(1) {
        char atual = mensagem[contador_mensagem];

        if (atual == '\0' || atual == '\n') {
            break;
        }

        int pos = get_index(dicionario, atual);

        if (pos == -1) {
            tem_invalido = 1;
            break;
        }

        // Converte o char para inteiro. Ex.: '1' -> 1
        int cifra = chave[contador_chave] - '0';

        int pos_novo_char = pos + cifra;


        if (pos_novo_char >= TAM_DICIONARIO) {
            pos_novo_char -= TAM_DICIONARIO;
        }

        cifrada[contador_mensagem] = dicionario[pos_novo_char];

        contador_mensagem += 1;
        contador_chave += 1;

        if (contador_chave == TAM_CHAVE - 1) {
            contador_chave = 0;
        }
    }

    if (tem_invalido) {
        printf("Caractere invalido na entrada!\n");
    } else {
        printf("%s\n", cifrada);
    }
    
    return 0;
}