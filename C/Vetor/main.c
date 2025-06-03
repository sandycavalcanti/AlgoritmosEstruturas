#include <stdio.h>
typedef struct{
    char nome[41];
    float peso;
    float altura;
    int idade;
    char sangue[4];
}Dados;
Dados pessoa[2];
int main(void) {
    float media;
    for(int i = 0; i < 2; i++){
        printf("\ninsira seu nome.\n");
        scanf(" %40[^\n]", pessoa[i].nome);
        printf("insira seu peso.\n");
        scanf("%f", &pessoa[i].peso);
        printf("insira sua altura.\n");
        scanf("%f", &pessoa[i].altura);
        printf("insira sua idade.\n");
        scanf("%d", &pessoa[i].idade);
        printf("insira seu tipo sanguineo.\n");
        scanf("%s", pessoa[i].sangue);
        // Exibindo os dados
        printf("\n\nNome  ==> %s \n", pessoa[i].nome);
        printf("Peso ==> %.2f\n", pessoa[i].peso);
        printf("Altura ==> %.2f\n", pessoa[i].altura);
        printf("Idade ==> %d\n", pessoa[i].idade);
        printf("Sangue ==> %s\n", pessoa[i].sangue);
    }
    media = (pessoa[0].idade + pessoa[1].idade)/2;
    printf("\n\n A média das idades é: %.2f", media);
    return 0;
}