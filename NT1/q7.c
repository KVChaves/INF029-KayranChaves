#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  typedef struct linhas_colunas
  {
    char nl;
    char nc;
    int val;
  } lincol;

  lincol vet[3];
  char tab[3][3];
  int i, j, fim = 0;

  vet[0].nl = 'A';
  vet[1].nl = 'B';
  vet[2].nl = 'C';
  vet[0].nc = '1';
  vet[1].nc = '2';
  vet[2].nc = '3';
  vet[0].val = 0;
  vet[1].val = 1;
  vet[2].val = 2;

  
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      tab[i][j] = ' ';
    }
  }

  int player = 2, r = 0;

  while(fim == 0){
    
    if(player == 2){
      player = 1;
    } 
    else{
      player = 2;
  }
  
    printf("     1   2    3 \n\n");
    printf("A    %c | %c | %c\n",tab[0][0],tab[0][1],tab[0][2]);
    printf("    ------------\n");
    printf("B    %c | %c | %c\n",tab[1][0],tab[1][1],tab[1][2]);
    printf("    ------------\n");
    printf("C    %c | %c | %c\n",tab[2][0],tab[2][1],tab[2][2]);
    
    char mov[3], simb;
    int l, c;

    if(player == 1){
      simb = 'X';
    }
    else{
      simb = 'O';
    }
    
    printf("\nJogador %d (%c): ", player, simb);
    fgets(mov, 3, stdin);
    size_t ln = strlen(mov) - 1;
    if(mov[ln] == '\n')
       mov[ln] = '\0';

    mov[0] = toupper(mov[0]);

    for(i=0;i<3;i++){
      if(mov[0] == vet[i].nl){
        l = vet[i].val;
        i = 3;
      };
    }
    i=0;
    for(i=0;i<3;i++){
      if(mov[1] == vet[i].nc){
        c = vet[i].val;
        i = 3;
      };
    }

    if(tab[l][c] == ' '){
      tab[l][c] = simb;
      r++;
    }
    else if(tab[l][c] != ' '){
      printf("\n !!! Inválido. !!!\n");
      if(player == 2){
      player = 1;
      } 
      else{
      player = 2;
      }
    }

    // #################################################

    if(tab[0][0] == simb && tab[0][1] == simb && tab[0][2] == simb){
      fim = 1;
    }
    else if(tab[1][0] == simb && tab[1][1] == simb && tab[1][2] == simb){
      fim = 1;
    }
    else if(tab[2][0] == simb && tab[2][1] == simb && tab[2][2] == simb){
      fim = 1;
    }
    else if(tab[0][0] == simb && tab[1][0] == simb && tab[2][0] == simb){
      fim = 1;
    }
    else if(tab[0][1] == simb && tab[1][1] == simb && tab[2][1] == simb){
      fim = 1;
    }
    else if(tab[0][2] == simb && tab[1][2] == simb && tab[2][2] == simb){
      fim = 1;
    }
    else if(tab[0][0] == simb && tab[1][1] == simb && tab[2][2] == simb){
      fim = 1;
    }
    else if(tab[0][2] == simb && tab[1][1] == simb && tab[2][0] == simb){
      fim = 1;
    }

    // #################################################

    printf("\n--------------------\n");

    if(r >= 9 && fim == 0){
      fim = 2;
    }

    getchar();
  }

  if(fim == 1){
  printf("!!! JOGADOR %d VENCEU !!!\n\n", player);
  printf("     1   2    3 \n\n");
  printf("A    %c | %c | %c\n",tab[0][0],tab[0][1],tab[0][2]);
  printf("    ------------\n");
  printf("B    %c | %c | %c\n",tab[1][0],tab[1][1],tab[1][2]);
  printf("    ------------\n");
  printf("C    %c | %c | %c\n",tab[2][0],tab[2][1],tab[2][2]);
    }
  else{
    printf("\n!!! EMPATE !!!\n");
    printf("     1   2    3 \n\n");
    printf("A    %c | %c | %c\n",tab[0][0],tab[0][1],tab[0][2]);
    printf("    ------------\n");
    printf("B    %c | %c | %c\n",tab[1][0],tab[1][1],tab[1][2]);
    printf("    ------------\n");
    printf("C    %c | %c | %c\n",tab[2][0],tab[2][1],tab[2][2]);
  }
  
}