#include <stdio.h>

//Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas sem utilizar variável auxiliar.

int main(){

  int va, vb;

  printf("Insira um valor para a variável A:");
  scanf("%d",&va);
  printf("Insira um valor para a variável B:");
  scanf("%d",&vb);

  va=va+vb;
  vb=va-vb;
  va=va-vb;
  
  printf("Os valores das variáveis foram invertidos.\nVariável A: %d\nVariável B: %d", va, vb);
  
}