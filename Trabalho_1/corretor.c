// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016 - 12/12/2018

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//renomeie o arquivo do include abaixo para PrimeiroUltimoNomeMATRICULA.h
#include "KayranChaves20212160049T1.h"

int main()
{

  int Q = 1;

// #################################################
  if(Q == 1){
    char str[11];

    strcpy(str, "/9/2014");
    printf("%d\n", q1(str)); //0
    strcpy(str, "01/06/2015");
    printf("%d\n", q1(str)); //0 - 29/02/2015
    strcpy(str, "29/02/2012");
    printf("%d\n", q1(str)); //1 
    strcpy(str, "9/13/2014");
    printf("%d\n", q1(str)); //0  
    strcpy(str, "45/4/2014");
    printf("%d\n", q1(str));  //0 
  }
// #################################################
  else if(Q == 2){
    char datainicial[11], datafinal[11];
    DiasMesesAnos dma;

    //teste 1
    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno);// == 1);
    printf("%d\n", dma.qtdDias);// == 0);
    printf("%d\n", dma.qtdMeses);// == 0);
    printf("%d\n", dma.qtdAnos);// == 1);

    //teste 2 - retornos
/*
    strcpy(datainicial, "01/30/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno);// == 2

    strcpy(datainicial, "01/3/2015");
    strcpy(datafinal, "40/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno); // == 3

    strcpy(datainicial, "01/06/2016");
    strcpy(datafinal, "01/06/2015");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno); // == 4
/*
    //teste 3

    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "07/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno); // == 1
    printf("%d\n", dma.qtdDias); // == 1
    printf("%d\n", dma.qtdMeses); // == 1
    printf("%d\n", dma.qtdAnos); // == 0
    */
  }
// #################################################
  else if(Q == 3){
    char str[250];
    strcpy(str, "Renato Lima Novais");
    printf("%d\n", q3(str, 'a', 0)); // == 3);
    printf("%d\n", q3(str, 'b', 0)); // == 0);
    printf("%d\n", q3(str, 'l', 1)); // == 0);
    printf("%d\n", q3(str, 'l', 0)); // == 1);
    printf("%d\n", q3(str, 'L', 0)); // == 1);
  }
// #################################################  
  else if(Q == 4){
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];

    strcpy(strTexto, "Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca, "rato");
    printf("%d\n", q4(strTexto, strBusca, posicoes));// == 2
    printf("%d\n", posicoes[0]); //== 5
    printf("%d\n", posicoes[1]); //== 8
    printf("%d\n", posicoes[2]); //== 34
    printf("%d\n", posicoes[3]); //== 37
  }
// #################################################
  else if(Q == 5){
    printf("%d\n", q5(345));// == 543
    printf("%d\n", q5(78));// == 87
    printf("%d\n", q5(3));// == 3
    printf("%d\n", q5(5430));// == 345
  }
// #################################################
  else{
    printf("%d\n", q6(34567368, 3));// == 2
    printf("%d\n", q6(34567368, 4576));// == 0
    printf("%d\n", q6(3539343, 3));// == 4
    printf("%d\n", q6(3539343, 39));// == 1
  }
}