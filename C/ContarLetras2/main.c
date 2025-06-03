#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

int main(void) {
    char texto[91];
    int i, tamanho, tabela[128] = {0};
    printf("Digite um texto: ");
    fgets(texto, 91, stdin);
    tamanho = strlen(texto)-1;
    printf("O texto digitado foi: %s\n", texto);

    for (i = 0; i < tamanho; i++){
        tabela[(int)texto[i]]++;
    }
    for (i = 0; i < 128; i++){
        if(tabela[i] > 0){  
        if(i == 32) {
            printf("branco = %d\n", tabela[i]);
        } else{
            printf("%c = %d\n", i, tabela[i]);
        }
        }
    }

    printf("\nTotal de caracteres = %d\n", tamanho);
    return 0;
}