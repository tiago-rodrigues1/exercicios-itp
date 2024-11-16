#include <stdio.h>
#include <stdlib.h>

typedef struct smartphone {
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
} Smartphone;

int cadastra_smartphone(Smartphone phones[], int index_cadastro) {
    Smartphone novo_phone;

    scanf(" %[^\n]s", novo_phone.modelo);
    getchar();
    scanf(" %d %f %f %f", &novo_phone.memoria, &novo_phone.processador, &novo_phone.camera, &novo_phone.bateria);
    getchar();
    
    phones[index_cadastro] = novo_phone;

    return index_cadastro + 1;

}

void imprime_smartphone(Smartphone phone) {
    printf("Modelo: %s\n", phone.modelo);
    printf("Memoria: %dGB\n", phone.memoria);
    printf("Processador: %.2fGhz\n", phone.processador);
    printf("Camera: %.2fMPixels\n", phone.camera);
    printf("Bateria: %.2fmA\n\n", phone.bateria);
}


int pesquisa_smartphone(Smartphone phones[], int index_cadastro, Smartphone req_min) {
    int quant_achados = 0;

    for (int i = 0; i < index_cadastro; i++) {
        if (
            phones[i].memoria >= req_min.memoria &&
            phones[i].processador >= req_min.processador &&
            phones[i].camera >= req_min.camera &&
            phones[i].bateria >= req_min.bateria
        ) {
            imprime_smartphone(phones[i]);
            quant_achados += 1;
        }
    }

    return quant_achados;
}


int main(void) {
    Smartphone phones[20];
    char deve_cadastrar;

    int index_cadastro = 0;


    while (1) {
        scanf("%c", &deve_cadastrar);
        getchar();

        if (deve_cadastrar == 'n') {
            break;
        }

        index_cadastro =  cadastra_smartphone(phones, index_cadastro);
    }

    Smartphone req_min;

    scanf(" %d %f %f %f", &req_min.memoria, &req_min.processador, &req_min.camera, &req_min.bateria);

    int quant_achados = pesquisa_smartphone(phones, index_cadastro, req_min);

    printf("%d smartphones encontrados.\n", quant_achados);
    
    return 0;
}