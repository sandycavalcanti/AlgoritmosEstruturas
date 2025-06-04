/*
	Name: QuickSort.cpp
	Author: Sandy Pereira Cavalcanti
	Date: 28/05/25 11:20
	Description: Implementa��o do m�todo de ordena��o Quick Sort
*/
// Sess�o de importa��o de bibliotecas
#include <stdio.h>
// Prototipa��o das fun��es
void quickSort(int *, int, int);
int partition(int *, int, int);
// inicio do main
int main()
{
	int tam, i;
	int vetor[] = { 35, 72, 17, 3, 28, 93, 54, 12, 21, 45};	// Vetor Randomico
//	int vetor[] = { 93, 72, 54, 45, 35, 28, 21, 17, 12, 3};	//Pior caso
//	int vetor[] = { 3, 12, 17, 21, 28, 35, 45, 54,72, 93};	//Melhor caso
	tam = sizeof(vetor)/ sizeof (int);
	puts("vetor desordenado:");
	for(i = 0; i < tam; i++){
		printf("%d | ", vetor[i]);
	};
	quickSort(vetor, 0, tam-1);
	tam = sizeof(vetor)/ sizeof (int);
	puts("\n\nvetor ordenado pelo Quick Sort:");
	for(i = 0; i < tam; i++){
		printf("%d | ", vetor[i]);
	};

} // Fim do main

// Fun��o quick sort para a esquerda e direita das parti��es
void quickSort(int *vet, int inicio, int fim)
{
	int pivot = 0;
	if(fim > inicio)
	{
		pivot = partition(vet, inicio, fim);
		quickSort(vet, inicio, pivot-1);	//quick sort para o lado esquerdo
		quickSort(vet, pivot+1, fim);		// quick sort para o lado direito
	};
};	// Fim da fun��o quickSort
// Fun��o partition para particionar o conjunto de dados
int partition(int *vet, int inicio, int fim)
{
	int esq, dir, pivot, aux;
	pivot = vet[inicio];
	esq = inicio;
	dir = fim;
	while(esq < dir)
	{
		while(vet[esq] <= pivot)
		{
			esq++;
		};
		while(vet[dir] > pivot)
		{
			dir--;
		};
		if(esq < dir)
		{
			aux = vet[esq];
			vet[esq] = vet[dir];
			vet[dir] = aux;
		}
	};	// Fim do While que caminha nas duas dire��es
	vet[inicio] = vet[dir];
	vet[dir] = pivot;
	return dir;
};	// Fim da fun��o partition
