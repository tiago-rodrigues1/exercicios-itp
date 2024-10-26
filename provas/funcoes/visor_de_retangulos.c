/* Visor de Retângulos */

#include <stdio.h>

int estaContido(
    float xA_bottom, 
    float yA_bottom, 
    float xA_top, 
    float yA_top, 
    float xB_bottom, 
    float yB_bottom,
    float xB_top,
    float yB_top
) {

    return (yB_bottom > yA_bottom && yB_top < yA_top) && (xB_bottom > xA_bottom && xB_top < xA_top);
}

int main(void) {
    float xA_top, xA_bottom, yA_top, yA_bottom;
    scanf("%f %f %f %f", &xA_bottom, &yA_bottom, &xA_top, &yA_top);

    while (1) {
        float xB_top, xB_bottom, yB_top, yB_bottom;
        scanf("%f %f %f %f", &xB_bottom, &yB_bottom, &xB_top, &yB_top);

        if (xB_top == 0 && xB_bottom == 0 && yB_top == 0 && yB_bottom == 0){
            break;
        }

        int B_esta_contido_em_A = estaContido(
            xA_bottom,
            yA_bottom,
            xA_top,
            yA_top,
            xB_bottom,
            yB_bottom,
            xB_top,
            yB_top
        );

        int A_esta_contido_em_B = estaContido(
            xB_bottom,
            yB_bottom,
            xB_top,
            yB_top,
            xA_bottom,
            yA_bottom,
            xA_top,
            yA_top
        );

        if (B_esta_contido_em_A) {
            printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", xA_bottom, yA_bottom, xA_top, yA_top, xB_bottom, yB_bottom, xB_top, yB_top);
        } else if (A_esta_contido_em_B) {
            printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", xB_bottom, yB_bottom, xB_top, yB_top, xA_bottom, yA_bottom, xA_top, yA_top);
        } else {
            printf("Nao posso afirmar!\n");
        }

    }
    

    return 0;
}