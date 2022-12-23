#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
void merge(int array[],int I,int M,int F){
    int i, j, k, n1 = M - I + 1, n2 = F - M;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[I + i];
    for (j = 0; j < n2; j++)
        R[j] = array[M + 1 + j];
    i = 0;
    j = 0;
    k = I;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int array[],int I,int F){
    int M;
    if (I<F){
    M=(I+F)/2;
    mergesort(array,I,M);
    mergesort(array,M+1,F);
    merge(array,I,M,F);}
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void CountSort(int V[],int T){
    int m=V[0];
    for(int i=1;i<T;i++){
        if (V[i]>m)
            m=V[i];
    }
    m++;
    int A[m],B[m],C[m],Au[T];
    for(int i=0;i<m;i++){
        A[i]=0;
        B[i]=0;
        C[i]=0;
    }
    for(int i=0;i<T;i++){
        A[V[i]]++;
    }
    B[0]=A[0];
    for(int i=1;i<m;i++){
        B[i]=A[i]+B[i-1];
    }
    for(int i=0;i<m;i++){
        C[i]=B[i]-A[i];
    }
    for(int i=0;i<T;i++){
        Au[C[V[i]]]=V[i];
        C[V[i]]++;
    }
    for(int i=0;i<T;i++){
        V[i]=Au[i];
    }
}
int particiona(int vet[], int inicio, int fim)
{
	int pivo, pivoI, i;
	pivo = vet[fim];
	pivoI = inicio;
	for(i = inicio; i < fim; i++)
	{
		if(vet[i] <= pivo)
		{
			troca(vet, i, pivoI);
			pivoI++;
		}
	}
	troca(vet, pivoI, fim);
	return pivoI;
}
void troca(int vet[], int i, int j)
{
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

int particiona_random(int vet[], int inicio, int fim)
{
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	troca(vet, pivo_indice, fim);
	return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim)
{
	if(inicio < fim)
	{
		int pivoI = particiona_random(vet, inicio, fim);

		quick_sort(vet, inicio, pivoI - 1);
		quick_sort(vet, pivoI + 1, fim);
	}
}
void swap(int *a, int *b) {

  int temp = *a;

  *a = *b;

  *b = temp;

}
void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}
void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

int main(){
    int V[10],op;
    for(int i=0;i<10;i++){
        printf("Numero %d:",i);
        scanf("%d",&V[i]);
    }
    int T=sizeof(V)/ sizeof(V[0]);
    printf("ESCOLHA DE QUE FORMA VOCE GOSTARIA DE ORDENAR A ARRAY\n");
    printf("[1]CountSort\n");
    printf("[2]HeapSort\n");
    printf("[3]QuickSort\n");
    printf("[4]MergeSort\n");
    scanf("%d",&op);
    switch(op){
        case 1:
            CountSort(V,T);
            printArray(V,T);
            break;
        case 2:
            heapSort(V,T);
        case 3:
            quick_sort(V,0,T-1);
            printArray(V,T);
            break;
        case 4:
            mergesort(V,0,sizeof(V) / sizeof(V[0])-1);
            printArray(V,T);
            break;
        default:
            printf("Nao ta nas opcoes \n \n KRL \n \n");
            break;
    }
    system("Pause");
}
