
#include "funcions.h"


void mostra(){
  puts("nemmmm");
}
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


/*
struct de horarios
  dia;      //14 ou 15
  horario 1;//07-09
  horario 2;//09-11
  horario 3;//11-13
  horario 4;//13-15
  horario 5;//15-17
  horario 6;//17-19
*/



void criarLocais(){

  //TESTA SE O ARQUIVO JA EXISTE
  int i;
  //abre arquivo e verifica
    FILE *fp;
    SLOCAL loca;//varial de local
    //teste de entrada de arquivo
    if ((fp = fopen("arquivos\\locais.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
  for(i=1;i<=8;i++){
    //codigo de llocais
      srand(time(NULL));
      loca.CODL = 900+(rand()% 9);//gerar num entre 900 e 999
      printf("Codigo do Local: %d\n",loca.CODL);
    //local em si
      loca.lugar=i;//enum de locais 1-8
      loca.cargahoraria=0;
      loca.horario=0;
      loca.capacidade=0;
      
      fwrite(&loca, sizeof(SLOCAL), 1, fp);
  }
  fclose(fp);
}

void escolheLocal(int evento){
  
}

//FUNÇÕES PALESTRANTES----------------------------------------
//cadastrar palestrante
void cadastroPalestrante(){
    printf("INICIAR CADASTRO DE PALESTRANTE\n");
    //abre arquivo e verifica
    FILE *fp;
    PROFS profs;//varial de professores
    //teste de entrada de arquivo
    if ((fp = fopen("arquivos\\palestrantes.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

    //ID
      srand(time(NULL));
      profs.ID = 800+(rand()% 99);//gerar num entre 800 e 899
      printf("Matricula: %d\n",profs.ID);
    //nome
      puts("Insira o nome do Palestrante");
      setbuf(stdin, NULL);
      fgets(profs.nome,TAM,stdin);
      strtok(profs.nome,"\n");
    //cpf ou curso
      puts("Insira seu CPF");
      scanf("%d",&profs.cpf);

      puts("!FALTA ZERAR EVENTOS!");
      puts("Cadastro concluido");

      fwrite(&profs,sizeof(PROFS),1,fp);
      fclose(fp);
}

//ALTERAR DADOS DE PALESTRANTES
void editaPalestrante(){
  puts("Editar palestrante");
    int op2;//op para switch
    int ID;//ID para pesquisa
    char novoNome[TAM];

    //abrir arquivo
    //abre arquivo e verifica
      FILE *fp=NULL;
      FILE *fp_aux=NULL;//arquivo auxiliar
      PROFS profs;
      //PROFS profs_aux;//struct auxiliar

      fp=fopen("arquivos\\palestrantes.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\tempProf.txt","ab");//abre arquivos temporarios no modo de acesso

      puts("Insira o ID do palestrante");
        scanf("%d",&ID);
        putchar('\n');
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
    rename("arquivos\\tempProf.txt","arquivos\\palestrantes.txt");//renomeia o aux com nome do orinial
    //fim
}

//REMOVER PALESTRANTES
void removerPalestrantes(){
  puts("Remover palestrante");
    int ID;//ID para pesquisa
    FILE *fp=NULL;
    FILE *fp_aux=NULL;//arquivo auxiliar
    PROFS profs;
    //PROFS aux;//struct auxiliar

    fp=fopen("arquivos\\palestrantes.txt","rb");//abre arquivos principais no modo de leitura
    fp_aux=fopen("arquivos\\tempProf.txt","ab");//abre arquivos temporarios no modo de acesso

        puts("Insira o ID do palestrante");
        scanf("%d",&ID);
        while(fread(&profs,sizeof(PROFS),1,fp)){
          if(profs.ID==ID && profs.numEventos>0){ //testa se num de eventos está maior que zero
          //se estiver exibe que não pode remover ate que ele saia dos eventos
            puts("Palestrante cadastrado em evento, saia do evento para poder remove-lo");
            break;
          }else{
            if(profs.ID!=ID){//se a matricula for a que eu quero editar
              fwrite(&profs,sizeof(PROFS),1,fp_aux);
            }
          }
        }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\palestrantes.txt");//remove o original
    rename("arquivos\\tempProf.txt","arquivos\\palestrantes.txt");//renomeia o aux com nome do orinial
    //fim
    puts("fim da função");
    //getchar();
}
//Listar palestrantes
void listarPalestrantes(){
  puts("listar palestrantes");
  FILE *fpp;
      PROFS profs;
      fpp = fopen("arquivos\\palestrantes.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&profs, sizeof(PROFS), 1,fpp)){//enquanto leitura for verdadeira
        printf("ID:%d\nNome: %s - CPF: %d\n",profs.ID, profs.nome,profs.cpf);
      }
      fclose(fpp);
    //fim
}
//Listar palestrantes
void listarPalestrantes2(int cod){//lista só os que não estão em certos eventos
  puts("listar palestrantes");
  FILE *fpp;
      PROFS profs;
      fpp = fopen("arquivos\\palestrantes.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&profs, sizeof(PROFS), 1,fpp)){//enquanto leitura for verdadeira
        if(cod>=100&&cod<200){//se for codigo de palestra
          if(profs.nPalestras!=1){
           printf("ID:%d\nNome: %s\n",profs.ID, profs.nome);
          } 
        }
        if(cod>=300&&cod<400){//se for codigo de curso
          if(profs.nCursos!=1){
           printf("ID:%d\nNome: %s\n",profs.ID, profs.nome);
          } 
        }
        if(cod>=400&&cod<500){//se for codigo de oficinas
          if(profs.nOficinas!=1){
           printf("ID:%d\nNome: %s\n",profs.ID, profs.nome);
          } 
        }
      }
      fclose(fpp);
    //fim
}
//EXIBIR PALESTRANTE EXPECIFICO
void mostraPalestrante(int ID){
  FILE *fpp;
      PROFS profs;
      fpp = fopen("arquivos\\palestrantes.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&profs, sizeof(PROFS), 1,fpp)){//enquanto leitura for verdadeira
        if(ID==profs.ID){
          printf("Nome: %s\n",profs.nome);
        }
      }
      fclose(fpp);
    //fim
}
//INCREMENTAR PALESTRANTES
void incrementarPale(int cod,int ID){
  //TALVEZ DEVA CRIAR NOVO ARQUIVO
  int i;
  FILE *fpp;
      PROFS profs;
      fpp = fopen("arquivos\\palestrantes.txt", "ab");//abre arquivo no modo de acesso
      while (fread(&profs, sizeof(PROFS), 1,fpp)){
        if(profs.ID==ID){//se for o ID do palestrante 
          profs.numEventos++;//incrementa numero de eventos
          int num = profs.numEventos;
          profs.eventos[num][0]=cod;
          //se for codigo de palestra incrementa numero de palestras
          if(cod>=100 && cod<200){
            profs.nPalestras=1;
          }
          if(cod>=400 && cod<500){//se for oficina
            profs.nOficinas=1;
          }
          if(cod>=300 && cod<400){//se for curso
            profs.nCursos=1;
          }
        }
      }
      fwrite(&profs,sizeof(PROFS),1,fpp);
      fclose(fpp);
    //fim
}
//DECREMENTAR PALESTRANTES
void decrementarPale(int cod,int ID){
  //TALVEZ DEVA CRIAR NOVO ARQUIVO
      int i;
      FILE *fpp;
      PROFS profs;
      fpp = fopen("arquivos\\palestrantes.txt", "ab");//abre arquivo no modo de acesso
      while (fread(&profs, sizeof(PROFS), 1,fpp)){
        if(profs.ID==ID){//se for o ID do palestrante 
          //codigo do evento será retirado do array
          int num = profs.numEventos;
          for(i=0;i<=num;i++){
            if(profs.eventos[i]==cod){//antes tinha[0]tbm
                profs.eventos[i]=0;//antes tinha[0]tbm
            }
          }
          //se for codigo de palestra decrementa numero de palestras
          if(cod>=100 && cod<200){
            profs.nPalestras=0;
          }
          if(cod>=400 && cod<500){
            profs.nOficinas=0;
          }
          if(cod>=300 && cod<400){
            profs.nCursos=0;
          }
        }
      }
      fwrite(&profs,sizeof(PROFS),1,fpp);
      fclose(fpp);
    //fim
}

//SUBSTITUIR PALESTRANTE
void trocaPalestrante(int cod,int IDvelho,int IDnovo){
  //TALVEZ DEVA CRIAR NOVO ARQUIVO
  //entrar no arquivo de palestrrantes
  int i;
  FILE *fpp;
    PROFS profs;
    fpp = fopen("arquivos\\palestrantes.txt", "ab");//abre arquivo no modo de acesso
      while (fread(&profs, sizeof(PROFS), 1,fpp)){
        //selecionar palestrante com o ID velho
        if(profs.ID==IDvelho){//se for o ID do palestrante 
          //remover COD da palestra do array de eventos
          for(i=0;i<=profs.numEventos;i++){
            if(profs.eventos[i]==cod){//antes tinha[0]tbm
                profs.eventos[i]=0;//antes tinha[0]tbm
            }
          }
          //decrementar numero de palestras
          //se for codigo de palestra decrementa numero de palestras
          if(cod>=100 && cod<200){
            profs.nPalestras=0;
          }
          if(cod>=400 && cod<500){
            profs.nOficinas=0;
          }
          if(cod>=300 && cod<400){
            profs.nCursos=0;
          }
        }
      //selecionar palestrante do novo ID
      if(profs.ID==IDnovo){//se for o ID do palestrante 
        //incrementar num de palestras
        //se for codigo de palestra incrementa numero de palestras
          if(cod>=100 && cod<200){
            profs.nPalestras=1;
          }
          if(cod>=400 && cod<500){//se for oficina
            profs.nOficinas=1;
          }
          if(cod>=300 && cod<400){//se for curso
            profs.nCursos=1;
          }
        //colocar cod da palestra no array de codigos
        profs.eventos[profs.numEventos][0]=cod;
        //incrementar num de eventos
        profs.numEventos++;
      }
    }
    fwrite(&profs,sizeof(PROFS),1,fpp);
    fclose(fpp);
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
   !! SE O COD DO EVENTO DO ARRAY FOR 0 NÃO LISTA!!
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

      fp=fopen("arquivos\\alunos.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\tempAlunos.txt","ab");//abre arquivos temporarios no modo de acesso

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
    rename("arquivos\\tempAlunos.txt","arquivos\\alunos.txt");//renomeia o aux com nome do orinial
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
      fp_aux=fopen("arquivos\\tempAlunos.txt","ab");//abre arquivos temporarios no modo de acesso


      while(fread(&aluno,sizeof(CONGRE),1,fp)){//le arquivo principal
        if(aluno.matricula!=mat){//se a matricula for a que eu quero editar
          fwrite(&aluno,sizeof(CONGRE),1,fp_aux);
        }
      }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\alunos.txt");//remove o original
    rename("arquivos\\tempAlunos.txt","arquivos\\alunos.txt");//renomeia o aux com nome do original
    //fim
  }
//listar congressistas
void listarAlunos(){
  int i;
      FILE *fp;
      CONGRE aluno;
      fp = fopen("arquivos\\alunos.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&aluno, sizeof(CONGRE), 1,fp)){//enquanto leitura for verdadeira
        printf("Matricula:%d\nNome: %s - CPF: %d\n",aluno.matricula, aluno.nome,aluno.cpf);
      }
      fclose(fp);
    //fim
}
//LISTAR CONGRESSISTAS DE EVENTOS
void listarAlunosdeEventos(int cod,int IDaluno){
  FILE *fp;
      CONGRE aluno;
      fp = fopen("arquivos\\alunos.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&aluno, sizeof(CONGRE), 1,fp)){//enquanto leitura for verdadeira
        for(i=0;i<aluno.numEventos;i++){
          if(aluno.cods[i]==cod){
            printf("Matricula: %d\nNome: %s\n",aluno.matricula,aluno.nome);
          }
        }
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
//***************************************************************************************
//PALESTRAS

//CRIAR PALESTRA
void criaPalestra(){
    //cria arquivo
    FILE *fp;
    PALESTRAS pale;//varial de ppalestras
    //teste de entrada de arquivo
    if ((fp = fopen("arquivos\\palestras.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

    puts("!FALTA ZERAR O NUM DE CADASTRADOS!")
    //cria cod
      //verifica cod
      srand(time(NULL));
      pale.cod = 100+(rand()% 99);//gerar num entre 100 e 199
      printf("Código: %d\n",pale.cod);
    
    //Insere tema
      puts("Insira o Tema da palestra");
      setbuf(stdin, NULL);
      fgets(pale.tema,TAM,stdin);
      strtok(pale.tema,"\n");
    // lista palestrantes
      puts("Lista de palestrantes");
      listarPalestrantes2(pale.cod);//envia cod pra listar só palestrantes sem palestra
      putchar('\n');
      puts("\nInsira o ID do palestrante desejado");
      //insere palestrantes
      //escolhe palestrantes da lista baseado no id
      scanf("%d",&pale.palestrante);
        //verifica se o ID escolhido corresponde ao palestrante existente!!
        //abre arquivo de palestrante para incrementar o num de palestrar e colocar o COD da palestras no array
        incrementarPale(pale.cod, pale.palestrante);

    //função para colocar local/hora/capacidade/cargahoraria
    puts("FUNÇÃO DE LOCAL TA FALTANDO");
    
      puts("Cadastro de palestra concluido");

    //escreve tudo no arquivo
      fwrite(&pale,sizeof(PALESTRAS),1,fp);
    //fecha o arquivo
      fclose(fp);
}

//LISTAR PALESTRA
void listaPalestras(){
    FILE *fp;
      PALESTRAS pale;
      fp = fopen("arquivos\\palestras.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&pale, sizeof(PALESTRAS), 1,fp)){//enquanto leitura for verdadeira
        printf("CODIGO: %d\nTEMA: %s\n",pale.cod,pale.tema);
        mostraPalestrante(pale.palestrante);//pega o id do palestrante para exibir nome
        //LISTAR HORÁRIO E LOCAL
        puts("LISTAR LOCAL E HR TA FALTANDO");
      }
      fclose(fp);
}

//EDITAR PALESTRA
void editaPalestra(){
    int op2;//op para switch
    int codigo;//codigo para pesquisa
    int ID;//ID para pesquisa
    char novoTema[TAM];

    //abrir arquivo
    //abre arquivo e verifica
      FILE *fp=NULL;
      FILE *fp_aux=NULL;//arquivo auxiliar
      PALESTRAS pale;

      fp=fopen("arquivos\\palestras.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\tempPale.txt","ab");//abre arquivos temporarios no modo de acesso

      puts("Insira o CODIGO da Palestra que deseja alterar");
        scanf("%d",&codigo);

      while(fread(&pale,sizeof(PALESTRAS),1,fp)){//le arquivo principal
        if(pale.cod==codigo){//se a matricula for a que eu quero editar
           puts("1-Tema\t2-Palestrante\t3-Local\t4-Horário");
           puts("O que deseja alterar?");
            scanf("%d",&op2);
            //escolha
            switch(op2){
                //alterar tema
                case 1:{
                  puts("Insira novo tema");
                  setbuf(stdin,NULL);
                  fgets(novoTema,TAM,stdin);
                  strtok(novoTema,"\n");
                  strcpy(pale.tema,novoTema);
                  break;
                }
                case 2:{
                  listarPalestrantes2(pale.cod);//lista palestrantes disponiveis
                  puts("Insira novo ID de palestrante");
                  scanf("%d",&ID);
                  //SUBSTITUIR PALESTRANTE
                  trocaPalestrante(pale.cod,pale.palestrante,ID);
                  
                  //substituir o ID do palestrante na palestra
                  pale.palestrante=ID;
                  break;
                }
                case 3:{//aterar local
                  puts("!Alterar local ainda não está disponivel!")
                  break;
                }
                case 4:{//aterar horario
                  puts("!Alterar horario ainda n está disponivel!")
                  break;
                }
                default:puts("Opção inválida");break;
          }
        fwrite(&pale,sizeof(PALESTRAS),1,fp_aux);//depois de editar escreve no arqivo novo
        }else{
          fwrite(&pale,sizeof(PALESTRAS),1,fp_aux);//as que eu não quero alterar são escritas no novo arquivo
        }
      }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\palestras.txt");//remove o original
    rename("arquivos\\tempPale.txt","arquivos\\palestras.txt");//renomeia o aux com nome do orinial
    //fim
}

//REMOVER PALESTRA
void removerPalestra(){
      int codigo;//pegar codigo
      puts("Insira o codigo da palestra que deseja remover");
        scanf("%d",&codigo);

      FILE *fp=NULL;
      FILE *fp_aux=NULL;//arquivo auxiliar
      PALESTRAS pale;

      fp=fopen("arquivos\\palestras.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\tempPale.txt","ab");//abre arquivos temporarios no modo de acesso

      //remover o cod da palestra dos arquivos dos palestrantes
        decrementarPale(pale.cod,pale.palestrante);
      //remover o cod da palestra dos arquivos dos alunos
        puts("!FUNÇÂO DE DECREMENTAR ALUNO ESTA EM FALTA!");
      //remover a palestra
      while(fread(&pale,sizeof(PALESTRAS),1,fp)){//le arquivo principal
        if(pale.cod!=codigo){//
          fwrite(&pale,sizeof(PALESTRAS),1,fp_aux);
        }
      }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\palestras.txt");//remove o original
    rename("arquivos\\tempPale.txt","arquivos\\palestras.txt");//renomeia o aux com nome do orinial
    //fim
}

//LISTA CONGRESSISTAS DA PALESTRA
void listarAlunosdaPalestra(){
  int codigo;//codigo da palestra
  int i;
   puts("Insira o codigo da palestra");
        scanf("%d",&codigo);

  FILE *fp=NULL;
  PALESTRAS pale;

  fp=fopen("arquivos\\palestras.txt","rb");//abre arquivos principais no modo de leitura

  while(fread(&pale,sizeof(PALESTRAS),1,fp)){//le arquivo principal
    if(pale.cod==codigo){
      for(i=0;i<pale.numCadastrados;i++){
        listarAlunosdeEventos(pale.cod,pale.cadastrados[i]);
      }
    }
  }

   fclose(fp);//fecha arquivo principal
   //fim
}