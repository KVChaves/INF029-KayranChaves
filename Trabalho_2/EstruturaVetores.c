//POSIÇÃO PRECISA PERDER 1 VALOR

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

No *principal[TAM];
tams tamanhos[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
  int retorno = 0;
  posicao = posicao--;

  if(posicao > 10 || 1 > posicao){
    // se posição é um valor válido {entre 1 e 10}
    return POSICAO_INVALIDA;
  }  
  else if(tamanhos[posicao].limite != 0){
    // a posicao pode já existir estrutura auxiliar
    return JA_TEM_ESTRUTURA_AUXILIAR;;
  }

  else if(tamanho > 20){
    // o tamanho ser muito grande
    return SEM_ESPACO_DE_MEMORIA;;
  }
  else if(tamanho < 1){
    // o tamanho nao pode ser menor que 1
    return TAMANHO_INVALIDO;
  }
  else{
    // deu tudo certo, crie
    tamanhos[posicao].limite = tamanho;
    return SUCESSO;
  }
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
  int retorno = 0;
  posicao = posicao--;
  
  if(posicao > 10 || 1 > posicao){
    return POSICAO_INVALIDA;
  }
  else if(tamanhos[posicao].limite == 0){
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else if(tamanhos[posicao].limite == tamanhos[posicao].ocupado){
    return SEM_ESPACO;
  }
  else{
    // testar se existe a estrutura auxiliar
    //insere
    tamanhos[posicao].ocupado++;
    
    No *aux, *novo = malloc(sizeof(No));  

    novo->conteudo = valor;
        
    if(principal[posicao] == NULL){ // a lista está vazia?
      novo->prox = NULL;
      principal[posicao] = novo;
    }
    else{ // é o menor?
      /*novo->prox = principal[posicao];
      principal[posicao] = novo;*/
      aux = principal[posicao];
      while(aux->prox != NULL)
        aux = aux->prox;
        novo->prox = aux->prox;
        aux->prox = novo;
    }

    return SUCESSO;  
}
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  int retorno = 0;
  posicao = posicao--;

  if(posicao > 10 || 1 > posicao){
    return POSICAO_INVALIDA;
  }
  else if(tamanhos[posicao].limite == 0){
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else if(tamanhos[posicao].ocupado == 0){
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  else{
    principal[posicao] = removerFinal(principal[posicao]);
    tamanhos[posicao].ocupado--;
    return SUCESSO;
  }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  int retorno = 0;
  posicao = posicao--;

  if(posicao > 10 || 1 > posicao){
    return POSICAO_INVALIDA;
  }
  else if(tamanhos[posicao].limite == 0){
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else if(tamanhos[posicao].ocupado == 0){
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  else{
    if(buscar(valor, principal[posicao]) == 0){
      return NUMERO_INEXISTENTE;
    }
    else{
      principal[posicao] = removerNum(valor, principal[posicao]);
      tamanhos[posicao].ocupado--;
      return SUCESSO; 
    }
  }
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int i, retorno;
  No *referencia = malloc(sizeof(No));
  referencia = principal[posicao];
    
    if (posicao > 10 || posicao < 1)
        return POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (tamanhos[posicao].limite != 0)
        {
          if (tamanhos[posicao].ocupado > 0){
          for (i = 0; i < tamanhos[posicao].ocupado; i++){
            vetorAux[i] = referencia->conteudo;
            referencia = referencia->prox;
          }
          return SUCESSO;
            }
        }       
         else
        {
          return SEM_ESTRUTURA_AUXILIAR;
        }
  
    }
}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno = 0, tam = 0;
  int i = 0, j, x, aux;
  No *referencia = malloc(sizeof(No));
  posicao = posicao--;

  if(posicao > 10 || 1 > posicao){
    return POSICAO_INVALIDA;
  }
  else if(tamanhos[posicao].limite == 0){
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else{
    getDadosEstruturaAuxiliar(posicao, vetorAux);
    // ordenação
            for (i = 0; i < tamanhos[posicao].ocupado; i++){
            for (j = i + 1; j < tamanhos[posicao].ocupado; j++){
              if (vetorAux[i] > vetorAux[j]){
                aux = vetorAux[i];
                vetorAux[i] = vetorAux[j];
                vetorAux[j] = aux;
              }
            }
          }
  
    return SUCESSO;
  }
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int retorno = 0, vazio = 0, j = 0, i = 0, k = 0;
  No *referencia = malloc(sizeof(No));

  for(i=0;i<10;i++){
    if(tamanhos[i].ocupado == 0){
      vazio++;
    };
  }
  if(vazio == 10){
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  };
  
  for(i=0;i<10;i++){
    referencia = principal[i];
    for (j = 0; j < tamanhos[i].ocupado; j++){
      vetorAux[k] = referencia->conteudo;
      referencia = referencia->prox;
      k++;
    }
  }

  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int retorno = 0, vazio = 0, j = 0, i = 0, x, tam = 0, aux;
  No *referencia = malloc(sizeof(No));

  for(i=0;i<10;i++){
    tam = tam + tamanhos[i].ocupado;
    if(tamanhos[i].ocupado == 0){
      vazio++;
    };
  }
  if(vazio == 10){
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  };
  
  getDadosDeTodasEstruturasAuxiliares(vetorAux);
  // ordenação
            for (i = 0; i < tam; i++){
            for (j = i + 1; j < tam; j++){
              if (vetorAux[i] > vetorAux[j]){
                aux = vetorAux[i];
                vetorAux[i] = vetorAux[j];
                vetorAux[j] = aux;
              }
            }
          }
  
  return SUCESSO;
}


/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
  int retorno = 0;
  posicao = posicao--;

  if(posicao > 10 || 1 > posicao){
    return POSICAO_INVALIDA;
  }
  else if(tamanhos[posicao].limite == 0){
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else{
    if(novoTamanho > 0){
      tamanhos[posicao].limite = tamanhos[posicao].limite + novoTamanho;
      return SUCESSO;
    }
    else{
      if(tamanhos[posicao].limite + novoTamanho < 1){
        return NOVO_TAMANHO_INVALIDO;
      }
      else{
        tamanhos[posicao].limite = tamanhos[posicao].limite + novoTamanho;
        if(tamanhos[posicao].limite < tamanhos[posicao].ocupado){
          int num = tamanhos[posicao].ocupado - tamanhos[posicao].limite;
          for(int i=0;i<num;i++){
            excluirNumeroDoFinaldaEstrutura(posicao);
          }
          tamanhos[posicao].ocupado = tamanhos[posicao].limite;
        };
        return SUCESSO;
      }
    }
    
  }
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
  int retorno = 0;
  posicao = posicao--;

  if(tamanhos[posicao].ocupado == 0){
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  else if(tamanhos[posicao].limite == 0){
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else if(posicao > 10 || 1 > posicao){
    return POSICAO_INVALIDA;
  }
  else{
    retorno = tamanhos[posicao].ocupado;
    return retorno;
  }
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
  No *cabecote = malloc(sizeof(No));

  int i=0, j=0, tam = 0;

  for(i=0;i<10;i++){
    tam = tam + tamanhos[i].ocupado;
  }

  if(tam == 0){
    return NULL;
  };

  int vet[tam];
  
  getDadosDeTodasEstruturasAuxiliares(vet);

  for(j=0;j<tam;j++){
    inserirCabecote(&cabecote->prox, vet[j]);
  }
  return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
  No *referencia = malloc(sizeof(No));
  int i = 0, j = 0, tam = 0;
  
  for(i=0;i<10;i++){
    tam = tam + tamanhos[i].ocupado;
  }

  referencia = inicio->prox;
  for (j = 0; j < tam; j++){
    vetorAux[j] = referencia->conteudo;
    referencia = referencia->prox;
  }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
  No *aux = *inicio;
  No *prox = aux;

  for (aux = *inicio; aux != NULL; aux = prox){
    prox = aux->prox;
    free(aux);
  }
  *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/
void inicializar()
{
  int i;
  
  for(i=0;i<10;i++){
    principal[i] = NULL;
    tamanhos[i].ocupado = 0;
    tamanhos[i].limite = 0;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/
void finalizar()
{
  int i = 0;
  
  for(i=0;i<10;i++){
    free(principal[i]);
  }
}

//#######################################################################
//#######################################################################
//#######################################################################

void ordenar(int vetor[], int tamanho) 
{
  for (int i = 0; i < tamanho - 1; ++i) {
    for (int j = i + 1; j < tamanho; ++j) {
      if (vetor[i] > vetor[j]) {
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
      }
    }
  }
}

No *removerFinal(No *pont){
	No* busca; 
	No* anterior;
	anterior = NULL;
	busca = pont;
	while (busca != NULL) {
		if (busca->prox == NULL) {
        if (anterior != NULL){ //primeiro elemento da lista
				  anterior->prox = busca -> prox;
				  return pont;
			  }
        else{
				  pont = busca-> prox;
				  return pont;
			  };
      };
		anterior = busca;
		busca = busca->prox;
	}
  return pont;
}

No *removerNum(int Num , No *ptr){
	No* busca; 
	No* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->conteudo == Num) {
        if (anterior != NULL){
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
}

int buscar(int Num , No *ptr){
	No* busca; 
	busca = ptr;
	while (busca != NULL) {
		if (busca->conteudo == Num) {
      return 1;
		};
		busca = busca->prox;
  }
  return 0;
}

void inserirCabecote(No **p, int valor){
  No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->conteudo = valor;

        if(*p == NULL){ // a lista está vazia?
            novo->prox = NULL;
            *p = novo;
        }
        else{ // inserção no meio ou no final da lista
            aux = *p;
            while(aux->prox != NULL)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}