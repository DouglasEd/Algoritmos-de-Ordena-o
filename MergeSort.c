#include <stdio.h>
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
int main(){
    int r, i=0;
    printf("Qual o tamanho do vetor?");
    scanf("%d",&r);
    int A[r];
    while (i<r){
        scanf("%d",&A[i]);
        i++;
    }

    mergesort(A,0,sizeof(A) / sizeof(A[0])-1);
    printArray(A,sizeof(A) / sizeof(A[0]));
    system("pause");
}
