/*Faça uma função recursiva que permita somar os elementos de um vetor de 
inteiros
CONCLUIDO*/
  
#include <stdio.h>
#include <stdlib.h>

int vet[5];
int total = 0;

int somavet(int num){
  if(num == 5){
    return total;
  }
  else{
    total = total + vet[num];
    somavet(num+1);
  }
}

int main(){
  int i, num;
  printf("Informe os cinco valores de um vetor:\n");
  for(i=0;i<5;i++){
    printf("- ");
    scanf("%d",&num);
    vet[i] = num;
  }

  printf("= %d",somavet(0));
}