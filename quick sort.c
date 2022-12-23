#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int main()
{
	int vet[] = {25,40,55,20,44,35,38,99,10,65,50};
	int tam_vet = sizeof(vet) / sizeof(int);
	int i;
	quick_sort(vet, 0, tam_vet - 1);
	for(i = 0; i < tam_vet; i++)
		printf("%d ", vet[i]);

	return 0;
}
