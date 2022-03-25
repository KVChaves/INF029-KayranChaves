/* 
! Incluir Alunos nas Disciplinas.
! Validar CPF.
! Listar Alunos ordenados por data de nascimento.
! Listar Professores ordenados por data de nascimento.
! Lista de pessoas (professor/aluno) a partir de uma string de busca. O usuário informa no mínimo três letras e deve ser listado todas as pessoas que contem essas três letras no nome.
! Lista de alunos matriculados em menos de 3 disciplinas.
! Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define n 50
#define completado 1

//-------STRUCTS-------

typedef struct data
{
    int dia;
    int mes;
    int ano;
} datanasc;

typedef struct pessoas
{
    char nome[40];
    char sexo[2];
    char cpf[15];
    datanasc data;
    int matricula;
} cadPessoas;

typedef struct disciplina
{
    char nomeDis[30];
    char codDis[10];
    int semDis;
    int alunosDis[n];
    char profDis[40];   
} cadDis;

//--------------------

int menuprincipal();
int menuAlunos();
int menuProf();
int menuDis();
int menuRel();

int cadastro(cadPessoas vet[], int num);
void listar(cadPessoas vet[], int num);
int atualizar(cadPessoas vet[], int num);
int excluir(cadPessoas vet[], int num);

int cadastrodis(cadDis listDis[], int numDis);
void listardis(cadDis listDis[], int numDis);
int atualizardis(cadDis listDis[], int numDis);
int excluirdis(cadDis listDis[], int numDis);
int incluiraluno (int mat[][n], cadDis vet[],  cadPessoas vet2[], int num, int num2);
void listardisalunos(cadDis vet[], int num, int mat[][n], cadPessoas vet2[], int num2);

void sexo(cadPessoas vet[], int num);
void alfabetica(cadPessoas vet[], int num);
void aniversarios(cadPessoas vet[], cadPessoas vet2[], int num, int num2);
//void busca(cadPessoas vet[], cadPessoas vet2[], int num, int num2);

cadPessoas listAlunos[n];
cadPessoas listProf[n];
cadDis listDis[n];
int alunosDis[n][n]; //[num da disciplina][num dos alunos] primeira coluna armazena o número de alunos da disciplina.
char *pt1, *pt2;
int numAlunos = 0;
int numProf = 0;
int numDis = 0;
int opcao, opcaoAlunos, opcaoProf, opcaoDis, opcaoRel, retorno;
int sair = 0;

//------MAIN-------

int main(void)
{  
    printf("- PROJETO ESCOLA -");

    int i;
    for(i=0;i<n;i++){
      alunosDis[i][0] = 1;
    }

    while (!sair)
    {
        opcao = menuprincipal();

        switch (opcao){
          case 0:{
            printf("\nSAINDO...\n");
            sair = 1;
            break;
          }
          case 1:{
            opcaoAlunos = menuAlunos();
            switch (opcaoAlunos){
              case 0:{
                break;
              }
              case 1:{
                retorno = cadastro(listAlunos,numAlunos);
                if (retorno == completado)
                {
                  printf("\nAluno cadastrado com sucesso!\n");
                  numAlunos++;
                }
                break;
              }
              case 2:{
                listar(listAlunos, numAlunos);
                break;
              } 
              case 3:{
                retorno = atualizar(listAlunos, numAlunos);
                if (retorno == completado)
                {
                  printf("\nDados atualizados com sucesso.");
                }
                break;
              }
              case 4:{
                retorno = excluir(listAlunos, numAlunos);
                if(retorno == completado){
                  numAlunos--;
                }
                break;
              }
              default:{
                printf("Opção Inválida. Tente novamente.");
                break;
              }
            }
            break;
          }//Aluno.
          case 2:{
            opcaoProf = menuProf();
            switch (opcaoProf){
              case 0:{
                break;
              }
              case 1:{
                retorno = cadastro(listProf,numProf);
                if (retorno == completado)
                {
                  printf("\nProfessor cadastrado com sucesso!\n");
                  numProf++;
                }
                break;
              }
              case 2:{
                listar(listProf, numProf);
                break;
              }
              case 3:{
                atualizar(listProf, numProf);
                break;
              }
              case 4:{
                retorno = excluir(listProf, numProf);
                if(retorno == completado){
                  numProf--;
                }
                break;
              }
              default:{
                printf("\nOpção Inválida. Tente novamente.\n");
                break;
              }
            }
            break;
          }//Prof.
          case 3:{
            opcaoDis=menuDis();
            switch(opcaoDis){
              case 0:{
                break;
                }
              case 1:{
                retorno = cadastrodis(listDis,numDis);
                if (retorno == completado)
                {
                  printf("\nDisciplina cadastrada com sucesso!\n");
                  numDis++;
                }
                break;
              }
              case 2:{
                listardis(listDis, numDis);
                break;
              }
              case 3:{
                atualizardis(listDis, numDis);
                break;
              }
              case 4:{
                retorno = excluirdis(listDis, numDis);
                if(retorno == completado){
                  numDis--;
                }
                break;
                }
              case 5:{
                incluiraluno(alunosDis, listDis, listAlunos, numDis, numAlunos);
                break;
              }
              case 6:{
                listardisalunos(listDis, numDis, alunosDis, listAlunos, numAlunos);
                break;
              }
              }
            break;
            }//Disciplina.
          case 4:{
            opcaoRel = menuRel();
            switch(opcaoRel){
              case 0:{
                  break;
                }
              case 1:{
                sexo(listAlunos, numAlunos);
                break;
              }
              case 2:{
                sexo(listProf, numProf);
                break;
              }
              case 3:{
                alfabetica(listAlunos, numAlunos);
                break;
              }
              case 4:{
                alfabetica(listProf, numProf);
                break;
              }
              case 5:{
                aniversarios(listProf, listAlunos, numProf ,numAlunos );
                break;
              }
              /*case 6:{
                busca(listAlunos, listProf, numAlunos, numProf);
              }*/
              default:{
                printf("\nOpção Inválida. Tente novamente.\n");
                break;
              }
              break;
            }
          }//Relatórios.
          }
    }
}

//-------F. MENUS-------

int menuprincipal()
{
    int opcao;
    printf("\n-------------------\nDigite uma Opção:\n\n");
    printf("0 - Sair.\n");
    printf("1 - Gerenciar Alunos.\n");
    printf("2 - Gerenciar Professores.\n");
    printf("3 - Gerenciar Disciplinas.\n");
    printf("4 - Relatórios.\n");
    printf("\n> ");
    scanf("%d", &opcao);

    return opcao;
}

int menuAlunos()
{
    int opcaoAlunos;
    printf("\n-------------------\n.....ALUNOS.....\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Aluno.\n");
    printf("2 - Listar Alunos.\n");
    printf("3 - Atualizar Aluno.\n");
    printf("4 - Excluir Aluno.\n");
    printf("\n> ");
    scanf("%d", &opcaoAlunos);

    return opcaoAlunos;
}

int menuProf()
{
    int opcaoProf;
    printf("\n-------------------\n...PROFESSORES...\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Professor.\n");
    printf("2 - Listar Professores.\n");
    printf("3 - Atualizar Professor.\n");
    printf("4 - Excluir Professor.\n");
    printf("\n> ");
    scanf("%d", &opcaoProf);

    return opcaoProf;
}

int menuDis()
{
    int opcaoDis;
    printf("\n-------------------\n...DISCIPLINAS...\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Cadastrar Disciplina.\n");
    printf("2 - Listar Disciplinas.\n");
    printf("3 - Atualizar Disciplina.\n");
    printf("4 - Excluir Disciplina.\n");
    printf("5 - Incluir Aluno na Disciplina.\n");
    printf("\n> ");
    scanf("%d", &opcaoDis);
    getchar();

    return opcaoDis;
}

int menuRel()
{
  int opcaoRel;
    printf("\n-------------------\n...RELATÓRIOS...\nDigite uma Opção:\n\n");
    printf("0 - Voltar.\n");
    printf("1 - Listar Alunos por Sexo.\n");
    printf("2 - Listar Professores por Sexo\n");
    printf("3 - Listar Alunos em Ordem Alfabetica.\n");
    printf("4 - Listar Professores em Ordem Alfabetica.\n");
    printf("5 - Aniversáriantes do Mês.\n");
    printf("6 - Busca a partir de 3 letras.\n");
    printf("\n> ");
    scanf("%d", &opcaoRel);
    getchar();

    return opcaoRel;
}

//-------F. PESSOAS------

int cadastro(cadPessoas vet[], int num)
{
    int tcpf, teste = 1, tesmat = 1, tescpf = 1, i;

    while(tesmat > 0){
      printf("Digite o número de Matrícula: ");
      scanf("%d", &vet[num].matricula);
      getchar();
      
      tesmat = 0;
      for(i=0;i<num;i++){
        if(vet[num].matricula == vet[i].matricula){
          tesmat++;
          }
      }
        }

    printf("Digite o nome completo: ");
    fgets(vet[num].nome, 40, stdin);
    size_t ln = strlen(vet[num].nome) - 1;
    if (vet[num].nome[ln] == '\n')
        vet[num].nome[ln] = '\0';

    while(teste != 0){
      printf("Digite o sexo (M/F): ");
      fgets(vet[num].sexo, 2, stdin);
      ln = strlen(vet[num].sexo) -1;
      if (vet[num].sexo[ln] == '\n')
          vet[num].sexo[ln] = '\0';
      
      teste = strcmp(vet[num].sexo,"M");
        if(teste != 0){
          teste = strcmp(vet[num].sexo,"F");
      }
      if(teste != 0){
        printf("Sexo Inválido.\n");
      }
      }

    printf("Digite a data de nascimento:\n");
    printf("Ano: ");
    scanf("%d", &vet[num].data.ano);
  
    while(vet[num].data.ano < 1910){
      printf("Inválido.\nAno: ");
      scanf("%d", &vet[num].data.ano);
      }

    printf("Mês: ");
    scanf("%d",&vet[num].data.mes);
    while(vet[num].data.mes>12){
      printf("Inválido.\nMês: ");
      scanf("%d",&vet[num].data.mes);
      } 

    printf("Dia: ");
    scanf("%d",&vet[num].data.dia);

    if(vet[num].data.mes==4||6||9||11)
    {
      while(vet[num].data.dia>30){
        printf("Inválido.\nDia: ");
        scanf("%d",&vet[num].data.dia);
        } 
    }
    if(vet[num].data.mes==1||3||5||7||8||10||12)
    {
      while(vet[num].data.dia>31){
        printf("Inválido.\nDia: ");
        scanf("%d",&vet[num].data.dia);
      }
    }
    else{
      while(vet[num].data.dia>29){
        printf("Inválido.\nDia: ");
        scanf("%d",&vet[num].data.dia);
      }
    }
    getchar();

    while(tescpf > 0){
      printf("Digite o CPF: ");
      fgets(vet[num].cpf, 15, stdin);
      ln = strlen(vet[num].cpf) - 1;
      if (vet[num].cpf[ln] == '\n')
          vet[num].cpf[ln] = '\0';
      
      tescpf = 0;
      for(i=0;i<num;i++){
        tcpf = strcmp(vet[num].cpf, vet[i].cpf);
        if(tcpf == 0){
          tesmat++;
          }
      }
        }


    __fpurge(stdin);

    return completado;
}

void listar(cadPessoas vet[], int num)
{
    printf("\n*******************");
    for (int i = 0; i < num; i++)
    {
        printf("\n----------\n");
        printf("Nome: %s\n", vet[i].nome);
        printf("Matricula: %d\n", vet[i].matricula);
        printf("CPF: %s\n", vet[i].cpf);
        printf("Sexo: %s\n", vet[i].sexo);
        printf("Data: %d-%d-%d \n", vet[i].data.dia,vet[i].data.mes,vet[i].data.ano);
    }
    printf("\n*******************");

  __fpurge(stdin);
}

int atualizar(cadPessoas vet[], int num)
{
  int i, ndm, teste = 1, ndp = -1, conf = 0;

  while(conf == 0){
  printf("\nInforme a matrícula da pessoa a ser atualizada: ");
  scanf("%d",&ndm);
  getchar();

  conf = 0;
  for(i=0;i<num;i++){
    ndp++;
    if(vet[i].matricula == ndm){
      conf++;
      i = num;
    }
  }
    }
  
    printf("\nDigite a nova matrícula: ");
    scanf("%d", &vet[ndp].matricula);
    getchar();

    printf("Digite o nome: ");
    fgets(vet[ndp].nome, 40, stdin);
    size_t ln = strlen(vet[ndp].nome) - 1;
    if (vet[ndp].nome[ln] == '\n')
        vet[ndp].nome[ln] = '\0';

    while(teste != 0){
      printf("Digite o sexo (M/F): ");
      fgets(vet[ndp].sexo, 2, stdin);
      ln = strlen(vet[ndp].sexo) -1;
      if (vet[ndp].sexo[ln] == '\n')
          vet[ndp].sexo[ln] = '\0';
      
      teste = strcmp(vet[ndp].sexo,"M");
        if(teste != 0){
          teste = strcmp(vet[ndp].sexo,"F");
      }
      if(teste != 0){
        printf("Sexo Inválido.\n");
      }
      }

printf("Digite a data de nascimento:\n");
    printf("Ano: ");
    scanf("%d", &vet[ndp].data.ano);
  
    while(vet[ndp].data.ano < 1910){
      printf("Inválido.\nAno: ");
      scanf("%d", &vet[ndp].data.ano);
      }

    printf("Mês: ");
    scanf("%d",&vet[ndp].data.mes);
    while(vet[ndp].data.mes>12){
      printf("Inválido.\nMês: ");
      scanf("%d",&vet[ndp].data.mes);
      } 

    printf("Dia: ");
    scanf("%d",&vet[ndp].data.dia);

    if(vet[ndp].data.mes==4||6||9||11)
    {
      while(vet[ndp].data.dia>30){
        printf("Inválido.\nDia: ");
        scanf("%d",&vet[ndp].data.dia);
        } 
    }
    if(vet[ndp].data.mes==1||3||5||7||8||10||12)
    {
      while(vet[ndp].data.dia>31){
        printf("Inválido.\nDia: ");
        scanf("%d",&vet[ndp].data.dia);
      }
    }
    else{
      while(vet[ndp].data.dia>29){
        printf("Inválido.\nDia: ");
        scanf("%d",&vet[ndp].data.dia);
      }
    }
    getchar();
  
    printf("Digite o CPF: ");
    fgets(vet[ndp].cpf, 15, stdin);
    ln = strlen(vet[ndp].cpf) -1;
    if (vet[ndp].cpf[ln] == '\n')
        vet[ndp].cpf[ln] = '\0';

    __fpurge(stdin);
    
    return completado;
  }

int excluir(cadPessoas vet[], int num)
{
  int i, ndp = -1, ndm, conf = 0;

  while(conf == 0){
  printf("\nInforme a matrícula da pessoa a ser excluida: ");
  scanf("%d",&ndm);
  getchar();

  conf = 0;
  for(i=0;i<num;i++){
    ndp++;
    if(vet[i].matricula == ndm){
      conf++;
      i = num;
    }
  }
    }  

  for(ndp;ndp<num-1;ndp++){
    strcpy(vet[ndp].nome, vet[ndp+1].nome);
    strcpy(vet[ndp].cpf, vet[ndp+1].cpf);
    strcpy(vet[ndp].sexo, vet[ndp+1].sexo);
    vet[ndp].matricula = vet[ndp+1].matricula;
    vet[ndp].data.ano = vet[ndp+1].data.ano;
    vet[ndp].data.mes = vet[ndp+1].data.mes;
    vet[ndp].data.mes = vet[ndp+1].data.dia;
  }
  
  cadPessoas *ptr;
  ptr = &vet[num-1];
  ptr = NULL;

    __fpurge(stdin);
    printf("\nDados excluídos com sucesso.");
    return completado;
  }

//-------F. DISCIPLINAS-------

int cadastrodis(cadDis listDis[], int numDis)
{

  int i, teste;
  
  printf("Digite o semestre da disciplina: ");
  scanf("%d", &listDis[numDis].semDis);
  getchar();
  
  printf("Digite o nome do disciplina: ");
  fgets(listDis[numDis].nomeDis, 40, stdin);
  size_t ln = strlen(listDis[numDis].nomeDis) - 1;
  if (listDis[numDis].nomeDis[ln] == '\n')
      listDis[numDis].nomeDis[ln] = '\0';

  printf("Digite o código da disciplina: ");
  fgets(listDis[numDis].codDis, 10, stdin);
  ln = strlen(listDis[numDis].codDis) -1;
  if (listDis[numDis].codDis[ln] == '\n')
      listDis[numDis].codDis[ln] = '\0';

  printf("Insira o nome do professor: ");
  fgets(listDis[numDis].profDis, 40, stdin);
  ln = strlen(listDis[numDis].profDis) -1;
  if (listDis[numDis].profDis[ln] == '\n')
      listDis[numDis].profDis[ln] = '\0';

  for(i=0;i<numProf;i++){
    teste = strcmp(listDis[numDis].profDis,listProf[i].nome);
    if(teste == 0){
      i=numProf;
    }
    }
  if(teste!=0){
    printf("\nERRO: Professor não encontrado.");
    }
  else{
    __fpurge(stdin);
    return completado;
  }
}

void listardis(cadDis listDis[], int numDis)
{
      printf("\n*******************\n");
      for (int i = 0; i < numDis; i++)
    {
        printf("----------\n");
        printf("Nome: %s\n", listDis[i].nomeDis);
        printf("Código: %s\n", listDis[i].codDis);
        printf("Semestre: %d\n", listDis[i].semDis);
        printf("Professor: %s\n", listDis[i].profDis);
    }
      printf("\n*******************");
}

void listardisalunos(cadDis vet[], int num, int mat[][n], cadPessoas vet2[], int num2)
{
  int i, tam, teste, ndd, ndp, conf = 0;
  char codigo[10];

  while(conf == 0){
  printf("\nInforme o código da disciplina: ");
  fgets(codigo, 10, stdin);
  size_t ln = strlen(codigo) - 1;
  if (codigo[ln] == '\n')
      codigo[ln] = '\0';
  getchar();

  conf = 0;
  for(i=0;i<num;i++){
    teste = strcmp(vet[i].codDis, codigo);
    ndd++;
    if(teste == 0){
      conf++;
      i = num;
    }
  }
    }
        printf("----------\n");
        printf("Nome: %s\n", vet[ndd].nomeDis);
        printf("Código: %s\n", vet[ndd].codDis);
        printf("Semestre: %d\n", vet[ndd].semDis);
        printf("Professor: %s\n", vet[ndd].profDis);

  printf("\nAlunos Matriculados:\n\n");
  tam = mat[ndd][0];
  for(i=1;i<tam;i++){
    ndp = mat[ndd][i];
    printf("- %s",vet2[ndp].nome);
  }
}

int atualizardis(cadDis listDis[], int numDis)
{
  int i, ndd, teste, conf = 0;
  int nddm=numDis-1;
  char codigo[10];

  while(conf == 0){
  printf("\nInforme o código da disciplina a ser atualizada: ");
  fgets(codigo, 10, stdin);
  size_t ln = strlen(codigo) - 1;
  if (codigo[ln] == '\n')
      codigo[ln] = '\0';
  getchar();

  conf = 0;
  for(i=0;i<numDis;i++){
    teste = strcmp(listDis[i].codDis, codigo);
    ndd++;
    if(teste == 0){
      conf++;
      i = numDis;
    }
  }
    }
  
    printf("Digite o semestre da disciplina: ");
    scanf("%d", &listDis[ndd].semDis);
    getchar();
    
    printf("Digite o nome do disciplina: ");
    fgets(listDis[ndd].nomeDis, 40, stdin);
    size_t ln = strlen(listDis[ndd].nomeDis) - 1;
    if (listDis[ndd].nomeDis[ln] == '\n')
        listDis[ndd].nomeDis[ln] = '\0';

    printf("Digite o código da disciplina: ");
    fgets(listDis[ndd].codDis, 10, stdin);
    ln = strlen(listDis[ndd].codDis) -1;
    if (listDis[ndd].codDis[ln] == '\n')
        listDis[ndd].codDis[ln] = '\0';

  for(i=0;i<numProf;i++){
    teste = strcmp(listDis[ndd].profDis,listProf[i].nome);
    if(teste == 0){
      i=numProf;
    }
    }
  if(teste!=0){
    printf("\nERRO: Professor não encontrado.");
    }
  else{
    __fpurge(stdin);

    printf("\nDados atualizados com sucesso.");
    return completado;
  }
  }

int excluirdis(cadDis listDis[], int numDis)
{
  
  int i, ndd, teste, conf = 0;
  int nddm=numDis-1;
  char codigo[10];

  while(conf == 0){
  printf("\nInforme o código da disciplina a ser excluida: ");
  fgets(codigo, 10, stdin);
  size_t ln = strlen(codigo) - 1;
  if (codigo[ln] == '\n')
      codigo[ln] = '\0';
  getchar();

  conf = 0;
  for(i=0;i<numDis;i++){
    teste = strcmp(listDis[i].codDis, codigo);
    ndd++;
    if(teste == 0){
      conf++;
      i = numDis;
    }
  }
    }
  
  cadDis *ptr1, *ptr2, *ptr3;
  ptr1 = &listDis[ndd];
  ptr2 = &listDis[ndd+1];
  ptr3 = &listDis[ndd-1];
  
    for(ndd;ndd<numDis;ndd++){
      ptr1 = ptr2;
      ptr3 = NULL;
    }
    
    __fpurge(stdin);
    printf("\nDados excluídos com sucesso.");
    return completado;
    
  }    

int incluiraluno (int mat[][n], cadDis vet[],  cadPessoas vet2[], int num, int num2)
{
  int i, val, ndm, ndp, teste, conf = 0, ndd = -1;
  char codigo[10];
  
  while(conf == 0){
  printf("\nInforme o código da disciplina: ");
  fgets(codigo, 10, stdin);
  size_t ln = strlen(codigo) - 1;
  if (codigo[ln] == '\n')
      codigo[ln] = '\0';

  conf = 0;
  for(i=0;i<num;i++){
    teste = strcmp(vet[i].codDis, codigo);
    ndd++;
    if(teste == 0){
      conf++;
      i = num;
    }
  }
    }

  printf("Incluir aluno em %s.\n",vet[ndd].nomeDis);
  conf = 0;
  
  while(conf == 0){
  printf("\nInforme a matrícula do aluno a ser incluído: ");
  scanf("%d",&ndm);
  getchar();

  conf = 0;
  for(i=0;i<num2;i++){
    ndp++;
    if(vet2[i].matricula == ndm){
      conf++;
      i = num2;
    }
  }
    }

  val = mat[ndd][0];
  mat[ndd][val] = ndp;
  val++;
  mat[ndd][0]=val;

  printf("\nO aluno foi matriculado em %s.", vet[ndd].nomeDis);
  
}

//-------RELATÓRIOS------

void sexo(cadPessoas vet[], int num)
{
  int i, teste;
  printf("\nMulheres Cadastradas no Sistema:\n");
  for(i=0;i<num;i++){
    teste = strcmp(vet[i].sexo, "F");
    if(teste == 0){
      printf("\n- %s",vet[i].nome);
    }
  }
  printf("\n--------------------\nHomens Cadastrados no Sistema:\n");
  for(i=0;i<num;i++){
    teste = strcmp(vet[i].sexo, "M");
    if(teste == 0){
      printf("\n- %s",vet[i].nome);
    }
  }
}

void alfabetica(cadPessoas vet[], int num)
{
  cadPessoas alfabetica[n];
  int i, j, k;
  char aux[50];

  for(i=0;i<num;i++){
    strcpy(alfabetica[i].nome, listAlunos[i].nome);
  }
  
  printf("\nNomes em Ordem Alfabética:\n\n");
  for(i=0;i<num;i++){
    for(j = i+1; j < num; j++){
      k = strcmp(alfabetica[i].nome, alfabetica[j].nome);
      if(k > 0){
        strcpy(aux, alfabetica[i].nome);
        strcpy(alfabetica[i].nome, alfabetica[j].nome);
        strcpy(alfabetica[j].nome, aux);
      }
    }
  }
  for(i = 0; i < num; i++){
    printf("- %s\n", alfabetica[i].nome);
  }
}      

void aniversarios(cadPessoas vet[], cadPessoas vet2[], int num, int num2)
{
  int mes, i;
  printf("Informe o mês: \n");
  scanf("%d",&mes);

  printf("Anivérsariantes do Mês %d:\n\n",mes);
  for(i=0;i<num;i++){
    if(vet[i].data.mes == mes){
      printf("- %s \n",vet[i].nome);
    }
  }
  for(i=0;i<num2;i++){
    if(vet2[i].data.mes == mes){
      printf("- %s \n",vet2[i].nome); 
    }
}
}

/*void busca(cadPessoas vet[], cadPessoas vet2[], int num, int num2)
{
  string lt1[1], lt2[1], lt3[1];
  int teste;
  
  printf("Informe 3 letras para a pesquisa: \n");
  printf("> ");
  scanf("%s",&lt1);
  printf("> ");
  scanf("%s",&lt2);
  printf("> ");
  scanf("%s",&lt3);

  int i, j, k, l, tam;

  for(i=0;i<num;i++){
    tam = strlen(vet[i].nome);
    for(j=0;j<tam;j++){
      teste = strcmp(vet[i].nome[j], lt1);
      if(teste == 0){
        for(k=0;k<tam;k++){
          teste = strcmp(vet[i].nome[k], lt2);
          if(teste == 0){
            for(l=0;l<tam;l++){
              teste = strcmp(vet[i].nome[l], lt3);
              if(teste == 0){
                printf("%s",vet[i].nome);
                j = tam;
                k = tam;
                l = tam;
              }
          }
        }
      }
    }
    }
}

 for(i=0;i<num2;i++){
    tam = strlen(vet2[i].nome);
    for(j=0;j<tam;j++){
      teste = strcmp(vet2[i].nome[j], lt1);
      if(teste == 0){
        for(k=0;k<tam;k++){
          teste = strcmp(vet2[i].nome[k], lt2);
          if(teste == 0){
            for(l=0;l<tam;l++){
              teste = strcmp(vet2[i].nome[l], lt3);
              if(teste == 0){
                printf("%s",vet2[i].nome);
                j = tam;
                k = tam;
                l = tam;
              }
          }
        }
      }
    }
    }
}
}*/

/*void nascimentoAlunos (cadAlunos listAlunos[], int numAlunos)
{
  cadAlunos nascimento[n];
  int i, j, k;
  char aux[n];

  for(i=0;i<numAlunos;i++){
    strcpy(nascimento[i].nome, listAlunos[i].nome);
    strcpy(nascimento[i].dataAluno, listAlunos[i].dataAluno);
  
  printf("\nAlunos Cadastrados em Ordem de Nascimento:\n\n");
  for(i=0;i<numAlunos;i++){
    for(j = i+1; j < numAlunos; j++){
      if(nascimento[i].dataAluno > nascimento[j].dataAluno){
        strcpy(aux, nascimento[i].nome);
        strcpy(nascimento[i].nome, nascimento[j].nome);
        strcpy(nascimento[j].nome, aux);
      }
    }
  }
  for(i = 0; i < numAlunos; i++){
    printf("- %s\n", alfabetica[i].nome);
  }
}
  }*/