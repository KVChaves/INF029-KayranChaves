#include <stdio.h>

//Faça um programa que leia a idade de uma pessoa e informe se ela é de maior ou de menor. O programa deve repetir essa ação até que uma idade negativa seja informada.

int main(){

  int idade;

    printf("Insira um idade:\nEntre com um valor negativo para terminar.\n");

  while (idade>0){
    scanf("%d",&idade);
    
    if (idade>=18)
      printf("Você é de maior.\n");
    else
      printf("Você é de menor.\n");
    }
  
  
}