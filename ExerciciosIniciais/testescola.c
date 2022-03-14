/* 
! Validar Datas.
! Incluir a opção de atualizar e excluir nos menus.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char profDis[40];
    int codDis;
    int semDis;
} cadDis;

int menuprincipal();
int menuAlunos();
int menuProf();
int menuDis();
int cadastroaluno(cadAlunos listAlunos[], int numAlunos);
int cadastroprof(cadProf listProf[], int numProf);
int cadastrodis(cadDis listDis[], int numDis);
void listaraluno(cadAlunos listAlunos[], int numAlunos);
void listarprof(cadProf listProf[], int numProf);

cadProf listProf[n];
cadAlunos listAlunos[n];
cadDis listDis[n];
int numAlunos = 0;
int numProf = 0;
int numDis = 0;

//------MAIN-------

int main(void)
{
    cadAlunos listAlunos[n];
    cadProf listProf[n];
    cadDis listDis[n];
    int numAlunos = 0;
    int numProf = 0;
    int numDis = 0;
    int opcao, opcaoAlunos, opcaoProf, opcaoDis, retorno;
    int sair = 0;

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
                  printf("\nCadastro realizado com sucesso!\n");
                  numAlunos++;
                }
                break;
              }
              case 2:{
                listaraluno(listAlunos, numAlunos);
                break;
              } 
              default:{
                printf("Opção Inválida. Tente novamente.");
                break;
              }
            }
            break;
          }
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
                  printf("\nCadastro realizado com sucesso!\n");
                  numProf++;
                }
                break;
              }
              case 2:{
                listarprof(listProf, numProf);
                break;
              }
              default:{
                printf("\nOpção Inválida. Tente novamente.\n");
                break;
              }
            }
            break;
          }
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
                  printf("\nCadastro realizado com sucesso!\n");
                  numDis++;
                }
                break;
              }
            }
          }
          default:{
            printf("\nOpção Inválida. Tente novamente.\n");
            break;
        }
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

//-------ALUNOS------

int menuAlunos()
{
    int opcaoAlunos;
    printf("\n-------------------\n.....ALUNOS.....\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Aluno.\n");
    printf("2 - Listar Alunos.\n");
    printf("3 - Excluir Aluno.\n");
    printf("\n> ");
    scanf("%d", &opcaoAlunos);

    return opcaoAlunos;
}

int cadastroaluno(cadAlunos listAlunos[], int numAlunos)
{
    printf("\nDigite a Matrícula do aluno: ");
    scanf("%d", &listAlunos[numAlunos].matriculaAluno);
    getchar();

    printf("Digite o nome do aluno: ");
    fgets(listAlunos[numAlunos].nome, 40, stdin);
    size_t ln = strlen(listAlunos[numAlunos].nome) - 1;
    if (listAlunos[numAlunos].nome[ln] == '\n')
        listAlunos[numAlunos].nome[ln] = '\0';

    printf("Digite o sexo do aluno (M/F): ");
    fgets(listAlunos[numAlunos].sexoAluno, 2, stdin);
    if (listAlunos[numAlunos].sexoAluno[ln] == '\n')
        listAlunos[numAlunos].sexoAluno[ln] = '\0';

    printf("Digite a data de nascimento (DD.MM.AAAA):\nDia: ");
    scanf("%d", &listAlunos[numAlunos].dataAluno.dia);
    printf("Mês: ");
    scanf("%d",&listAlunos[numAlunos].dataAluno.mes);
    printf("Ano: ");
    scanf("%d",&listAlunos[numAlunos].dataAluno.ano);
    getchar();

    printf("Digite o CPF: ");
    fgets(listAlunos[numAlunos].cpfAluno, 15, stdin);
    ln = strlen(listAlunos[numAlunos].cpfAluno) - 1;
    if (listAlunos[numAlunos].cpfAluno[ln] == '\n')
        listAlunos[numAlunos].cpfAluno[ln] = '\0';

    return completado;
}

void listaraluno(cadAlunos listAlunos[], int numAlunos)
{
    for (int i = 0; i < numAlunos; i++)
    {
        printf("-----\n");
        printf("Nome: %s\n", listAlunos[i].nome);
        printf("Matricula: %d\n", listAlunos[i].matriculaAluno);
        printf("CPF: %s\n", listAlunos[i].cpfAluno);
        printf("Sexo: %s\n", listAlunos[i].sexoAluno);
        printf("Data: %d-%d-%d \n", listAlunos[i].dataAluno.dia,listAlunos[i].dataAluno.mes,listAlunos[i].dataAluno.ano);
    }
}

//-------PROFESSORES-------

int menuProf()
{
    int opcaoProf;
    printf("\n-------------------\n...PROFESSORES...\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Professor.\n");
    printf("2 - Listar Professores.\n");
    printf("3 - Excluir Professor.\n");
    printf("\n> ");
    scanf("%d", &opcaoProf);

    return opcaoProf;
}

int cadastroprof(cadProf listProf[], int numProf)
{
    printf("\nDigite a Matrícula do professor: ");
    scanf("%d", &listProf[numProf].matriculaProf);
    getchar();

    printf("Digite o nome do professor: ");
    fgets(listProf[numProf].nomeProf, 40, stdin);
    size_t ln = strlen(listProf[numProf].nomeProf) - 1;
    if (listProf[numProf].nomeProf[ln] == '\n')
        listProf[numProf].nomeProf[ln] = '\0';

    printf("Digite o sexo do professor (M/F): ");
    fgets(listProf[numProf].sexoProf, 2, stdin);
    if (listProf[numProf].sexoProf[ln] == '\n')
        listProf[numProf].sexoProf[ln] = '\0';

    printf("Digite a data de nascimento (DD.MM.AAAA):\nDia: ");
    scanf("%d", &listProf[numProf].dataProf.dia);
    printf("Mês: ");
    scanf("%d", &listProf[numProf].dataProf.mes);
    printf("Ano: ");
    scanf("%d", &listProf[numProf].dataProf.ano);
    getchar();

    printf("Digite o CPF: ");
    fgets(listProf[numProf].cpfProf, 15, stdin);
    ln = strlen(listProf[numProf].cpfProf) - 1;
    if (listProf[numProf].cpfProf[ln] == '\n')
        listProf[numProf].cpfProf[ln] = '\0';

    return completado;
}

void listarprof(cadProf listProf[], int numProf)
{
    for (int i = 0; i < numProf; i++)
    {
        printf("-----\n");
        printf("Nome: %s\n", listProf[i].nomeProf);
        printf("Matricula: %d\n", listProf[i].matriculaProf);
        printf("CPF: %s\n", listProf[i].cpfProf);
        printf("Sexo: %s\n", listProf[i].sexoProf);
        printf("Data: %d-%d-%d", listProf[i].dataProf.dia,listProf[i].dataProf.mes,listProf[i].dataProf.ano);
    }
}

//-------DISCIPLINAS-------

int menuDis(){
    int opcaoDis;
    printf("\n-------------------\n...DISCIPLINAS...\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Disciplina.\n");
    printf("2 - Listar Disciplinas.\n");
    printf("3 - Excluir Disciplina.\n");
    printf("\n> ");
    scanf("%d", &opcaoDis);

    return opcaoDis;
}

int cadastrodis(cadDis listDis[], int numDis)
{
    printf("\nDigite a código do disciplina: ");
    scanf("%d", &listDis[numDis].codDis);
    getchar();

    printf("Digite o nome da disciplina: ");
    fgets(listDis[numDis].nomeDis, 40, stdin);
    size_t ln = strlen(listDis[numDis].nomeDis) - 1;
    if (listDis[numDis].nomeDis[ln] == '\n')
        listDis[numDis].nomeDis[ln] = '\0';

    printf("Digite o semestre: ");
    scanf("%d",&listDis[numDis].semDis);
    getchar();
  
    printf("Digite o nome do professor desta disciplina: ");
    while(listDis[numDis].profDis!==listProf[numProf].nomeProf || listDis[numDis].profDis!=="X"){
      fgets(listDis[numDis].profDis, 40, stdin);
      if (listDis[numDis].profDis[ln] == '\n')
          listDis[numDis].profDis[ln] = '\0';

      if(listDis[numDis].profDis!=listProf[numProf].nomeProf){
        printf("Professor não cadastrado, tente outro.\n(Digite 'X' para pular.)\n");
      }
    }
  
    return completado;
}