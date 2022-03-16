#include <stdio.h>

//Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do usuário e retornar os quatro números. A função main deve imprimir esses quatro números. Utilize struct para fazer o retorno.

typedef struct numeros
{
  int num1;
  int num2;
  int num3;
  int num4;
} nums;

nums stp;

int main(void){

  ler4num(stp)
  
  printf("%d"stp.num1);  
  printf("%d",stp.num2);  
  printf("%d",stp.num3);  
  printf("%d",stp.num4);

  return 0;
}

int ler4num (nums stp){

  printf("1º número: ");
  scanf("%d",&stp.num1);
  printf("2º número: ");
  scanf("%d",&stp.num2);
  printf("3º número: ");
  scanf("%d",&stp.num3);
  printf("4º número: ");
  scanf("%d",&stp.num4);

  return stp;
}