/*Crie um programa em C, que contenha uma função recursiva que receba dois 
inteiros positivos k e n e calcule k^n
. Utilize apenas multiplicações. O programa principal 
deve solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da 
função
CONCLUIDO*/

#include <stdio.h>
#include <stdlib.h>

float quadrado(float k, float n, float num){
  if(n > 1){
    k = k*num;
    quadrado(k,n-1,num);
  }
  else{
    return k;
  }
}

int main(){
  float k, n;

  printf("K será elevado a N.\nInforme o valor de K: ");
  scanf("%f",&k);
  printf("Informe o valor de N: ");
  scanf("%f",&n);

  printf("\n- %.0f",quadrado(k,n,k));
}