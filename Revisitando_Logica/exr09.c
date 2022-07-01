#include <stdio.h>

//Faça um programa que leia 10 números do usuário e informe quais deles são primos. Além disso, mostre a soma de todos os números primos existentes.

int main(){

  int nump[10]={0,0,0,0,0,0,0,0,0,0};
  int num, cp, x, i;
  int sp=0;
  
  printf("Insira 10 números\n");

  for (i=0;i<10;i++){
    printf("Número: ");
    scanf("%d",&num);
    if (num!=1){
      for (x=1;x<=num;x++){
      if (num%x==0){
        cp++;
      }
      }
      if (cp<3){
      nump[i]=num;
      printf("%d é primo!\n",num);
      }
    }  
  cp=0;
  }

  for (i=0;i<10;i++){
    sp=nump[i]+sp;
  }

  if (sp>0){
    printf("\nA soma dos números primos inseridos é de %d.",sp);
  }
  else
    printf("Você não inseriu nenhum número primo.");
  
}