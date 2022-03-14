#include <stdio.h>

//Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor para fazer o retorno.

int main(void){

  int vetm[3];
  int ler3num(int vetf[]);

  ler3num (vetm);
  
  printf("Os três números são: %d, %d e %d",vetm[0], vetm[1], vetm[2]);

  return 0;
}

int ler3num(int vetf[]){
  
  printf("Insira 3 números.\nPrimeiro: ");
  scanf("%d", &vetf[0]);
  printf("Segundo: ");
  scanf("%d", &vetf[1]);
  printf("Terceiro: ");
  scanf("%d",&vetf[2]);
  
    }

/*int main(void)
{
    float vmain[3];
    float ler3numeros (float vetor[]);

    ler3numeros (vmain);

    printf("\n%.1f", vmain[0]);
    printf("\n%.1f", vmain[1]);
    printf("\n%.1f", vmain[2]);

    return 0;
}

    float ler3numeros (float vetor[])
    {
            printf("Digite um numero: ");
            scanf("%f", &vetor[0]);
            printf("Digite um numero: ");
            scanf("%f", &vetor[1]);
            printf("Digite um numero: ");
            scanf("%f", &vetor[2]);
    }*/
