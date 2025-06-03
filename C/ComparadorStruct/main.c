#include <stdio.h>

#define Tam 3

typedef struct{
    char nome[41];
    float peso;
    float altura;
    int idade;
    char sangue[4];
}Dados;
Dados pessoa[Tam];

int main(void) {

    int mais_velho, mais_novo, mais_alto, mais_baixo, menor_peso, maior_peso;
    mais_velho = mais_novo = mais_alto = mais_baixo = menor_peso = maior_peso = 0;

    for(int i = 0; i < Tam; i++){
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
    
        printf("\n\nNome  ==> %s \n", pessoa[i].nome);
        printf("Peso ==> %.2f\n", pessoa[i].peso);
        printf("Altura ==> %.2f\n", pessoa[i].altura);
        printf("Idade ==> %d\n", pessoa[i].idade);
        printf("Sangue ==> %s\n", pessoa[i].sangue);
    }

    for(int j = 0; j < Tam; j++){
        
        if(pessoa[mais_velho].idade < pessoa[j].idade){
            mais_velho = j;
        } else if(pessoa[j].idade < pessoa[mais_novo].idade){
            mais_novo = j;
        }
        
        if(pessoa[mais_alto].altura < pessoa[j].altura){
            mais_alto = j;
        } else if(pessoa[j].altura < pessoa[mais_baixo].altura){
            mais_baixo = j;
        }
        
        if(pessoa[maior_peso].peso < pessoa[j].peso){
            maior_peso = j;
        } else if(pessoa[j].peso < pessoa[menor_peso].peso){
            menor_peso = j;
        }
    }

    printf("\nO individuo com maior idade é: %s\n", pessoa[mais_velho].nome);
    printf("O individuo com menor idade é: %s\n", pessoa[mais_novo].nome);
    printf("\nO individuo com maior altura é: %s\n", pessoa[mais_alto].nome);
    printf("O individuo com menor altura é: %s\n", pessoa[mais_baixo].nome);
    printf("\nO individuo com maior peso é: %s\n", pessoa[maior_peso].nome);
    printf("O individuo com menor peso é: %s\n", pessoa[menor_peso].nome);
    return 0;
}