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
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cabecalho.h"

// #################################################

DataQuebrada quebraData(char data[]){
  
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;
  int fev = 28;

  dq.valido = 0;

  for (i = 0; data[i] != '/'; i++){
      sDia[i] = data[i];	
  }
  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
      sDia[i] = '\0';  // coloca o barra zero no final
	} else 
    {
        dq.valido = 0;
    }
	
  int j = i + 1; //anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++){
      sMes[i] = data[j];
	  i++;
    }

  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
    sMes[i] = '\0';  // coloca o barra zero no final
	} else
    {
		dq.valido = 0;
    }

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
  for(; data[j] != '\0'; j++){
	  sAno[i] = data[j];
	  i++;
	}

  if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
	  sAno[i] = '\0';  // coloca o barra zero no final
	}else
    {
	  dq.valido = 0;
    }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);

  if(dq.iAno % 4 == 0 && (dq.iAno % 400 == 0 || dq.iAno % 100 != 0))
  {
    fev = 29;
  };

  if(dq.iMes > 0 && dq.iMes < 12)
  {
    if(dq.iDia <= 31 && dq.iDia > 0 && (dq.iMes == 1||3||5||7||8||10||12))
    {
      dq.valido = 1;
    }
    if(dq.iDia <= 30 && dq.iDia > 0 && (dq.iMes == 4||6||9||11))
    {
      dq.valido = 1;
    }
    if(dq.iDia <= fev && dq.iDia > 0 && dq.iMes == 2)
    {
      dq.valido = 1;
    }
    else
    {
        dq.valido = 0;
    }
  }

  printf("\n%d\n",fev);
  printf("%d.%d.%d\n",dq.iDia,dq.iMes,dq.iAno);
    
  return dq;
}

// #################################################

int q1(char data[])
{

  DataQuebrada dataQuebrada = quebraData(data);

  return dataQuebrada.valido;
}

// #################################################

DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir

  char datai[11];
  char dataf[11];
  DataQuebrada di, df;
  int testI, testF, DImaior = 0;
  DiasMesesAnos dma;

  printf("\nInsira a data inicial: ");
  fgets(datai, 11, stdin);
  size_t ln = strlen(datai) - 1;
  if(datai[ln] == '\n')
     datai[ln] = '\0';

  printf("\nInsira a data final: ");
  fgets(dataf, 11, stdin);
  ln = strlen(dataf) - 1;
  if(dataf[ln] == '\n')
     dataf[ln] = '\0';

  testI = q1(datai);
  testF = q1(dataf);

  if(testI == 1 && testF == 1)
  {
    di = quebraData(datai);
    df = quebraData(dataf);

    if(di.iAno > df.iAno){
      DImaior = 1;
    }
    else{
      if(di.iMes > df.iMes){
        DImaior = 1;
      }
      else{
        if(di.iDia > df.iDia){
          DImaior = 1;
        }
        else{
          DImaior = 0;
        }
      }
    }
  };

  if (testI == 0){
    dma.retorno = 2;
    return dma;
  }else if (testF == 0){
    dma.retorno = 3;
    return dma;
  }else if (testI == 1 && testF == 1 && DImaior == 1){
    dma.retorno = 4;
    return dma;
  }
  else{    
    
    dma.retorno = 1;
     return dma;
      
    }
    
}

// #################################################

int q3(char texto[], char c, int cs)
{

  //Ignorar acentos.

  int i, j, tam, qtdOcorrencias = 0;
  
  tam = strlen(texto);

  if(cs != 1){
      for(i=0;i<tam;i++){
        if(texto[i] == toupper(c) || texto[i] == tolower(c)){
          qtdOcorrencias++;
        }
      }
    }
  else if(cs == 1){
    for(i=0;i<tam;i++){
      if(texto[i] == c){
        qtdOcorrencias++;
      }
    }
  }

  return qtdOcorrencias;
}

// #################################################

int q4(char strTexto[], char strBusca[], int posicoes[30])
{
  int qtd = 0;
  
  int tam = strlen(strTexto);
  int tam2 = strlen(strBusca);

  char scop[tam2];
  int k;
  for(k=0;k<tam2;k++){
    scop[k] = 'k';
  }
  //printf("%s - %d\n", scop, tam2);
  
  int i, f=0, f2=0, p=0;
  
  int ini = 1, fim = tam2;

  while(tam>=tam2){
    //printf("%d - %d \n",tam, tam2); 
    for(i=0;i<tam2;i++){
      scop[i] = strTexto[f];
      f++;
    }
    //printf("- %s\n", scop);
    int a = strlen(scop);
    
    //printf("- %d - %d\n", a, tam2);
    //printf("%s - %s\n",scop, strBusca);
    
  int teste = strcmp(scop, strBusca);
    if(teste==0){
      qtd++;
      posicoes[p] = ini;
      p++;
      posicoes[p] = fim;
      p++;
      //printf("%d - %d - %d - %d\n", ini, fim, p, qtd);
    };
    
    ini++;
    fim++;
    //printf("%s\n", strTexto);   
    scop[0] = '0';
    tam--;
    f2++;
    f = f2;
  }

  return qtd;
}

// #################################################

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int cont = 1, val = num; 
  
  while(val>9){
    val = val/10;
    cont++;
  }

  char sNum[cont], invert[cont];

  sprintf(sNum, "%d", num);
  int i, j=cont-1;
  for(i=0;i<cont;i++){
    invert[i] = sNum[j];
    j--;
  }

  num = atoi(invert);

  return num;
}

// #################################################

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias = 0, tam = 1, tam2 = 1;

  int val = numerobase;
  while(val>9){
    val = val/10;
    tam++;
  }  
  val = numerobusca;
  while(val>9){
    val = val/10;
    tam2++;
  }   

  char sbas[tam], sbus[tam2];
  sprintf(sbas, "%d", numerobase);
  sprintf(sbus, "%d", numerobusca);
  //printf("%s - %d\n", sbus, tam2);

  char scop[tam2];
  strcpy(scop, "1");
  int i, f=0;
  
  while(tam>=tam2){
    for(i=0;i<tam2;i++){
      scop[i] = sbas[f];
      f++;
    }

    //printf("%s - %s\n",scop, sbus);

    int teste = strcmp(scop, sbus);
    if(teste==0){
      qtdOcorrencias++;
    };
    scop[0] = '0';
    tam--;
  }
  
  return qtdOcorrencias;
}
