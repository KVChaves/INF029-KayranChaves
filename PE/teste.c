#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "teste.h"
#include "structs.h"

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
    printf("6 - Excluir Aluno da Disciplina.\n");
    printf("7 - Listar Disciplina com Alunos.\n");
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
    printf("7 - Disciplinas com Mais de 40 Vagas.\n");
    printf("8 - Alunos Matriculados em Menos de 3 Disciplinas.\n");
    printf("\n> ");
    scanf("%d", &opcaoRel);
    getchar();

    return opcaoRel;
  }

//---------------------

int cadastro(cadPessoas vet[], int num)
{
    int tcpf, tam, teste = 1, tesmat = 1, tescpf = 1, i;

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
      while(tam != 11){
      printf("Digite o CPF: ");
      fgets(vet[num].cpf, 15, stdin);
      ln = strlen(vet[num].cpf) - 1;
      if (vet[num].cpf[ln] == '\n')
          vet[num].cpf[ln] = '\0';
        
      tam = strlen(vet[num].cpf);
        
      tescpf = 0;
      for(i=0;i<num;i++){
        tcpf = strcmp(vet[num].cpf, vet[i].cpf);
        if(tcpf == 0){
          tescpf++;
          }
      }
        }
      }

      vet[num].dismat = 0;


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
    vet[ndp] = vet[ndp+1];
    /*strcpy(vet[ndp].nome, vet[ndp+1].nome);
    strcpy(vet[ndp].cpf, vet[ndp+1].cpf);
    strcpy(vet[ndp].sexo, vet[ndp+1].sexo);
    vet[ndp].matricula = vet[ndp+1].matricula;
    vet[ndp].data.ano = vet[ndp+1].data.ano;
    vet[ndp].data.mes = vet[ndp+1].data.mes;
    vet[ndp].data.mes = vet[ndp+1].data.dia;*/
  }
  
  cadPessoas *ptr;
  ptr = &vet[num-1];
  ptr = NULL;

    __fpurge(stdin);
    printf("\nDados excluídos com sucesso.");
    return completado;
  }

//------------

int cadastrodis(cadDis vet[], cadPessoas vet2[], int num, int num2)
{

  int i, teste;
  
  printf("Digite o semestre da disciplina: ");
  scanf("%d", &vet[num].semDis);
  getchar();
  
  printf("Digite o nome do disciplina: ");
  fgets(vet[num].nomeDis, 40, stdin);
  size_t ln = strlen(vet[num].nomeDis) - 1;
  if (vet[num].nomeDis[ln] == '\n')
      vet[num].nomeDis[ln] = '\0';

  printf("Digite o código da disciplina: ");
  fgets(vet[num].codDis, 10, stdin);
  ln = strlen(vet[num].codDis) -1;
  if (vet[num].codDis[ln] == '\n')
      vet[num].codDis[ln] = '\0';

  printf("Insira o nome do professor: ");
  fgets(vet[num].profDis, 40, stdin);
  ln = strlen(vet[num].profDis) -1;
  if (vet[num].profDis[ln] == '\n')
      vet[num].profDis[ln] = '\0';

  for(i=0;i<num2;i++){
    teste = strcmp(vet[num].profDis,vet2[i].nome);
    if(teste == 0){
      i=num2;
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

void listardis(cadDis vet[], int num)
{
      printf("\n*******************\n");
      for (int i = 0; i < num; i++)
    {
        printf("----------\n");
        printf("Nome: %s\n", vet[i].nomeDis);
        printf("Código: %s\n", vet[i].codDis);
        printf("Semestre: %d\n", vet[i].semDis);
        printf("Professor: %s\n", vet[i].profDis);
    }
      printf("\n*******************");
}

void listarDCA(cadDis vet[], int num, aldis mat[][n], cadPessoas vet2[], int num2)
{
  int i, tam, teste, ndd = -1, ndp, conf = 0;
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
        printf("----------\n");
        printf("Nome: %s\n", vet[ndd].nomeDis);
        printf("Código: %s\n", vet[ndd].codDis);
        printf("Semestre: %d\n", vet[ndd].semDis);
        printf("Professor: %s\n", vet[ndd].profDis);

  printf("\nAlunos Matriculados:\n\n");
  tam = mat[ndd][0].numA;
  for(i=1;i<tam;i++){
    printf("- %s\n",mat[ndd][i].nomeA);
  }
}

int atualizardis(cadDis vet[], int num, cadPessoas vet2[], int num2)
{
  int i, ndd = -1, teste, conf = 0;
  int nddm=num-1;
  char codigo[10];

  while(conf == 0){
  printf("\nInforme o código da disciplina a ser atualizada: ");
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
  
    printf("Digite o semestre da disciplina: ");
    scanf("%d", &vet[ndd].semDis);
    getchar();
    
    printf("Digite o nome do disciplina: ");
    fgets(vet[ndd].nomeDis, 40, stdin);
    size_t ln = strlen(vet[ndd].nomeDis) - 1;
    if (vet[ndd].nomeDis[ln] == '\n')
        vet[ndd].nomeDis[ln] = '\0';

    printf("Digite o código da disciplina: ");
    fgets(vet[ndd].codDis, 10, stdin);
    ln = strlen(vet[ndd].codDis) -1;
    if (vet[ndd].codDis[ln] == '\n')
        vet[ndd].codDis[ln] = '\0';

    printf("Insira o nome do professor: ");
    fgets(vet[ndd].profDis, 40, stdin);
    ln = strlen(vet[ndd].profDis) -1;
    if (vet[ndd].profDis[ln] == '\n')
        vet[ndd].profDis[ln] = '\0';

  for(i=0;i<num2;i++){
    teste = strcmp(vet[ndd].profDis,vet2[i].nome);
    if(teste == 0){
      i=num2;
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

int excluirdis(cadDis vet[], cadPessoas vet2[], aldis mat[][n], int num, int num2)
{ 
  
  int i, ndd = -1, teste, conf = 0;
  int nddm=num-1;
  char codigo[10];

  while(conf == 0){
  printf("\nInforme o código da disciplina a ser excluida: ");
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

  //------------------
  int teste2, tam, j;

  tam = mat[ndd][0].numA;
  
  for(i=0;i<num2;i++){
    for(j=1;j<tam;j++){
      teste2 = strcmp(mat[ndd][j].nomeA, vet2[i].nome);
       if(teste2 == 0){
         vet2[j].dismat--;
  }
    }
    }
  //------------------
  
  int nd = ndd;
  
  for(ndd;ndd<num-1;ndd++){
    strcpy(vet[ndd].nomeDis, vet[ndd+1].nomeDis);
    strcpy(vet[ndd].codDis, vet[ndd+1].codDis);
    strcpy(vet[ndd].profDis, vet[ndd+1].profDis);
    vet[ndd].semDis = vet[ndd+1].semDis;
  }
  
  for(nd;nd<num;nd++){
    mat[nd][0].numA = mat[nd+1][0].numA;
    for(i=1;i<num;i++){
      strcpy(mat[nd][i].nomeA,mat[nd+1][i].nomeA);
    }
  }
  
  cadDis *ptr;
  ptr = &vet[num-1];
  ptr = NULL;
    
    __fpurge(stdin);
    printf("\nDados excluídos com sucesso.");
    return completado;
    
  }    

int incluiraluno (aldis mat[][n], cadDis vet[],  cadPessoas vet2[], int num, int num2)
{
  int i, val, ndm, ndp = -1, teste, conf = 0, ndd = -1;
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

  val = mat[ndd][0].numA;
  strcpy(mat[ndd][val].nomeA, vet2[ndp].nome);
  val++;
  mat[ndd][0].numA=val;

  printf("\nO aluno %s foi matriculado em %s.", vet2[ndp].nome, vet[ndd].nomeDis);

  vet2[ndp].dismat++;
  
}

int excluiraluno (aldis mat[][n], cadDis vet[],  cadPessoas vet2[], int num, int num2)
{
  int i, k, aux, val, ndm, ndp = -1, teste, conf = 0, ndd = -1;
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

  printf("Excluir aluno de %s.\n",vet[ndd].nomeDis);
  conf = 0;
  
  while(conf == 0){
  printf("\nInforme a matrícula do aluno a ser excluído: ");
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

  val = mat[ndd][0].numA;
  for(k=1;k<val;k++){
    teste = strcmp(mat[ndd][k].nomeA, vet2[ndp].nome);
    if(teste == 0){
      aux = k;
      k = val;
    }
  }

  for(aux;aux<val;aux++){
    strcpy(mat[ndd][aux].nomeA, mat[ndd][aux+1].nomeA);
  }
  
  val--;
  mat[ndd][0].numA=val;

  printf("\nO aluno %s foi desmatriculado em %s.", vet2[ndp].nome, vet[ndd].nomeDis);

  vet2[ndp].dismat--;
  
}

//--------------

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
    strcpy(alfabetica[i].nome, vet[i].nome);
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

void numvagas(aldis mat[][n], cadDis vet[], int num)
{
  int i, val, vagas;
  printf("\nDisciplians com Mais de 40 Vagas:\n");
  for(i=0;i<num;i++){
    val = mat[i][0].numA;
    vagas = n - val;
    vagas++;
    if(vagas > 40){
      printf("\nDisciplina: %s\n",vet[i].nomeDis);
      printf("Professor: %s\n",vet[i].profDis);
      printf("Vagas: %d\n",vagas);
    }
  }
}

void busca(cadPessoas vet[], cadPessoas vet2[], int num, int num2)
{
  int i;
  char strbusca[10], *ponteiro;

  printf("\nInsira de 3 à 10 letras para a pesquisa:\n");
  fgets(strbusca, 10, stdin);
  size_t ln = strlen(strbusca) - 1;
  if (strbusca[ln] == '\n')
      strbusca[ln] = '\0';

  for(i=0;i<num;i++){
    ponteiro = strstr(vet[i].nome, strbusca);
    if(ponteiro){
      printf("- %s\n",vet[i].nome);
    }
  }
  for(i=0;i<num2;i++){
    ponteiro = strstr(vet2[i].nome, strbusca);
    if(ponteiro){
      printf("- %s\n",vet2[i].nome);
    }
  }
  
}

void menos3mat(cadPessoas vet[], int num)
{
  printf("\nAlunos Matriculados em Menos de 3 Disciplinas:\n\n");
  
  int i;
  
  for(i=0;i<num;i++)
    if(vet[i].dismat < 3){
      printf("- %s\n",vet[i].nome);
    }
}