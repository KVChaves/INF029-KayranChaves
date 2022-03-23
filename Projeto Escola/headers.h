#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

int menuprincipal();
int menuAlunos();
int menuProf();
int menuDis();
int menuRel();

int cadastroaluno(cadAlunos listAlunos[], int numAlunos);
void listaraluno(cadAlunos listAlunos[], int numAlunos);
int atualizaraluno(cadAlunos listAlunos[], int numAlunos);
int excluiraluno(cadAlunos listAlunos[], int numAlunos);

int cadastroprof(cadProf listProf[], int numProf);
void listarprof(cadProf listProf[], int numProf);
int atualizarprof(cadProf listProf[], int numProf);
int excluirprof(cadProf listProf[], int numProf);

int cadastrodis(cadDis listDis[], int numDis);
void listardis(cadDis listDis[], int numDis);
int atualizardis(cadDis listDis[], int numDis);
int excluirdis(cadDis listDis[], int numDis);

void sexoalunos(cadAlunos listAlunos[], int numAlunos);
void sexoprof (cadProf listProf[], int numProf);
void alfabeticaAlunos (cadAlunos listAlunos[], int numAlunos);
void alfabeticaProf (cadProf listProf[], int numProf);
void aniversarios (cadProf listProf[], cadAlunos listAlunos[], int numAlunos, int numProf);

#endif // FUNCOES_H_INCLUDED