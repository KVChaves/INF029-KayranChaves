#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "structs.h"
#include "pessoas.h"
#include "extras.h"

#define n 50
#define completado 1

int cadastro(cadPessoas vet[], int num)
{
    int tcpf, tam, teste = 1, tesmat = 1, tescpf = 1, i;

    while(tesmat > 0){
      printf("Digite o número de Matrícula: ");
      scanf("%d", &vet[num].matricula);
      getchar();
      
      tesmat = 0;
      for(i=0;i<num;i++){
        if(vet[num].matricula == vet[i].matricula){
          tesmat++;
        }
      }
    }

    printf("Digite o nome completo: ");
    fgets(vet[num].nome, 40, stdin);
    size_t ln = strlen(vet[num].nome) - 1;
    if (vet[num].nome[ln] == '\n')
        vet[num].nome[ln] = '\0';

    while(teste != 0){
      printf("Digite o sexo (M/F): ");
      fgets(vet[num].sexo, 2, stdin);
      ln = strlen(vet[num].sexo) -1;
      if (vet[num].sexo[ln] == '\n')
          vet[num].sexo[ln] = '\0';
      
      teste = strcmp(vet[num].sexo,"M");
        if(teste != 0){
          teste = strcmp(vet[num].sexo,"F");
        }
      if(teste != 0){
        printf("Sexo Inválido.\n");
      }
    }

    printf("Digite a data de nascimento:\n");
    printf("Ano: ");
    scanf("%d", &vet[num].data.ano);
  
    while(vet[num].data.ano < 1910){
      printf("Inválido.\nAno: ");
      scanf("%d", &vet[num].data.ano);
    }

    printf("Mês: ");
    scanf("%d",&vet[num].data.mes);
    while(vet[num].data.mes>12){
      printf("Inválido.\nMês: ");
      scanf("%d",&vet[num].data.mes);
    } 

    printf("Dia: ");
    scanf("%d",&vet[num].data.dia);

    if(vet[num].data.mes==4||6||9||11)
    {
      while(vet[num].data.dia>30){
        printf("Inválido.\nDia: ");
        scanf("%d",&vet[num].data.dia);
      } 
    }
    if(vet[num].data.mes==1||3||5||7||8||10||12)
    {
      while(vet[num].data.dia>31){
        printf("Inválido.\nDia: ");
        scanf("%d",&vet[num].data.dia);
      }
    }
    else{
      while(vet[num].data.dia>29){
        printf("Inválido.\nDia: ");
        scanf("%d",&vet[num].data.dia);
      }
    }
    getchar();

    while(tescpf > 0){
      while(tam != 11){
      printf("Digite o CPF: ");
      fgets(vet[num].cpf, 15, stdin);
      ln = strlen(vet[num].cpf) - 1;
      if (vet[num].cpf[ln] == '\n')
          vet[num].cpf[ln] = '\0';
        
      tam = strlen(vet[num].cpf);
        
      tescpf = 0;
      for(i=0;i<num;i++){
        tcpf = strcmp(vet[num].cpf, vet[i].cpf);
        if(tcpf == 0){
          tescpf++;
        }
      }
      }
    }

      vet[num].dismat = 0;


    __fpurge(stdin);

    return completado;
}

void listar(cadPessoas vet[], int num)
{
    printf("\n*******************");
    for (int i = 0; i < num; i++)
    {
        printf("\n----------\n");
        printf("Nome: %s\n", vet[i].nome);
        printf("Matricula: %d\n", vet[i].matricula);
        printf("CPF: %s\n", vet[i].cpf);
        printf("Sexo: %s\n", vet[i].sexo);
        printf("Data: %d-%d-%d \n", vet[i].data.dia,vet[i].data.mes,vet[i].data.ano);
    }
    printf("\n*******************");

  __fpurge(stdin);
}

int atualizar(cadPessoas vet[], int num)
{
  int i, ndm, tam, teste = 1, tcpf, tescpf = 1, ndp, conf = 0;

  ndp = descpes(vet, num);
  
    printf("\nDigite a nova matrícula: ");
    scanf("%d", &vet[ndp].matricula);
    getchar();

    printf("Digite o nome: ");
    fgets(vet[ndp].nome, 40, stdin);
    size_t ln = strlen(vet[ndp].nome) - 1;
    if (vet[ndp].nome[ln] == '\n')
        vet[ndp].nome[ln] = '\0';

    while(teste != 0){
      printf("Digite o sexo (M/F): ");
      fgets(vet[ndp].sexo, 2, stdin);
      ln = strlen(vet[ndp].sexo) -1;
      if (vet[ndp].sexo[ln] == '\n')
          vet[ndp].sexo[ln] = '\0';
      
      teste = strcmp(vet[ndp].sexo,"M");
        if(teste != 0){
          teste = strcmp(vet[ndp].sexo,"F");
      }
      if(teste != 0){
        printf("Sexo Inválido.\n");
      }
    }

printf("Digite a data de nascimento:\n");
    printf("Ano: ");
    scanf("%d", &vet[ndp].data.ano);
  
    while(vet[ndp].data.ano < 1910){
      printf("Inválido.\nAno: ");
      scanf("%d", &vet[ndp].data.ano);
    }

    printf("Mês: ");
    scanf("%d",&vet[ndp].data.mes);
    while(vet[ndp].data.mes>12){
      printf("Inválido.\nMês: ");
      scanf("%d",&vet[ndp].data.mes);
    } 

    printf("Dia: ");
    scanf("%d",&vet[ndp].data.dia);

    if(vet[ndp].data.mes==4||6||9||11)
    {
      while(vet[ndp].data.dia>30){
        printf("Inválido.\nDia: ");
        scanf("%d",&vet[ndp].data.dia);
      } 
    }
    if(vet[ndp].data.mes==1||3||5||7||8||10||12)
    {
      while(vet[ndp].data.dia>31){
        printf("Inválido.\nDia: ");
        scanf("%d",&vet[ndp].data.dia);
      }
    }
    else{
      while(vet[ndp].data.dia>29){
        printf("Inválido.\nDia: ");
        scanf("%d",&vet[ndp].data.dia);
      }
    }
    getchar();
  
    while(tescpf > 0){
      while(tam != 11){
      printf("Digite o CPF: ");
      fgets(vet[ndp].cpf, 15, stdin);
      ln = strlen(vet[ndp].cpf) - 1;
      if (vet[ndp].cpf[ln] == '\n')
          vet[ndp].cpf[ln] = '\0';
        
      tam = strlen(vet[ndp].cpf);
        
      tescpf = 0;
      for(i=0;i<num;i++){
        tcpf = strcmp(vet[ndp].cpf, vet[i].cpf);
        if(tcpf == 0){
          tescpf++;
        }
      }
      }
    }

    __fpurge(stdin);
    
    return completado;
  }

int excluir(cadPessoas vet[], int num)
{
  int i, ndp, ndm, conf = 0;

  ndp = descpes(vet, num);

  for(ndp;ndp<num-1;ndp++){
    vet[ndp] = vet[ndp+1];
  }
  
  cadPessoas *ptr;
  ptr = &vet[num-1];
  ptr = NULL;

    __fpurge(stdin);
    printf("\nDados excluídos com sucesso.");
    return completado;
  }