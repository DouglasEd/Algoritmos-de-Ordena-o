#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

//LISTA CIRCULAR
//define a estrutura do nodo
typedef struct TipoNo
{
    int info;
    struct TipoNo *prox;
}TNo;

//cria o inicio da lista
typedef struct TipoLista
{
    TNo *inicio;
    TNo *fim;
}TLista;

//funcao que define a lista como vazia
void inicializarLista(TLista *pLista)
{
    pLista->inicio = NULL;
    pLista->fim = NULL;
}

//funcao que insere um elemento do inicio da lista
void inserir(TLista *pLista)
{
    TNo *novoElemento;
    
    novoElemento = (TNo*)malloc(sizeof(TNo));
    
    printf("\n Informe um valor para lista circular: ");
    scanf("%d", &novoElemento->info);
    novoElemento->prox = NULL;
    
    if (pLista->inicio == NULL)
    {
        pLista->inicio = novoElemento;
    }else
    {
        pLista->fim->prox = novoElemento;
    }
    pLista->fim = novoElemento;
    novoElemento->prox = pLista->inicio;
}

//funcao que imprime toda a lista
void apresentar(TLista *pLista)
{
    TNo *aux;
    if (pLista->inicio == NULL)
    {
        printf("-----fim da lista-----\n\n");
        return;
    }else //caso a lista nao esteja vazia
    { 
     aux = pLista->inicio;
     
     do {
         printf("\nInfo = %d", aux->info);
         aux = aux->prox;
     }while (aux != pLista->inicio);
     
     printf("\n-----fim da lista-----\n\n");
     getch();
  }
 }
//funcao que busca um elemento na lista
void consultar(TLista *pLista)
{
    if (pLista->inicio == NULL)
    {
        printf("---fim da lista\n\n");
    }else
    {
       TNo *aux;
       int pesquisa;
       int achou = 0;
       
       printf("\nInforme o dado a ser pesquisado: ");
       scanf("%d", &pesquisa);
       
       aux = pLista->inicio;
       do{
           if (aux->info == pesquisa) //achou
        {
            printf("+++Achou o %d\n", aux->info);
            achou = 1;
        }else
        {
            aux = aux->prox;
       }
       }while (aux != pLista->inicio && achou == 0);
       if (achou == 0)
       {
           printf("\n Valor nao encontrado");
       }
       getch();
    }
}
//funcao que remove um elemento especificado
void excluir(TLista *pLista)
{
    if (pLista->inicio == NULL)
    {
        printf("---fim da lista---");
    }else
    {
        TNo *atual, *anterior;
        int pesquisa;
        
        printf("\nInforme o dado a ser excluido: ");
        scanf("%d", &pesquisa);
        
        //caso a lista nao esteja vazia
        atual = pLista->inicio;
        anterior = pLista->inicio;
        
        do{
            if (atual->info == pesquisa)
            {
                //se o elemento esta no inicio da lista
                if (atual == pLista->inicio)
                {
                    pLista->inicio = atual->prox;
                    pLista->fim->prox = atual->prox;
                    free(atual);
                    break;
                }else //caso nao seja o primeiro elemento
                {
                    anterior->prox = atual->prox;
                    if (atual == pLista->fim) //caso seja o ultimo elemento
                    {
                        pLista->fim = anterior;
                    }
                    free(atual);
                    break;
                }
            }else
            {
                anterior = atual;
                atual = atual->prox;
            }
        }while (atual != pLista->inicio);
    }
}
//programa principal
int main()
{
    int opcao;
    
    TLista listaCircular;
    
    inicializarLista(&listaCircular);
    
    do{
        printf("\nOpcoes: \n\n");
        printf("1 - Inserir novo numero \n");
        printf("2 - Consultar numero \n");
        printf("3 - Remover numero \n");
        printf("4 - Listar todos os numeros \n");
        printf("0 - Para sair \n\n");
        printf("Entre com sua opcao: ");
        scanf("%d", &opcao); //le a opcao do usuario
        switch (opcao)
        {
            case 1: inserir(&listaCircular); break;
            case 2: consultar(&listaCircular); break;
            case 3: excluir(&listaCircular); break;
            case 4: apresentar(&listaCircular); break;
            case 0: break;
            default: printf("\n\nOpcao invalida"); getch(); break;
        }
    }while (opcao != 0);
}