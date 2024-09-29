/* [ITP] Conversor de temperaturas */

#include <stdio.h>

int main(void) {
    float temperatura;
    char escala;

    scanf("%f %c", &temperatura, &escala);

    float celsius, kelvin, farenheit;

    if (escala == 'C') {
        celsius = temperatura;
        farenheit = celsius * 1.8 + 32;
        kelvin = celsius + 273.15;
    } else if (escala == 'F') {
        farenheit = temperatura;
        celsius = (farenheit - 32) / 1.8;
        kelvin = celsius + 273.15;
    } else if (escala == 'K') {
        kelvin = temperatura;
        celsius = kelvin - 273.15;
        farenheit = celsius * 1.8 + 32;
    }

    printf("Celsius: %.2f\n", celsius);
    printf("Farenheit: %.2f\n", farenheit);
    printf("Kelvin: %.2f\n", kelvin);
    
    return 0;
}