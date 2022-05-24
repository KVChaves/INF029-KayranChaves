#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
//####################################################################

struct Pos
{
	int num;
	struct Pos *prox;
};
typedef struct Pos pos;

//####################################################################

void listar(pos* ptr, int num){
	pos *referencia;
	for(referencia= ptr;referencia!= NULL; referencia=referencia->prox){
		  printf("> %d\n",referencia->num);
	}
}

//####################################################################

void inserir(pos **p, int Num){
  pos *aux, *novo = malloc(sizeof(pos));  

    if(novo){
        novo->num = Num;
        
        if(*p == NULL){ // a lista está vazia?
            novo->prox = NULL;
            *p = novo;
        }
        else if(novo->num < (*p)->num){ // é o menor?
            novo->prox = *p;
            *p = novo;
        }
        else{ // inserção no meio ou no final da lista
            aux = *p;
            while(aux->prox && novo->num > aux->prox->num)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}
//####################################################################

pos *remover(int Num , pos *ptr){
	pos* busca; 
	pos* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->num == Num) {
      printf("\n!!! Número %d excluido da estrutura. !!!\n", Num);
        if (anterior != NULL){ //primeiro elemento da lista
				  anterior->prox = busca -> prox;
				  return ptr;
			  }
        else{
				  ptr = busca-> prox;
				  return ptr;
			  };
      };
		anterior = busca;
		busca = busca->prox;
	}
  printf("\n!!! Elemento não encontrado !!!\n");
  return ptr;
}

//####################################################################
int menu(){
  int op;
  printf("---------------------------------------------\n");
  printf("##### TRABALHO 2 #####\n\n");
  printf("1 - Inserir elemento.\n2 - Listar os números de todas as estruturas.\n3 - Listar números ordenados por estrutura.\n4 - Listar todos os números ordenados.\n5 - Excluir um elemento.\n6 - Aumentar o tamanho de uma estrutura.\n7 - Sair.\n\n> ");
  scanf("%d",&op);
  return op;
}

//####################################################################
int main(){
  pos *geral = NULL;
  pos *estrutura[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}; //Vetor de ponteiros
  int lim_est[10] = {2,4,0,8,3,0,5,0,0,0}; //Limite de cada coluna
  int tam_est[10] = {1,2,0,3,1,0,3,0,0,0}; //Espaços ocupados
  int start;
  //####################################################################
  inserir(&estrutura[0], 4);
  inserir(&geral, 4);
  inserir(&estrutura[1], 5);
  inserir(&geral, 5);
  inserir(&estrutura[1], 3);
  inserir(&geral, 3);
  inserir(&estrutura[3], 2);
  inserir(&geral, 2);
  inserir(&estrutura[3], 35);
  inserir(&geral, 35);
  inserir(&estrutura[3], 23);
  inserir(&geral, 23);
  inserir(&estrutura[4], 6);
  inserir(&geral, 6);
  inserir(&estrutura[6], -1);
  inserir(&geral, -1);
  inserir(&estrutura[6], 18);
  inserir(&geral, 18);
  inserir(&estrutura[6], -16);
  inserir(&geral, -16);
  //####################################################################
  while(start != 7){
    start = menu();
    int aux, tam, elt;
    switch(start){
      case 1:{
        int psc, val;
        printf("Deseja inserir qual valor? ");
        scanf("%d",&val);;
        getchar();
        printf("Em qual posição da estrutura principal? ");
        scanf("%d",&psc);
        getchar();
        psc = psc - 1;
        if(lim_est[psc] == 0){
          printf("Estrutura não iniciada, informe um tamanho para ela e reinicie o processo.\n> ");
          scanf("%d",&tam);
          getchar();
          lim_est[psc] = tam;
          printf("\n!!! Estrutura iniciada. !!!\n");
        }
        else if(lim_est[psc] == tam_est[psc]){
          printf("\n!!! Tamanho máximo da estrutura atingido. !!!\n");
        }
        else{
          inserir(&estrutura[psc], val);
          inserir(&geral, val);
          printf("\n!!! Valor inserido com sucesso. !!!\n");
        }
        break;
      }
      case 2:{
        for(int i=0;i<10;i++){
          printf("\n###############################\n");
  printf("Estrutura Número %d:\n\n",i+1);
          listar(estrutura[i], i);
        }
        printf("\n###############################\n");
        break;
      }
      case 3:{
        printf("\nDe qual posição da estrutura? ");
        scanf("%d",&aux);
        printf("\n###############################\n");
        printf("Estrutura Número %d:\n\n",aux);
        listar(estrutura[aux-1],aux);
        printf("\n###############################\n");
        break;
      }
      case 4:{
        printf("\n###############################\n");
        printf("Todos os elementos:\n\n");
        listar(geral, 0);
        printf("\n###############################\n");
        break;
      }
      case 5:{
        printf("\nRemover elemento em qual posição da estrutura? ");
        scanf("%d",&aux);
        aux = aux - 1;
        printf("Informe o elemento: ");
        scanf("%d",&elt);
        estrutura[aux] = remover(elt, estrutura[aux]);
        break;
      }
      case 6:{
        printf("Aumentar tamanho de qual posição da estrutura? ");
        scanf("%d",&aux);
        printf("Adicionar mais quantos espaços? ");
        scanf("%d",&tam);
        lim_est[aux-1] = lim_est[aux-1] + tam;
        break;
      }
      }
    }
  }