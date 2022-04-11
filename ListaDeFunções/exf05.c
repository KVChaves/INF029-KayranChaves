#include <stdio.h>

//Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do usuário e retornar os quatro números. A função main deve imprimir esses quatro números. Utilize struct para fazer o retorno.

typedef struct numeros
{
  int num1;
  int num2;
  int num3;
  int num4;
} nums;

nums ler4num (nums stc);
nums stp;
int saida;

int main(void){

  stp = ler4num(stp);
  
  printf("%d\n",stp.num1);  
  printf("%d\n",stp.num2);  
  printf("%d\n",stp.num3);  
  printf("%d",stp.num4);

}

nums ler4num (nums stc){

  printf("1º número: ");
  scanf("%d",&stc.num1);
  printf("2º número: ");
  scanf("%d",&stc.num2);
  printf("3º número: ");
  scanf("%d",&stc.num3);
  printf("4º número: ");
  scanf("%d",&stc.num4);

  return stc;
}