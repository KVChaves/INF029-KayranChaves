#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define num 5

char pos[2];
int l, c;
int nums[10]={0,1,2,3,4,5,6,7,8,9};
char alf[10]={"ABCDEFGHIJ"};

int full(char mat[][10]);
int config(char mat[][10]);
void printab(char mat[][10]);
int position(char mat[][10], int tam);
int play(char mat[][10], char mat2[][10]); //Tela - Tabuleiro

// #################################################
int main(){

  printf("--- BATALHA NAVAL ---\n\n");
  char p1[10][10], p2[10][10], tela1[10][10], tela2[10][10];
  int confirm, stk1, stk2, fim = 0, conf = 0;
  
  printf("Configurando Tabuleiro do Jogador 1.\n");
  confirm = full(p1);
  confirm = config(p1);
  printf("\nTabuleiro Configurado!\n");
  getchar();
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\nConfigurando Tabuleiro do Jogador 2.\n");
  confirm = full(p2);
  confirm = config(p2);
  printf("\nTabuleiro Configurado!\n");
  getchar();
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

  printf("\n-------BATALHA NAVAL-------\n");
  confirm = full(tela1);
  confirm = full(tela2);

  while(fim == 0){
    printf("\n### JOGADOR 1 ###\n");
    stk1 = stk1 + play(tela1, p2);
    if(stk1 == 10){
      printf("\n!!! JOGADOR 1 VENCEU !!!\n");
      fim = 1;
    }
    else{
      printf("\n### JOGADOR 2 ###\n");
      stk2 = stk2 + play(tela2, p1);
      if(stk2 == 10){
        printf("\n!!! JOGADOR 2 VENCEU !!!\n");
        fim = 1;
      };
    }
  }
  
  
}
// #################################################
//Preencher o tabuleiro.
int full(char mat[][10]){

  int i, j;
  
  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
      mat[i][j] = ' ';
    }
  }
  return 1;
}
// #################################################
//Configurar o tabuleiro de um jogador.
int config(char mat[][10]){
  int v, conf = 0;
  
  for(v=0;v<3;v++){
    printab(mat);
    while(conf != 1){
      conf = position(mat, 1);
    }
    conf = 0;
  }
  printab(mat);

  while(conf != 1){
    conf = position(mat, 3);
  }
  
  printab(mat);
  conf = 0;

  while(conf != 1){
    conf = position(mat, 4);
  }
  
  printab(mat);

  return 1;
}
// #################################################
//Posicionar um barco de tamanho N.
int position(char mat[][10], int tam){

  int i = 0, k = 0, a = 0, b = 0, l = 0, c = 0, ambas = 0;
  char sent;
  pos[0] = '\0';
  
  if(tam==1){
    
    printf("\nBarco de tamanho %d na posição: ",tam);
    fgets(pos, 3, stdin);
    size_t ln = strlen(pos) - 1;
    if(pos[ln] == '\n')
       pos[ln] = '\0';

    pos[0] = toupper(pos[0]);

    for(a=0;a<10;a++){
      if(pos[0] == alf[a]){
        ambas++;
      };
    }

    for(k=0;k<10;k++){
      if(pos[0] == alf[k]){
        l = nums[k];
      };
    }
    c = pos[1] - '0';
    getchar();

    for(b=0;b<10;b++){
      if(c == nums[b]){
        ambas++;
      };
    }

    if(ambas != 2){
      printf("\n!!! Insira uma posição válida !!!\n");
      return 0;
    };

    if(mat[l][c] != ' '){
      printf("\n!!! Posição já preenchida !!!\n");
      return 0;
    }
    else{
      mat[l][c] = 'N';
      return 1;
    }
  }
    
  else if(tam > 1){
    int hz = 0, l2 = 0, c2 = 0;
    ambas = 0;
    
    printf("\nPosição inical do barco de tamanho %d: ",tam);
    fgets(pos, 3, stdin);
    size_t ln = strlen(pos) - 1;
    if(pos[ln] == '\n')
       pos[ln] = '\0';

    pos[0] = toupper(pos[0]);

    for(a=0;a<10;a++){
      if(pos[0] == alf[a]){
        ambas++;
      };
    }

    for(k=0;k<10;k++){
      if(pos[0] == alf[k]){
        l = nums[k];
      };
    }
    c = pos[1] - '0';
    getchar();

    for(b=0;b<10;b++){
      if(c == nums[b]){
        ambas++;
      };
    }

    if(ambas != 2){
      printf("\n!!! Insira uma posição válida !!!\n");
      return 0;
    };

    pos[0] = '\0';
    a = 0;
    b = 0;
    k = 0;
    i = 0;
    ambas = 0;

    printf("Posição final do barco de tamanho %d: ",tam);
    fgets(pos, 3, stdin);
    ln = strlen(pos) - 1;
    if(pos[ln] == '\n')
       pos[ln] = '\0';
    
    pos[0] = toupper(pos[0]);

    for(a=0;a<10;a++){
      if(pos[0] == alf[a]){
        ambas++;
      };
    }

    for(k=0;k<10;k++){
      if(pos[0] == alf[k]){
        l2 = nums[k];
      };
    }
    c2 = pos[1] - '0';
    getchar();

    for(b=0;b<10;b++){
      if(c2 == nums[b]){
        ambas++;
      };
    }

    if(ambas != 2){
      printf("\n!!! Insira uma posição válida !!!\n");
      return 0;
    };  

    k = 0;
    i = 0;
    
    if(l == l2 && c != c2){
      if(c > c2){
        if(c - c2 != tam -1){
          printf("\n!!! Barco com tamanho incorreto !!!\n");
          return 0;
        };
        for(i=c;i>=c2;i--){
          if(mat[l][i] != ' '){
            printf("\n!!! Área já preenchida !!!\n");
            return 0;
          };
        }
        for(i=c;i>=c2;i--){
          mat[l][i] = 'N';
        }
        return 1;
      }
      else{
        if(c2 - c != tam -1){
          printf("\n!!! Barco com tamanho incorreto !!!\n");
          return 0;
        };
        for(i=c;i<=c2;i++){
          if(mat[l][i] != ' '){
            printf("\n!!! Área já preenchida !!!\n");
            return 0;
          }
        }
        for(i=c;i<=c2;i++){
          mat[l][i] = 'N';
        }
        return 1;
      }
    }
    else if(c == c2 && l != l2){
      if(l > l2){
        if(l - l2 != tam-1){
          printf("\n!!! Barco com tamanho incorreto !!!\n");
          return 0;
    };
        for(i=l;i>=l2;i--){
          if(mat[i][c] != ' '){
            printf("\n!!! Área já preenchida !!!\n");
            return 0;
          }
        }
        for(i=l;i>=l2;i--){
          mat[i][c] = 'N';
        }
        return 1;
      }
      else{
        if(l2 - l != tam-1 ){
          printf("\n!!! Barco com tamanho incorreto !!!\n");
          return 0;
        }
        for(i=l;i<=l2;i++){
          if(mat[i][c] != ' '){
            printf("\n!!! Área já preenchida !!!\n");
            return 0;
          }
        }
        for(i=l;i<=l2;i++){
          mat[i][c] = 'N';
        }
        return 1;
      }
    }
    else{
      printf("\n!!! Inválido !!!\n");
      return 0;
    }
    
  }
  }

// #################################################
//Mostrar o tabuleiro.
void printab(char mat[][10]){

  int i;
  
    printf("\n---0--1--2--3--4--5--6--7--8--9\n");
  for(i=0;i<10;i++){
    printf("%c-[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",alf[i],mat[i][0],mat[i][1],mat[i][2],mat[i][3],mat[i][4],mat[i][5],mat[i][6],mat[i][7],mat[i][8],mat[i][9]);
    }
}

// #################################################

int play(char mat[][10], char mat2[][10])
{
  char pos[3], a = 0, b = 0, k = 0, l = 0, c = 0, ambas = 0, erro = 1;
  
  while(erro == 1){
  printab(mat);
  printf("\nEm qual posição você deseja atacar? ");
    fgets(pos, 3, stdin);
    size_t ln = strlen(pos) - 1;
    if(pos[ln] == '\n')
       pos[ln] = '\0';

    pos[0] = toupper(pos[0]);

    for(a=0;a<10;a++){
      if(pos[0] == alf[a]){
        ambas++;
      };
    }

    for(k=0;k<10;k++){
      if(pos[0] == alf[k]){
        l = nums[k];
      };
    }
    c = pos[1] - '0';
    getchar();

    for(b=0;b<10;b++){
      if(c == nums[b]){
        ambas++;
      };
    }

    if(ambas != 2){
      printf("\n!!! Insira uma posição válida !!!\n");
      erro = 1;
      ambas = 0;
    }
    else if(ambas == 2){
      erro = 0;
      ambas = 0;
    };
    }

  if(mat2[l][c] == 'N'){
    mat[l][c] = 'O';
    printab(mat);
    printf("\nBarco inimigo atingido!\n");
    getchar();
    return 1;
  }
  else{
    mat[l][c] = 'X';
    printab(mat);
    printf("\nTiro errado!\n");
    getchar();
    return 0;
  }
}