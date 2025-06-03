#include <stdio.h>
#include <string.h>
#include <locale.h>
int main(void) {
    
    char nome[80];

            // fazendo com que o scanf não pare no primeiro espaço
    // printf("Digite seu nome:  ");
    // scanf(" %79[^\n]", nome);
    // printf("%s", nome);

    
            // usando fgets

    setlocate(LC_ALL, "Portuguese");
    
    printf("Digite seu nome:  ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome)-1] = '\0';
    printf("\n%s", nome);
    return 0;
    

    //       //strcpy

    // char texto[200], novotexto[200], console[20];
    // printf("Digite o texto: ");
    // gets(texto);
    
    
}