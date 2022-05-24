#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 20

typedef struct veiculo
{
    char marca[tam];
    char modelo[tam];
    int ano;
} carro;

carro car;
carro* ppp = &car;

void ler_carro(carro a);
void imprimir(carro a);

int main(){
  ler_carro(car);
  imprimir(car);
}

void ler_carro(carro a){
  char marca[tam];
  char modelo[tam];
  int ano;
  
  printf("Digite a marca do carro: ");
  fgets(marca, tam, stdin);
  size_t ln = strlen(marca) - 1;
  if(marca[ln] == '\n')
     marca[ln] = '\0';

  printf("Digite o modelo do carro: ");
  fgets(modelo, tam, stdin);
  ln = strlen(modelo) - 1;
  if(modelo[ln] == '\n')
     modelo[ln] = '\0';

  printf("Digite o ano do carro: ");
  scanf("%d",&ano);
  getchar();

  strcpy(ppp->marca,marca);
  strcpy(ppp->modelo,modelo);
  ppp->ano = ano;

}

void imprimir(carro a){
  printf("\nMarca:.....%s\n",a.marca);
  printf("Modelo:....%s\n",a.modelo);
  printf("Ano:.......%d",a.ano);
}