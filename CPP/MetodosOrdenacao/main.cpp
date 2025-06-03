/*
	Name: metodosordenacao.cpp
	Author: Sandy Pereira Cavalcanti
	Date: 25/05/25 15:00
	Description: Implementação de vários métodos de ordenação
    para estudo e comparação de desempenho.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Sessão de prototipação
void bubbleSort(int *, int, int *, int *);
void insetionSort(int , int);
void selectionSort(int *, int , int *, int *);
void mergeSort(int , int , int);
void merge(int , int , int , int);
void heapfy(int , int ,int);
void heapSort(int, int);
// Inicio do programa
int main()
{
    int tam, i, comp, troca, chave, menor, fim, inicio;
	int vet[] = { 35, 72, 17, 3, 28, 93, 54, 12, 21, 45};	// Vetor Randomico
//	int vetor[] = { 93, 72, 54, 45, 35, 28, 21, 17, 12, 3};	//Pior caso
//	int vetor[] = { 3, 12, 17, 21, 28, 35, 45, 54,72, 93};	//Melhor caso
	tam = sizeof(vet)/sizeof(int);
	puts("vetor desordenado:");
	for(i = 0; i < tam; i++)
	{
		printf("%d | ", vet[i]);
	};
    tam = sizeof(vet)/sizeof(int);
    printf("\n\nSelecione o método de ordenação:\n");
    printf("1 - Bubble Sort\n2 - Insertion Sort\n3 - Selection Sort\n4 - Merge Sort\n5 - Heap Sort\n");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            bubbleSort(vet, tam, &comp, &troca);
            break;
        case 2:
            insetionSort(vet, tam);
            puts("\nvetor ordenado pelo método Insertion Sort:");
            for(i = 0; i < tam; i++)
            {
                printf("%d | ", vet[i]);
            }
            break;
        case 3:
            selectionSort(vet, tam, &comp, &troca);
            puts("\nvetor ordenado pelo método Selection Sort:");
            for(i = 0; i < tam; i++)
            {
                printf("%d | ", vet[i]);
            }
            printf("\nQuantidade de comparações: %d ", comp);
            printf("\nQuantidade de trocas: %d ", troca);
            break;
        case 4:
            mergeSort(vet, inicio, tam);
            puts("\nvetor ordenado pelo método Merge Sort:");
            for(i = 0; i < tam; i++)
            {
                printf("%d | ", vet[i]);
            }
            break;
        case 5:
        	heapSort(vet, tam);
            break;
        default:
            printf("Opção inválida!\n");
    }
	puts("\nvetor ordenado pelo método Heap Sort:");
	for(i = 0; i < tam; i++)
	{
		printf("%d | ", vet[i]);
	};
} // fim do main
// Metodo de ordenação Bubble Sort
void bubbleSort(int vetor[], int tam, int comp, int troca){
	// l�gica do Bubble Sort
    int i, aux;
	while(tam > 0){
		for(i = 0; i < tam-1; i++){
			if(vetor[i] > vetor[i+1]){
				aux = vetor[i+1];	// Variavel auxiliar
				vetor[i+1] = vetor[i];
				vetor[i] = aux;
				troca++;
			};
			comp++;
		};
		tam--;
	};// fim do While
	tam = sizeof(vetor)/ sizeof (int);
	puts("\n\nvetor ordenado por Bubble:");
	for(i = 0; i < tam; i++){
		printf("%d | ", vetor[i]);
	};
	printf("\nQuantidade de compara��es: %d ", comp);
	printf("\nQuantidade de trocas: %d ", troca);
}	// Fim da função BubbleSort
// Metodo de ordenação Insertion Sort
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
};  // Fim do Insertion Sort
// Metodo de ordenação Selection Sort
void selectionSort( int vet[], int tam, int comp, int troca)
{
    int i, j, chave, menor, aux;
    i = j = 0;
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
	};
}; // Fim do Selection Sort
// Metodo de ordenação Merge Sort
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
// Metodo de ordenação Heap Sort
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