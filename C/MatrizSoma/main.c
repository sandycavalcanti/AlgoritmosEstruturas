#include <stdio.h>

int numero[4][4], soma = 0;

int main(void) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
        numero[i][j] = (i + j)*2 + (i * j)*3;
        if(i == j){
        soma = soma + numero[i][j];
        }
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
        printf("%2d ", numero[i][j]);
        }
        printf("\n");
    }
    printf("\nA soma de todos os elementos principais diagonais da tabela, é igual a: %d", soma);


    return 0;
}