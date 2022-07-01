/*Crie um programa em C que receba um vetor de números reais com 100 elementos. 
Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor.
CONCLUIDO*/

#include <stdio.h>
#include <stdlib.h>

int cem[100], cem_cont[100];

int invert(int a, int b){
  int j;
  if(a == 100){
    printf("\nINICIO\n");
    for(j=0;j<100;j++){
      printf("\n- %d",cem_cont[j]);
    }
    printf("\n\nFIM");
    return 0;
  }
  else{
    cem_cont[b] = cem[a];
    invert(a+1, b-1);
  }
}

int main(){
  int primeiro, i;
  
  printf("Um vetor de 100 elementos será preenchido e depois invertido. Informe o primeiro elemento do vetor: ");
  scanf("%d",&primeiro);

  cem[0] = primeiro;
  int k = primeiro+1;
  
  for(i=1;i<100;i++){
    cem[i] = k;
    k++;
  }

  invert(0, 99);
}