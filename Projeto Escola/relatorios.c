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

void nascimento(cadPessoas vet[], int num)
{
  cadPessoas nascimento[n], aux;
  int i, j, k;

  for(i=0;i<num;i++){
    nascimento[i].data = vet[i].data;
  }
  
  for(i=0;i<num;i++){
    for(j = i+1; j < num; j++){
      if(nascimento[i].data.dia > nascimento[j].data.dia){
        aux.data = nascimento[i].data;
        nascimento[i].data = nascimento[j].data;
        nascimento[j].data = aux.data;
        i=0;
      }
    }
  }
  for(i=0;i<num;i++){
    for(j = i+1; j < num; j++){
      if(nascimento[i].data.mes > nascimento[j].data.mes){
        aux.data = nascimento[i].data;
        nascimento[i].data = nascimento[j].data;
        nascimento[j].data = aux.data;
        i=0;
      }
    }
  }
  for(i=0;i<num;i++){
    for(j = i+1; j < num; j++){
      if(nascimento[i].data.ano > nascimento[j].data.ano){
        aux.data = nascimento[i].data;
        nascimento[i].data = nascimento[j].data;
        nascimento[j].data = aux.data;
        i=0;
      }
    }
  }

  printf("\nMembros Ordenados por Data de Nascimento:\n\n");

  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      if(nascimento[i].data.dia == vet[j].data.dia){
        if(nascimento[i].data.mes == vet[j].data.mes){
          if(nascimento[i].data.ano == vet[j].data.ano){
            printf("\n----------\n");
            printf("Nome: %s\n",vet[j].nome);
            printf("Data: %d-%d-%d\n",vet[j].data.dia,vet[j].data.mes,vet[j].data.ano);
          }
        }
      }
    }
  }
}