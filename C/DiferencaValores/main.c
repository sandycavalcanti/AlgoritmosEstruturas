#include <stdio.h>
#include <string.h>
#define Tam_Max 5 
int main(void) {
    int id[Tam_Max], i, t, maior, menor;
    float m;
    i = 0;
    do{
        printf("Insira a idade númrero %d\n", i+1);
        scanf("%d", &id[i]);
        i++;
    }while(i < Tam_Max);
    t = 0;  
    for(int j = 0; j < Tam_Max; j++){
        t = t + id[j];
    }
    printf("Soma das idades é igual a %d\n\n", t);
    i = 0;
    maior = 0;
    do{
        if(id[i] > maior){
        maior = id[i];
        }
        i++;
    }while(i < Tam_Max);
    printf("A maior idade é de  %d\n\n", maior);
    i = 0;
    menor = maior;
    do{
        if(menor > id[i]){
            menor = id[i];
        }
        i++;
    }while(i < Tam_Max);
    printf("A menor idade é de  %d\n\n", menor);
    printf("A diferença entre a maior idade %d e a menor idade %d, é de %d\n\n", maior, menor, maior - menor);
    m = (float)t/Tam_Max;
    printf("A média das idades é igual a %.1f\n\n", m);
    return 0;
}