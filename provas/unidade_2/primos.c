#include <stdio.h>

int gerar_sequencia(int n) {
    printf("%d ", n);

    if (n == 1) {
        return 1;
    }

    if (n % 2 == 0) {
        return gerar_sequencia(n / 2);
    }

    if (n % 3 == 0) {
        return gerar_sequencia(n / 3);
    }

    if (n % 5 == 0) {
        return gerar_sequencia(n / 5);
    }

    if (n % 7 == 0) {
        return gerar_sequencia(n / 7);
    }


}

int main(void) {
    int n;
    scanf("%d", &n);

    gerar_sequencia(n);
    printf("\n");
    
    return 0;
}