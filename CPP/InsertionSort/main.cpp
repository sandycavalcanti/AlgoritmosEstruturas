/*
	Name: InsertionSort.cpp
	Author: Sandy Pereira Cavalcanti
	Date: 14/05/25 11:33
	Description: Implementação do algoritmo do método de ordenação InsertionSort
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sessão de prototipação
void insetionSort(int *, int);

main(){
	int i, comp, troca;
	comp = troca = 0;
	int vet[] = { 35, 72, 17, 3, 28, 93, 54, 12, 21, 45};	// Vetor Randomico
//	int vetor[] = { 93, 72, 54, 45, 35, 28, 21, 17, 12, 3};	//Pior caso
//	int vetor[] = { 3, 12, 17, 21, 28, 35, 45, 54,72, 93};	//Melhor caso
	int tam = sizeof(vet)/sizeof(int);
	
	puts("vetor desordenado:");
	for(i = 0; i < tam; i++){
		printf("%d | ", vet[i]);
	};
	
	insetionSort(vet, tam); //Invoke da função de ordenação
	puts("vetor ordenado pelo método Insertion Sort:");
	for(i = 0; i < tam; i++){
		printf("%d | ", vet[i]);
	};
	
} //Fim do main

void insetionSort(int vet[], int tam){
	int i, j, k, chave;
	for(i=1; 1<tam;i++){
		chave = vet[i];
		j = i-1;
		while(j>=0 && vet[j]>chave){
			vet[j+1] = vet[j];
			j = j-1;
		}
		vet[j+1] = chave;
	};
};