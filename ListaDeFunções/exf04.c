#include <stdio.h>

//Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor para fazer o retorno.

int main(void){

  int vetm[3];
  int ler3num(int vetf[]);

  vetm = ler3num();
  
  printf("Os três números são: %d, %d e %d",vetm[0], vetm[1], vetm[2]);
}

int ler3num(int vetf[]){
  
  printf("Insira 3 números.\nPrimeiro: ");
  scanf("%d", &vetf[0]);
  printf("Segundo: ");
  scanf("%d", &vetf[1]);
  printf("Terceiro: ");
  scanf("%d",&vetf[2]);

  return vetf[];
  
}