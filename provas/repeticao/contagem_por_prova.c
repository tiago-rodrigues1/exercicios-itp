/* [ITP] Contagem por Prova (Atletismo) */

#include <stdio.h>

#define MAX_LINE 50

int main(void) {
    int quantidade_equipes;
    int quantidade_corridas = 0, quantidade_saltos = 0, quantidade_lancamentos = 0, quantidade_atletas = 0;

    scanf("%d", &quantidade_equipes);
    getchar();

    for (int i = 0; i < quantidade_equipes; i++) {
        char inscricoes[MAX_LINE];
        fgets(inscricoes, MAX_LINE, stdin);

        for (int j = 0; j < sizeof inscricoes; j++) {
            switch (inscricoes[j]) {
                case 'C':
                    quantidade_corridas += 1;
                    break;
                
                case 'S':
                    quantidade_saltos += 1;
                    break;
                case 'L':
                    quantidade_lancamentos += 1;
                    break;
                default:
                    break;
            }
        }

        quantidade_atletas = quantidade_corridas + quantidade_lancamentos + quantidade_saltos;
    }

    printf("%d %d %d %d\n", quantidade_corridas, quantidade_saltos, quantidade_lancamentos, quantidade_atletas);
    
    return 0;
}