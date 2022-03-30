/* 
gcc projeto_main.c disciplinas.c menus.c pessoas.c relatorios.h disciplinas.h menus.h pessoas.h relatorios.c structs.h extras.h extras.c -o exe
! Listar Alunos ordenados por data de nascimento.
! Listar Professores ordenados por data de nascimento.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "structs.h"
#include "menus.h"
#include "pessoas.h"
#include "disciplinas.h"
#include "relatorios.h"
#include "extras.h"

#define n 50
#define completado 1

cadPessoas listAlunos[n];
cadPessoas listProf[n];
cadDis listDis[n];
aldis alunosDis[n][n];
int numAlunos = 0;
int numProf = 0;
int numDis = 0;
int opcao, opcaoAlunos, opcaoProf, opcaoDis, opcaoRel, retorno;
int sair = 0;

//------MAIN-------

int main(void)
{  
    printf("- PROJETO ESCOLA -");

    int i;
    for(i=0;i<n;i++){
      alunosDis[i][0].numA = 1;
    }

    while (!sair)
    {
        opcao = menuprincipal();

        switch (opcao){
          case 0:{
            printf("\nSAINDO...\n");
            sair = 1;
            break;
          }
          case 1:{
            opcaoAlunos = menuAlunos();
            switch (opcaoAlunos){
              case 0:{
                break;
              }
              case 1:{
                retorno = cadastro(listAlunos,numAlunos);
                if (retorno == completado)
                {
                  printf("\nAluno cadastrado com sucesso!\n");
                  numAlunos++;
                }
                break;
              }
              case 2:{
                listar(listAlunos, numAlunos);
                break;
              } 
              case 3:{
                retorno = atualizar(listAlunos, numAlunos);
                if (retorno == completado)
                {
                  printf("\nDados atualizados com sucesso.");
                }
                break;
              }
              case 4:{
                retorno = excluir(listAlunos, numAlunos);
                if(retorno == completado){
                  numAlunos--;
                }
                break;
              }
              default:{
                printf("Opção Inválida. Tente novamente.");
                break;
              }
            }
            break;
          }//Aluno.
          case 2:{
            opcaoProf = menuProf();
            switch (opcaoProf){
              case 0:{
                break;
              }
              case 1:{
                retorno = cadastro(listProf,numProf);
                if (retorno == completado)
                {
                  printf("\nProfessor cadastrado com sucesso!\n");
                  numProf++;
                }
                break;
              }
              case 2:{
                listar(listProf, numProf);
                break;
              }
              case 3:{
                atualizar(listProf, numProf);
                break;
              }
              case 4:{
                retorno = excluir(listProf, numProf);
                if(retorno == completado){
                  numProf--;
                }
                break;
              }
              default:{
                printf("\nOpção Inválida. Tente novamente.\n");
                break;
              }
            }
            break;
          }//Prof.
          case 3:{
            opcaoDis=menuDis();
            switch(opcaoDis){
              case 0:{
                break;
                }
              case 1:{
                retorno = cadastrodis(listDis,listProf, numDis,numProf);
                if (retorno == completado)
                {
                  printf("\nDisciplina cadastrada com sucesso!\n");
                  numDis++;
                }
                break;
              }
              case 2:{
                listardis(listDis, numDis);
                break;
              }
              case 3:{
                atualizardis(listDis, numDis, listProf, numProf);
                break;
              }
              case 4:{
                retorno = excluirdis(listDis, listAlunos, alunosDis, numDis, numAlunos);
                if(retorno == completado){
                  numDis--;
                }
                break;
                }
              case 5:{
                incluiraluno(alunosDis, listDis, listAlunos, numDis, numAlunos);
                break;
              }
              case 6:{
                excluiraluno (alunosDis, listDis, listAlunos, numDis, numAlunos);
                break;
              }
              case 7:{
                listarDCA(listDis, numDis, alunosDis, listAlunos, numAlunos);
                break;
              }
              default:{
                printf("\nOpção Inválida. Tente novamente.\n");
                break;
              }
              }
            break;
            }//Disciplina.
          case 4:{
            opcaoRel = menuRel();
            switch(opcaoRel){
              case 0:{
                  break;
                }
              case 1:{
                sexo(listAlunos, numAlunos);
                break;
              }
              case 2:{
                sexo(listProf, numProf);
                break;
              }
              case 3:{
                alfabetica(listAlunos, numAlunos);
                break;
              }
              case 4:{
                alfabetica(listProf, numProf);
                break;
              }
              case 5:{
                aniversarios(listProf, listAlunos, numProf ,numAlunos );
                break;
              }
              case 6:{
                busca(listAlunos, listProf, numAlunos, numProf);
                break;
              }
              case 7:{
                numvagas(alunosDis, listDis ,numDis);
                break;
              }
              case 8:{
                menos3mat(listAlunos, numAlunos);
                break;
              }
              case 9:{
                nascimento(listAlunos, numAlunos);
                break;
              }
              case 10:{
                nascimento(listProf, numProf);
                break;
              }
              default:{
                printf("\nOpção Inválida. Tente novamente.\n");
                break;
              }
              break;
            }
          }//Relatórios.
          }
    }
}

//-----------------

/*void nascimento (cadPessoas vet[], int num)
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
        i=-0;
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
      datanasc *pt1, *pt2;
      pt1 = &nascimento[j].data;
      pt2 = &vet[i].data;
      if(pt1 == pt2){
        printf("Nome: %s\n",vet[i].nome);
        printf("Data: %d-%d-%d\n-----",vet[i].data.dia,vet[i].data.mes,vet[i].data.ano);
      }
    }
  }
  
}*/