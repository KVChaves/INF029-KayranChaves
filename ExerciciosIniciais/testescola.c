#include <stdio.h>
#include <string.h>

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
    char nomeProf[31];
    char sexoProf;
    int nascProf;
    int cpfProf;
    int matriculaProf;
} cadProf;

typedef struct materia
{
    char nomeMat[31];
    char profMat[31];
    int codigoMat;
    int semestreMat;
} cadMat;

int main(void)
{
    cadAlunos listAlunos[10];
    int numAlunos = 0;
    int opcao;
    int sair = 0;

    printf("- PROJETO ESCOLA -\n-------------------");

    while (!sair)
    {
        printf("\nDigite uma Opção:\n\n");
        printf("0 - Sair.\n");
        printf("1 - Inserir Aluno.\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 0:
            {
                printf("SAINDO...\n");
                sair = 1;
                break;
            }

            case 1:
            {
                printf("Digite a Matrícula do aluno: ");
                scanf("%d", &listAlunos[numAlunos].matriculaAluno);
                getchar();
              
                printf("Digite o nome do aluno: ");
                fgets(listAlunos[numAlunos].nome, 40, stdin);
                size_t ln = strlen(listAlunos[numAlunos].nome) - 1; 
                if (listAlunos[numAlunos].nome[ln] == '\n')
                    listAlunos[numAlunos].nome[ln] = '\0';

                printf("Digite o sexo do aluno: ");
                fgets(listAlunos[numAlunos].sexoAluno, 2, stdin);
                if (listAlunos[numAlunos].sexoAluno[ln] == '\n')
                    listAlunos[numAlunos].sexoAluno[ln] = '\0';
              
                printf("Digite a data de nascimento (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &listAlunos[numAlunos].dataAluno.dia, &listAlunos[numAlunos].dataAluno.mes, &listAlunos[numAlunos].dataAluno.ano);
                getchar();
              
                printf("Digite o CPF: ");
                fgets(listAlunos[numAlunos].cpfAluno, 15, stdin);
                if (listAlunos[numAlunos].cpfAluno[ln] == '\n')
                    listAlunos[numAlunos].cpfAluno[ln] = '\0';

                numAlunos++;
              
                break;
            }
        }
    }
}