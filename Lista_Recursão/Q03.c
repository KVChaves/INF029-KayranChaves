// Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321

#include <stdlib.h>
#include <stdio.h>

int invert(int num)
{
  int cont = 1, val = num; 
  
  while(val>9){
    val = val/10;
    cont++;
  }

  char sNum[cont], invert[cont];

  sprintf(sNum, "%d", num);
  int i, j=cont-1;
  for(i=0;i<cont;i++){
    invert[i] = sNum[j];
    j--;
  }

  num = atoi(invert);

  return num;
}

int main(){
  int num;
  printf("Informe um número para que ele seja invertido: ");
  scanf("%d",&num);
  printf("Resultado: %d",invert(num));
}