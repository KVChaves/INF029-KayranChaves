#include <stdio.h>

//Faça um programa que leia a idade de duas pessoas e imprima a soma das idades.

int main(){

  int id1, id2, soma;

  printf("Insira a primeira idade:");
  scanf("%d",&id1);
  printf("Insira a segunda idade:");
  scanf("%d",&id2);

  soma=id1+id2;

  printf("A soma das idades é de %d",soma);
}
