#include <stdio.h>

  //Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas.

int main(){

  int va, vb, vr;

  printf("Insira um valor para a variável A:");
  scanf("%d",&va);
  printf("Insira um valor para a variável B:");
  scanf("%d",&vb);

  vr=va;
  va=vb;
  vb=vr;

  printf("Os valores foram invertidos. \nVariável A: %d \nVariável B: %d.", va, vb);
  
}