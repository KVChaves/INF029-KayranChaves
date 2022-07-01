/*Faça uma função recursiva que receba um número inteiro positivo N e imprima 
todos os números naturais de 0 até N em ordem decrescente.
CONCLUIDO*/

#include <stdio.h>
#include <stdlib.h>

int n;

int decrescente(int num){
  if(n > num){
    return num;
  }
  else{
    printf("\n- %d",num - n);
    n++;
    decrescente(num);
  }
}

int main(){
  int num;
  printf("Insira um número: ");
  scanf("%d",&num);
  n = 0;
  printf("\nV\n");
  decrescente(num);
}