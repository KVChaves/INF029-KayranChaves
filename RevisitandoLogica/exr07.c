#include <stdlib.h>
#include <stdio.h>

int main(){

  int num, i, c;
  c=0;

  printf("Insira um número.");
  scanf("%d",&num);

  if (num<=3){
    printf("O Número %d e primo.",num);
  }
  else
      for (i=2;i<6;i++){
        if (num%i==0){
          c++;
        }
      }

      if (c>0){
        printf("O número não é primo.");
      }
      else 
        printf("O número é primo.");
  }