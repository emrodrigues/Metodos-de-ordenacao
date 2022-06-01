//Trabalho Estrutura de Dados em C - 2022.1
//Emanoel de Lima Rodrigues - 202005004021
//Professor Rafael Araujo

//========================================================
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define V_SIZE 100      //tamanho do vetor
#define MAX_VALUE 99    //valor máximo dos elementos
//----------------------------------------------------------

int vector[V_SIZE];

//funções auxiliares ======================================
//irá copiar o vetor inicial para um novo, assim não organizará o original
void copyVector(int *copiedvector)
{
    int i;
    for(i = 0; i < V_SIZE; i++)
        copiedvector[i] = vector[i];
}
//--------------------------------
//função dedicada a exibir um vetor
void printVector(int *tempvector)
{
    int i;
    for(i = 0; i< V_SIZE; i++)
        if(i < V_SIZE-1) printf("%d ", tempvector[i]);
        else printf("%d.", tempvector[i]); 
}
//--------------------------------
//função com único propósito de preencher o vetor
void fillVector()
{
    int i;
    for(i = 0; i<V_SIZE; i++)
        vector[i] = rand()%(MAX_VALUE+1);
}
//fim das funções auxiliares ====================================

// funções de ordenação ==================================
void bubbleSort()
{
    printf("\n\nbubble sort: \n");
    int temp, i, j;
    int bubblevector[V_SIZE];

    //crescente
    copyVector(bubblevector);
    for(i=0; i<V_SIZE; i++)
    {
        for(j=0; j<V_SIZE-1; j++)
        {
            if(bubblevector[j] > bubblevector[j+1])
            {
                temp = bubblevector[j];
                bubblevector[j] = bubblevector[j+1];
                bubblevector[j+1] = temp;
            }
        }
    }
    printf("crescente: ");
    printVector(bubblevector);

    //decrescente -- eu sei que poderia apenas inverter a função já ordenada, mas a graça é reordenar em decrescente :)
    copyVector(bubblevector);
    for(i=V_SIZE-1; i>= 0; i--)
    {
        for(j=V_SIZE-2; j>=0; j--)
        {
            if(bubblevector[j] < bubblevector[j+1])
            {
                temp = bubblevector[j];
                bubblevector[j] = bubblevector[j+1];
                bubblevector[j+1] = temp;
            }
        }
    }
    printf("\ndecrescente: ");
    printVector(bubblevector);
}
//----------------------------------------------------------
void insertionSort()
{
    printf("\n\nInsertion sort: \n");
    int i, j;
    int insertionVector[V_SIZE];

    //crescente
    copyVector(insertionVector);
    for(i=1; i<V_SIZE; i++)
    {
        int hold = insertionVector[i];
        j = i-1;
        while (j >= 0 && insertionVector[j] > hold)
        {
            insertionVector[j+1] = insertionVector[j];
            j -= 1;
        }
        insertionVector[j+1] = hold;
    }
    printf("crescente: ");
    printVector(insertionVector);

    //decrescente
    copyVector(insertionVector);
    for(i=1; i<V_SIZE; i++)
    {
        int hold = insertionVector[i];
        j = i-1;
        while (j >= 0 && insertionVector[j] < hold)
        {
            insertionVector[j+1] = insertionVector[j];
            j -= 1;
        }
        insertionVector[j+1] = hold;
    }
    printf("\ndecrescente: ");
    printVector(insertionVector);
}
//----------------------------------------------------------
void selectionSort()
{
    printf("\n\nSelection sort: \n");
    int i, j;
    int selectionVector[V_SIZE];

    //crescente
    copyVector(selectionVector);
    for(i=0; i<V_SIZE-1; i++)
    {
        int min = i;
        for(j=i+1; j<V_SIZE; j++)
        {
            if(selectionVector[j] < selectionVector[min])
                min = j;
        }
        if(min != i)
        {
            int aux = selectionVector[i];
            selectionVector[i] = selectionVector[min];
            selectionVector[min] = aux;
        }
    }
    printf("crescente: ");
    printVector(selectionVector);

    //decrescente
    copyVector(selectionVector);
    for(i=0; i<V_SIZE-1; i++)
    {
        int max = i;
        for(j=i+1; j<V_SIZE; j++)
        {
            if(selectionVector[j] > selectionVector[max])
                max = j;
        }
        if(max != i)
        {
            int aux = selectionVector[i];
            selectionVector[i] = selectionVector[max];
            selectionVector[max] = aux;
        }
    }
    printf("\ndecrescente: ");
    printVector(selectionVector);
}
// fim das funções de ordenação ===================================
void main()
{
    srand(time(NULL));

    fillVector();
    printf("Original: \n");
    printVector(vector);
    bubbleSort();  
    insertionSort();
    selectionSort();
    printf("\n\n");
    //system("pause");
}