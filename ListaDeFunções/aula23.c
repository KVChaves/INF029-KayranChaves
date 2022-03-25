/*soma 2 = n
  diminui 2 = n2
    multiplica n por n2*/

#include <stdio.h>

int soma();
int subt();
int mult();

int main(){

  int sm1, sm2, sb1, sb2, val1, val2, total;
  
  printf("Insira 2 números para serem somados: \nPrimeiro número: ");
  scanf("%d",&sm1);
  printf("Segundo número: ");
  scanf("%d",&sm2);

  val1 = soma(sm1, sm2);

  printf("\nInsira 2 números para serem subtraídos: \nPrimeiro número: ");
  scanf("%d",&sb1);
  printf("Segundo número: ");
  scanf("%d",&sb2);

  val2 = subt(sb1, sb2);

  total = mult(val1, val2);

  printf("\nResultado da multiplicação dos dois valores: %d", total);
}

int soma(int a, int b){
  
  int resultado;
  
  resultado = a + b;

  return resultado;
}

int subt(int a, int b){

  int resultado;
  
  resultado = a - b;

  return resultado;
}

int mult(int a, int b){

  int resultado;
  
  resultado = a * b;

  return resultado;
}