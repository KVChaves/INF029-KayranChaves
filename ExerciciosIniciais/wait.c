#include <stdio.h>
#include <string.h>

struct data
{
    int dia;
    int mes;
    int ano;
};

struct alunos
{
    char nome[50];
    char sexoAluno[2];
    int matriculaAluno;
    int cpfAluno;
    
};

struct professor
{
    char nomeProf[31];
    char sexoProf;
    int nascProf;
    int cpfProf;
    int matriculaProf;
};

struct materia
{
    char nomeMat[31];
    char profMat[31];
    int codigoMat;
    int semestreMat;
};

int main(void)
{
    struct alunos cadastro;
    struct data cadDat;
    int opcao;
    int sair = 0;

    while (!sair)
    {
        printf("digite a opcao:\n");
        printf("0 - sair\n");
        printf("1 - inserir aluno\n");
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
                printf("Digite a matricula do aluno: ");
                scanf("%d", &cadastro.matriculaAluno);
                printf("Digite o nome do aluno: ");
                fgets(cadastro.nome, 50, stdin);
                size_t ln = strlen(cadastro.nome) - 1; 
                if (cadastro.nome[ln] == '\n')
                    cadastro.nome[ln] = '\0';

                printf("Digite o sexo do aluno: ");
                fgets(cadastro.sexoAluno, 2, stdin);
                printf("Digite a data de nascimento (dd/mm/aa): ");
                scanf("%d/%d/%d", &cadDat.dia, &cadDat.mes, &cadDat.ano);
                printf("Digite o CPF: ");
                scanf("%d", &cadastro.cpfAluno);
                break;
            }
        }
    }
}