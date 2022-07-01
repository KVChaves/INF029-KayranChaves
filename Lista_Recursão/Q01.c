//1) Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N. CONCLUIDO

#include <stdlib.h>
#include <stdio.h>

float fat(float num){
  float val_fat;
  if(num == 1){
    return 1;
  }
  else if(num<1){
    return 0;
  }
  else{
    val_fat = num * fat(num - 1);
    return val_fat;
  }
}

int main(){
  float num;
  printf("Insira um número para descobrir seu fatorial: ");
  scanf("%f",&num);
  printf("Resultado: %.0f", fat(num));
}