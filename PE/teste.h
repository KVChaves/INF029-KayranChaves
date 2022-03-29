#ifndef TESTE_H_
#define TESTE_H_
#include "structs.h"

#define n 50
#define completado 1

int menuprincipal();
int menuAlunos();
int menuProf();
int menuDis();
int menuRel();

int cadastro(cadPessoas vet[], int num);
void listar(cadPessoas vet[], int num);
int atualizar(cadPessoas vet[], int num);
int excluir(cadPessoas vet[], int num);

int cadastrodis(cadDis vet[], cadPessoas vet2[], int num, int num2);
void listardis(cadDis vet[], int num);
int atualizardis(cadDis vet[], int num, cadPessoas vet2[], int num2);
int excluirdis(cadDis vet[], cadPessoas vet2[], aldis mat[][n], int num, int num2);
int incluiraluno (aldis mat[][n], cadDis vet[],  cadPessoas vet2[], int num, int num2);
int excluiraluno (aldis mat[][n], cadDis vet[],  cadPessoas vet2[], int num, int num2);
void listarDCA(cadDis vet[], int num, aldis mat[][n], cadPessoas vet2[], int num2);

void sexo(cadPessoas vet[], int num);
void alfabetica(cadPessoas vet[], int num);
void aniversarios(cadPessoas vet[], cadPessoas vet2[], int num, int num2);
void numvagas(aldis mat[][n], cadDis vet[], int num);
void busca(cadPessoas vet[], cadPessoas vet2[], int num, int num2);
void menos3mat(cadPessoas vet[], int num);

#endif