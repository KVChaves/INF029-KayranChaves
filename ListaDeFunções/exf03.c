#include <stdio.h>

//Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial.

void fatorial(int a){
  if (a>0){
    int c, i;
    c=a;
  
    for (i=1;i<c;i++){
      a=a*i;
    }

    printf("O fatorial de %d é %d.",c,a);
  }
  else
    printf("Erro: Não é possível calcular o fatorial deste número.");
}

int main(){

  int nf;
  
  printf("Insira um número para que seu fatorial seja calculado: ");
  scanf("%d",&nf);

  fatorial(nf);
  return 0;
}