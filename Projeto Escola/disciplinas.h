#ifndef DISCIPLINAS_H_
#define DISCIPLINAS_H_

#include "structs.h"
#include "extras.h"

#define n 50
#define completado 1

int cadastrodis(cadDis vet[], cadPessoas vet2[], int num, int num2);
void listardis(cadDis vet[], int num);
int atualizardis(cadDis vet[], int num, cadPessoas vet2[], int num2);
int excluirdis(cadDis vet[], cadPessoas vet2[], aldis mat[][n], int num, int num2);
int incluiraluno (aldis mat[][n], cadDis vet[],  cadPessoas vet2[], int num, int num2);
int excluiraluno (aldis mat[][n], cadDis vet[],  cadPessoas vet2[], int num, int num2);
void listarDCA(cadDis vet[], int num, aldis mat[][n], cadPessoas vet2[], int num2);

#endif