#include "funcions.h"
//teste


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
CONGRESSISTAS
  CADASTRO DE NOVO CONGRESSISTA:{ 
    matricula;numero randominco não editavel
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
    escolha
      alterar nome
      alterar cpf
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