#include <stdio.h>

int vet[3];

int ler3nums(int a, int b, int c){
  
  vet[0]=a;
  vet[1]=b;
  vet[2]=c;

  return (vet[3]);
}

int main(void){

  int num1, num2, num3;

  printf("Insira 3 números.\nPrimeiro número: ");
  scanf("%d",&num1);
  printf("Segundo número: ");
  scanf("%d",&num2);
  printf("Terceiro número: ");
  scanf("%d",&num3);

  ler3nums(num1,num2,num3);
  return 0;
  
  for(int i=0;i>3;i++){
    printf("%d\n",vet[i]);
  }
}