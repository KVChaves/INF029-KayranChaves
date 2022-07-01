/*Faça uma função recursiva que receba um número inteiro positivo par N e imprima 
todos os números pares de 0 até N em ordem decrescente.
CONCLUIDO*/

#include <stdio.h>
#include <stdlib.h>

int n;

int pares(int par){
  if(n > par){
    return 0;
  }
  else{
    printf("\n- %d",par - n);
    n = n+2;
    pares(par);
  }
}

int main(){
  int par = 1;
  while(par%2 != 0){
    printf("Insira um número par: ");
    scanf("%d",&par);
  }
  n = 0;
  printf("\nV\n");
  pares(par);
}