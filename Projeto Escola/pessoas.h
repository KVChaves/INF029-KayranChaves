#ifndef PESSOAS_H_
#define PESSOAS_H_

#include "structs.h"
#include "extras.h"

#define n 50
#define completado 1

int cadastro(cadPessoas vet[], int num);
void listar(cadPessoas vet[], int num);
int atualizar(cadPessoas vet[], int num);
int excluir(cadPessoas vet[], int num);

#endif