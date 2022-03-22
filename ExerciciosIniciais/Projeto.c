/* 
! Incluir Alunos nas Disciplinas.
! Listar Alunos ordenados por data de nascimento.
! Listar Professores ordenados por data de nascimento.
! Lista de pessoas (professor/aluno) a partir de uma string de busca. O usuário informa no mínimo três letras e deve ser listado todas as pessoas que contem essas três letras no nome.
! Lista de alunos matriculados em menos de 3 disciplinas.
! Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define n 50
#define completado 1

//-------STRUCTS-------

typedef struct data
{
    int dia;
    int mes;
    int ano;
} datanasc;

typedef struct alunos
{
    char nome[40];
    char sexoAluno[2];
    char cpfAluno[15];
    datanasc dataAluno;
    int matriculaAluno;
} cadAlunos;

typedef struct professor
{
    char nomeProf[40];
    char sexoProf[2];
    char cpfProf[15];
    datanasc dataProf;
    int matriculaProf;
} cadProf;

typedef struct disciplina
{
    char nomeDis[30];
    char codDis[10];
    int semDis;
    int alunosDis[n];
    char profDis[40];   
} cadDis;

//--------------------

int menuprincipal();
int menuAlunos();
int menuProf();
int menuDis();
int menuRel();

int cadastroaluno(cadAlunos listAlunos[], int numAlunos);
void listaraluno(cadAlunos listAlunos[], int numAlunos);
int atualizaraluno(cadAlunos listAlunos[], int numAlunos);
int excluiraluno(cadAlunos listAlunos[], int numAlunos);

int cadastroprof(cadProf listProf[], int numProf);
void listarprof(cadProf listProf[], int numProf);
int atualizarprof(cadProf listProf[], int numProf);
int excluirprof(cadProf listProf[], int numProf);

int cadastrodis(cadDis listDis[], int numDis);
void listardis(cadDis listDis[], int numDis);
int atualizardis(cadDis listDis[], int numDis);
int excluirdis(cadDis listDis[], int numDis);

void sexoalunos(cadAlunos listAlunos[], int numAlunos);
void sexoprof (cadProf listProf[], int numProf);
void alfabeticaAlunos (cadAlunos listAlunos[], int numAlunos);
void alfabeticaProf (cadProf listProf[], int numProf);
void aniversarios (cadProf listProf[], cadAlunos listAlunos[], int numAlunos, int numProf);

cadAlunos listAlunos[n];
cadProf listProf[n];
cadDis listDis[n];
char *pt1, *pt2;
int numAlunos = 0;
int numProf = 0;
int numDis = 0;
int opcao, opcaoAlunos, opcaoProf, opcaoDis, opcaoRel, retorno;
int sair = 0;

//------MAIN-------

int main(void)
{  
    printf("- PROJETO ESCOLA -");

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
                retorno = cadastroaluno(listAlunos,numAlunos);
                if (retorno == completado)
                {
                  printf("\nAluno (%d) cadastrado com sucesso!\n",numAlunos);
                  numAlunos++;
                }
                break;
              }
              case 2:{
                listaraluno(listAlunos, numAlunos);
                break;
              } 
              case 3:{
                atualizaraluno(listAlunos, numAlunos);
                break;
              }
              case 4:{
                retorno = excluiraluno(listAlunos, numAlunos);
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
                retorno = cadastroprof(listProf,numProf);
                if (retorno == completado)
                {
                  printf("\nProfessor (%d) cadastrado com sucesso!\n",numProf);
                  numProf++;
                }
                break;
              }
              case 2:{
                listarprof(listProf, numProf);
                break;
              }
              case 3:{
                atualizarprof(listProf, numProf);
                break;
              }
              case 4:{
                retorno = excluirprof(listProf, numProf);
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
                retorno = cadastrodis(listDis,numDis);
                if (retorno == completado)
                {
                  printf("\nDisciplina (%d) cadastrada com sucesso!\n",numDis);
                  numDis++;
                }
                break;
              }
              case 2:{
                listardis(listDis, numDis);
                break;
              }
              case 3:{
                atualizardis(listDis, numDis);
                break;
              }
              case 4:{
                retorno = excluirdis(listDis, numDis);
                if(retorno == completado){
                  numDis--;
                }
                break;
                }
              }
              /*default:{
                printf("\nOpção Inválida. Tente novamente.\n");
                break;
              }*/
            break;
            }//Disciplina.
          case 4:{
            opcaoRel = menuRel();
            switch(opcaoRel){
              case 0:{
                  break;
                }
              case 1:{
                sexoalunos(listAlunos, numAlunos);
                break;
              }
              case 2:{
                sexoprof (listProf, numProf);
                break;
              }
              case 3:{
                alfabeticaAlunos(listAlunos, numAlunos);
                break;
              }
              case 4:{
                alfabeticaProf(listProf, numProf);
                break;
              }
              case 5:{
                aniversarios (listProf, listAlunos, numAlunos, numProf);
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


//-------FUNÇÕES-------

int menuprincipal()
{
    int opcao;
    printf("\n-------------------\nDigite uma Opção:\n\n");
    printf("0 - Sair.\n");
    printf("1 - Gerenciar Alunos.\n");
    printf("2 - Gerenciar Professores.\n");
    printf("3 - Gerenciar Disciplinas.\n");
    printf("4 - Relatórios.\n");
    printf("\n> ");
    scanf("%d", &opcao);

    return opcao;
}

//------- F. ALUNOS------

int menuAlunos()
{
    int opcaoAlunos;
    printf("\n-------------------\n.....ALUNOS.....\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Aluno.\n");
    printf("2 - Listar Alunos.\n");
    printf("3 - Atualizar Aluno.\n");
    printf("4 - Excluir Aluno.\n");
    printf("\n> ");
    scanf("%d", &opcaoAlunos);

    return opcaoAlunos;
}

int cadastroaluno(cadAlunos listAlunos[], int numAlunos)
{
    int teste = 1, tesmat = 1, i;

    while(tesmat > 0){
      printf("Digite a Matrícula do Aluno: ");
      scanf("%d", &listAlunos[numAlunos].matriculaAluno);
      getchar();
      
      tesmat = 0;
      for(i=0;i<numAlunos;i++){
        if(listAlunos[numAlunos].matriculaAluno == listAlunos[i].matriculaAluno){
          tesmat++;
          }
      }
        }

    printf("Digite o nome do aluno: ");
    fgets(listAlunos[numAlunos].nome, 40, stdin);
    size_t ln = strlen(listAlunos[numAlunos].nome) - 1;
    if (listAlunos[numAlunos].nome[ln] == '\n')
        listAlunos[numAlunos].nome[ln] = '\0';

    while(teste != 0){
      printf("Digite o sexo do aluno (M/F): ");
      fgets(listAlunos[numAlunos].sexoAluno, 2, stdin);
      ln = strlen(listAlunos[numAlunos].sexoAluno) -1;
      if (listAlunos[numAlunos].sexoAluno[ln] == '\n')
          listAlunos[numAlunos].sexoAluno[ln] = '\0';
      
      teste = strcmp(listAlunos[numAlunos].sexoAluno,"M");
        if(teste != 0){
          teste = strcmp(listAlunos[numAlunos].sexoAluno,"F");
      }
      if(teste != 0){
        printf("Sexo Inválido.\n");
      }
      }

    printf("Digite a data de nascimento:\n");
    printf("Ano: ");
    scanf("%d", &listAlunos[numAlunos].dataAluno.ano);
  
    while(listAlunos[numAlunos].dataAluno.ano < 1910){
      printf("Inválido.\nAno: ");
      scanf("%d", &listAlunos[numAlunos].dataAluno.ano);
      }

    printf("Mês: ");
    scanf("%d",&listAlunos[numAlunos].dataAluno.mes);
    while(listAlunos[numAlunos].dataAluno.mes>12){
      printf("Inválido.\nMês: ");
      scanf("%d",&listAlunos[numAlunos].dataAluno.mes);
      } 

    printf("Dia: ");
    scanf("%d",&listAlunos[numAlunos].dataAluno.dia);

    if(listAlunos[numAlunos].dataAluno.mes==4||6||9||11)
    {
      while(listAlunos[numAlunos].dataAluno.dia>30){
        printf("Inválido.\nDia: ");
        scanf("%d",&listAlunos[numAlunos].dataAluno.dia);
        } 
    }
    if(listAlunos[numAlunos].dataAluno.mes==1||3||5||7||8||10||12)
    {
      while(listAlunos[numAlunos].dataAluno.dia>31){
        printf("Inválido.\nDia: ");
        scanf("%d",&listAlunos[numAlunos].dataAluno.dia);
      }
    }
    else{
      while(listAlunos[numAlunos].dataAluno.dia>29){
        printf("Inválido.\nDia: ");
        scanf("%d",&listAlunos[numAlunos].dataAluno.dia);
      }
    }
    getchar();

    printf("Digite o CPF: ");
    fgets(listAlunos[numAlunos].cpfAluno, 15, stdin);
    ln = strlen(listAlunos[numAlunos].cpfAluno) - 1;
    if (listAlunos[numAlunos].cpfAluno[ln] == '\n')
        listAlunos[numAlunos].cpfAluno[ln] = '\0';

    __fpurge(stdin);

    return completado;
}

void listaraluno(cadAlunos listAlunos[], int numAlunos)
{
    printf("\n*******************");
    for (int i = 0; i < numAlunos; i++)
    {
        printf("\n----------\n");
        printf("Nome: %s (%d)\n", listAlunos[i].nome, i);
        printf("Matricula: %d\n", listAlunos[i].matriculaAluno);
        printf("CPF: %s\n", listAlunos[i].cpfAluno);
        printf("Sexo: %s\n", listAlunos[i].sexoAluno);
        printf("Data: %d-%d-%d \n", listAlunos[i].dataAluno.dia,listAlunos[i].dataAluno.mes,listAlunos[i].dataAluno.ano);
    }
    printf("\n*******************");

  __fpurge(stdin);
}

int atualizaraluno(cadAlunos listAlunos[], int numAlunos)
{
  int i, ndm, teste = 1, num = 0, conf = 0;
  
  while(conf == 0){
  printf("\nInforme a matrícula do aluno a ser atualizado: ");
  scanf("%d",&ndm);
  getchar();

  conf = 0;
  for(i=0;i<numAlunos;i++){
    num++;
    if(listAlunos[i].matriculaAluno == ndm){
      conf++;
      i = numAlunos;
    }
  }
    }
  
    printf("\nDigite a nova matrícula do aluno: ");
    scanf("%d", &listAlunos[num].matriculaAluno);
    getchar();

    printf("Digite o nome do aluno: ");
    fgets(listAlunos[num].nome, 40, stdin);
    size_t ln = strlen(listAlunos[num].nome) - 1;
    if (listAlunos[num].nome[ln] == '\n')
        listAlunos[num].nome[ln] = '\0';

    while(teste != 0){
      printf("Digite o sexo do aluno (M/F): ");
      fgets(listAlunos[num].sexoAluno, 2, stdin);
      ln = strlen(listAlunos[num].sexoAluno) -1;
      if (listAlunos[num].sexoAluno[ln] == '\n')
          listAlunos[num].sexoAluno[ln] = '\0';
      
      teste = strcmp(listAlunos[num].sexoAluno,"M");
        if(teste != 0){
          teste = strcmp(listAlunos[num].sexoAluno,"F");
      }
      if(teste != 0){
        printf("Sexo Inválido.\n");
      }
      }

    printf("Digite a data de nascimento: (DD.MM.AAAA):\nDia: ");
    scanf("%d", &listAlunos[num].dataAluno.dia);
    printf("Mês: ");
    scanf("%d",&listAlunos[num].dataAluno.mes);
    printf("Ano: ");
    scanf("%d",&listAlunos[num].dataAluno.ano);
    getchar();

    printf("Digite o CPF: ");
    fgets(listAlunos[num].cpfAluno, 15, stdin);
    ln = strlen(listAlunos[num].cpfAluno) -1;
    if (listAlunos[num].cpfAluno[ln] == '\n')
        listAlunos[num].cpfAluno[ln] = '\0';

    __fpurge(stdin);
    
    printf("\nDados atualizados com sucesso.");
    return completado;
  }

int excluiraluno(cadAlunos listAlunos[], int numAlunos)
{
  int eda;
  int ndam=numAlunos-1;
  cadAlunos *ptr1, *ptr2, *ptr3;
  ptr1 = &listAlunos[eda];
  ptr2 = &listAlunos[eda+1];
  ptr3 = &listAlunos[numAlunos-1];
  
  printf("\nInforme o número do aluno: ");
  scanf("%d",&eda);
  while(eda>ndam){
    printf("(Digite -1 para sair)\nNúmero inválido! Tente outro: ");
    scanf("%d",&eda);
  }
  
  if(eda==-1){
    printf("\nNão foi possível concluir a operação.");
  }
  else{
    for(eda;eda<numAlunos;eda++){
      ptr1 = ptr2;
      ptr3 = NULL;
    }

    __fpurge(stdin);
    printf("\nDados excluídos com sucesso. Numeração atualizada.");
    return completado;
  }
}

//-------F. PROFESSORES-------

int menuProf()
{
    int opcaoProf;
    printf("\n-------------------\n...PROFESSORES...\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Professor.\n");
    printf("2 - Listar Professores.\n");
    printf("3 - Atualizar Professor.\n");
    printf("4 - Excluir Professor.\n");
    printf("\n> ");
    scanf("%d", &opcaoProf);

    return opcaoProf;
}

int cadastroprof(cadProf listProf[], int numProf)
{
    int teste = 1, tesmat = 1, i;

    while(tesmat > 0){
      printf("Digite a Matrícula do professor: ");
      scanf("%d", &listProf[numProf].matriculaProf);
      getchar();
      
      tesmat = 0;
      for(i=0;i<numProf;i++){
        if(listProf[numProf].matriculaProf == listProf[i].matriculaProf){
          tesmat++;
          }
      }
        }

    printf("Digite o nome do professor: ");
    fgets(listProf[numProf].nomeProf, 40, stdin);
    size_t ln = strlen(listProf[numProf].nomeProf) - 1;
    if (listProf[numProf].nomeProf[ln] == '\n')
        listProf[numProf].nomeProf[ln] = '\0';

    while(teste != 0){
      printf("Digite o sexo do professor (M/F): ");
      fgets(listProf[numProf].sexoProf, 2, stdin);
      ln = strlen(listProf[numProf].sexoProf) -1;
      if (listProf[numProf].sexoProf[ln] == '\n')
          listProf[numProf].sexoProf[ln] = '\0';
      
      teste = strcmp(listProf[numProf].sexoProf,"M");
        if(teste != 0){
          teste = strcmp(listProf[numProf].sexoProf,"F");
      }
      if(teste != 0){
        printf("Sexo Inválido.\n");
      }
      }

    printf("Digite a data de nascimento:\n");
    printf("Ano: ");
    scanf("%d", &listProf[numProf].dataProf.ano);
  
    while(listProf[numProf].dataProf.ano<1910){
      printf("Inválido.\nAno: ");
      scanf("%d", &listProf[numProf].dataProf.ano);
      }

    printf("Mês: ");
    scanf("%d",&listProf[numProf].dataProf.mes);
    while(listProf[numProf].dataProf.mes>12){
      printf("Inválido.\nMês: ");
      scanf("%d",&listProf[numProf].dataProf.mes);
      } 

    printf("Dia: ");
    scanf("%d",&listProf[numProf].dataProf.dia);

    if(listProf[numProf].dataProf.mes==4||6||9||11)
    {
      while(listProf[numProf].dataProf.dia>30){
        printf("Inválido.\nDia: ");
        scanf("%d",&listProf[numProf].dataProf.dia);
        } 
    }
    if(listProf[numProf].dataProf.mes==1||3||5||7||8||10||12)
    {
      while(listProf[numProf].dataProf.dia>31){
        printf("Inválido.\nDia: ");
        scanf("%d",&listProf[numProf].dataProf.dia);
      }
    }
    else{
      while(listProf[numProf].dataProf.dia>29){
        printf("Inválido.\nDia: ");
        scanf("%d",&listProf[numProf].dataProf.dia);
      }
    }
    getchar();

    printf("Digite o CPF: ");
    fgets(listProf[numProf].cpfProf, 15, stdin);
    ln = strlen(listProf[numProf].cpfProf) - 1;
    if (listProf[numProf].cpfProf[ln] == '\n')
        listProf[numProf].cpfProf[ln] = '\0';

    __fpurge(stdin);
  
    return completado;
}

void listarprof(cadProf listProf[], int numProf)
{
    printf("\n*******************");
    for (int i = 0; i < numProf; i++)
    {
        printf("\n----------\n");
        printf("Nome: %s (%d)\n", listProf[i].nomeProf, i);
        printf("Matricula: %d\n", listProf[i].matriculaProf);
        printf("CPF: %s\n", listProf[i].cpfProf);
        printf("Sexo: %s\n", listProf[i].sexoProf);
        printf("Data: %d-%d-%d", listProf[i].dataProf.dia,listProf[i].dataProf.mes,listProf[i].dataProf.ano);
    }
    printf("\n*******************");
}

int atualizarprof(cadProf listProf[], int numProf)
{
  int i, ndm, teste = 1, num = 0, conf = 0;
  
  while(conf == 0){
  printf("\nInforme a matrícula do professor a ser atualizado: ");
  scanf("%d",&ndm);
  getchar();

  conf = 0;
  for(i=0;i<numProf;i++){
    num++;
    if(listProf[i].matriculaProf == ndm){
      conf++;
      i = numProf;
    }
  }
    }
    printf("\nDigite a nova matrícula do professor: ");
    scanf("%d", &listProf[num].matriculaProf);
    getchar();

    printf("Digite o nome do professor: ");
    fgets(listProf[num].nomeProf, 40, stdin);
    size_t ln = strlen(listProf[num].nomeProf) - 1;
    if (listProf[num].nomeProf[ln] == '\n')
        listProf[num].nomeProf[ln] = '\0';

    while(teste != 0){
      printf("Digite o sexo do professor (M/F): ");
      fgets(listProf[num].sexoProf, 2, stdin);
      ln = strlen(listProf[num].sexoProf) -1;
      if (listProf[num].sexoProf[ln] == '\n')
          listProf[num].sexoProf[ln] = '\0';
      
      teste = strcmp(listProf[num].sexoProf,"M");
        if(teste != 0){
          teste = strcmp(listProf[num].sexoProf,"F");
      }
      if(teste != 0){
        printf("Sexo Inválido.\n");
      }
      }
  
    printf("Digite a data de nascimento: (DD.MM.AAAA):\nDia: ");
    scanf("%d", &listProf[num].dataProf.dia);
    printf("Mês: ");
    scanf("%d",&listProf[num].dataProf.mes);
    printf("Ano: ");
    scanf("%d",&listProf[num].dataProf.ano);
    getchar();

    printf("Digite o CPF: ");
    fgets(listProf[num].cpfProf, 15, stdin);
    ln = strlen(listProf[num].cpfProf) -1;
    if (listProf[num].cpfProf[ln] == '\n')
        listProf[num].cpfProf[ln] = '\0';

    __fpurge(stdin);
    
    printf("\nDados atualizados com sucesso.");
    return completado;
  }

int excluirprof(cadProf listProf[], int numProf)
{
  int edp;
  int ndpm=numProf-1;
  cadProf *ptr1, *ptr2, *ptr3;
  ptr1 = &listProf[edp];
  ptr2 = &listProf[edp+1];
  ptr3 = &listProf[edp-1];
  
  printf("\nInforme o número do professor: ");
  scanf("%d",&edp);
  while(edp>ndpm){
    printf("(Digite -1 para sair)\nNúmero inválido! Tente outro: ");
    scanf("%d",&edp);
  }
  
  if(edp==-1){
    printf("\nNão foi possível concluir a operação.");
  }
  else{
    for(edp;edp<numProf;edp++){
      ptr1 = ptr2;
      ptr3 = NULL;
    }

    __fpurge(stdin);
    printf("\nDados excluídos com sucesso. Numeração atualizada.");
    return completado;
  }
}

//-------F. DISCIPLINAS-------

int menuDis()
{
    int opcaoDis;
    printf("\n-------------------\n...DISCIPLINAS...\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Disciplina.\n");
    printf("2 - Listar Disciplinas.\n");
    printf("3 - Atualizar Disciplina.\n");
    printf("4 - Excluir Disciplina.\n");
    printf("5 - Incluir Aluno na Disciplina.\n");
    printf("\n> ");
    scanf("%d", &opcaoDis);
    getchar();

    return opcaoDis;
}

int cadastrodis(cadDis listDis[], int numDis)
{

  int i, teste;
  
  printf("Digite o semestre da disciplina: ");
  scanf("%d", &listDis[numDis].semDis);
  getchar();
  
  printf("Digite o nome do disciplina: ");
  fgets(listDis[numDis].nomeDis, 40, stdin);
  size_t ln = strlen(listDis[numDis].nomeDis) - 1;
  if (listDis[numDis].nomeDis[ln] == '\n')
      listDis[numDis].nomeDis[ln] = '\0';

  printf("Digite o código da disciplina: ");
  fgets(listDis[numDis].codDis, 10, stdin);
  ln = strlen(listDis[numDis].codDis) -1;
  if (listDis[numDis].codDis[ln] == '\n')
      listDis[numDis].codDis[ln] = '\0';

  printf("Insira o nome do professor: ");
  fgets(listDis[numDis].profDis, 40, stdin);
  ln = strlen(listDis[numDis].profDis) -1;
  if (listDis[numDis].profDis[ln] == '\n')
      listDis[numDis].profDis[ln] = '\0';

  for(i=0;i<numProf;i++){
    teste = strcmp(listDis[numDis].profDis,listProf[i].nomeProf);
    if(teste == 0){
      i=numProf;
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

void listardis(cadDis listDis[], int numDis)
{
      printf("\n*******************\n");
      for (int i = 0; i < numDis; i++)
    {
        printf("----------\n");
        printf("Nome: %s (%d)\n", listDis[i].nomeDis,i);
        printf("Código: %s\n", listDis[i].codDis);
        printf("Semestre: %d\n", listDis[i].semDis);
        printf("Professor: %s\n", listDis[i].profDis);
    }
      printf("\n*******************");
}

int atualizardis(cadDis listDis[], int numDis)
{
  int ndd;
  int nddm=numDis-1;

  printf("\nInforme o número da disciplina: ");
  scanf("%d",&ndd);
  while(ndd>nddm){
    printf("(Digite -1 para sair)\nNúmero inválido! Tente outro: ");
    scanf("%d",&ndd);
  }

  if(ndd==-1){
    printf("\nNão foi possível concluir a operação.");
  }
  else{
    printf("Digite o semestre da disciplina: ");
    scanf("%d", &listDis[ndd].semDis);
    getchar();
    
    printf("Digite o nome do disciplina: ");
    fgets(listDis[ndd].nomeDis, 40, stdin);
    size_t ln = strlen(listDis[numDis].nomeDis) - 1;
    if (listDis[ndd].nomeDis[ln] == '\n')
        listDis[ndd].nomeDis[ln] = '\0';

    printf("Digite o código da disciplina: ");
    fgets(listDis[ndd].codDis, 10, stdin);
    ln = strlen(listDis[ndd].codDis) -1;
    if (listDis[ndd].codDis[ln] == '\n')
        listDis[ndd].codDis[ln] = '\0';

    printf("Digite o nome do professor da disciplina: ");
    fgets(listDis[ndd].profDis, 40, stdin);
    ln = strlen(listDis[ndd].profDis) -1;
    if (listDis[ndd].profDis[ln] == '\n')
        listDis[ndd].profDis[ln] = '\0';

    __fpurge(stdin);

    printf("\nDados atualizados com sucesso.");
    return completado;
  }
}

int excluirdis(cadDis listDis[], int numDis)
{
  
  int edd;
  int nddm=numDis-1;
  cadDis *ptr1, *ptr2, *ptr3;
  ptr1 = &listDis[edd];
  ptr2 = &listDis[edd+1];
  ptr3 = &listDis[edd-1];
  
  printf("\nInforme o número da disciplina: ");
  scanf("%d",&edd);
  while(edd>nddm){
    printf("(Digite -1 para sair)\nNúmero inválido! Tente outro: ");
    scanf("%d",&edd);
  }
  
  if(edd==-1){
    printf("\nNão foi possível concluir a operação.");
  }
  else{
    for(edd;edd<numDis;edd++){
      ptr1 = ptr2;
      ptr3 = NULL;
    }
    
    __fpurge(stdin);
    printf("\nDados excluídos com sucesso. Numeração atualizada.");
    return completado;
    }    
  }

//-------RELATÓRIOS------

int menuRel()
{
  int opcaoRel;
    printf("\n-------------------\n...RELATÓRIOS...\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Listar Alunos por Sexo.\n");
    printf("2 - Listar Professores por Sexo\n");
    printf("3 - Listar Alunos em Ordem Alfabetica.\n");
    printf("4 - Listar Professores em Ordem Alfabetica.\n");
    printf("5 - Aniversáriantes do Mês.\n");
    printf("\n> ");
    scanf("%d", &opcaoRel);
    getchar();

    return opcaoRel;
}

void sexoalunos (cadAlunos listAlunos[], int numAlunos)
{
  int i, teste;
  printf("\nAlunas Cadastradas no Sistema:\n");
  for(i=0;i<numAlunos;i++){
    teste = strcmp(listAlunos[i].sexoAluno, "F");
    if(teste == 0){
      printf("\n- %s",listAlunos[i].nome);
    }
  }
  printf("\n--------------------\nAlunos Cadastrados no Sistema:\n");
  for(i=0;i<numAlunos;i++){
    teste = strcmp(listAlunos[i].sexoAluno, "M");
    if(teste == 0){
      printf("\n- %s",listAlunos[i].nome);
    }
  }
}

void sexoprof (cadProf listProf[], int numProf)
{
  int i, teste;
  printf("\nProfessoras Cadastradas no Sistema:\n");
  for(i=0;i<numProf;i++){
    teste = strcmp(listProf[i].sexoProf, "F");
    if(teste == 0){
      printf("\n- %s",listProf[i].nomeProf);
    }
  }
  printf("\n--------------------\nProfessores Cadastrados no Sistema:\n");
  for(i=0;i<numProf;i++){
    teste = strcmp(listProf[i].sexoProf, "M");
    if(teste == 0){
      printf("\n- %s",listProf[i].nomeProf);
    }
  }
}

void alfabeticaAlunos (cadAlunos listAlunos[], int numAlunos)
{
  cadAlunos alfabetica[n];
  int i, j, k;
  char aux[50];

  for(i=0;i<numAlunos;i++){
    strcpy(alfabetica[i].nome, listAlunos[i].nome);
  }
  
  printf("\nAlunos Cadastrados em Ordem Alfabética:\n\n");
  for(i=0;i<numAlunos;i++){
    for(j = i+1; j < numAlunos; j++){
      k = strcmp(alfabetica[i].nome, alfabetica[j].nome);
      if(k > 0){
        strcpy(aux, alfabetica[i].nome);
        strcpy(alfabetica[i].nome, alfabetica[j].nome);
        strcpy(alfabetica[j].nome, aux);
      }
    }
  }
  for(i = 0; i < numAlunos; i++){
    printf("- %s\n", alfabetica[i].nome);
  }
}

void alfabeticaProf (cadProf listProf[], int numProf)
{
  cadProf alfabeticaP[n];
  int i, j, k;
  char aux[50];

  for(i=0;i<numProf;i++){
    strcpy(alfabeticaP[i].nomeProf, listProf[i].nomeProf);
  }
  
  printf("\nProfessores Cadastrados em Ordem Alfabética:\n\n");
  for(i=0;i<numProf;i++){
    for(j = i+1; j < numProf; j++){
      k = strcmp(alfabeticaP[i].nomeProf, alfabeticaP[j].nomeProf);
      if(k > 0){
        strcpy(aux, alfabeticaP[i].nomeProf);
        strcpy(alfabeticaP[i].nomeProf, alfabeticaP[j].nomeProf);
        strcpy(alfabeticaP[j].nomeProf, aux);
      }
    }
  }
  for(i = 0; i < numProf; i++){
    printf("- %s\n", alfabeticaP[i].nomeProf);
  }
}        

void aniversarios (cadProf listProf[], cadAlunos listAlunos[], int numAlunos, int numProf)
{
  int mes, i;
  printf("Informe o mês: \n");
  scanf("%d",&mes);

  printf("Anivérsariantes do Mês %d:\n\n",mes);
  for(i=0;i<numAlunos;i++){
    if(listAlunos[i].dataAluno.mes == mes){
      printf("- %s (Aluno)\n",listAlunos[i].nome);
    }
  }
  for(i=0;i<numProf;i++){
    if(listProf[i].dataProf.mes == mes){
      printf("- %s (Prof.)\n",listProf[i].nomeProf); 
    }
}
}