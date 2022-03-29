#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "structs.h"
#include "disciplinas.h"
#include "extras.h"

#define n 50
#define completado 1

int cadastrodis(cadDis vet[], cadPessoas vet2[], int num, int num2)
{

  int i, teste;
  
  printf("Digite o semestre da disciplina: ");
  scanf("%d", &vet[num].semDis);
  getchar();
  
  printf("Digite o nome do disciplina: ");
  fgets(vet[num].nomeDis, 40, stdin);
  size_t ln = strlen(vet[num].nomeDis) - 1;
  if (vet[num].nomeDis[ln] == '\n')
      vet[num].nomeDis[ln] = '\0';

  printf("Digite o código da disciplina: ");
  fgets(vet[num].codDis, 10, stdin);
  ln = strlen(vet[num].codDis) -1;
  if (vet[num].codDis[ln] == '\n')
      vet[num].codDis[ln] = '\0';

  printf("Insira o nome do professor: ");
  fgets(vet[num].profDis, 40, stdin);
  ln = strlen(vet[num].profDis) -1;
  if (vet[num].profDis[ln] == '\n')
      vet[num].profDis[ln] = '\0';

  for(i=0;i<num2;i++){
    teste = strcmp(vet[num].profDis,vet2[i].nome);
    if(teste == 0){
      i=num2;
    }
    }
  if(teste!=0){
    printf("\nERRO: Professor não encontrado.");
    }
  else{
    __fpurge(stdin);
    return completado;
  }
}

void listardis(cadDis vet[], int num)
{
      printf("\n*******************\n");
      for (int i = 0; i < num; i++)
    {
        printf("----------\n");
        printf("Nome: %s\n", vet[i].nomeDis);
        printf("Código: %s\n", vet[i].codDis);
        printf("Semestre: %d\n", vet[i].semDis);
        printf("Professor: %s\n", vet[i].profDis);
    }
      printf("\n*******************");
}

void listarDCA(cadDis vet[], int num, aldis mat[][n], cadPessoas vet2[], int num2)
{
  int i, tam, teste, ndd, ndp, conf = 0;
  char codigo[10];

  ndd = descdis(vet, num);
  
        printf("----------\n");
        printf("Nome: %s\n", vet[ndd].nomeDis);
        printf("Código: %s\n", vet[ndd].codDis);
        printf("Semestre: %d\n", vet[ndd].semDis);
        printf("Professor: %s\n", vet[ndd].profDis);

  printf("\nAlunos Matriculados:\n\n");
  tam = mat[ndd][0].numA;
  for(i=1;i<tam;i++){
    printf("- %s\n",mat[ndd][i].nomeA);
  }
}

int atualizardis(cadDis vet[], int num, cadPessoas vet2[], int num2)
{ 
  int i, teste, ndd, conf = 0;
  int nddm=num-1;
  char codigo[10];

  ndd = descdis(vet, num);
  
    printf("Digite o semestre da disciplina: ");
    scanf("%d", &vet[ndd].semDis);
    getchar();
    
    printf("Digite o nome do disciplina: ");
    fgets(vet[ndd].nomeDis, 40, stdin);
    size_t ln = strlen(vet[ndd].nomeDis) - 1;
    if (vet[ndd].nomeDis[ln] == '\n')
        vet[ndd].nomeDis[ln] = '\0';

    printf("Digite o código da disciplina: ");
    fgets(vet[ndd].codDis, 10, stdin);
    ln = strlen(vet[ndd].codDis) -1;
    if (vet[ndd].codDis[ln] == '\n')
        vet[ndd].codDis[ln] = '\0';

    printf("Insira o nome do professor: ");
    fgets(vet[ndd].profDis, 40, stdin);
    ln = strlen(vet[ndd].profDis) -1;
    if (vet[ndd].profDis[ln] == '\n')
        vet[ndd].profDis[ln] = '\0';

  for(i=0;i<num2;i++){
    teste = strcmp(vet[ndd].profDis,vet2[i].nome);
    if(teste == 0){
      i=num2;
    }
    }
  if(teste!=0){
    printf("\nERRO: Professor não encontrado.");
    }
  else{
    __fpurge(stdin);

    printf("\nDados atualizados com sucesso.");
    return completado;
  }
  }

int excluirdis(cadDis vet[], cadPessoas vet2[], aldis mat[][n], int num, int num2)
{ 
  
  int i, ndd, teste, conf = 0;
  int nddm=num-1;
  char codigo[10];

  ndd = descdis(vet, num);

  //------------------
  int teste2, tam, j;

  tam = mat[ndd][0].numA;
  
  for(i=0;i<num2;i++){
    for(j=1;j<tam;j++){
      teste2 = strcmp(mat[ndd][j].nomeA, vet2[i].nome);
       if(teste2 == 0){
         vet2[j].dismat--;
  }
    }
    }
  //------------------
  
  int nd = ndd;
  
  for(ndd;ndd<num-1;ndd++){
    strcpy(vet[ndd].nomeDis, vet[ndd+1].nomeDis);
    strcpy(vet[ndd].codDis, vet[ndd+1].codDis);
    strcpy(vet[ndd].profDis, vet[ndd+1].profDis);
    vet[ndd].semDis = vet[ndd+1].semDis;
  }
  
  for(nd;nd<num;nd++){
    mat[nd][0].numA = mat[nd+1][0].numA;
    for(i=1;i<num;i++){
      strcpy(mat[nd][i].nomeA,mat[nd+1][i].nomeA);
    }
  }
  
  cadDis *ptr;
  ptr = &vet[num-1];
  ptr = NULL;
    
    __fpurge(stdin);
    printf("\nDados excluídos com sucesso.");
    return completado;
    
  }    

int incluiraluno (aldis mat[][n], cadDis vet[],  cadPessoas vet2[], int num, int num2)
{
  int i, val, ndm, ndp, teste, conf = 0, ndd;
  char codigo[10];
  
  ndd = descdis(vet, num);

  printf("Incluir aluno em %s.\n",vet[ndd].nomeDis);
  conf = 0;
  
  ndp = descpes(vet2, num2);

  val = mat[ndd][0].numA;
  strcpy(mat[ndd][val].nomeA, vet2[ndp].nome);
  val++;
  mat[ndd][0].numA=val;

  printf("\nO aluno %s foi matriculado em %s.", vet2[ndp].nome, vet[ndd].nomeDis);

  vet2[ndp].dismat++;
  
}

int excluiraluno (aldis mat[][n], cadDis vet[],  cadPessoas vet2[], int num, int num2)
{
  int i, k, aux, val, ndm, ndp, teste, conf = 0, ndd;
  char codigo[10];
  
  ndd = descdis(vet, num);

  printf("Excluir aluno de %s.\n",vet[ndd].nomeDis);
  conf = 0;
  
  ndp = descpes(vet2, num2);
  
  val = mat[ndd][0].numA;
  for(k=1;k<val;k++){
    teste = strcmp(mat[ndd][k].nomeA, vet2[ndp].nome);
    if(teste == 0){
      aux = k;
      k = val;
    }
  }

  for(aux;aux<val;aux++){
    strcpy(mat[ndd][aux].nomeA, mat[ndd][aux+1].nomeA);
  }
  
  val--;
  mat[ndd][0].numA=val;

  printf("\nO aluno %s foi desmatriculado em %s.", vet2[ndp].nome, vet[ndd].nomeDis);

  vet2[ndp].dismat--;
  
}