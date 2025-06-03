#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matriz[10][10] = {0};
int linha[10] = {0};
int coluna[10] = {0};
int indices[2][4] = {0};

int numerosrandomicos(l, c){
    matriz[l][c] = rand() % 100;
    return 0;
}
int exibirmatriz(){
    for(int l = 0; l < 10; l++){
        for(int c = 0; c < 10; c++){
        printf(" %02d", matriz[l][c]);
        }
        printf("\n");
    }
    return 0;
}
int main(void) {
    // preenche matriz
    srand(time(NULL));
    for(int l = 0; l < 10; l++){
        for(int c = 0; c < 10; c++){
        numerosrandomicos(l,c);
        }
    }
    //  soma geral de linhas e colunas da matriz
    for(int i = 0; i < 10; i++){
        for(int a = 0; a < 10; a++){
        linha[i] = linha[i] + matriz[i][a];
        coluna[i] = coluna[i] + matriz[a][i];
        }
    }
    exibirmatriz();
    printf("\n");
    // captura as linhas indicadas pelo usuário
    for(int i = 1; i <= 4; i++){
        printf("Digite a linha %d: ", i);
        scanf("%d", &indices[0][i-1]);
        if(indices[0][i-1] > 9 || indices[0][i-1] < 0){
        printf("Valor Inválido. Digite um valor entre 0-9.\n");
        i--;
        }
    }
    printf("\n");
    // captura as colunas indicadas pelo usuário 
    for(int i = 1; i <= 4; i++){
        printf("Digite a coluna %d: ", i);
        scanf("%d", &indices[1][i-1]);
        if(indices[1][i-1] > 9 || indices[1][i-1] < 0){
        printf("Valor Inválido. Digite um valor entre 0-9.\n");
        i--;
        }
    }
    printf("\n");
    // apresenta a soma das linhas cadastradas pelo usuário
    for(int i = 0; i < 4; i++){
        printf("A soma da linha %d (Indice %d) é: %d \n", indices[0][i]+1, indices[0][i], linha[indices[0][i]]);
    }
    printf("\n");
    // apresenta a soma das colunas cadastradas pelo usuário 
    for(int i = 0; i < 4; i++){
        printf("A soma da coluna %d (Indice %d) é: %d \n", indices[1][i]+1, indices[1][i], coluna[indices[1][i]]);
    }
    return 0;
}