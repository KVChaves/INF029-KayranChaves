#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct data
{
    int dia;
    int mes;
    int ano;
} datanasc;

typedef struct pessoas
{
    char nome[40];
    char sexo[2];
    char cpf[15];
    datanasc data;
    int matricula;
    int dismat;
} cadPessoas;

typedef struct disciplina
{
    char nomeDis[30];
    char codDis[10];
    int semDis;
    char profDis[40];   
} cadDis;

typedef struct alunos_disciplina
{
int numA;
char nomeA[40];
} aldis;

#endif