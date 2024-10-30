#include <stdio.h>

float media_aritmetica(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

float media_ponderada(float n1, float n2, float n3) {
    return (n1 * 4 + n2 * 5 + n3 * 6) / 15;
}

float calcula_media(char tipo, float n1, float n2, float n3){
    if(tipo == 'A'){
        printf("Média %.2f", media_aritmetica(n1, n2, n3));
    }
    else if(tipo == 'P'){
        printf("Média %.2f", media_ponderada(n1, n2, n3));
    }
}

int main(void) {
  char tipo;
  float nota_1, nota_2, nota_3;

  scanf("%c", &tipo);
  scanf("%f %f %f", &nota_1, &nota_2, &nota_3);

  calcula_media(tipo, nota_1, nota_2, nota_3);
}