#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

int q4(char strTexto[], char strBusca[], int posicoes[30]);

int main(){
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];

    strcpy(strTexto, "Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca, "rato");
    printf("%d\n", q4(strTexto, strBusca, posicoes));// == 2
    printf("%d\n", posicoes[0]); //== 5
    printf("%d\n", posicoes[1]); //== 8
    printf("%d\n", posicoes[2]); //== 34
    printf("%d\n", posicoes[3]); //== 37
}

int q4(char strTexto[], char strBusca[], int posicoes[30])
{
  int qtd = 0;
  
  int tam = strlen(strTexto);
  int tam2 = strlen(strBusca);

  char scop[tam2];
  int k;
  for(k=0;k<tam2;k++){
    scop[k] = 'k';
  }

  scop[0] = '\0';
  
  printf("%s - %d\n", scop, tam2);
  
  int i, f=0, f2=0, p=0;
  
  int ini = 1, fim = tam2;

  while(tam>=tam2){
    //printf("%d - %d \n",tam, tam2); 
    for(i=0;i<tam2;i++){
      scop[i] = strTexto[f];
      f++;
    }
    //printf("- %s\n", scop);
    int a = strlen(scop);
    
    //printf("- %d - %d\n", a, tam2);
    printf("%s - %s\n",scop, strBusca);
    
  int teste = strcmp(scop, strBusca);
    if(teste==0){
      qtd++;
      posicoes[p] = ini;
      p++;
      posicoes[p] = fim;
      p++;
      printf("%d - %d - %d - %d\n", ini, fim, p, qtd);
    };
    
    ini++;
    fim++;
    //printf("%s\n", strTexto);   
    scop[0] = '0';
    tam--;
    f2++;
    f = f2;
  }

  return qtd;
}