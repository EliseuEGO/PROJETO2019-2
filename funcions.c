
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

//FUNÇÕES PALESTRANTES----------------------------------------
//cadastrar palestrante
void cadastroPalestrante(){
    //abre arquivo e verifica
    FILE *fp;
    PROFS profs;//varial de professores
    if ((fp = fopen("arquivos\\palestrantes.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

    //ID
      srand(time(NULL));
      profs.ID = 800+(rand()% 899);//gerar num entre 1000 e 1300
      printf("Matricula: %d",profs.ID);
    //nome 
      puts("Insira o nome do Palestrante");
      setbuf(stdin, NULL);
      fgets(profs.nome,TAM,stdin);
    //cpf ou curso
      puts("Insira seu CPF");
      scanf("%d",&profs.cpf);
      
      puts("Cadastro concluido");

      fwrite(&profs,sizeof(PROFS),1,fp);
      fclose(fp);
}

//ALTERAR DADOS DE PALESTRANTES
void editaPalestrante(){
    int op2;//op para switch
    int ID;//ID para pesquisa
    char novoNome[TAM];

    //abrir arquivo
    //abre arquivo e verifica
      FILE *fp=NULL;
      FILE *fp_aux=NULL;//arquivo auxiliar
      PROFS profs;  
      PROFS profs;//struct auxiliar
      
      fp=fopen("arquivos\\palestrantes.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\temp.txt","ab");//abre arquivos temporarios no modo de acesso

      puts("Insira o ID do palestrante");
        scanf("%d",&ID);

      while(fread(&profs,sizeof(PROFS),1,fp)){//le arquivo principal
        if(profs.ID==ID){//se o ID for a que eu quero editar
           puts("1-Alterar nome\t2-Alterar CPF\t3NENHUM");
           puts("O que deseja alterar?");
            scanf("%d",&op2);
            //escolha
            switch(op2){
                //alterar nome
                case 1:{
                  puts("Insira novo nome");
                  setbuf(stdin,NULL);
                  fgets(novoNome,TAM,stdin);
                  strtok(novoNome,"\n");
                  strcpy(profs.nome,novoNome);
                  break;
                }
                case 2:{
                  puts("Insira novo CPF");
                  scanf("%d",&profs.cpf);
                  break;
                }
                case 3:{
                  break;
                }
                default:puts("Opção inválida");break;
          }
        fwrite(&profs,sizeof(PROFS),1,fp_aux);//depois de editar escreve no arqivo novo
        }else{
          fwrite(&profs,sizeof(PROFS),1,fp_aux);//as que eu não quero alterar são escritas no novo arquivo
        }
      }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\palestrantes.txt");//remove o original
    rename("arquivos\\temp.txt","arquivos\\palestrantes.txt");//renomeia o aux com nome do orinial
    //fim
}

//REMOVER PALESTRANTES
void removerPalestrantes(){
    int ID;//ID para pesquisa


    FILE *fp=NULL;
    FILE *fp_aux=NULL;//arquivo auxiliar
    PROFS profs;
    PROFS aux;//struct auxiliar
          
    fp=fopen("arquivos\\palestrantes.txt","rb");//abre arquivos principais no modo de leitura
    fp_aux=fopen("arquivos\\temp.txt","ab");//abre arquivos temporarios no modo de acesso

        puts("Insira o ID do palestrante");
        scanf("%d",&ID);
        while(fread(&profs,sizeof(PROFS),1,fp)){
          if(profs.ID==ID && profs.numEventos>0){ //testa se num de eventos está maior que zero
          //se estiver exibe que não pode remover ate que ele saia dos eventos
            puts("Palestrante cadastrado em evento, saia do evento para poder remove-lo");
            break;
          }else{
          //SE NÃO
          //TALVEZ TENHA QUE COLOCAR UM REWIND PARA VOLTAR O ARQUIVO
            //rewind(fp);//retorna para o inicio do arquivo
            //while(fread(&profs,sizeof(PROFS),1,fp)){//le arquivo principal
              if(profs.ID!=ID){//se a matricula for a que eu quero editar
              fwrite(&profs,sizeof(PROFS),1,fp_aux);
              }
            //}fim do while
          }
        }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\palestrantes.txt");//remove o original
    rename("arquivos\\temp.txt","arquivos\\palestrantes.txt");//renomeia o aux com nome do orinial
    //fim
}
//Listar palestrantes
void listarPalestrantes(){
  FILE *fp;
      PROFS profs;
      fp = fopen("arquivos\\palestrantes.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&profs, sizeof(PROFS), 1,fp)){//enquanto leitura for verdadeira
        printf("ID:%d\nNome: %s - CPF: %d\n",profs.ID, profs.nome,profs.cpf);
      }
      fclose(fp);
    //fim
}

//-----------------------------------------------------------------

/*
PALESTRANTE 

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


*/

//funções congressistas------------------------------------------------------
void NovoCongressista(){

      FILE *fp=NULL;
      CONGRE aluno;

  //abre arquivo e verifica

   
    if ((fp = fopen("arquivos\\alunos.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

    //matricula
      srand(time(NULL));
      aluno.matricula = 1000+(rand()% 1300);//gerar num entre 1000 e 1300
      printf("Matricula: %d",aluno.matricula);
    //nome 
      puts("Insira o nome do congressista");
      setbuf(stdin, NULL);
      fgets(aluno.nome,TAM,stdin);
    //cpf ou curso
      puts("Insira seu CPF");
      scanf("%d",&aluno.cpf);
      
      puts("Cadastro concluido");

      fwrite(&aluno,sizeof(CONGRE),1,fp);
      fclose(fp);
}
//EDITAR CONGRESSISTA
void editaAluno(){
    int op2;//op para switch
    int mat;//matricula para pesquisa
    char novoNome[TAM];

    //abrir arquivo
    //abre arquivo e verifica
      FILE *fp=NULL;
      FILE *fp_aux=NULL;//arquivo auxiliar
      CONGRE aluno;
      CONGRE aux;//struct auxiliar
      
      fp=fopen("arquivos\\alunos.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\temp.txt","ab");//abre arquivos temporarios no modo de acesso

      puts("Insira a matricula do aluno");
        scanf("%d",&mat);

      while(fread(&aluno,sizeof(CONGRE),1,fp)){//le arquivo principal
        if(aluno.matricula==mat){//se a matricula for a que eu quero editar
           puts("1-Alterar nome\t2-Alterar CPF\t3NENHUM");
           puts("O que deseja alterar?");
            scanf("%d",&op2);
            //escolha
            switch(op2){
                //alterar nome
                case 1:{
                  puts("Insira novo nome");
                  setbuf(stdin,NULL);
                  fgets(novoNome,TAM,stdin);
                  strtok(novoNome,"\n");
                  strcpy(aluno.nome,novoNome);
                  break;
                }
                case 2:{
                  puts("Insira novo CPF");
                  scanf("%d",&aluno.cpf);
                  break;
                }
                case 3:{
                  break;
                }
                default:puts("Opção inválida");break;
          }
        fwrite(&aluno,sizeof(CONGRE),1,fp_aux);//depois de editar escreve no arqivo novo
        }else{
          fwrite(&aluno,sizeof(CONGRE),1,fp_aux);//as que eu não quero alterar são escritas no novo arquivo
        }
      }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\alunos.txt");//remove o original
    rename("arquivos\\temp.txt","arquivos\\alunos.txt");//renomeia o aux com nome do orinial
    //fim
}
//REMOVER CONGRESSISTA
void removerAluno(){
      int mat;//pegar matricula
      puts("Insira a matricula do aluno");
        scanf("%d",&mat);
      //testa SE o num de eventos é maior q zero
          //selecionar os ID's dos eventos que ele está cadastrados
          //for(i=numDeEventosCadastrados)
          //remove ID'eventos[i]
          //abre o evento
            //pesquisa e remove a matricula do aluno do array de matriculas;
            //decrementa o num de matriculas cadastradas;

    //remove o Congressista
      FILE *fp=NULL;
      FILE *fp_aux=NULL;//arquivo auxiliar
      CONGRE aluno;
      CONGRE aux;//struct auxiliar
      
      fp=fopen("arquivos\\alunos.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\temp.txt","ab");//abre arquivos temporarios no modo de acesso


      while(fread(&aluno,sizeof(CONGRE),1,fp)){//le arquivo principal
        if(aluno.matricula!=mat){//se a matricula for a que eu quero editar
          fwrite(&aluno,sizeof(CONGRE),1,fp_aux);
        }
      }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\alunos.txt");//remove o original
    rename("arquivos\\temp.txt","arquivos\\alunos.txt");//renomeia o aux com nome do orinial
    //fim
  }
//listar congressistas 
void listarAlunos(){
      FILE *fp;
      CONGRE aluno;
      fp = fopen("arquivos\\alunos.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&aluno, sizeof(CONGRE), 1,fp)){//enquanto leitura for verdadeira
        printf("Matricula:%d\nNome: %s - CPF: %d\n",aluno.matricula, aluno.nome,aluno.cpf);
      }
      fclose(fp);
    //fim
}

//fim das funções dos congressistas---------------------------------------------------------

/*
CONGRESSISTAS
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
*/