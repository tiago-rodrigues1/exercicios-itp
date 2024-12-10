#include <stdio.h>

int sequencia(int n) {
    printf("%d ", n);

    if (n == 1) {
        return 1;
    }

    if (n % 2 == 0) {
        return sequencia( n / 2);
    } else {
        return sequencia((n * 3) + 1);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    sequencia(n);
    printf("\n");

    return 0;
}