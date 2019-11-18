#include <stdio.h>

#include <stdlib.h>
#include <string.h>
//#include <windows.h>
#include <time.h>
#include <locale.h>
#define TAM 21
#define TAM2 30


//ENUM's-------------------------------------------------------
//switch aud, sala ou lab e depois para aud 1, 2 ,3 etc...
typedef enum{//enum de auditório
  AUD1=1,AUD2,AUD3,SALA1,SALA2,SALA3,LAB1,LAB2//auditório 1,2,3...
}LOCAL;




//STRUCTS-------------------------------------------------------



/*criar struct de local com ID local tbm*/


typedef struct{
    int cod;//codigo para identificcar a palestra de 100 a 199
    int numPalestrante;//usar para saber se o evento possui ou n palestrante
    char tema[TAM];//vai ser o tbm o nome da struct
    int cadastrados[TAM2][5];//int para matricula dos congressistas
    int numCadastrados;//numero de cadastrados no evento
	char palestrante[TAM];//exibe lista e pesquisa para escolher os cadastrados
	int local; //|Auditório 1,2,3..... o local define a capacidade//switch de locais que define capacidade
	int capacidade; //de 50 até a 150 pessoas//switch para local//cada novo congressista decrementa a capacidade
	float cargahoraria; //saaber como vai ser... talvez seja fixa
	float horario; //só pela manhã
}PALESTRAS;

typedef struct{
  int cod;//codigo para identificcar o GP de 200 a 299
  int numPalestrante;//usar para saber se o evento possui ou n palestrante
  int cadastrados[TAM2][5];//int para matricula dos congressistas
  int numCadastrados;//numero de cadastrados no evento
	char Tema[TAM];//vai ser o tbm o nome da struct
	char Membros_da_mesa[5][TAM];// Até 5 pessoas//lista os palestrantes cadastrados e insere o nome dos que serão escolhidos
	int Local;//locais que possuem limitação de 30/50
	int Capacidade;// de 30/50 pessoas////cada novo congressista decrementa a capacidade
	float carga_horaria;
	float Horario;//horario da tarde
}GRUPO_DE_DISCUSSOES;

typedef struct{
  int cod;//codigo para identificcar o curso de 300 a 399
  int numPalestrante;//usar para saber se o evento possui ou n palestrante
  int cadastrados[TAM2][5];//int para matricula dos congressistas
  int numCadastrados;//numero de cadastrados no evento
	char Tema[TAM];//vai ser o tbm o nome da struct
	char Palestrante[TAM];//pesquisa para escolher os cadastrados
	int Capacidade;// de 40 pessoas//cada novo congressista decrementa a capacidade
	int Local;
	float Carga_horaria;
	float Horario;
}CURSO;

typedef struct{
  int cod;//codigo para identificcar a oficina de 400 a 499
  int numPalestrante;//usar para saber se o evento possui ou n palestrante
  int cadastrados[TAM2][5];//int para matricula dos congressistas
  int numCadastrados;//numero de cadastrados no evento
	char Tema[TAM];
  char Palestrante[TAM];//pesquisa para escolher os cadastrados
	int Local;
	int Capacidade;// 20 alunos//cada novo congressista decrementa a capacidade
	float Horario;
	float Carga_horaria;
}OFICINAS;

typedef struct{
  int matricula;//numero randomico entre 1001 e 1301
  char nome[TAM];
  int cpf;
  int id[20][4];//array pra guardar ID's dos eventos que o congressista participar
  int numEventos;//int pra guardar o num de eventos q o congressista participa
  int nOficinas;//numero de oficinas não pode ser maior q 1
  int nCursos;//numero de cusos não pode ser maior q 1
}CONGRE;//struct de congressistas

typedef struct{
  int ID;//num para identificar palestrante entre 800 e 899;
  int eventos[15][4];//vetor pra guardar os cod's dos eventos
  int numEventos;//inteiro pra guardar a qntidade de eventos do palestrante
  char nome[TAM];
  int cpf;
  int nPalestras;//numero de palestras não pode ser maior q 1
  int nOficinas;//numero de oficinas não pode ser maior q 1
  int nCursos;//numero de cusos não pode ser maior q 1
}PROFS;//struct de palestrantes


//FUNÇÕES-------------------------------------------------------

void escolherLocal();

//PALESTRANTES**************************
//cadastrar palestrante
void cadastroPalestrante();

//ALTERAR DADOS DE PALESTRANTES
void editaPalestrante();

//REMOVER PALESTRANTES
void removerPalestrantes();

//Listar palestrantes
void listarPalestrantes();

//CADASTRAR PALESTRANTE EM EVENTO

//LISTAR EVENTOS DO PALESTRANTE

//SAIR DE EVENTO


//******************************************************

//CONGRESSISTAS
//CRIAR CONGRESSISTA
void NovoCongressista();

//EDITAR CONGRESSISTA
void editaAluno();

//REMOVER CONGRESSISTA
void removerAluno();

//listar congressistas
void listarAlunos();

//CADASTRAR CONGRESSISTA EM EVENTO

//LISTAR EVENTOS DO CONGRESSISTA

//SAIR DE EVENTO

//************************************************************
