/*A multiplicação de dois números inteiros pode ser feita através de somas 
sucessivas. Proponha um algoritmo recursivo Multip_Rec(n1,n2) que calcule a multiplicação de dois inteiros.
CONCLUIDO*/

#include <stdio.h>
#include <stdlib.h>

int total = 0;

int mult(int a, int b){
  if(b == 0){
    a = total;
    total = 0;
    return a;
  }
  else{
    total = total + a;
    mult(a,b-1);
  }
}

int main(){
  int a, b;
  
  printf("Informe um número A para ser multiplicado por um número B.\nA: ");
  scanf("%d",&a);
  printf("B: ");
  scanf("%d",&b);

  printf("Resultado = %d", mult(a,b));
}
