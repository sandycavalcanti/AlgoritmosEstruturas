/*
	Name: SelectionSort.cpp 
	Author: Sandy Pereira Cavalcanti
	Date: 07/05/25 11:34
	Description: Implementação do algoritmo do método de ordenação Selection Sort
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main(){
	int chave, i, j, aux, comp, troca, menor;
	comp = troca = 0;
	int vet[] = { 35, 72, 17, 3, 28, 93, 54, 12, 21, 45};	// Vetor Randomico
//	int vetor[] = { 93, 72, 54, 45, 35, 28, 21, 17, 12, 3};	//Pior caso
//	int vetor[] = { 3, 12, 17, 21, 28, 35, 45, 54,72, 93};	//Melhor caso
	int tam = sizeof(vet)/sizeof(int);
	
	puts("vetor desordenado:");
	for(i = 0; i < tam; i++){
		printf("%d | ", vet[i]);
	};
	
	i = 0;
	while(i < tam){
		chave = menor = i;
		j = i+1;
		do{
			if(vet[j] < vet[menor]){
				menor = j;
			};
		j++;
		}while(j < tam);
		if(i != menor){
			aux = vet[i];
			vet[i] = vet[menor];
			vet[menor] = aux;
			troca++;
		};
		i++;
		comp++;
	};// Fim do While
	// Mostrar vetor ordenado por Selection Sort
	tam = sizeof(vet)/ sizeof (int);
	puts("\n\nvetor ordenado por Selection Sort:");
	for(i = 0; i < tam; i++){
		printf("%d | ", vet[i]);
	};
	printf("\nQuantidade de comparações: %d ", comp);
	printf("\nQuantidade de trocas: %d ", troca);
}; //Fim do main