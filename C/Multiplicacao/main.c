#include <stdio.h>
int v2, v1;
double resultado;
double multiplicacao(int multiplicador, int multiplicado)
{
    int r;
    r =  multiplicado * multiplicador;
    return (r);
}
int main(void) {
    printf("insira o multiplicador\n");
    scanf("%d", & v1);
    printf("insira o multiplicado\n");
    scanf("%d", & v2);
    resultado = multiplicacao(v1,v2);
    printf("O resultado é: %.2f \n", resultado);
    return 0;
}