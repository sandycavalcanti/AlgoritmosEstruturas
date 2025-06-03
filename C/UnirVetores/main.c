#include <stdio.h>
int a[20], b[20], c[40];

int main(void) {
    int numeroDigitado, resto[20];

    printf("Programa juntar em um vetor!!\n");

    for (int i = 0; i < 20; i++) {
        printf("Digite os valores do vetor A: \n");
        scanf("%d", &numeroDigitado);
        if (numeroDigitado < 0) {
        break;
        }
        a[i] = numeroDigitado;
    }
    for (int i = 0; i < 20; i++) {
        printf("Digite os valores do vetor B: \n");
        scanf("%d", &numeroDigitado);
        if (numeroDigitado < 0) {
        break;
        }
        b[i] = numeroDigitado;
    }

    for (int i = 0; i < 20; i++) {
        if (a[i] < b[i] && a[i] < resto[i]){
        c[i] = a[i];
        int resto = b[i];
        } else if (a[i] < b[i] && a[i] < resto[i]){
        c[i] = b[i];
        resto[i] = a[i];
        }
    }

    for (size_t i = 0; i < count; i++)
    {
        /* code */
    }
    

    return 0;
}