/*Faça uma função recursiva que receba um número inteiro positivo N e imprima 
todos os números naturais de 0 até N em ordem crescente
CONCLUIDO*/

#include <stdio.h>
#include <stdlib.h>

int n;

int crescente(int num){
  if(n < 0){
    return num;
  }
  else{
    printf("\n- %d",num - n);
    n--;
    crescente(num);
  }
}

int main(){
  int num;
  printf("Insira um número: ");
  scanf("%d",&num);
  n = num;
  printf("\nV\n");
  crescente(num);
}