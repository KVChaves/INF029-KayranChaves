#include <stdio.h>

//Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial.
 int fatorial (int a){
   int res=1;
   if(a>0){
     for (int i=1;a>1;a--){
       res=res*a;
     }
    return res;
   }
   else{
     res=-1;
     return res;
   }
}

//-----------------------------------------------

int main(){

  int res, nf;
  printf("Insira um número para que seu fatorial seja calculado: ");
  scanf("%d",&nf);
  res=fatorial(nf);
  if (res<0){
    printf("Não é possível calcular o fatorial desse número.");
  }
  else{
    printf("O fatorial de %d é %d", nf, res);
  }
}