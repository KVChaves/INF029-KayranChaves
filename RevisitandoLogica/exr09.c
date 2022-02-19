#include <stdio.h>

//Faça um programa que leia 10 números do usuário e informe quais deles são primos. Além disso, mostre a soma de todos os números primos existentes.

int main(){

  int nums[10];
  int c=0;

  printf("Insira 10 números:\n");
  for (int i=0;i<10;i++){
    c++;
    printf("%dº número.",c);
    scanf("%d",&nums[i]);
  }
  //printf("%d - %d",nums[0],nums[9]);
  

  
  
}