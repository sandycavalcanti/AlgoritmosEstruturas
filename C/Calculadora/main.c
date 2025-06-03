#include <stdio.h>

int v2, v1;
double resultado;
char indice;

double soma(int n1, int n2)
{
  int r;
  r =  n2 + n1;
  return (r);
}
double subtracao(int n1, int n2)
{
  int r;
  r =  n2 - n1;
  return (r);
}
double divisao(int n1, int n2)
{
  int r;
    if(n1 > 0 && n2 > 0){
      r =  n2 / (double) n1;
      return (r);
    }else{
      printf("Valores invalidos, insira novamente\n");
      return(0);
    }
}
double multiplicacao(int n1, int n2)
{
  int r;
  r =  n2 * n1;
  return (r);
}

int main(void) {
  printf("insira o primeiro numero\n");
  scanf("%d", & v1);
  printf("insira o segundo numero\n");
  scanf("%d", & v2);

  printf("\n\nCaso queira somar selecione = +\n");
  printf("Caso queira subtrair selecione = -\n");
  printf("Caso queira dividir selecione = /\n");
  printf("Caso queira multiplicar selecione = *\n");

  scanf("%s", & indice);

  switch(indice){
    case '+':
      resultado = soma(v1,v2);
      break;
    case '-':
      resultado = subtracao(v1,v2);
      break;
    case '/':
      resultado = divisao(v1,v2);
      break;
    case '*':
      resultado = multiplicacao(v1,v2);
      break;
  }
  
  printf("O resultado é: %.2f \n", resultado);
  return 0;
}