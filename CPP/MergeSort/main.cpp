/*
	Name: MergeSort.cpp
	Author: Sandy Pereira Cavalcanti
	Date: 14/05/25 12:08
	Description: Implementação do algoritmo do método de ordenação Merge Sort
*/
#include <stdio.h>

// Sessão de prototipação
void mergeSort(int *, int, int);	//Prototipação da função que QUEBRA
void merge(int *, int, int, int);	//Prototipo da função que JUNTA TUDO (MESCLA)

main()
{
	int inicio, fim, i, comp, troca;
	comp = troca = 0;
	int vet[] = { 35, 72, 17, 3, 28, 93, 54, 12, 21, 45};	// Vetor Randomico
//	int vetor[] = { 93, 72, 54, 45, 35, 28, 21, 17, 12, 3};	//Pior caso
//	int vetor[] = { 3, 12, 17, 21, 28, 35, 45, 54,72, 93};	//Melhor caso
	int tam = sizeof(vet)/sizeof(int);
	
	puts("vetor desordenado:");
	for(i = 0; i < tam; i++)
	{
		printf("%d | ", vet[i]);
	};
	
	puts("\nvetor ordenado pelo método Merge Sort:");
	for(i = 0; i < tam; i++)
	{
		printf("%d | ", vet[i]);
	};
	
} //Fim do main

//Função recursaiva direta, que quebra at´chegar em uma unica unidade
void mergeSort(int vetor[], int inicio, int fim)
{
	if(inicio < fim)
	{
		int meio = (inicio + fim)/2;
		mergeSort(vetor, inicio, meio);	//Lado esquerdo
		mergeSort(vetor, meio+1, fim);	//Lado direito
		merge(vetor, inicio, meio, fim);
	}
}
//Função que junta as partes unitáias (merge) mesclando os elementos
void merge(int vet[], int inicio, int meio, int fim)
{
	int esquerda, direita, aux, tam;
	esquerda = inicio;
	direita = meio+1;
	aux = 0;
	tam = fim-inicio+1;
}

