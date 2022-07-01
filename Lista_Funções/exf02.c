#include <stdio.h>

//Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores (primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o resultado da subtração.

int subt(int a, int b, int c){
  int res;
  res=(a-b)-c;
  return res;
}

int main(){

  int val1, val2, val3, res;
  printf("Insira 3 números para que uma subtração seja realizada.\nPrimeiro número: ");
  scanf("%d",&val1);
  printf("Segundo número: ");
  scanf("%d",&val2);
  printf("Terceiro número: ");
  scanf("%d",&val3);

  res = subt(val1, val2, val3);
  printf("O valor da subtração destes 3 números é %d",res);
}