#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
   
    int numero;
    
    struct Lista *proximo;
}Lista;

Lista *novo;
Lista *inicio;
Lista *fim;
Lista *aux;

void enfileirar();
void exibir();
int tamanho();
void retirar();

void enfileirar(){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    printf("Informe um numero: ");
    scanf("%d", &novo->numero);
   
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
        fim->proximo = NULL;
    }else{ //se a fila nao estiver vazia
        fim->proximo = novo;
        fim = novo;
        fim->proximo = NULL;
    }
    
    printf("\nNumero enfileirado!\n");
}
void retirar(){
    if (tamanho == 0)
    {
        printf("\nFila vazia!\n");
    }else
    {
        aux = inicio;
        inicio = inicio->proximo;
        printf("\nElemento %d removido da fila!\n", aux->numero);
    }
}
void exibir(){   
    if(inicio==NULL){
        printf("\nFila vazia!\n");
    }else{
        aux = inicio;
        printf("\nFILA:\n");
        while(aux!=NULL){
            printf("|%d|\n", aux->numero);
            aux = aux->proximo;
        }
        printf("\n");
    }
}
int tamanho(){
    int contador = 0;
    aux = inicio;
    while (aux != NULL) {
        aux = aux->proximo;
        contador++;
    }
    
    return contador;
}
int main()
{
    int op;
    
    while(op != 4){
        printf("\nFila simplesmente encacadeada\n");
        printf("Informe a opcao desejada:\n");
        printf("1-Enfileirar\n");
        printf("2-Remover da fila\n");
        printf("3-Exibir Todos\n");
        printf("4-Sair\n");
        
        scanf("%d", &op) ;
        switch(op){
            case 1:
                enfileirar();break;
            case 2:
                retirar();break;
            case 3:
                exibir();break;
        }
    }
    return 0;
}