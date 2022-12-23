#include <stdio.h>
void CountSort();
int main(){
    int V[6]={1,4,2,6,3,10};
    int T=sizeof(V)/ sizeof(V[0]);
    CountSort(V,T);
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
