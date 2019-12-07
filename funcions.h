#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#define TAM 21
#define TAM2 30


//ENUM's-------------------------------------------------------
//switch aud, sala ou lab e depois para aud 1, 2 ,3 etc...
typedef enum{//enum de auditório
  AUD1=1,AUD2,AUD3,SALA1,SALA2,SALA3,LAB1,LAB2//auditório 1,2,3...
}LOCAL;

typedef enum{
  PRIMEIRO=1,SEGUNDO,TERCEIRO,QUARTO,QUINTO,SEXTO
}HORARIO;

//STRUCTS-------------------------------------------------------

/*criar struct de local com ID local tbm*/

typedef struct{
  int lugar; //|Auditório 1,2,3..... o local define a capacidade//switch de locais que define capacidade
  int CODE;//codigo do evento add ao local
  int CODL;//codigo de local
  int disponibilidade;
  float cargahoraria; //saaber como vai ser... talvez seja fixa
  HORARIO horario[2][6]; //imprime horario dependendo do local//primeira parte é dia e segunda é horario
  int capacidade;
  int Eventos[2][6][4];
}SLOCAL;


typedef struct{
    int cod;//codigo para identificcar a palestra de 100 a 199
    //int numPalestrante;//usar para saber se o evento possui ou n palestrante
    char tema[TAM];//vai ser o tbm o nome da struct
    int cadastrados[150][5];//int para matricula dos congressistas
    int numCadastrados;//numero de cadastrados no evento
	  int palestrante;//exibe lista e pesquisa para escolher os cadastrados
	  int capacidadeE;//capacidade de alunos no evento

    int Local; //|Auditório 1,2,3..... o local define a capacidade//switch de locais que define capacidade
	 //de 50 até a 150 pessoas//switch para local//cada novo congressista decrementa a capacidade
	 //só pela manhã
}PALESTRAS;

typedef struct{
  int cod;//codigo para identificcar o GP de 200 a 299
	char Tema[TAM];//vai ser o tbm o nome da struct
  int numPalestrante;//usar para saber se o evento possui ou n palestrante
	int Membros_da_mesa[5][5];// Até 5 pessoas//lista os palestrantes cadastrados e insere o nome dos que serão escolhidos
  int cadastrados[50][5];//int para matricula dos congressistas
  int numCadastrados;//numero de cadastrados no evento
  int capacidadeE;//capacidade de alunos no evento
	
  SLOCAL Local;//locais que possuem limitação de 30/50
	
}GRUPO_DE_DISCUSSOES;

typedef struct{
  int cod;//codigo para identificcar o curso de 300 a 399
	char Tema[TAM];//vai ser o tbm o nome da struct
  int numPalestrante;//usar para saber se o evento possui ou n palestrante
	int Palestrante;//pesquisa para escolher os cadastrados
  int cadastrados[TAM2][5];//int para matricula dos congressistas
  int numCadastrados;//numero de cadastrados no evento
  int capacidadeE;//capacidade de alunos no evento
	
  SLOCAL Local;
}CURSO;

typedef struct{
  int cod;//codigo para identificcar a oficina de 400 a 499
	char Tema[TAM];
  int numPalestrante;//usar para saber se o evento possui ou n palestrante
  int Palestrante;//pesquisa para escolher os cadastrados
  int cadastrados[TAM2][5];//int para matricula dos congressistas
  int numCadastrados;//numero de cadastrados no evento
  int capacidadeE;//capacidade de alunos no evento
	
  SLOCAL Local;
}OFICINAS;

typedef struct{
  int matricula;//numero randomico entre 1001 e 1301
  char nome[TAM];
  int cpf;
  int cods[20][4];//array pra guardar ID's dos eventos que o congressista participar
  int numEventos;//int pra guardar o num de eventos q o congressista participa
  int nOficinas;//numero de oficinas não pode ser maior q 1
  int nCursos;//numero de cusos não pode ser maior q 1
}CONGRE;//struct de congressistas

typedef struct{
  int ID;//num para identificar palestrante entre 800 e 899;
  int eventos[30][4];//vetor pra guardar os cod's dos eventos
  int numEventos;//inteiro pra guardar a qntidade de eventos do palestrante
  char nome[TAM];
  int cpf;
  int nPalestras;//numero de palestras não pode ser maior q 1
  int nOficinas;//numero de oficinas não pode ser maior q 1
  int nCursos;//numero de cusos não pode ser maior q 1
}PROFS;//struct de palestrantes

typedef struct{
  int ID;//id do organizador entre 900 e 999
  char nome[TAM];
  int cpf;
}ORGANIZADORES;


//FUNÇÕES-------------------------------------------------------

void mostra();

void criarLocais(int i);

//void escolherLocal();


void listarEventos(int cod);

void incrementarEventos(int cod, int mat);

void decrementarEventos(int cod, int mat);

int numCongressistas();

int numPalestrantes();

//PALESTRANTES**************************
//cadastrar palestrante
void cadastroPalestrante();

//ALTERAR DADOS DE PALESTRANTES
void editaPalestrante();

//REMOVER PALESTRANTES
void removerPalestrantes();

//Listar palestrantes
void listarPalestrantes();

//INCREMENTAR PALESTRANTES
void incrementarPale();

//DECREMENTAR PALESTRANTES
void decrementarPale();

//LISTAR EVENTOS DO PALESTRANTE
void listaEventosdoPalestrante();

void listarPalestrantes2(int cod);//lista só os que não estão em certos eventos

void mostraPalestrante(int ID);//exibi palestrante especifico

void trocaPalestrante(int cod,int IDvelho,int IDnovo);//retira o cadastro de um palestrante de certo evento e coloca outro no lugar

//******************************************************

//CONGRESSISTAS
//CRIAR CONGRESSISTA
void NovoCongressista();//

//EDITAR CONGRESSISTA
void editaAluno();

//REMOVER CONGRESSISTA
void removerAluno();

//listar congressistas
void listarAlunos();

//LISTAR ALUNO SEM CURSO OU OFICINA
void listarAlunos2(int cod);

//CADASTRAR CONGRESSISTA EM EVENTO
void cadastrarAlunoemEvento();

//LISTAR EVENTOS DO CONGRESSISTA
void listaEventosdeAlunos();

//SAIR DE EVENTO
void deixarEvento();

void listarAlunosdeEventos(int cod,int IDaluno);//lista congressistas de determinado evento

void listadeAlunoscomEventos();//listar alunos que possuem eventos cadastrados

void incrementarAluno(int cod,int mat);//incrementar evento em aluno

//decrementar evento no aluno
void decrementarAluno(int cod, int mat);

//************************************************************

//PALESTRAS-------------------------------------------------------
//CRIAR PALESTRAS
void criaPalestra();//
//EDITAR PALESTRAS
void editaPalestra();//
//LISTAR PALESTRAS
void listaPalestras();//
//REMOVER PALESTRAS
void removerPalestra();//
//LISTAR CONGRESSISTAS DE UMA PALESTRA
void listarAlunosdaPalestra();//
//incrmenta aluno na palestra


//****************************************************

//CURSOS*********************************************

//CRIAR CURSOS
void criaCurso();
//EDITAR CURSOS
void editaCurso();//
//LISTAR CURSOS
void listaCursos();//
//REMOVER CURSOS
void removerCurso();//
//LISTAR CONGRESSISTAS DE UM CURSO
void listarAlunosdoCurso();//
//*****************************************************

//OFICINAS********************************************
//CRIAR OFICINAS
void criaOficina();//
//EDITAR OFICINAS
void editaOficinas();//
//LISTAR OFICINAS
void listaOficinas();//
//REMOVER OFICINAS
void removerOficinas();//
//LISTAR CONGRESSISTAS DE OFICINAS
void listaAlunosdaOficina();//
//****************************************************

//GRUPO_DE_DISCUSSOES*********************************

//CRIAR GRUPO_DE_DISCUSSOES
void criaGrupo();//
//EDITAR GRUPO_DE_DISCUSSOES

//LISTAR GRUPO_DE_DISCUSSOES

//REMOVER GRUPO_DE_DISCUSSOES

//LISTAR CONGRESSISTAS DE GRUPO_DE_DISCUSSOES

//ADD PALESTRANTE AO GRUPO DE DISCUSSÃO
void addPalestranteaGrupo();



//=============================================================
void escolheLocal(int cod);

void testeEscolheLocal(int cod);

void listaHorarios(int dia, int cod, int local);

void listaLocais(int capacidade);

//LISTAR O HORARIO DO EVENTO
void listaHorariodoEvento(int cod);