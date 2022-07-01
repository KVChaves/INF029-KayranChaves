/*Escreva uma função recursiva que determine quantas vezes um dígito K ocorre em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, i,cont = 1;
char x;

int ocorrencias(int num){
  int val = num;
  if(num > 9){
    val = val/10;
    cont++;
    ocorrencias(val);
  }
  else{
    char sNum[cont];
    int vezes = 0;
    sprintf(sNum, "%d", num);
    for(i=0;i<cont;i++){
      printf("\n> %c, %d",sNum[i], i);
      if(sNum[i] == x){
        vezes++;
      }
    }
    cont = 1;
    return vezes;
  }
}

int main(){
  printf("Insira um número N e depois um número X para descobrimos a quantidade de ocorrências de X em N.\nN: ");
  scanf("%d",&n);
  getchar();
  printf("X: ");
  x = getchar();
  //scanf("%c",&x);
  printf("= %c =",x);
  printf("\n- %d",ocorrencias(n));
}
