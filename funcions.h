#define TAM 21

typedef struct{
	char Tema[TAM];//vai ser o tbm o nome da struct
	char Palestrante[TAM];//exibe lista e pesquisa para escolher os cadastrados 
	int Local //Auditório 1,2,3..... o local define a capacidade//switch de locais que define capacidade
	int Capacidade //de 50 até a 150 pessoas//switch para local
	float carga_horária //saber como vai ser... talvez seja fixa
	float Horário //só pela manhã
}PALESTRAS;

typedef struct{
	char Tema[TAM];//vai ser o tbm o nome da struct
	char Membros da mesa[5][TAM];// Até 5 pessoas//quem seriam????
	int Local;//locais que possuem limitação de 30/50
	int Capacidade;// de 30/50 pessoas
	float carga_horária;
	float Horário;//horario da tarde
}GRUPO_DE_DISCUSSOES;

typedef struct{
	char Tema[TAM];//vai ser o tbm o nome da struct
	char Palestrante[TAM];//pesquisa para escolher os cadastrados 
	int Capacidade;// de 40 pessoas
	int Local;
	float Carga_horária;
	float Horário;
}CURSO;

typedef struct{
	char Tema[TAM];
  char Palestrante[TAM];//pesquisa para escolher os cadastrados 
	int Local;
	int Capacidade// 20 alunos
	float Horário;
	float Carga_horária;
}OFICINAS;