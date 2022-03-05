#include <stdio.h>

//Crie um programa que tenha uma função soma e a função main. A função main deve ler dois valores, enviar para a função soma. A função soma deve realizar a soma e retornar o valor. A Função main deve imprimir o resultado da soma.

void soma(int a, int b){
  int res;
  res=a+b;
  printf("O valor da soma é %d",res);
}

int main(){

  int val1, val2;
  
  printf("Insira dois números para que uma soma seja realizada.\nPrimeiro Número: ");
  scanf("%d",&val1);
  printf("Segundo Número: ");
  scanf("%d",&val2);

  soma(val1, val2);
  return 0;
  
}