#include <stdlib.h>
#include <stdio.h>

int bolo(int a);

int main(){
  int bl = 3;
  printf("\n- O bolo tem %d fatias -\n",bl);
  bolo(bl);
}

int bolo(int a){
  if(a==1){
    printf("\nResta 1 fatia de bolo!");
    printf("\n> A última fatia foi comida.");
    bolo(a-1);
    }
  else if(a>0){
    printf("\nRestam %d fatias de bolo!",a);
    printf("\n> Uma fatia foi comida.");
    bolo(a-1);
  }
  else{
    printf("\n\nAcabou o bolo!");
    return 1;
  }
}

