#include <stdio.h>
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

typedef struct materia
{
    char nomeMat[30];
    char profMat[40];
    int codigoMat;
    int semestreMat;

} cadMat;

int menuprincipal();
int menuAlunos();
int menuProf();
int cadastroaluno(cadAlunos listAlunos[], int numAlunos);
int cadastroprof(cadProf listProf[], int numProf);
void listaraluno(cadAlunos listAlunos[], int numAlunos);
void listarprof(cadProf listProf[], int numProf);

//------MAIN-------

int main(void)
{
    cadAlunos listAlunos[n];
    cadProf listProf[n];
    int numAlunos = 0;
    int numProf = 0;
    int opcao, opcaoAlunos, opcaoProf, retorno;
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
                  break;
                }
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
                  break;
                }
              }
              case 2:{
                listarprof(listProf, numProf);
                break;
              }
              default:{
                printf("Opção Inválida. Tente novamente.");
                break;
              }
            }
          }
          default:{
            printf("Opção Inválida. Tente novamente.");
            break;
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
    printf("3 - Gerenciar Matérias.\n");
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

    printf("Digite o sexo do(a) aluno(a) - 'M', 'F': ");
    fgets(listAlunos[numAlunos].sexoAluno, 2, stdin);
    if (listAlunos[numAlunos].sexoAluno[ln] == '\n')
        listAlunos[numAlunos].sexoAluno[ln] = '\0';

    printf("Digite a data de nascimento (DD.MM.AAAA): ");
    scanf("%d/%d/%d", &listAlunos[numAlunos].dataAluno.dia, &listAlunos[numAlunos].dataAluno.mes, &listAlunos[numAlunos].dataAluno.ano);
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

    printf("Digite o sexo do(a) professor(a) - 'M','F': ");
    fgets(listProf[numProf].sexoProf, 2, stdin);
    if (listProf[numProf].sexoProf[ln] == '\n')
        listProf[numProf].sexoProf[ln] = '\0';

    printf("Digite a data de nascimento (DD.MM.AAAA): ");
    scanf("%d/%d/%d", &listProf[numProf].dataProf.dia, &listProf[numProf].dataProf.mes, &listProf[numProf].dataProf.ano);
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
    }
}