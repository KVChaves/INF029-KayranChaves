#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "structs.h"
#include "relatorios.h"

#define n 50
#define completado 1

void sexo(cadPessoas vet[], int num)
{
  int i, teste;
  printf("\nMulheres Cadastradas no Sistema:\n");
  for(i=0;i<num;i++){
    teste = strcmp(vet[i].sexo, "F");
    if(teste == 0){
      printf("\n- %s",vet[i].nome);
    }
  }
  printf("\n--------------------\nHomens Cadastrados no Sistema:\n");
  for(i=0;i<num;i++){
    teste = strcmp(vet[i].sexo, "M");
    if(teste == 0){
      printf("\n- %s",vet[i].nome);
    }
  }
}

void alfabetica(cadPessoas vet[], int num)
{
  cadPessoas alfabetica[n];
  int i, j, k;
  char aux[50];

  for(i=0;i<num;i++){
    strcpy(alfabetica[i].nome, vet[i].nome);
  }
  
  printf("\nNomes em Ordem Alfabética:\n\n");
  for(i=0;i<num;i++){
    for(j = i+1; j < num; j++){
      k = strcmp(alfabetica[i].nome, alfabetica[j].nome);
      if(k > 0){
        strcpy(aux, alfabetica[i].nome);
        strcpy(alfabetica[i].nome, alfabetica[j].nome);
        strcpy(alfabetica[j].nome, aux);
      }
    }
  }
  for(i = 0; i < num; i++){
    printf("- %s\n", alfabetica[i].nome);
  }
}      

void aniversarios(cadPessoas vet[], cadPessoas vet2[], int num, int num2)
{
  int mes, i;
  printf("Informe o mês: \n");
  scanf("%d",&mes);

  printf("Anivérsariantes do Mês %d:\n\n",mes);
  for(i=0;i<num;i++){
    if(vet[i].data.mes == mes){
      printf("- %s \n",vet[i].nome);
    }
  }
  for(i=0;i<num2;i++){
    if(vet2[i].data.mes == mes){
      printf("- %s \n",vet2[i].nome); 
    }
}
}

void numvagas(aldis mat[][n], cadDis vet[], int num)
{
  int i, val, vagas;
  printf("\nDisciplians com Mais de 40 Vagas:\n");
  for(i=0;i<num;i++){
    val = mat[i][0].numA;
    vagas = n - val;
    vagas++;
    if(vagas > 40){
      printf("\nDisciplina: %s\n",vet[i].nomeDis);
      printf("Professor: %s\n",vet[i].profDis);
      printf("Vagas: %d\n",vagas);
    }
  }
}

void busca(cadPessoas vet[], cadPessoas vet2[], int num, int num2)
{
  int i;
  char strbusca[10], *ponteiro;

  printf("\nInsira de 3 à 10 letras para a pesquisa:\n");
  fgets(strbusca, 10, stdin);
  size_t ln = strlen(strbusca) - 1;
  if (strbusca[ln] == '\n')
      strbusca[ln] = '\0';

  for(i=0;i<num;i++){
    ponteiro = strstr(vet[i].nome, strbusca);
    if(ponteiro){
      printf("- %s\n",vet[i].nome);
    }
  }
  for(i=0;i<num2;i++){
    ponteiro = strstr(vet2[i].nome, strbusca);
    if(ponteiro){
      printf("- %s\n",vet2[i].nome);
    }
  }
  
}

void menos3mat(cadPessoas vet[], int num)
{
  printf("\nAlunos Matriculados em Menos de 3 Disciplinas:\n\n");
  
  int i;
  
  for(i=0;i<num;i++)
    if(vet[i].dismat < 3){
      printf("- %s\n",vet[i].nome);
    }
}