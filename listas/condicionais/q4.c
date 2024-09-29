/* A melhor trilha */

#include <stdio.h>

int main(void) {
    int trilhas;

    scanf("%i", &trilhas);

    if (trilhas < 5) {
        printf("Iniciante\n");
    } else {
        int saude;
        scanf("%i", &saude);    

        if (trilhas >= 5 && trilhas < 20) {
            if (saude) {
                printf("Intermediário\n");
            } else {
                printf("Iniciante\n");
            }
        } else {
            if (saude) {
                printf("Avançado\n");
            } else {
                printf("Intermediário\n"); 
            }
        }
    }
}