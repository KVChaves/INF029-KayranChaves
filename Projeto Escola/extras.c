#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "structs.h"
#include "extras.h"

#define n 50
#define completado 1

int descdis(cadDis vet[], int num)
{
  int teste, i, ndd = -1, conf = 0;
  char codigo[10];
  
  while(conf == 0){
  printf("\nInforme o código da disciplina: ");
  fgets(codigo, 10, stdin);
  size_t ln = strlen(codigo) - 1;
  if (codigo[ln] == '\n')
      codigo[ln] = '\0';

  conf = 0;
  for(i=0;i<num;i++){
    teste = strcmp(vet[i].codDis, codigo);
    ndd++;
    if(teste == 0){
      conf++;
      i = num;
    }
  }
    }

  return ndd;
}

int descpes(cadPessoas vet[], int num)
{
  int conf = 0, ndm, i, ndp = -1;
  
  while(conf == 0){
  printf("\nInforme a matrícula da pessoa: ");
  scanf("%d",&ndm);
  getchar();

  conf = 0;
  for(i=0;i<num;i++){
    ndp++;
    if(vet[i].matricula == ndm){
      conf++;
      i = num;
    }
  }
    }

  return ndp;
}