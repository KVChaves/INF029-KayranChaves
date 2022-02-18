#include <stdio.h>

//Faça um programa que calcula o fatorial de um número.

int main(){

  int num, c, i;

  printf("Insira um número:");
  scanf("%d",&num);
  c=num;
  
  for (i=1;i<c;i++){
    num=num*i;
  }

  printf("O fatorial de %d é %d.",c,num);
}