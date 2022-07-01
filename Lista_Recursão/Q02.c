/*Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência 
Fibonacci. Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...
CONCLUIDO*/

#include <stdlib.h>
#include <stdio.h>

float n_esimo;
float f[3] = {0,1,0}; //1 - 1 - 1

float fib(float num){
  if(num == n_esimo){
    return f[0];
  }
  else if(num != n_esimo){
    f[2] = f[0] + f[1];
    f[0] = f[1];
    f[1] = f[2];
    fib(num+1);
  }
}

int main(){
  float num = 1;

  printf("Deseja descobrir o termo de fibonacci de qual posição? ");
  scanf("%f",&n_esimo);

  printf("\n- %.0f",fib(num));
}