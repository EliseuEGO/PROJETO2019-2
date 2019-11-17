
#include "funcions.h"



void escolherLocal(){
  //criar switch pra saber se vai colocar em auditório, lab ou sala e depois para escolher qual sala ou lab etc...
  //case xxxx: struc->local=_____;struct->capacidade=_____

  //usar ID do evento

  /*
    Auditório 1:até 150 pessoas
    Auditório 2:até 100 pessoas
    Auditório 3:Até 50 pessoas

    Sala 1:Até 50 pessoas
    Sala 2:Até 50 pessoas
    Sala 3:Até 30 pessoas

    Laboratório 1:Até 20 pessoas
    Laboratório 2:Até 20 pessoas
  */

}

void cadastro(/*ponteiro da variavel da struct */){
  //NOME:struct->nome
  //CPF:struct->CPF
  //
}

void criaCongressista(){
  //RECEBE ENDEREÇO DE Congressista; TALVEZ O NUM DE CONGRESSISTAS TBM
  //VERIFICA SE TEM ARQUIVO DE CONGRESSISTA E SE N TEM ELE CRIA
  //USA A FUNÇÃO DE cadastro PRA PREENCHER OS DADOS
}

void criaPalestrante(){
  //RECEBE ENDEREÇO DE Palestrante; TALVEZ O NUM DE Palestrante TBM
  //VERIFICA SE TEM ARQUIVO DE Palestrante E SE N TEM ELE CRIA
  //USA A FUNÇÃO DE cadastro PRA PREENCHER OS DADOS
}

void criaOrganizador(){
  //RECEBE ENDEREÇO DE Organizador; TALVEZ O NUM DE Organizador TBM
  //VERIFICA SE TEM ARQUIVO DE Organizador E SE N TEM ELE CRIA
  //USA A FUNÇÃO DE cadastro PRA PREENCHER OS DADOS
}

//CRIAR PALESTRA, CURSO E OFICINA
void criaEvento(){
  //tema
  /*Palestrante
  if(op2==2){
    
  }
    
    
  */
}

/*
 PALESTRA
  typedef struct{
  int numPalestrante;//usar para saber se o evento possui ou n palestrante
	char Tema[TAM];//vai ser o tbm o nome da struct
  int cadastrados[TAM2][5];//int para matricula dos congressistas
  int numCadastrados;//numero de cadastrados no evento
	char Palestrante[TAM];//exibe lista e pesquisa para escolher os cadastrados 
	int Local; //|Auditório 1,2,3..... o local define a capacidade//switch de locais que define capacidade
	int Capacidade; //de 50 até a 150 pessoas//switch para local//cada novo congressista decrementa a capacidade
	float carga_horária; //saber como vai ser... talvez seja fixa
	float Horário; //só pela manhã
  }PALESTRAS;

  CRIAR PALESTRA{
    cria cod
    verifica cod
    
  }
  EDITA PALESTRA{

  }
  LISTA PALESTRA{//TEMA,PALESTRANTE,HORARIO E Local

  }
  REMOVE PALESTRA{

  }
  LISTA CONGRESSISTAS DA PALESTRA{

  }
  

*/

/*
PALESTRANTE 
  CADASTRO DE NOVO PALESTRANTE:{
    ID; num randominco não editavel
      verifica id
    NOME;
    CPF;

  }
  CADASTRAR EM EVENTO:{
    lista eventos disponiveis(evento indisponivel é oq o contadorde palestrantes esteja preenchido)
    abre evento 
      coloca id do palestrante na variavel palestrante 
      incrementa qnt de palestrantes

      [se for uma palesta, curso ou oficina]
        incrementa o contador correspondente na struct
      
      add id do evento no array de eventos que o palestrante está
      incrementa a qnt de eventos que o palestrante está
  }

  LISTAR EVENTOS DO PALESTRANTE:{
    for com numero de id's cadastrados
      lista os ID's com nomes e horarios
  }

  SAIR DE EVENTO{
    lista os eventos que está com ID
    pega o id do evento q for SAIR
    entra no evento
      remove o ID do char de palestrantes
        [se for GP decrementa o num de palestrantes]
    decrementa o num de eventos e o contador de evento especifico

  }
  ALTERAR DADO:{
     escolha
      alterar nome
      alterar cpf

  }
   REMOVER palestrante{
     [se o num de eventos for maior que zero]
      imprime: não é possivel apagar o Palestrante ate que esteja fora de todos os eventos
    remove id do palestrante do array e decrementa o num de palestrantes
   }
   LISTAR palestrantes{
     for(i=numDePalestrantes)...

   }
*/

//funções congressistas
void NovoCongressista(){
/*
  //abre arquivo e verifica
  FILE *fp;
    CONGRE aluno;
    if ((fp = fopen("arquivos\\alunos.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

    //matricula
      //srand(time(NULL));
      //aluno.matricula = 1000+(rand()% 1300);//gerar num entre 1000 e 1300
    //nome 
      puts("Insira o nome do congressista");
      setbuf(stdin, NULL);
      fgets(aluno.nome,TAM,stdin);
    //cpf ou curso
      puts("Insira seu CPF");
      scanf("%d",&aluno.cpf);
      

*/
}

/*
CONGRESSISTAS
  CADASTRO DE NOVO CONGRESSISTA:{ 
    matricula;numero randominco não editavel
      verifica matricula
    nome
    cpf
  }

  CADASTRAR EM EVENTO:{
    lista eventos com ID's 
    pega ID digitado 
      [Abre o evento e testa se o numero de matriculas é igual a capacidade do local]
        Add matricula do aluno no array de matriculas;
        Incrementa o num de matriculas cadastradas;
      
      [se for ID de curso ou oficina incremente o contador dentro   da struc do Congressista  ]

      Add ID do evento em um array de eventos[n] dentro da struct Congressista e incrementa int num de eventos dentro da struct

  }
  LISTAR EVENTOS DO CONGRESSISTA:{
    Pega os ID's do array de eventos usando o int num de eventos
    entra nos arquivos 
    lista os nomes com os temas e horários
  }

  SAIR DE EVENTO:{
    lista os eventos com os ID's usando o int num de eventos
    pega o ID 
      abre o evento
      pesquisa e remove a matricula do aluno do array de matriculas
      decrementa o num de matriculas cadastradas
    
    [se for ID de curso ou oficina decrementa o contador]
    Remove o ID do array de eventos cadastrados

  }

  ALTERAR DADO:{
    int op2;
    abrir arquivo
    //abre arquivo e verifica
      FILE *fp;
      CONGRE aluno;
      if ((fp = fopen("arquivos\\alunos.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }


    puts("1-Alterar nome\t2-Alterar CPF");
      scanf("%d",&op2);

    escolha
    switch(op2){
      case 1://alterar nome
      //alterar cpf

    }
  }

  REMOVER CONGRESSISTA:{
    selecionar os ID's dos eventos que ele está cadastrados
      for(i=numDeEventosCadastrados)
      remove ID'eventos[i]
        abre o evento
        pesquisa e remove a matricula do aluno do array de matriculas;
        decrementa o num de matriculas cadastradas;

    remove o Congressista
  }

  LISTAR CONGRESSISTAS{
    for(num de congressistas)
      imprime matricula de nome
  }

*/