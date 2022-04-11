//Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário e retornar as três letras. A função main deve imprimir essas três letras.

#include <stdio.h>

int main(){

  int ler3let(char let[]);
  char letras[3];
  
  ler3let(letras);  

  printf("%s", letras);
  
}

int ler3let(char let[])
{
  printf("Insira 3 letras:\n");
  fgets(let, 4, stdin);
  
  return 0;
}