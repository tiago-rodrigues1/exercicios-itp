#include <stdio.h>

int fibonacci(int n){
    if(n <2 ) {
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}
 
int main(void) {
    int a, b, quant = 0;

    scanf("%d %d", &a, &b);
    
    for (int i = 0; i <= b; i++) {
        int fibo_number = fibonacci(i);

        if (fibo_number > b) {
            break;
        } else if (fibo_number > a && fibo_number < b) {
            quant += 1;
        }
    }

    printf("Existem %d números de fibonacci entre %d e %d\n", quant, a, b);

    return 0;
}