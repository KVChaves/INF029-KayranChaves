#include <stdlib.h>
#include <stdio.h>

int main(){

  int num, i, c;
  c=0;

  printf("Insira um número.");
  scanf("%d",&num);

  for (i=1;i<6;i++){
    if (num%i==0){
      c++;
    }
  }

  if (c>2){
    printf("O número %d não é primo.",num);
  }
    else 
      printf("O número %d é primo.",num);
  }