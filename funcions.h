#define TAM 21


//ENUM's-------------------------------------------------------
//switch aud, sala ou lab e depois para aud 1, 2 ,3 etc...
typedef enum{//enum de auditório
  AUD1=1,AUD2,AUD3,SALA1,SALA2,SALA3,LAB1,LAB2//auditório 1,2,3...
}LOCAL;




//STRUCTS-------------------------------------------------------
typedef struct{
	char Tema[TAM];//vai ser o tbm o nome da struct
	char Palestrante[TAM];//exibe lista e pesquisa para escolher os cadastrados 
	int Local; //|Auditório 1,2,3..... o local define a capacidade//switch de locais que define capacidade
	int Capacidade; //de 50 até a 150 pessoas//switch para local//cada novo congressista decrementa a capacidade
	float carga_horária; //saber como vai ser... talvez seja fixa
	float Horário; //só pela manhã
}PALESTRAS;

typedef struct{
	char Tema[TAM];//vai ser o tbm o nome da struct
	char Membros_da_mesa[5][TAM];// Até 5 pessoas//lista os palestrantes cadastrados e insere o nome dos que serão escolhidos
	int Local;//locais que possuem limitação de 30/50
	int Capacidade;// de 30/50 pessoas////cada novo congressista decrementa a capacidade
	float carga_horária;
	float Horário;//horario da tarde
}GRUPO_DE_DISCUSSOES;

typedef struct{
	char Tema[TAM];//vai ser o tbm o nome da struct
	char Palestrante[TAM];//pesquisa para escolher os cadastrados 
	int Capacidade;// de 40 pessoas//cada novo congressista decrementa a capacidade
	int Local;
	float Carga_horária;
	float Horário;
}CURSO;

typedef struct{
	char Tema[TAM];
  char Palestrante[TAM];//pesquisa para escolher os cadastrados 
	int Local;
	int Capacidade;// 20 alunos//cada novo congressista decrementa a capacidade
	float Horário;
	float Carga_horária;
}OFICINAS;

typedef struct{
  char nome[TAM];
  int nOficinas;//numero de oficinas não pode ser maior q 1
  int nCursos;//numero de cusos não pode ser maior q 1
}CONGRE;//struct de congressistas

typedef struct{
  char nome[TAM];
  int nPalestras;//numero de palestras não pode ser maior q 1
  int nOficinas;//numero de oficinas não pode ser maior q 1
  int nCursos;//numero de cusos não pode ser maior q 1
}PROFS;//struct de palestrantes


//FUNÇÕES-------------------------------------------------------

void escolherLocal();