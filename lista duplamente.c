#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

//LISTA DUPLAMENTE
//define a estrutura do nodo
typedef struct TipoNo{
    int valor;
    struct TipoNo *proximo;
    struct TipoNo *anterior;
}TNo;

// procedimento para inserir no início
void inserir_no_inicio(TNo **lista, int num){
    TNo *novo = malloc(sizeof(TNo));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        novo->anterior = NULL;
        if(*lista)
            (*lista)->anterior = novo;
        *lista = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim
void inserir_no_fim(TNo **lista, int num){
    TNo *aux, *novo = malloc(sizeof(TNo));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(*lista == NULL){
            *lista = novo;
            novo->anterior = NULL;
        }
        else{
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}
TNo* remover(TNo **lista, int num){
    TNo *aux, *remover = NULL;

    if(*lista){
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->proximo;
            if(*lista)
                (*lista)->anterior = NULL;
        }
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if(aux->proximo)
                    aux->proximo->anterior = aux;
            }
        }
    }
    return remover;
}
TNo* buscar(TNo **lista, int num){
    TNo *aux, *TipoNo = NULL;

    aux = *lista;
    while(aux && aux->valor != num)
        aux = aux->proximo;
    if(aux)
        TipoNo = aux;
    return TipoNo;
}

void imprimir(TNo *TipoNo){
    printf("\n\tLista: ");
    while(TipoNo){
        printf("%d ", TipoNo->valor);
        TipoNo = TipoNo->proximo;
    }
    printf("\n\n");
}

// retorna ponteiro para o último nó da lista
TNo* ultimo(TNo **lista){
    TNo *aux = *lista;
    while(aux->proximo)
        aux = aux->proximo;
    return aux;
}

// imprime a lista do fim para o início
// recebe um ponteiro para o último nó da lista
void imprimirContrario(TNo *TipoNo){
    printf("\n\tLista: ");
    while(TipoNo){
        printf("%d ", TipoNo->valor);
        TipoNo = TipoNo->anterior;
    }
    printf("\n\n");
}

int main(){

    int opcao, valor, anterior;
    TNo *removido, *lista = NULL;

    do{
        printf("Escolha alguma opcao:\n0 - Sair\n1 - Inserir no Inicio\n2 - inserir no Fim\n3 - Remover\n4 - Buscar\n5 - Imprimir\n6 - Imprimir Contrario da lista\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);break;
        case 3:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if(removido){
                printf("Elemento a ser removido: %d\n", removido->valor);
                free(removido);
            }
            else
                printf("Elemento inexistente!\n");break;
        case 4:
            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if(removido)
                printf("Elemento encontrado: %d\n", removido->valor);
            else
                printf("Elemento nao encontrado!\n");break;
        case 5:
            imprimir(lista);break;
            
        case 6:
            imprimirContrario(ultimo(&lista));break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}