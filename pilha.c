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

void empilhar();
void listar();
int tamanho();
void retirar();

int main()
{
    int op;
    
    while(op != 4){
        printf("Pilha simplesmente encacadeada\n");
        printf("Informe a opcao desejada:\n");
        printf("1-Empilhar\n");
        printf("2-Retirar\n");
        printf("3-Exibir Todos\n");
        printf("4-Sair\n");
        
        scanf("%d", &op) ;
        switch(op){
            case 1:
                empilhar();break;
            case 2:
                retirar();break;
            case 3:
                listar();break;
        }
    }
    return 0;
}
void empilhar(){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    printf("Informe um numero: ");
    scanf("%d", &novo->numero);
   
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
        fim->proximo = NULL;
    }else{ //se a pilha nao estiver vazia
        novo->proximo = inicio;
        inicio = novo; 
    }
    
    printf("\nNumero Empilhado!\n");
}
void retirar(){
    if (inicio == NULL)
    {
        printf("\nPilha Vazia!\n");
    }else
    {
        printf("\nElemento %d retirado!\n", inicio->numero);
        inicio = inicio->proximo;
    }
}
void listar(){   
    if(inicio==NULL){
        printf("\nPilha vazia!\n");
    }else{
        aux = inicio;
        printf("\nPILHA: \n");
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