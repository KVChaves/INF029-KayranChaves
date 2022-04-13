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
#include "HKayranChaves20212160049.h"

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
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
    //quebrar a string data em strings sDia, sMes, sAno

    //DataQuebrada dataQuebrada = quebraData(data);
    //if (dataQuebrada.valido == 0) return 0;

    //converter sDia, sMes e sAno em inteiros (ex: atoi)

    //criar as variáveis iDia, iMes, iAno
    //int iAno = atoi(dataQuebrada.sAno);

    //printf("%s\n", data);

  DataQuebrada dataQuebrada = quebraData(data);

  return dataQuebrada.valido;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
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

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char texto[], char c, int cs)
{

  //Ao invés de fazer no começo faça na hora da comparação.

  int i, j, tam, qtdOcorrencias = 0;

  char *comAc = "ÁÂÀÃäáâàãÉÊËÈéêëèÍÎÏÌíîïìÖÓÔÒÕöóôòõÜÚÛÙüúûùÇçÑñ";
  char *semAc = "AAAAaaaaaEEEEeeeeIIIIiiiiOOOOOoooooUUUUuuuuCcNn";

  tam = strlen(texto);

  /*for(i=0;i<48;i++)
  {
    if(c == comAc[i])
    {
      c = semAc[i];
    }
  };*/

  /*for(i=0;i<tam;i++)
  {
    for(j=0;j<48;j++)
    {
      if(texto[i]==comAc[j])
      {
        texto[i]=semAc[j];
      };
    }
  };*/

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

  printf("%s - %c - %d :", texto, c, cs);

  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

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

    return num;
}

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
    int qtdOcorrencias;
    return qtdOcorrencias;
}