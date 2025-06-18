/*
	Name: BuscaOrdenacao.cpp
	Author: Sandy Pereira Cavalcanti 
	Date: 17/06/25 
	Description: Implementação de um algoritmo que ordena um conjunto de dados e permite executar buscas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// SESSÃO DE PROTOTIPOS
// Funções de ordenação
void exibirVet(int *, int, int *,int *);    //Função para exibir o vetor ordenado e as quantidades de comparações e trocas
void bubbleSort(int *,int, int *,int *);    //Função de ordenação Bubble Sort
void selectionSort(int *, int, int *,int *);    //Função de ordenação Selection Sort
void insertionSort(int *, int, int *,int *);    //Função de ordenação Insertion Sort
void mergeSort(int *, int, int, int *);   //Função de ordenação Merge Sort
void merge(int *, int, int, int, int *);    //Função auxiliar do Merge Sort, que realiza a junção das sublistas de forma ordenada
void heapSort(int *,int, int *,int *);  //Função de ordenação Heap Sort
void heapfy(int *, int, int, int *,int *);  //Função auxiliar do Heap Sort, que organiza a árvore binária de forma que o maior elemento fique na raiz
void quickSort(int *,int, int, int *,int *);    //Função de ordenação Quick Sort
int partition(int *, int, int, int *,int *);    //Função auxiliar do Quick Sort, que particiona o vetor em duas partes, uma com elementos menores que o pivô e outra com elementos maiores
// Funções de busca
void buscaSequencial(int *, int, int);  //Função de busca sequencial
void buscaBinaria(int *, int, int); //Função de busca binária

int main()  // Função principal
{
    int i,tam,seek,vet[10], comp, troca;
    comp = troca = 0;
    tam = sizeof(vet)/sizeof(int);
    puts("\n\nORDENADOR E BUSCADOR DE NUMEROS!!!\n\n");
    puts("\nVetor desordenado: \n");
    srand(time(NULL));  // Semente para geração de números aleatórios
    for(i=0;i<tam;i++)  
    {
        vet[i] = rand()%10; // Gera números aleatórios entre 0 e 9
        printf("%d | ", vet[i]);
    }
    puts("\n\n1 - Busca Sequencial\n2 - Busca Binária\n3 - Sair\n\n");  // Opções de busca, caso escolha 2, o vetor deverá ser ordenado antes da busca binária
    puts("\nSelecione o método de busca desejado: ");
    int op;
	scanf("%d", &op);
    switch (op)
    {
    case 1:
        puts("\nQual elemento deseja buscar?");
        scanf("%d", &seek);
        buscaSequencial(vet, tam, seek);
        break;
    case 2:     //O usuário deve escolher o método de ordenação desejado antes de realizar a busca binária
        puts("\n\n1 - Metodo Bubble Sort\n2 - Metodo Selection Sort\n3 - Metodo Insertion Sort\n4 - Metodo Merge Sort\n5 - Metodo Heap Sort\n6 - Metodo Quick Sort\n");
        puts("\nSelecione o método que desejada utilizar para ordenar o vetor:");
        int escolha;
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            bubbleSort(vet,tam, &comp, &troca);
            exibirVet(vet, tam, &comp, &troca);
            break;
        case 2:
            selectionSort(vet,tam, &comp, &troca);
            exibirVet(vet, tam, &comp, &troca);
            break;
        case 3:
            insertionSort(vet,tam, &comp, &troca);
            exibirVet(vet, tam, &comp, &troca);
            break;
        case 4:        
            mergeSort(vet, 0, tam - 1, &comp);
            exibirVet(vet, tam, &comp, &troca);
            break;
        case 5:        
            heapSort(vet, tam, &comp, &troca);
            exibirVet(vet, tam, &comp, &troca);
            break;
        case 6:        
            quickSort(vet,0, tam-1, &comp, &troca);
            exibirVet(vet, tam, &comp, &troca);
            break;
        default:
            puts("Opção invalida  x_x");
            puts("Saindo...");
            break;
        }
        //Inicio da busca binária
        puts("\nQual elemento deseja buscar?"); 
        scanf("%d", &seek);
        buscaBinaria(vet, tam, seek);
        break;
    case 3:
        puts("Saindo...");
        break;
    default:
        puts("Opção invalida  x_x");
        puts("Saindo...");
        break;
    }
}   // Fim do main

// Função para exibir o vetor ordenado e as quantidades de comparações e trocas
void exibirVet(int *vet, int tam, int *comp, int *troca)
{
    int i;
    puts("Vetor ordenado:");
    for(i = 0; i < tam; i++) {
        printf("%d | ", vet[i]);
    }
    printf("\nQuantidade de comparações: %d", *comp);
    printf("\nQuantidade de trocas: %d", *troca);
}// Fim da função exibirVet

// FUNÇÕES DE ORDENAÇÃO

//Implementação do método de ordenação Bubble Sort
void bubbleSort(int *vet, int tam, int *comp, int *troca)
{
    int i, aux;
    while (tam>0)
    {
        for(i=0;i<tam-1;i++)
        {
            if(vet[i] > vet[i+1])
            {
                (*troca)++;
                aux = vet[i+1];
                vet[i+1] = vet[i];
                vet[i] = aux;
            }
            (*comp)++;
        }
        tam--;
    }
}   //Fim do Bubble Sort
// Implementação do método de ordenação Selection Sort
void selectionSort(int *vet,int tam, int *comp, int *troca)
{
    int i, j,chave, aux, menor;
    for(i=0;i<tam-1;i++)
    {
        chave = menor = i;
        for ( j = i+1; j < tam; j++)
        {
            (*comp)++;
            if (vet[j] < vet[menor])
            {
                menor = j;
            }
        }
        if (vet[chave] > vet[menor])
        {
            (*troca)++;
            aux = vet[chave];
            vet[chave] = vet[menor];
            vet[menor] = aux;
        }
    }
}   // Fim do Selection Sort
// Implementação do método de ordenação Insertion Sort
void insertionSort(int *vet, int tam, int *comp, int *troca)
{
    int chave, j, i;
    for(i = 1; i < tam; i++)
    {
        chave = vet[i];
        j =i-1;
        while (j>=0 && vet[j]>chave)
        {
            (*comp)++;
            (*troca)++;
            vet[j+1] = vet[j];
            j--;
        }
        (*comp)++;
        vet[j+1] = chave;
        (*troca)++;   
    }
}   // Fim do Insertion Sort
// Implementação do método de ordenação Merge Sort
void mergeSort(int *vet, int inicio, int fim, int *comp)
{
    if(inicio<fim)
    {
        int meio = (inicio+fim)/2;
        mergeSort(vet,inicio,meio, comp);
        mergeSort(vet,meio+1,fim, comp);
        merge(vet,inicio, meio, fim, comp);
    }
}   // Fim do Merge Sort
// Função auxiliar do Merge Sort, que realiza a junção das sublistas de forma ordenada
void merge(int *vet, int inicio, int meio, int fim, int *comp)
{
    int dir, esq, i, tam;
    esq = inicio;
    dir = meio+1;
    tam = (fim-inicio) +1;
    int vetAux[tam];
    i = 0;
    while (esq<=meio && dir<=fim)
    {
        (*comp)++;
        if(vet[esq]<vet[dir])
        {
            vetAux[i] = vet[esq];
            esq++;
        }
        else
        {
            vetAux[i] = vet[dir];
            dir++;
        }
        i++;
    }
    while (esq<=meio)
    {
        vetAux[i] = vet[esq];
        esq++;
        i++;
    }
    while (dir<=fim)
    {
        vetAux[i] = vet[dir];
        dir++;
        i++;
    }
    for(i=inicio;i<=fim;i++)
    {
        vet[i] = vetAux[i-inicio];
    }
}   // Fim da função merge
// Função auxiliar do Heap Sort, que organiza a árvore binária de forma que o maior elemento fique na raiz
void heapfy(int *vet,int tam, int pai, int *comp, int *troca)
{
    int esq, dir;
    int maior = pai;
    esq=pai*2+1;
    dir=pai*2+2;
    if(esq<tam && vet[esq] > vet[maior])
    {
        (*comp)++;
        maior = esq;
    }
    if (dir<tam && vet[dir] > vet[maior])
    {
        (*comp)++;
        maior = dir;
    }
    if(maior != pai)
    {
        int aux = vet[pai];
        vet[pai] =vet[maior];
        vet[maior] = aux;
        (*troca)++;
        heapfy(vet,tam,maior, comp, troca);
    }
}   // Fim da função heapfy
// Implementação do método de ordenação Heap Sort
void heapSort(int *vet, int tam, int *comp, int *troca)
{
    int i;
    //Loop para construir a árvore binária inicialmente
    //A partir do meio do vetor, pois os elementos a direita já são folhas
    for(i=tam/2-1;i>=0;i--)
    {
        heapfy(vet,tam,i, comp, troca);
    }
    for (i=tam-1;i>0;i--)
    {
        int aux;
        (*troca)++;
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        heapfy(vet,i,0, comp, troca);
    }
}   // Fim do Heap Sort
// Implementação do método de ordenação Quick Sort
void quickSort(int *vet, int inicio, int fim, int *comp, int *troca){
    if (inicio<fim)
    {
        int pivot = partition(vet,inicio,fim, comp, troca);
        quickSort(vet,inicio,pivot-1, comp, troca);
        quickSort(vet,pivot+1,fim, comp, troca);
    }
}   // Fim do Quick Sort
// Função auxiliar do Quick Sort, que particiona o vetor em duas partes, uma com elementos menores que o pivô e outra com elementos maiores
int partition(int *vet, int inicio, int fim, int *comp, int *troca)
{
    int aux = 0;
    int esq = inicio;
    int dir = fim;
    int pivot = vet[inicio];
    while (esq < dir)
    {
        while (esq <= fim && vet[esq] <= pivot)
        {
            (*comp)++;
            esq++;
        }
        while (dir >= inicio && vet[dir] > pivot)
        {
            (*comp)++;
            dir--;
        }
        if(esq<dir)
        {
            (*troca)++;
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
        }
    }
    (*troca)++;
    aux = vet[dir];
    vet[dir] = vet[inicio];
    vet[inicio] = aux;
    return dir;
}   // Fim da função partition

// FUNÇÕES DE BUSCA

// Implementação da busca sequencial
void buscaSequencial(int *vet, int tam,int seek)
{
    int i, comp;
    i = comp = 0;
    while(tam){
        comp++;
        if(vet[i] == seek)
        {
        printf("\nElemento %d encontrado na possoção %d", seek, i+1);
        printf("\nQuantidade de comparações: %d", comp);
        break;
        }
        i++;
        tam--;
    }
    if(tam == 0)
    {
        printf("\nElemento não encontrado!");
        printf("\nQuantidade de comparações: %d", comp);
    }    
}   // Fim da função buscaSequencial
// Implementação da busca binária
void buscaBinaria(int *vet, int tam,int seek)
{
    int inicio, meio, flag, comp;
    int fim = tam-1;
    inicio = comp = flag = 0;
    while (flag!=1 && inicio<=fim)
    {   
        comp++;
        meio = (inicio+fim)/2;
        if (vet[meio] == seek)
        {
            flag = 1;
        }
        if(vet[meio] < seek)
        {
            inicio = meio+1;
        }
        else
        {
            fim = meio-1;
        }
    }
    if(flag == 1)
    {
        printf("Elemento %d encontrado na posição %d", seek, meio+1);
        printf("\nQuantidade de comparações: %d", comp);
    }
    else
    {
        printf("\nElemento não encontrado!");
        printf("\nQuantidade de comparações: %d", comp);
    }
}   // Fim da função buscaBinaria
// Fim do código BuscaOrdenação.cpp