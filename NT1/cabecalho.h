// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Dados do Aluno -----
//  Nome: Kayran Vieira Chaves
//  email: kayranchaves2002@gmail.com
//  Matrícula: 20212160049
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021

// #################################################
#ifndef _CABECALHO_H_
#define _CABECALHO_H_

typedef struct DQ
{
    int iDia;
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;

typedef struct Qtd
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

} DiasMesesAnos;

int q1(char data[]);
DiasMesesAnos q2(char datainicial[], char datafinal[]);
int q3(char texto[], char c, int cs);
int q4(char strTexto[], char strBusca[], int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);
DataQuebrada quebraData(char data[]);

#endif  // _CABECALHO_H_