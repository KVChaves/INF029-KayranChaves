#include <stdio.h>

//Incompleto.

//Faça um programa que leia 10 números do usuário e informe quais deles são primos. Além disso, mostre a soma de todos os números primos existentes.

int main(){

  int nums[10];
  int c=0;
  int x=0;
  int vets[10];

  printf("Insira 10 números:\n");
  for (int i=0;i<10;i++){
    c++;
    printf("%dº número.",c);
    scanf("%d",&nums[i]);
  }
  //printf("%d - %d",nums[0],nums[9]);

  while (x<10){
    c=0;
    for (i=1;i<6;i++){
      if (num[x]%i==0){
      c++;
      }
    }
    if (c>2){
      vets[x]=nums[x];
    }
    x++;
  }  
  
}