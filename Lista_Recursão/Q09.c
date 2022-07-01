/*Crie uma função recursiva que receba um número inteiro positivo N e calcule o 
somatório dos números de 1 a N.
CONCLUIDO*/

#include <stdio.h>
#include <stdlib.h>

int result = 0;

int soma(int num){
  if(num > 0){
    result = result + num;
    soma(num-1);
  }
  else{
    int res_fim = result;
    result = 0;
    return res_fim;
  }
}

int main(){
  int num;
  printf("Insira um número: ");
  scanf("%d",&num);
  printf("Resultado: %d", soma(num));
}