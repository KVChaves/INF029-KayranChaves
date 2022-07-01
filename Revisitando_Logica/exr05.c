#include <stdio.h>
#include <stdlib.h>

//Faça um programa que leia a idade de uma pessoa e informe se ela é de maior ou menor.

int main(){

  int idade;

  printf("Insira sua idade:");
  scanf("%d",&idade);

  if (idade>=18)
    printf("Você é maior de idade.");
  else
    printf("Você é menor de idade");
  
}