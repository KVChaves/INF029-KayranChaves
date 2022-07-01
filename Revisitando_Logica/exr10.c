#include <stdio.h>
#include <string.h>

//Incompleto.

//Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas. Ao final imprima tudo. Utilize vetor e struct.

int main(){

  struct dados_pessoais
{
  char nome[40];
  char sexo[40];
  char cpf[15];
  int idade;
};

  struct dados_pessoais dados1;

  printf("- Dados Pessoais -\n\n");
  printf("Nome: ");
  fgets(dados1.nome,40,stdin);
  printf("Sexo: ");
  fgets(dados1.sexo,3,stdin);
  printf("CPF: ");
  fgets(dados1.cpf,13,stdin);
  printf("Idade: ");
  scanf("%d",&dados1.idade);
  
  printf("\n\n- Dados Cadastrados -\n\n");
  printf("Nome: %s",dados1.nome);
  printf("Sexo: %s",dados1.sexo);
  printf("CPF: %s",dados1.cpf);
  printf("Idade: %d",dados1.idade);
  
}