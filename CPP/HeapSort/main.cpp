/*
	Name: HeapSort.cpp
	Copyright: 
	Author: Sandy Pereira Cavalcanti
	Date: 21/05/25 11:46
	Description: Implementalção do algoritmo para o metodo de ordenação Heap Sort
*/
#include <stdio.h>

// Sessão de prototipação

void heapfy(int *, int,int);// (vet,tam,i)
void heapSort(int *, int);// (vet, tam)

int main(){
	int i;
	int vet[] = { 35, 72, 17, 3, 28, 93, 54, 12, 21, 45};	// Vetor Randomico
//	int vetor[] = { 93, 72, 54, 45, 35, 28, 21, 17, 12, 3};	//Pior caso
//	int vetor[] = { 3, 12, 17, 21, 28, 35, 45, 54,72, 93};	//Melhor caso
	int tam = sizeof(vet)/sizeof(int);
	
	puts("vetor desordenado:");
	for(i = 0; i < tam; i++)
	{
		printf("%d | ", vet[i]);
	};
	heapSort(vet, tam);
	puts("\nvetor ordenado pelo método Heap Sort:");
	for(i = 0; i < tam; i++)
	{
		printf("%d | ", vet[i]);
	};
}
void heapfy(int vet[], int tam,int i){
	int maior = i;
	int esq = i*2+1;
	int dir = i*2+2;
	if(esq < tam && vet[esq] > vet[maior]){
		maior = esq;
	}
	if(dir < tam && vet[dir]>vet[maior]){
		maior = dir;
	}
	if(maior != i){
		int aux = vet[i];
		vet[i] = vet[maior];
		vet[maior] = aux;
		heapfy(vet, tam, maior);
	}
}	// fim da função heapfy
// Função do Heap Sort
void heapSort(int vet[], int tam){
	for(int i = tam/2-1; i>=0; i--){
		heapfy(vet, tam, i);
	}
	for(int i = tam-1; i> 0; i--){	// Faz o Suap
		int aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		heapfy(vet,i,0);
	}
}// fim da função heapSort
