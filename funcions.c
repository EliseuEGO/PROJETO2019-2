
#include "funcions.h"


void mostra(){
  puts("não né");
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



void criarLocais(int i){
printf("I eh %d\n",i);
  //TESTA SE O ARQUIVO JA EXISTE
  int j,x,y;
  //abre arquivo e verifica
    FILE *fp;
    SLOCAL loca;//varial de local
    //teste de entrada de arquivo
    if ((fp = fopen("arquivos\\locais.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    puts("\nENTRANDO EM CRIAR LOCAIS\n");
//while (fread(&loca, sizeof(SLOCAL), 1,fp)){//enquanto leitura for verdadeira
puts("WHILW DE CRIAAR LOCAIS");
  
    //codigo de llocais
      //srand(time(NULL));
      //loca.CODL = 2000+(rand()% 999);//gerar num entre 2000 e 2999
      //printf("Codigo do Local: %d\n",loca.CODL);
    //local em si
      loca.lugar=i;//enum de locais 1-8
     // puts("lugar");
      //carga horaria de duas horas
      loca.cargahoraria=2;
      //puts("carga");
      for(j=1;j<=6;j++){//deixar todos os horarios disponiveis
        loca.horario[0][j]=j;//dia 1
        printf("\n\nDIA 1 HORA %d = %d",j,j);
        loca.horario[1][j]=j;//dia 2
        printf("\n\nDIA 2 HORA %d = %d\n",j,j);
        //puts("horario");
      }
      //zera a matriz de cods dos eventos
       for(x=0;x<6;x++){
          //for(y=0;y<4;y++){
             loca.Eventos[0][x][0]=0;
             loca.Eventos[1][x][0]=0;
             //puts("evento");
          //}
       }

      //define as capacidades dos locais
      if(i==AUD1){//se for auditorio 1
        loca.capacidade=150;
        puts("capacidade do auditorio 1");
      }
      if(i==AUD2){//se for auditorio 2
        loca.capacidade=100;
      }
      if(i==AUD3||i==SALA1||i==SALA2){//se for auditorio 3, sala1 ou sala 2
        loca.capacidade=50;
      }
      if(i==SALA3){//se for sala 3
        loca.capacidade=30;
      }
      if(i==LAB1||i==LAB2){//se for lab 1 ou lab 2
        loca.capacidade=20;
      }


  
//}
puts("FINAL");
      fwrite(&loca, sizeof(SLOCAL), 1, fp);
  fclose(fp);
}



//FUNÇÃO PARA LISTAR EVENTOS
void listarEventos(int cod){
  if(cod>=100 && cod<200){//cod de palestra
      FILE *fp;
      PALESTRAS pale;
      fp = fopen("arquivos\\palestras.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&pale, sizeof(PALESTRAS), 1,fp)){//enquanto leitura for verdadeira
        if(cod==pale.cod){
          printf("CODIGO: %d\nTEMA: %s\n",pale.cod,pale.tema);
          //LISTAR HORÁRIO E LOCAL
          puts("\nLISTAR LOCAL E HR TA FALTANDO");
        }
      }
      fclose(fp);
  }
  if(cod>=400 && cod<500){//cod de oficina
      FILE *fp;
      OFICINAS ofi;
      fp = fopen("arquivos\\oficinas.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&ofi, sizeof(OFICINAS), 1,fp)){//enquanto leitura for verdadeira
       if(cod==ofi.cod){      
        printf("CODIGO: %d\nTEMA: %s\n",ofi.cod,ofi.Tema);
        mostraPalestrante(ofi.Palestrante);//pega o id do palestrante para exibir nome
        //LISTAR HORÁRIO E LOCAL
        puts("LISTAR LOCAL E HR TA FALTANDO");
       }
      }
      fclose(fp);
      //fim
  }
  if(cod>=300 && cod<400){//cod de curso
      FILE *fp;
      CURSO curse;
      fp = fopen("arquivos\\cursos.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&curse, sizeof(CURSO), 1,fp)){//enquanto leitura for verdadeira
        if(cod==curse.cod){
          printf("CODIGO: %d\nTEMA: %s\n",curse.cod,curse.Tema);
          mostraPalestrante(curse.Palestrante);//pega o id do palestrante para exibir nome
          //LISTAR HORÁRIO E LOCAL
          puts("LISTAR LOCAL E HR TA FALTANDO");
        }
      }
      fclose(fp);
      //fim
  }
  if(cod>=200 && cod<300){//cod de GRUPO_DE_DISCUSSOES
    puts("!FUNÇÂO DE LISTAR GP ESTÁ FALTANDO!");
  }
  //!! SE O COD DO EVENTO DO ARRAY FOR 0 NÃO LISTA!!
}

//INCREMENTAR eventos com congressistas
void incrementarEventos(int cod, int mat){
  if(cod>=100 && cod<200){//cod de palestra
      int i;
    FILE *fpp;
    FILE *fpp2;
    PALESTRAS pale;

    fpp = fopen("arquivos\\palestras.txt", "rb");//abre arquivo no modo de leitura
    fpp2 = fopen("arquivos\\tempPale.txt", "ab");//abre arquivo no modo de acesso

    while (fread(&pale, sizeof(PALESTRAS), 1,fpp)){
      if(cod==pale.cod){
        //num de cadastradas não pode ser maior que a capacidade
        if((pale.numCadastrados+1)<pale.capacidadeE){
          pale.numCadastrados++;//incrementa num de cadastradas
          pale.cadastrados[pale.numCadastrados][0]=mat;//add matricula do aluno no array de cadastradas
        }else{
          puts("Numero de cadastrados atingiu o max disponivel");
        }
        fwrite(&pale,sizeof(PALESTRAS),1,fpp2);
      }else{
        fwrite(&pale,sizeof(PALESTRAS),1,fpp2);
      }
    }
    fclose(fpp);
    fclose(fpp2);
    remove("arquivos\\palestras.txt");//remove o original
    rename("arquivos\\tempPale.txt","arquivos\\palestras.txt");//renomeia o aux com nome do original
    //fim
  }

  if(cod>=200 && cod<300){//cod de GRUPO_DE_DISCUSSOES
    puts("!INCREMENTAR GRUPO_DE_DISCUSSOES ESTÁ EM FALTA!");
     //num de cadastradas não pode ser maior que a capacidade
  }

  if(cod>=300 && cod<400){//cod de curso
    int i;
    FILE *fpp;
    FILE *fpp2;
    CURSO curse;

    fpp = fopen("arquivos\\cursos.txt", "rb");//abre arquivo no modo de leitura
    fpp2 = fopen("arquivos\\tempCurse.txt", "ab");//abre arquivo no modo de acesso

    while (fread(&curse, sizeof(CURSO), 1,fpp)){
      if(cod==curse.cod){
         //num de cadastradas não pode ser maior que a capacidade
        curse.numCadastrados++;//incrementa num de cadastradas
        curse.cadastrados[curse.numCadastrados][0]=mat;//add matricula do aluno no array de cadastradas
        fwrite(&curse,sizeof(CURSO),1,fpp2);
      }else{
        fwrite(&curse,sizeof(CURSO),1,fpp2);
      }
    }
    fclose(fpp);
    fclose(fpp2);
    remove("arquivos\\cursos.txt");//remove o original
    rename("arquivos\\tempCurse.txt","arquivos\\cursos.txt");//renomeia o aux com nome do original
    //fim
  }

  if(cod>=400 && cod<500){//cod de oficina
      int i;
    FILE *fpp;
    FILE *fpp2;
    OFICINAS ofi;

    fpp = fopen("arquivos\\oficinas.txt", "rb");//abre arquivo no modo de leitura
    fpp2 = fopen("arquivos\\tempOfi.txt", "ab");//abre arquivo no modo de acesso

    while (fread(&ofi, sizeof(OFICINAS), 1,fpp)){
      if(cod==ofi.cod){
         //num de cadastradas não pode ser maior que a capacidade
        ofi.numCadastrados++;//incrementa num de cadastradas
        ofi.cadastrados[ofi.numCadastrados][0]=mat;//add matricula do aluno no array de cadastradas
        fwrite(&ofi,sizeof(OFICINAS),1,fpp2);
      }else{
        fwrite(&ofi,sizeof(OFICINAS),1,fpp2);
      }
    }
    fclose(fpp);
    fclose(fpp2);
    remove("arquivos\\oficinas.txt");//remove o original
    rename("arquivos\\tempOfi.txt","arquivos\\oficinas.txt");//renomeia o aux com nome do original
    //fim
  }
}

//DECREMENTAR EVENTOS DO CONGRESSISTA
void decrementarEventos(int cod, int mat){
  if(cod>=100 && cod<200){//cod de palestra
      int i;
    FILE *fpp;
    FILE *fpp2;
    PALESTRAS pale;

    fpp = fopen("arquivos\\palestras.txt", "rb");//abre arquivo no modo de leitura
    fpp2 = fopen("arquivos\\tempPale.txt", "ab");//abre arquivo no modo de acesso

    while (fread(&pale, sizeof(PALESTRAS), 1,fpp)){
      if(cod==pale.cod){
        //num de cadastradas não pode ser maior que a capacidade
        for(i=0;i<pale.numCadastrados;i++){
          if(pale.cadastrados[i][0]==mat){
            pale.cadastrados[i][0]=0;//add matricula do aluno no array de cadastradas
          }
        }
        pale.numCadastrados--;//decrementa num de cadastradas
        fwrite(&pale,sizeof(PALESTRAS),1,fpp2);
      }else{
        fwrite(&pale,sizeof(PALESTRAS),1,fpp2);
      }
    }
    fclose(fpp);
    fclose(fpp2);
    remove("arquivos\\palestras.txt");//remove o original
    rename("arquivos\\tempPale.txt","arquivos\\palestras.txt");//renomeia o aux com nome do original
    //fim
  }

  if(cod>=200 && cod<300){//cod de GRUPO_DE_DISCUSSOES
    puts("!INCREMENTAR GRUPO_DE_DISCUSSOES ESTÁ EM FALTA!");
     //num de cadastradas não pode ser maior que a capacidade
  }

  if(cod>=300 && cod<400){//cod de curso
    int i;
    FILE *fpp;
    FILE *fpp2;
    CURSO curse;

    fpp = fopen("arquivos\\cursos.txt", "rb");//abre arquivo no modo de leitura
    fpp2 = fopen("arquivos\\tempCurse.txt", "ab");//abre arquivo no modo de acesso

    while (fread(&curse, sizeof(CURSO), 1,fpp)){
      if(cod==curse.cod){
         for(i=0;i<curse.numCadastrados;i++){
          if(curse.cadastrados[i][0]==mat){
            curse.cadastrados[i][0]=0;//add matricula do aluno no array de cadastradas
          }
        }
        curse.numCadastrados--;//decrementa num de cadastradas
        fwrite(&curse,sizeof(CURSO),1,fpp2);
      }else{
        fwrite(&curse,sizeof(CURSO),1,fpp2);
      }
    }
    fclose(fpp);
    fclose(fpp2);
    remove("arquivos\\cursos.txt");//remove o original
    rename("arquivos\\tempCurse.txt","arquivos\\cursos.txt");//renomeia o aux com nome do original
    //fim
  }

  if(cod>=400 && cod<500){//cod de oficina
      int i;
    FILE *fpp;
    FILE *fpp2;
    OFICINAS ofi;

    fpp = fopen("arquivos\\oficinas.txt", "rb");//abre arquivo no modo de leitura
    fpp2 = fopen("arquivos\\tempOfi.txt", "ab");//abre arquivo no modo de acesso

    while (fread(&ofi, sizeof(OFICINAS), 1,fpp)){
      if(cod==ofi.cod){
         for(i=0;i<ofi.numCadastrados;i++){
          if(ofi.cadastrados[i][0]==mat){
            ofi.cadastrados[i][0]=0;//add matricula do aluno no array de cadastradas
          }
        }
        ofi.numCadastrados--;//decrementa num de cadastradas
        fwrite(&ofi,sizeof(OFICINAS),1,fpp2);
      }else{
        fwrite(&ofi,sizeof(OFICINAS),1,fpp2);
      }
    }
    fclose(fpp);
    fclose(fpp2);
    remove("arquivos\\oficinas.txt");//remove o original
    rename("arquivos\\tempOfi.txt","arquivos\\oficinas.txt");//renomeia o aux com nome do original
    //fim
  }
}

int numCongressistas(){
  int cont=0;
  FILE *fp;
  CONGRE aluno;
  fp = fopen("arquivos\\alunos.txt", "rb");
  while(fread(&aluno,sizeof(CONGRE),1,fp)){
    cont++;
  }
  return cont;
}

int numPalestrantes(){
  int cont=0;
  FILE *fp;
  PROFS profs;
  fp = fopen("arquivos\\palestrantes.txt", "rb");
  while(fread(&profs,sizeof(PROFS),1,fp)){
    cont++;
  }
  return cont;
}
//FUNÇÕES PALESTRANTES----------------------------------------
//cadastrar palestrante
void cadastroPalestrante(){
    int i,j;
    printf("\nCADASTRO DE PALESTRANTE\n");
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

    //zerar eventos
      profs.numEventos=0;
    //zerar contador de eventos
      for(i=0;i<30;i++){
        for(j=0;j<4;j++){
          profs.eventos[i][j]=0;
        }
      }
    //zerar num de palestras, cursos e oficinas
      profs.nPalestras=0;
      profs.nCursos=0;
      profs.nOficinas=0;
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

      listarPalestrantes();
      puts("\n\nInsira o ID do palestrante");
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
        listarPalestrantes();
        puts("\n\nInsira o ID do palestrante que deseja remover");
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
  puts("\nListar palestrantes");
  FILE *fpp;
      PROFS profs;
      fpp = fopen("arquivos\\palestrantes.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&profs, sizeof(PROFS), 1,fpp)){//enquanto leitura for verdadeira
        printf("\nID:%d\nNome: %s - CPF: %d\n",profs.ID, profs.nome,profs.cpf);
      }
      fclose(fpp);
    //fim
}
//Listar palestrantes
void listarPalestrantes2(int cod){//lista só os que não estão em certos eventos
  puts("**entrando em listar palestrantes 2**");
  FILE *fpp;
      PROFS profs;
      fpp = fopen("arquivos\\palestrantes.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&profs, sizeof(PROFS), 1,fpp)){//enquanto leitura for verdadeira
        if(cod>=100&&cod<200){//se for codigo de palestra
          if(profs.nPalestras==0){
           printf("\nID:%d\nNome: %s\n",profs.ID, profs.nome);
          } 
        }
        if(cod>=300&&cod<400){//se for codigo de curso
          if(profs.nCursos==0){
           printf("\nID:%d\nNome: %s\n",profs.ID, profs.nome);
          } 
        }
        if(cod>=400&&cod<500){//se for codigo de oficinas
          if(profs.nOficinas==0){
           printf("\nID:%d\nNome: %s\n",profs.ID, profs.nome);
          } 
        }
        if(cod>=200&&cod<300){//se for codigo de grupo
          printf("\nID:%d\nNome: %s\n",profs.ID, profs.nome);
        }
      }
      fclose(fpp);
    //fim
}
//LISTAR EVENTOS DO PALESTRANTE 
void listaEventosdoPalestrante(){
  puts("\nLista de Eventos de um palestrante");
  int i; //contador
  listarPalestrantes();
  int ID;
  printf("Insira o ID do palestrante >>");
  scanf("%d",&ID);
  FILE *fpp;
      PROFS profs;
      fpp = fopen("arquivos\\palestrantes.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&profs, sizeof(PROFS), 1,fpp)){//enquanto leitura for verdadeira
        if(ID==profs.ID){
          printf("Eventos de %s\n",profs.nome);
          //FUNÇÃO PARA LISTAR EVENTOS
          for(i=0;i<profs.numEventos;i++){
              listarEventos(profs.eventos[i][0]);
          }
          //!! SE O COD DO EVENTO DO ARRAY FOR 0 NÃO LISTA!!
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
          printf("Palestrante: %s\n",profs.nome);
        }
      }
      fclose(fpp);
    //fim
}
//INCREMENTAR PALESTRANTES
void incrementarPale(int cod,int ID){
  //TALVEZ DEVA CRIAR NOVO ARQUIVO
  puts("\n**ENTRANDO EM INCREMENTAR PALESTRAS\n**");
  int i;
  FILE *fpp;
  FILE *fpp2;
      PROFS profs;
      fpp = fopen("arquivos\\palestrantes.txt", "rb");//abre arquivo no modo de LEITURA
      fpp2 = fopen("arquivos\\tempProfI.txt","ab");
      while (fread(&profs, sizeof(PROFS), 1,fpp)){
        if(profs.ID==ID){//se for o ID do palestrante 
          profs.numEventos++;//incrementa numero de eventos
          puts("\n**INCREMENTANDO NUM DE EVENTOS\n**");
          int num = profs.numEventos;
          profs.eventos[num][0]=cod;
          //se for codigo de palestra incrementa numero de palestras
          if(cod>=100 && cod<200){
            profs.nPalestras=1;
            puts("\n**PALESTRAS=1\n**");
          }
          if(cod>=400 && cod<500){//se for oficina
            profs.nOficinas=1;
            puts("\n**OFICINAS=1\n**");
          }
          if(cod>=300 && cod<400){//se for curso
            profs.nCursos=1;
            puts("\n**CURSOS=1\n**");
          }
          fwrite(&profs,sizeof(PROFS),1,fpp2);
        }else{
          fwrite(&profs,sizeof(PROFS),1,fpp2);
        }
      }
      puts("\n**ESCREVENDO NO ARQUIVO E SAINDO DA FUNÇÃO\n**");
      //fwrite(&profs,sizeof(PROFS),1,fpp);
      fclose(fpp);
      fclose(fpp2);
      system("PAUSE");
      remove("arquivos\\palestrantes.txt");//remove o original
      rename("arquivos\\tempProfI.txt","arquivos\\palestrantes.txt");//renomeia o aux com nome do orinial
    //fim 
    system("PAUSE");
    //fim
}
//DECREMENTAR PALESTRANTES
void decrementarPale(int cod,int ID){
 
      puts("\n**ENTRANDO EM DECREMENTAR PALESTRAS\n**");
      int i;
      FILE *fpp;
      FILE *fpp2;
      PROFS profs;
      fpp = fopen("arquivos\\palestrantes.txt", "rb");//abre arquivo no modo de acesso
      fpp2 = fopen("arquivos\\tempProfI.txt","ab");
      while (fread(&profs, sizeof(PROFS), 1,fpp)){
        if(profs.ID==ID){//se for o ID do palestrante 
          //codigo do evento será retirado do array
          int num = profs.numEventos;
          for(i=0;i<=num;i++){
            if(profs.eventos[i][0]==cod){//antes tinha[0]tbm
                profs.eventos[i][0]=0;//antes tinha[0]tbm
                puts("\n**COD DO EVENTO ZERA\n**");
            }
          }
          //se for codigo de palestra decrementa numero de palestras
          if(cod>=100 && cod<200){
            profs.nPalestras=0;
            puts("\n**PALESTRAS=0\n**");
          }
          if(cod>=400 && cod<500){
            profs.nOficinas=0;
            puts("\n**OFICINAS=0\n**");
          }
          if(cod>=300 && cod<400){
            profs.nCursos=0;
            puts("\n**CURSOS=0\n**");
          }
          fwrite(&profs,sizeof(PROFS),1,fpp2);
        }else{
          fwrite(&profs,sizeof(PROFS),1,fpp2);
        }
      }
      fclose(fpp2);
      fclose(fpp);
      remove("arquivos\\palestrantes.txt");//remove o original
      rename("arquivos\\tempProfI.txt","arquivos\\palestrantes.txt");//renomeia o aux com nome do orinial
    //fim
}

//SUBSTITUIR PALESTRANTE
void trocaPalestrante(int cod,int IDvelho,int IDnovo){
  
  incrementarPale(cod,IDnovo);//insere os dados do evento no novo palestrante
  decrementarPale(cod,IDvelho);//retira os dados do evento do antigo palestrante
  
}


//-----------------------------------------------------------------



//funções congressistas------------------------------------------------------
void NovoCongressista(){
  puts("\nCadastrar congressista");
      int i,j;//contadores
      FILE *fp=NULL;
      CONGRE aluno;

  //abre arquivo e verifica


    if ((fp = fopen("arquivos\\alunos.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

    //matricula
      srand(time(NULL));
      aluno.matricula = 1001+(rand()% 301);//gerar num entre 1000 e 1300
      printf("Matricula: %d\n",aluno.matricula);
    //nome
      puts("Insira o nome do congressista");
      setbuf(stdin, NULL);
      fgets(aluno.nome,TAM,stdin);
      strtok(aluno.nome,"\n");
    //cpf ou curso
      puts("Insira seu CPF");
      scanf("%d",&aluno.cpf);
    //zerar contador de eventos
      for(i=0;i<20;i++){
        for(j=0;j<4;j++){
          aluno.cods[i][j]=0;
        }
      }
    //zerar numero de eventos
      aluno.numEventos=0;
    //zerar numero de cursos e oficinas
      aluno.nOficinas=0;
      aluno.nCursos=0;
      puts("Cadastro concluido");

      fwrite(&aluno,sizeof(CONGRE),1,fp);
      fclose(fp);
}
//EDITAR CONGRESSISTA
void editaAluno(){
  puts("\nEditar congressista");
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
      listarAlunos();
      puts("\n\nInsira a matricula do aluno");
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
  puts("\nRemover congressista");
      int mat,i;//pegar matricula
      listarAlunos();
      puts("\n\nInsira a matricula do aluno");
        scanf("%d",&mat);

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
        }else{
          for(i=0;i<aluno.numEventos;i++){
            decrementarEventos(aluno.cods[i][0] ,mat);
          }
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
  puts("\nLista de congressistas");
      int i;
      FILE *fpp;
      CONGRE aluno;
      fpp = fopen("arquivos\\alunos.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&aluno, sizeof(CONGRE), 1,fpp)){//enquanto leitura for verdadeira
        printf("\nMatricula:%d\nNome: %s - CPF: %d\n\n",aluno.matricula, aluno.nome,aluno.cpf);
      }
      fclose(fpp);
    //fim
}
//LISTAR ALUNOS SEM CURSO OU SEM OFICINA
void listarAlunos2(int cod){
  puts("\nLista de congressistas");
      int i;
      FILE *fpp;
      CONGRE aluno;
      fpp = fopen("arquivos\\alunos.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&aluno, sizeof(CONGRE), 1,fpp)){//enquanto leitura for verdadeira
        if(cod>=400 && cod<500){//se for oficina
            if(aluno.nOficinas==0){
              printf("\nMatricula:%d\nNome: %s - CPF: %d\n\n",aluno.matricula, aluno.nome,aluno.cpf);
            }
          }
          if(cod>=300 && cod<400){//se for curso
            if(aluno.nCursos==0){
              printf("\nMatricula:%d\nNome: %s - CPF: %d\n\n",aluno.matricula, aluno.nome,aluno.cpf);
            }
          }
          if((cod>=100 && cod<200)||(cod>=200 && cod<300)){
            printf("\nMatricula:%d\nNome: %s - CPF: %d\n\n",aluno.matricula, aluno.nome,aluno.cpf);
          }
      }
      fclose(fpp);
    //fim
}
//LISTAR CONGRESSISTAS DE EVENTOS
void listarAlunosdeEventos(int cod,int IDaluno){
    int i;
    FILE *fpp;
      CONGRE aluno;
      fpp = fopen("arquivos\\alunos.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&aluno, sizeof(CONGRE), 1,fpp)){//enquanto leitura for verdadeira
        for(i=0;i<aluno.numEventos;i++){
          if(aluno.cods[i][0]==cod){
            printf("Matricula: %d\nNome: %s\n",aluno.matricula,aluno.nome);
          }
        }
      }
      fclose(fpp);
    //fim
}
//INCREMENTAR EVENTO EM CONGRESSISTA
void incrementarAluno(int cod,int mat){//recebe o codigo do evento e a matricula do aluno
    int i;
    FILE *fpp;
    FILE *fpp2;
    CONGRE aluno;

    fpp = fopen("arquivos\\alunos.txt", "rb");//abre arquivo no modo de leitura
    fpp2 = fopen("arquivos\\tempAlunos.txt", "ab");//abre arquivo no modo de acesso

    while (fread(&aluno, sizeof(CONGRE), 1,fpp)){
        if(mat==aluno.matricula){
          aluno.cods[aluno.numEventos][0]=cod;//coloca codigo do evento no array de codigos
          aluno.numEventos++;//incrementa num de evnetos 

          if(cod>=400 && cod<500){//se for oficina
            aluno.nOficinas=1;
            puts("\n**OFICINAS=1\n**");
          }
          if(cod>=300 && cod<400){//se for curso
            aluno.nCursos=1;
            puts("\n**CURSOS=1\n**");
          }
          fwrite(&aluno,sizeof(CONGRE),1,fpp2);
        }else{
          fwrite(&aluno,sizeof(CONGRE),1,fpp2);
        }
    }
    fclose(fpp);
    fclose(fpp2);
    remove("arquivos\\alunos.txt");//remove o original
    rename("arquivos\\tempAlunos.txt","arquivos\\alunos.txt");//renomeia o aux com nome do original
    //fim
}
//DECREMENTAR EVENTO DE UM CONGRESSISTA
void decrementarAluno(int cod, int mat){
    int i;
    FILE *fpp;
    FILE *fpp2;
    CONGRE aluno;

    fpp = fopen("arquivos\\alunos.txt", "rb");//abre arquivo no modo de leitura
    fpp2 = fopen("arquivos\\tempAlunos.txt", "ab");//abre arquivo no modo de acesso

    while (fread(&aluno, sizeof(CONGRE), 1,fpp)){
        if(mat==aluno.matricula){
          for(i=0;i<aluno.numEventos;i++){          
            if(aluno.cods[i][0]==cod){
              aluno.cods[i][0]=0;
            };//zera o codigo do evento no array de codigos
          }

          if(cod>=400 && cod<500){//se for oficina
            aluno.nOficinas=0;
            puts("\n**OFICINAS=0\n**");
          }
          if(cod>=300 && cod<400){//se for curso
            aluno.nCursos=0;
            puts("\n**CURSOS=0\n**");
          }
          fwrite(&aluno,sizeof(CONGRE),1,fpp2);
        }else{
          fwrite(&aluno,sizeof(CONGRE),1,fpp2);
        }
    }
    fclose(fpp);
    fclose(fpp2);
    remove("arquivos\\alunos.txt");//remove o original
    rename("arquivos\\tempAlunos.txt","arquivos\\alunos.txt");//renomeia o aux com nome do original
    //fim

}

//CADASTRAR EM EVENTO
void cadastrarAlunoemEvento(){
  int op,mat,cod;

  puts("\n1-Palestras\t2-Gp de discussão\t3-Curso\t4-Oficina\n5-Sair");
  printf("Deseja cadastrar um congressita em qual evento?>>");
  scanf("%d",&op);

  switch(op){
    case 1:{//PALESTRAS
    //[Abre o evento e testa se o numero de matriculas é igual a capacidade do local]
    puts("!Falta testar se o num de matriculas é igual a capacidade do local!");
      //listar palestras
      listaPalestras();
      putchar('\n');
      printf("\nInsira o codigo da palestra desejada>>");
      scanf("%d",&cod);

        listarAlunos2(cod);//LISTAR ALUNOS PARA escolha
        printf("Insira a matricula do aluno que quer cadastrar>>");
        putchar('\n');
        scanf("%d",&mat);

      //incrementar PALESTRA
      incrementarEventos(cod,mat);
      //incrementar aluno
      incrementarAluno(cod,mat);
      break;
    }
    case 2:{//GRUPO_DE_DISCUSSOES
      puts("!FALTA FUNÇÃO PARA CADASTRAR CONGRESSISTA NO GRUPO_DE_DISCUSSOES!");
      break;
    }
    case 3:{//Curso
      //[Abre o evento e testa se o numero de matriculas é igual a capacidade do local]
      puts("!Falta testar se o num de matriculas é igual a capacidade do local!");
      //listar cursos
      listaCursos();
      putchar('\n');
      printf("\nInsira o codigo da palestra desejada>>");
      scanf("%d",&cod);

      listarAlunos2(cod);//LISTAR ALUNOS PARA escolha
        printf("Insira a matricula do aluno que quer cadastrar>>");
        putchar('\n');
        scanf("%d",&mat);

      //incrementar curso
      incrementarEventos(cod,mat);
      //incrementar aluno
      incrementarAluno(cod,mat);
      break;
    }
    case 4:{//OFICINA
      //[Abre o evento e testa se o numero de matriculas é igual a capacidade do local]
      puts("!Falta testar se o num de matriculas é igual a capacidade do local!");
      //listar oficina
      listaOficinas();
      putchar('\n');
      printf("\nInsira o codigo da palestra desejada>>");
      scanf("%d",&cod);

      listarAlunos2(cod);//LISTAR ALUNOS PARA escolha
        printf("Insira a matricula do aluno que quer cadastrar>>");
        putchar('\n');
        scanf("%d",&mat);

      //incrementar PALESTRA
      incrementarEventos(cod,mat);
      //incrementar aluno
      incrementarAluno(cod,mat);
      break;
    }
  }
 
}
//LISTAR ALUNOS COM EVENTOS
void listadeAlunoscomEventos(){
  FILE *fpp;
      CONGRE aluno;
      fpp = fopen("arquivos\\alunos.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&aluno, sizeof(CONGRE), 1,fpp)){//enquanto leitura for verdadeira
        if(aluno.numEventos>0){
          printf("\nMatricula: %d\nNome: %s\n",aluno.matricula,aluno.nome);
        }
      }
    fclose(fpp);
}
//LISTAR EVENTOS DO CONGRESSISTA
void listaEventosdeAlunos(){
  int mat,i;
    FILE *fpp;
      CONGRE aluno;
      fpp = fopen("arquivos\\alunos.txt", "rb");//abre arquivo no modo de leitura
      listadeAlunoscomEventos();
      putchar('\n');
      printf("Insira a matricula do aluno para listar eventos>>");
      scanf("%d",&mat);
      while (fread(&aluno, sizeof(CONGRE), 1,fpp)){//enquanto leitura for verdadeira
        if(mat==aluno.matricula){
          for(i=0;i<aluno.numEventos;i++){
            listarEventos(aluno.cods[i][0]);
          }
        }
      }
}
//SAIR DO EVENTO
void deixarEvento(){
  puts("\nSair do evento");
  int mat,i,cod;
    FILE *fpp;

    CONGRE aluno;
    fpp = fopen("arquivos\\alunos.txt", "rb");//abre arquivo no modo de leitura
    
    listadeAlunoscomEventos();
    putchar('\n');
    printf("Insira a matricula do congressista>>");
    scanf("%d",&mat);
      while (fread(&aluno, sizeof(CONGRE), 1,fpp)){//enquanto leitura for verdadeira
        if(mat==aluno.matricula){
          for(i=0;i<aluno.numEventos;i++){
            listarEventos(aluno.cods[i][0]);
          }
        }
      }
      printf("Insira o codigo do evento que deseja remover>>");
      scanf("%d",&cod);
      decrementarEventos(cod,mat);
      puts("Removido dos eventos");
      decrementarAluno(cod, mat);
      puts("Evento removido");
      fclose(fpp);
      //fim
}
//fim das funções dos congressistas---------------------------------------------------------

//***************************************************************************************
//PALESTRAS

//CRIAR PALESTRA
void criaPalestra(){
  puts("\nCriar palestra");
    int i,j;//contadores
    //cria arquivo
    FILE *fp;
    PALESTRAS pale;//varial de palestras
    //teste de entrada de arquivo
    if ((fp = fopen("arquivos\\palestras.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

    //zerar cadastrados
    for(i=0;i<150;i++){
        for(j=0;j<5;j++){
          pale.cadastrados[i][j]=0;
        }
      }
    //zerar num de cadastrados
      pale.numCadastrados=0;
    //zerar palestrantes
      pale.palestrante=0;

    //cria cod
      //verifica cod
      srand(time(NULL));
      pale.cod = 100+(rand()% 99);//gerar num entre 100 e 199
      printf("Código da palestra: %d\n",pale.cod);
    
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
    //ESCOLHE LOCAL(COD DO EVENTO)
      testeEscolheLocal(pale.cod);
      puts("Cadastro de palestra concluido");

    //escreve tudo no arquivo
      fwrite(&pale,sizeof(PALESTRAS),1,fp);
    //fecha o arquivo
      fclose(fp);
}

//LISTAR PALESTRA
void listaPalestras(){
  puts("\nLista de palestras");
    FILE *fp;
      PALESTRAS pale;
      fp = fopen("arquivos\\palestras.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&pale, sizeof(PALESTRAS), 1,fp)){//enquanto leitura for verdadeira
        printf("CODIGO: %d\nTEMA: %s\n",pale.cod,pale.tema);
        mostraPalestrante(pale.palestrante);//pega o id do palestrante para exibir nome
        //LISTAR HORÁRIO E LOCAL
        puts("\nLISTAR LOCAL E HR TA FALTANDO");
        listaHorariodoEvento(pale.cod);
        puts("\n------------------------------------------\n");
      }
      fclose(fp);
}

//EDITAR PALESTRA
void editaPalestra(){
  puts("\nEditar palestra\n");

    listaPalestras();

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

      puts("\n\nInsira o CODIGO da Palestra que deseja alterar");
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
                  puts("!Alterar local ainda não está disponivel!");
                  break;
                }
                case 4:{//aterar horario
                  puts("!Alterar horario ainda n está disponivel!");
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
  puts("\nRemover palestra\n");
      int codigo;//pegar codigo
      int i;
      listaPalestras();
      puts("\nInsira o codigo da palestra que deseja remover");
        scanf("%d",&codigo);

      FILE *fp=NULL;
      FILE *fp_aux=NULL;//arquivo auxiliar
      PALESTRAS pale;

      fp=fopen("arquivos\\palestras.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\tempPale.txt","ab");//abre arquivos temporarios no modo de acesso

      
      //remover a palestra
      while(fread(&pale,sizeof(PALESTRAS),1,fp)){//le arquivo principal
        if(pale.cod!=codigo){//
          fwrite(&pale,sizeof(PALESTRAS),1,fp_aux);
        }else{
            //remover o cod da palestra dos arquivos dos palestrantes
            decrementarPale(codigo,pale.palestrante);
            //remover o cod da palestra dos arquivos dos alunos
            for(i=0;i<pale.numCadastrados;i++){
            decrementarAluno(codigo,pale.cadastrados[i][0]);
        }
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
  puts("\nLista de alunos da palestra");
  int codigo;//codigo da palestra
  int i;
    listaPalestras();
   puts("\n\nInsira o codigo da palestra");
        scanf("%d",&codigo);

  FILE *fp=NULL;
  PALESTRAS pale;

  fp=fopen("arquivos\\palestras.txt","rb");//abre arquivos principais no modo de leitura

  while(fread(&pale,sizeof(PALESTRAS),1,fp)){//le arquivo principal
    if(pale.cod==codigo){
      for(i=0;i<pale.numCadastrados;i++){
        //codigos=pale.cadastrados
        listarAlunosdeEventos(pale.cod,pale.cadastrados[i][0]);
      }
    }
  }

   fclose(fp);//fecha arquivo principal
   //fim
}




//CURSOS******************************************************************
//CRIAR CURSO
void criaCurso(){
  puts("\nCriar curso");
  int i,j;//contadores
  //cria arquivo
    FILE *fp;
    CURSO curse;
    //teste de entrada de arquivo
    if ((fp = fopen("arquivos\\cursos.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

   //zerar cadastrados
    for(i=0;i<TAM2;i++){
        for(j=0;j<5;j++){
          curse.cadastrados[i][j]=0;
        }
      }
    //zerar num de cadastrados
      curse.numCadastrados=0;
    //zerar palestrantes
      curse.Palestrante=0;
    //cria cod
      //verifica cod
      srand(time(NULL));
      curse.cod = 300+(rand()% 99);//gerar num entre 300 e 199
      printf("Código: %d\n",curse.cod);
    
    //Insere tema
      puts("Insira o Tema do curso");
      setbuf(stdin, NULL);
      fgets(curse.Tema,TAM,stdin);
      strtok(curse.Tema,"\n");
    // lista palestrantes
      puts("Lista de palestrantes");
      listarPalestrantes2(curse.cod);//envia cod pra listar só palestrantes sem curso
      putchar('\n');
      puts("\nInsira o ID do palestrante desejado");
      //insere palestrantes
      //escolhe palestrantes da lista baseado no id
      scanf("%d",&curse.Palestrante);
        //verifica se o ID escolhido corresponde ao palestrante existente!!
        //abre arquivo de palestrante para incrementar o num de palestrar e colocar o COD da palestras no array
        incrementarPale(curse.cod, curse.Palestrante);

    //função para colocar local/hora/capacidade/cargahoraria
    puts("FUNÇÃO DE LOCAL TA FALTANDO");
    
      puts("Cadastro de curso concluido");

    //escreve tudo no arquivo
      fwrite(&curse,sizeof(CURSO),1,fp);
    //fecha o arquivo
      fclose(fp);
    //fim
}

//LISTAR CURSOS
void listaCursos(){
  puts("\nLista de cursos");
  FILE *fp;
      CURSO curse;
      fp = fopen("arquivos\\cursos.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&curse, sizeof(CURSO), 1,fp)){//enquanto leitura for verdadeira
        printf("CODIGO: %d\nTEMA: %s\n",curse.cod,curse.Tema);
        mostraPalestrante(curse.Palestrante);//pega o id do palestrante para exibir nome
        //LISTAR HORÁRIO E LOCAL
        puts("LISTAR LOCAL E HR TA FALTANDO");
      }
      fclose(fp);
      //fim
}

//EDITAR CURSO
void editaCurso(){
  puts("\nEditar curso");
    int op2;//op para switch
    int codigo;//codigo para pesquisa
    int ID;//ID para pesquisa
    char novoTema[TAM];

    //abrir arquivo
    //abre arquivo e verifica
      FILE *fp=NULL;
      FILE *fp_aux=NULL;//arquivo auxiliar
      CURSO curse;

      fp=fopen("arquivos\\cursos.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\tempCurse.txt","ab");//abre arquivos temporarios no modo de acesso

      listaCursos();
      puts("\n\nInsira o CODIGO do Curso que deseja alterar");
        scanf("%d",&codigo);

      while(fread(&curse,sizeof(CURSO),1,fp)){//le arquivo principal
        if(curse.cod==codigo){//se a matricula for a que eu quero editar
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
                  strcpy(curse.Tema,novoTema);
                  break;
                }
                case 2:{
                  listarPalestrantes2(curse.cod);//lista palestrantes disponiveis
                  puts("Insira novo ID de palestrante");
                  scanf("%d",&ID);
                  //SUBSTITUIR PALESTRANTE
                  trocaPalestrante(curse.cod,curse.Palestrante,ID);
                  
                  //substituir o ID do palestrante na palestra
                  curse.Palestrante=ID;
                  break;
                }
                case 3:{//aterar local
                  puts("!Alterar local ainda não está disponivel!");
                  break;
                }
                case 4:{//aterar horario
                  puts("!Alterar horario ainda n está disponivel!");
                  break;
                }
                default:puts("Opção inválida");break;
          }
        fwrite(&curse,sizeof(CURSO),1,fp_aux);//depois de editar escreve no arqivo novo
        }else{
          fwrite(&curse,sizeof(CURSO),1,fp_aux);//as que eu não quero alterar são escritas no novo arquivo
        }
      }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\cursos.txt");//remove o original
    rename("arquivos\\tempCurse.txt","arquivos\\cursos.txt");//renomeia o aux com nome do orinial
    //fim
}

//REMOVER CURSO
void removerCurso(){
  puts("\nRemover curso");
    int codigo;//pegar codigo
    int i;
      listaCursos();
      puts("Insira o codigo do curso que deseja remover");
        scanf("%d",&codigo);

      FILE *fp=NULL;
      FILE *fp_aux=NULL;//arquivo auxiliar
      CURSO curse;

      fp=fopen("arquivos\\cursos.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\tempCurse.txt","ab");//abre arquivos temporarios no modo de acesso

     
        puts("!FUNÇÂO DE DECREMENTAR ALUNO ESTA EM FALTA!");
      //remover a palestra
      while(fread(&curse,sizeof(CURSO),1,fp)){//le arquivo principal
        if(curse.cod!=codigo){//
          fwrite(&curse,sizeof(CURSO),1,fp_aux);
        }else{
          //remover o cod da palestra dos arquivos dos palestrantes
            decrementarPale(codigo,curse.Palestrante);
            //remover o cod da palestra dos arquivos dos alunos
            for(i=0;i<curse.numCadastrados;i++){
            decrementarAluno(codigo,curse.cadastrados[i][0]);
            }
        }
      }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\cursos.txt");//remove o original
    rename("arquivos\\tempCurse.txt","arquivos\\cursos.txt");//renomeia o aux com nome do orinial
    //fim
}

//LISTAR CONGRESSISTAS DO CURSO
void listarAlunosdoCurso(){
  puts("\nListar alunos do curso");
  int codigo;//codigo do curso
  int i;
  listaCursos();
   puts("\n\nInsira o codigo do curso");
        scanf("%d",&codigo);

  FILE *fp=NULL;
  CURSO curse;

  fp=fopen("arquivos\\cursos.txt","rb");//abre arquivos principais no modo de leitura

  while(fread(&curse,sizeof(CURSO),1,fp)){//le arquivo principal
    if(curse.cod==codigo){
      for(i=0;i<curse.numCadastrados;i++){
        listarAlunosdeEventos(curse.cod,curse.cadastrados[i][0]);
      }
    }
  }

   fclose(fp);//fecha arquivo principal
   //fim
}
//***************************************************************************

//OFICINAS**************************************************************************
//CRIAR OFICINA
void criaOficina(){
  puts("\nCriar oficina");
    int i,j;//contadores
  //cria arquivo
    FILE *fp;
    OFICINAS ofi;
    //teste de entrada de arquivo
    if ((fp = fopen("arquivos\\oficinas.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

     //zerar cadastrados
    for(i=0;i<TAM2;i++){
        for(j=0;j<5;j++){
          ofi.cadastrados[i][j]=0;
        }
      }
    //zerar num de cadastrados
      ofi.numCadastrados=0;
    //zerar palestrantes
      ofi.Palestrante=0;
    //cria cod
      //verifica cod
      srand(time(NULL));
      ofi.cod = 400+(rand()% 99);//gerar num entre 400 e 199
      printf("Código: %d\n",ofi.cod);
    
    //Insere tema
      puts("Insira o Tema da oficina");
      setbuf(stdin, NULL);
      fgets(ofi.Tema,TAM,stdin);
      strtok(ofi.Tema,"\n");
    // lista palestrantes
      puts("Lista de palestrantes");
      listarPalestrantes2(ofi.cod);//envia cod pra listar só palestrantes sem oficina
      putchar('\n');
      puts("\nInsira o ID do palestrante desejado");
      //insere palestrantes
      //escolhe palestrantes da lista baseado no id
      scanf("%d",&ofi.Palestrante);
        //verifica se o ID escolhido corresponde ao palestrante existente!!
        //abre arquivo de palestrante para incrementar o num de palestrar e colocar o COD da palestras no array
        incrementarPale(ofi.cod, ofi.Palestrante);

    //função para colocar local/hora/capacidade/cargahoraria
    puts("FUNÇÃO DE LOCAL TA FALTANDO");
    
      puts("Cadastro de oficina concluido");

    //escreve tudo no arquivo
      fwrite(&ofi,sizeof(OFICINAS),1,fp);
    //fecha o arquivo
      fclose(fp);
    //fim
}

//LISTAR OFICINAS
void listaOficinas(){
  puts("\nLista de oficinas");
  FILE *fp;
      OFICINAS ofi;
      fp = fopen("arquivos\\oficinas.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&ofi, sizeof(OFICINAS), 1,fp)){//enquanto leitura for verdadeira
        printf("CODIGO: %d\nTEMA: %s\n",ofi.cod,ofi.Tema);
        mostraPalestrante(ofi.Palestrante);//pega o id do palestrante para exibir nome
        //LISTAR HORÁRIO E LOCAL
        puts("LISTAR LOCAL E HR TA FALTANDO");
      }
      fclose(fp);
      //fim
}

//EDITAR OFICINAS
void editaOficinas(){
  puts("\nEditar oficina");
    int op2;//op para switch
    int codigo;//codigo para pesquisa
    int ID;//ID para pesquisa
    char novoTema[TAM];

    //abrir arquivo
    //abre arquivo e verifica
      FILE *fp=NULL;
      FILE *fp_aux=NULL;//arquivo auxiliar
      OFICINAS ofi;

      fp=fopen("arquivos\\oficinas.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\tempOfi.txt","ab");//abre arquivos temporarios no modo de acesso
      listaOficinas();
      puts("\n\nInsira o CODIGO da oficina que deseja alterar");
        scanf("%d",&codigo);

      while(fread(&ofi,sizeof(OFICINAS),1,fp)){//le arquivo principal
        if(ofi.cod==codigo){//se a matricula for a que eu quero editar
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
                  strcpy(ofi.Tema,novoTema);
                  break;
                }
                case 2:{
                  listarPalestrantes2(ofi.cod);//lista palestrantes disponiveis
                  puts("Insira novo ID de palestrante");
                  scanf("%d",&ID);
                  //SUBSTITUIR PALESTRANTE
                  trocaPalestrante(ofi.cod,ofi.Palestrante,ID);
                  
                  //substituir o ID do palestrante na palestra
                  ofi.Palestrante=ID;
                  break;
                }
                case 3:{//aterar local
                  puts("!Alterar local ainda não está disponivel!");
                  break;
                }
                case 4:{//aterar horario
                  puts("!Alterar horario ainda n está disponivel!");
                  break;
                }
                default:puts("Opção inválida");break;
          }
        fwrite(&ofi,sizeof(OFICINAS),1,fp_aux);//depois de editar escreve no arqivo novo
        }else{
          fwrite(&ofi,sizeof(OFICINAS),1,fp_aux);//as que eu não quero alterar são escritas no novo arquivo
        }
      }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\oficinas.txt");//remove o original
    rename("arquivos\\tempOfi.txt","arquivos\\oficinas.txt");//renomeia o aux com nome do orinial
    //fim
}

//REMOVER OFICINAS
void removerOficinas(){
  puts("\nRemover oficina");
       int codigo;//pegar codigo
      int i;
      puts("Insira o codigo da oficina que deseja remover");
        scanf("%d",&codigo);

      FILE *fp=NULL;
      FILE *fp_aux=NULL;//arquivo auxiliar
      OFICINAS ofi;

      fp=fopen("arquivos\\oficinas.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\tempOfi.txt","ab");//abre arquivos temporarios no modo de acesso

      
      //remover a oficina
      while(fread(&ofi,sizeof(OFICINAS),1,fp)){//le arquivo principal
        if(ofi.cod!=codigo){//
          fwrite(&ofi,sizeof(OFICINAS),1,fp_aux);
        }else{
            //remover o cod da palestra dos arquivos dos palestrantes
            decrementarPale(ofi.cod,ofi.Palestrante);
            //remover o cod da palestra dos arquivos dos alunos
            for(i=0;i<ofi.numCadastrados;i++){
            decrementarAluno(codigo,ofi.cadastrados[i][0]);
            }
        }
      }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\oficinas.txt");//remove o original
    rename("arquivos\\tempOfi.txt","arquivos\\oficinas.txt");//renomeia o aux com nome do orinial
    //fim
}

//LISTAR ALUNOS DAS OFICINAS
void listaAlunosdaOficina(){
  puts("\nListar alunos da oficina");
  int codigo;//codigo da oficina
  int i;
   puts("Insira o codigo da oficina");
        scanf("%d",&codigo);

  FILE *fp=NULL;
  OFICINAS ofi;

  fp=fopen("arquivos\\oficinas.txt","rb");//abre arquivos principais no modo de leitura

  while(fread(&ofi,sizeof(OFICINAS),1,fp)){//le arquivo principal
    if(ofi.cod==codigo){
      for(i=0;i<ofi.numCadastrados;i++){
        listarAlunosdeEventos(ofi.cod,ofi.cadastrados[i][0]);//envia o ID do array de acordo que o for passar por ele
      }
    }
  }

   fclose(fp);//fecha arquivo principal
   //fim
}
//**************************************************************************************************

//GRUPOS DE DISCUSSÃO******************************************************************************
//CRIAR GRUPO
void criaGrupo(){
  int i,j,qntd;
    //cria arquivo
    FILE *fp;
    GRUPO_DE_DISCUSSOES grup;
    //teste de entrada de arquivo
    if ((fp = fopen("arquivos\\grupos.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

    //zerar cadastrados
    for(i=0;i<50;i++){
        for(j=0;j<5;j++){
          grup.cadastrados[i][j]=0;
        }
      }
      //zera numero de cadastrados
      grup.numCadastrados=0;
      //zera num de palestrnates
      grup.numPalestrante=0;

    //cria cod
      //verifica cod
      srand(time(NULL));
      grup.cod = 200+(rand()% 99);//gerar num entre 200 e 299
      printf("Código: %d\n",grup.cod);
    
    //Insere tema
      puts("Insira o Tema da discussão");
      setbuf(stdin, NULL);
      fgets(grup.Tema,TAM,stdin);
      strtok(grup.Tema,"\n");
    // lista palestrantes
      puts("Lista de palestrantes");
      listarPalestrantes2(grup.cod);//
      putchar('\n');
      printf("Quantos palestrantes deseja adicionar no grupo?(MAX 5)>>");
      scanf("%d",&qntd);
      if(qntd>numPalestrantes()){
        puts("Numero desejado de palestrantes é maior que o numero de palestrantes disponiveis\nO numero de palestrantes cadastrados será o mesmo dos palestrantes disponiveis");
        listarPalestrantes();
        for(i=0;i<=numPalestrantes();i++){
          printf("\nInsira o ID do palestrante desejado>>");
          //insere palestrantes
          //escolhe palestrantes da lista baseado no id
          scanf("%d",&grup.Membros_da_mesa[grup.numPalestrante][0]);
          //verifica se o ID escolhido corresponde ao palestrante existente!!
          //abre arquivo de palestrante para incrementar o num de palestrar e colocar o COD da palestras no array
          incrementarPale(grup.cod, grup.Membros_da_mesa[grup.numPalestrante][0]);
          grup.numPalestrante++;
        }
      }else{
        for(i=0;i<=qntd;i++){
          printf("\nInsira o ID do palestrante desejado>>");
          //insere palestrantes
          //escolhe palestrantes da lista baseado no id
          scanf("%d",&grup.Membros_da_mesa[grup.numPalestrante][0]);
          //verifica se o ID escolhido corresponde ao palestrante existente!!
          //abre arquivo de palestrante para incrementar o num de palestrar e colocar o COD da palestras no array
          incrementarPale(grup.cod, grup.Membros_da_mesa[grup.numPalestrante][0]);
          grup.numPalestrante++;
        }
      }
      
      
    //função para colocar local/hora/capacidade/cargahoraria
    puts("FUNÇÃO DE LOCAL TA FALTANDO");
    
      puts("Cadastro de oficina concluido");

    //escreve tudo no arquivo
      fwrite(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fp);
    //fecha o arquivo
      fclose(fp);
    //fim
}


void listaGrupos(){
  puts("\nLista de grupos");
  int i;
  FILE *fp;
      GRUPO_DE_DISCUSSOES grup;
      fp = fopen("arquivos\\grupos.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&grup, sizeof(OFICINAS), 1,fp)){//enquanto leitura for verdadeira
        printf("CODIGO: %d\nTEMA: %s\n",grup.cod,grup.Tema);
        for(i=0;i<grup.numPalestrante;i++){
          mostraPalestrante(grup.Membros_da_mesa[i][0]);//pega o id do palestrante para exibir nome
          putchar('\n');
        }
        //LISTAR HORÁRIO E LOCAL
        puts("LISTAR LOCAL E HR TA FALTANDO");
      }
      fclose(fp);
      //fim
}








//ADD PALESTRANTE AO GRUPO DE DISCUSSÃO
void addPalestranteaGrupo(){
    //cria arquivo
    FILE *fp;
    GRUPO_DE_DISCUSSOES grup;
    //teste de entrada de arquivo
    if ((fp = fopen("arquivos\\grupos.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

    while (fread(&grup, sizeof(OFICINAS), 1,fp)){
      
    }

}

//************************************************************************************************


//FUNÇÕES DE LOCAIS***************************************************************
//ESCOLHE LOCAL(cod do evnto)
void escolheLocal(int cod){
  printf("\n\nEntra em escolher local\n\n");
      int i;//contador
      
      int nLocal,nHora,nDia;
    //abre arquivos de locais
      FILE *fp;
      FILE *fp2;
      SLOCAL loca;//varial de local
        fp = fopen("arquivos\\locais.txt", "rb");
        fp2 = fopen("arquivos\\tempLocais.txt", "ab");
        
      //if tipo de  cod de evento
        //FUNÇÃO DE INCREMENTAR LOCAL NO EVENTO(coloca o cod do local)

          //if cod de evento
          //abre local COMPATIVEL com evento 
          //if(cod entre 100 200 exibe locais com capacidade pra ate 150)

          if(cod>=100 && cod<200){//cod de palestra
             //i=1;
            puts("\nEscolha o local da sua Palestra\n");
            puts("Locais disponíveis:");

            listaLocais(150);//função paralistar locais com capacidade de ate 150 

              printf("Insira o número do Local desejado>> ");
              scanf("%d",&nLocal);
              while (fread(&loca, sizeof(SLOCAL), 1,fp)){
                if(loca.lugar==nLocal){
                  printf("\n1-Primeiro dia\t2-Segundo dia\n");
                  printf("Deseja incluir o evento em qual dia?>> ");
                  scanf("%d",&nDia);

                  puts("\nHorários disponiveis:");
                  listaHorarios(nDia,cod,nLocal);
                  printf("\nInsira o digito do horário que deseja adicionar o evento (EX:1 para primeiro horário)\n>> ");
                  scanf("%d",&nHora);

                  loca.horario[nDia-1][nHora]=0;//torna horario indisponivel
                  printf("\nDia %d\tHora: %d\tFica %d \n",nDia,nHora,loca.horario[nDia-1][nHora]);
                  loca.Eventos[nDia-1][nHora][0]=cod;//add cod de evento da matriz

                  fwrite(&loca,sizeof(SLOCAL),1,fp2);
                }else{
                  fwrite(&loca,sizeof(SLOCAL),1,fp2);
                }
            }
          }

          //=============================================================================
          if(cod>=200 && cod<300){//cod de GRUPO_DE_DISCUSSOES
            puts("\nEscolha o local do seu Grupo de discussão\n");
            puts("Locais disponíveis:");
            listaLocais(150);//função paralistar locais com capacidade de ate 150 
            
              printf("Insira o número do Local desejado>> ");
              scanf("%d",&nLocal);
              while (fread(&loca, sizeof(SLOCAL), 1,fp)){
                if(loca.lugar==nLocal){
                  printf("\n1-Primeiro dia\t2-Segundo dia\n");
                  printf("Deseja incluir o evento em qual dia?>> ");
                  scanf("%d",&nDia);

                  puts("\nHorários disponiveis:");
                  listaHorarios(nDia,cod,nLocal);
                  printf("\nInsira o digito do horário que deseja adicionar o evento (EX:1 para primeiro horário)\n>> ");
                  scanf("%d",&nHora);

                  loca.horario[nDia-1][nHora]=0;//torna horario indisponivel
                  printf("\nDia %d\tHora: %d\tFica %d \n",nDia,nHora,loca.horario[nDia-1][nHora]);
                  loca.Eventos[nDia-1][nHora][0]=cod;//add cod de evento da matriz

                  fwrite(&loca,sizeof(SLOCAL),1,fp2);
                }else{
                  fwrite(&loca,sizeof(SLOCAL),1,fp2);
                }
            }
          }

          //==================================================================================
          if(cod>=300 && cod<400){//cod de curso
            puts("\nEscolha o local do seu curso\n");
            puts("Locais disponíveis:");
            //while (fread(&loca, sizeof(SLOCAL), 1,fp)){//enquanto leitura for verdadeira
              for(i=1;i<=8;i++){
                  if(loca.lugar==i && loca.capacidade<40){//capacidade de 150 pq é palestra
                      if(i==1){
                        printf("%d-Auditório 1\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==2){
                        printf("%d-Auditório 2\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==3){
                        printf("%d-Auditório 3\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==4){
                        printf("%d-Sala 1\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==5){
                        printf("%d-Sala 2\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==6){
                        printf("%d-Sala 3\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==7){
                        printf("%d-Laboratório 1\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==8){
                        printf("%d-Laboratório 2\n",i);
                        disponiveis[i-1]=1;
                      }
                  }
              }
              printf("Insira o número do Local desejado>> ");
              scanf("%d",&nLocal);
              
              printf("1-Primeiro dia\t2-Segundo dia");
              printf("Deseja incluir o evento em qual dia?>> ");
              scanf("%d",&nDia);

              puts("\nHorários disponiveis:");
              for(i=1;i<=6;i++){
                if((loca.horario[nDia-1][i])!=0){//lista só os horarios disponiveis
                  if(i==1){
                    puts("1- Primeiro horário (Das 7h às 9h)");
                  }
                  if(i==2){
                    puts("2- Segundo horário (Das 9h às 11h) ");
                  }
                  if(i==3){
                    puts("3- Terceiro horário horário (Das 11h às 13h) ");
                  }
                  if(i==4){
                    puts("4- Quarto horário (Das 13h às 15h) ");
                  }
                  if(i==5){
                    puts("5- Quinto horário (Das 15h às 17h) ");
                  }
                  if(i==6){
                    puts("6- Sexto horário (Das 17h às 19h) ");
                  }
                }
              }
            printf("Insira o digito do horário que deseja adicionar o evento (EX:1 para primeiro horário)\n>> ");
            scanf("%d",&nHora);

              loca.horario[nDia-1][nHora]=0;//torna horario indisponivel
              loca.Eventos[nDia-1][nHora][0]=cod;//add cod de evento da matriz

           // }  
          }


          //===================================================================================
          if(cod>=400 && cod<500){//cod de oficina
            puts("\nEscolha o local da sua oficina\n");
            puts("Locais disponíveis:");
            //while (fread(&loca, sizeof(SLOCAL), 1,fp)){//enquanto leitura for verdadeira
              for(i=1;i<=8;i++){
                  if(loca.lugar==i && loca.capacidade==20){//capacidade d
                      if(i==1){
                        printf("%d-Auditório 1\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==2){
                        printf("%d-Auditório 2\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==3){
                        printf("%d-Auditório 3\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==4){
                        printf("%d-Sala 1\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==5){
                        printf("%d-Sala 2\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==6){
                        printf("%d-Sala 3\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==7){
                        printf("%d-Laboratório 1\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==8){
                        printf("%d-Laboratório 2\n",i);
                        disponiveis[i-1]=1;
                      }
                  }
              }
              printf("Insira o número do Local desejado>> ");
              scanf("%d",&nLocal);
              
              printf("1-Primeiro dia\t2-Segundo dia");
              printf("Deseja incluir o evento em qual dia?>> ");
              scanf("%d",&nDia);

              puts("\nHorários disponiveis:");
              for(i=1;i<=6;i++){
                if((loca.horario[nDia-1][i])!=0){//lista só os horarios disponiveis
                  if(i==1){
                    puts("1- Primeiro horário (Das 7h às 9h)");
                  }
                  if(i==2){
                    puts("2- Segundo horário (Das 9h às 11h) ");
                  }
                  if(i==3){
                    puts("3- Terceiro horário horário (Das 11h às 13h) ");
                  }
                  if(i==4){
                    puts("4- Quarto horário (Das 13h às 15h) ");
                  }
                  if(i==5){
                    puts("5- Quinto horário (Das 15h às 17h) ");
                  }
                  if(i==6){
                    puts("6- Sexto horário (Das 17h às 19h) ");
                  }
                }
              }
            printf("Insira o digito do horário que deseja adicionar o evento (EX:1 para primeiro horário)\n>> ");
            scanf("%d",&nHora);

              loca.horario[nDia-1][nHora]=0;//torna horario indisponivel
              loca.Eventos[nDia-1][nHora][0]=cod;//add cod de evento da matriz

            //}  
          }

          //escolhe o local
            //switch dia 14 ou 15
            //de acordo com o local,pega a capacidade do local e coloca na capacidade do evento 
              //função para imprimir só os horarios disponiveis//recebe os
                //switch para pegar os horarios
                  //insira o horario inicial do evento EX: 07 
                    //loca.horario[dia][horario]=0//indisponivel
                    //loca.Eventos[dia][horario]=cod do evento
  //}
  printf("\n\nsai de  escolher local\n\n");
    fwrite(&loca,sizeof(SLOCAL),1,fp);
    fclose(fp);
}
//LISTAR OS HORARIOS(int dia, int cod, int lugar)//recebe o dia, cod do evento, e o local escolhido
  //abre arquivos de locais
    //abre cod de locais
    //if cod de local {aparece determinados horarios compativeis}
    //while cods de locais
      //abre o array de horarios
        //lista os horarios diferentes de zero
        

//ALTERAR HORARIO

//LISTAR O HORARIO DO EVENTO
void listaHorariodoEvento(int cod){
  int i,j;
  FILE *fp;
    SLOCAL loca;//varial de local
    //teste de entrada de arquivo
    if ((fp = fopen("arquivos\\locais.txt", "rb")) == NULL){//modo de leitura
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

    while (fread(&loca, sizeof(SLOCAL), 1,fp)){//enquanto leitura for verdadeira
      for(j=0;j<2;j++){
        for(i=1;i<=6;i++){
          if(loca.Eventos[j][i][0]==cod){
            printf("Dia %d\n",j+1);
            switch(i){
              case 1:puts("Primeiro horário (Das 7h às 9h)"); break;
              case 2:puts("Segundo horário (Das 9h às 11h)"); break;
              case 3:puts("Terceiro horário (Das 11h às 13h)"); break;
              case 4:puts("Quarto horário (Das 13h às 15h)"); break;
              case 5:puts("Quinto horário (Das 15h às 17h)"); break;
              case 6:puts("Sexto horário (Das 17h às 19h)"); break;
            }
          }
        }
      }
    }
    fclose(fp);
}

void testeEscolheLocal(int cod){
  int disponiveis[8];
  printf("\n\nEntra em teste escolher local\n\n");
  int nLocal,nHora,nDia,i;

    FILE *fp;
    FILE *fp2;
    SLOCAL loca;//varial de local

    fp = fopen("arquivos\\locais.txt", "rb");
    fp2 = fopen("arquivos\\tempLocais.txt", "ab");

    //while (fread(&loca, sizeof(SLOCAL), 1,fp)){//enquanto leitura for verdadeira
          if(cod>=100 && cod<200){//cod de palestra
            //i=1;
            puts("\nEscolha o local da sua Palestra\n");
            puts("Locais disponíveis:");
            listaLocais(150);//função paralistar locais com capacidade de ate 150 
              printf("Insira o número do Local desejado>> ");
              scanf("%d",&nLocal);
              while (fread(&loca, sizeof(SLOCAL), 1,fp)){
                if(loca.lugar==nLocal){
                  printf("\n1-Primeiro dia\t2-Segundo dia\n");
                  printf("Deseja incluir o evento em qual dia?>> ");
                  scanf("%d",&nDia);

                  puts("\nHorários disponiveis:");
                  listaHorarios(nDia,cod,nLocal);
                  printf("\nInsira o digito do horário que deseja adicionar o evento (EX:1 para primeiro horário)\n>> ");
                  scanf("%d",&nHora);

                  loca.horario[nDia-1][nHora]=0;//torna horario indisponivel
                  printf("\nDia %d\tHora: %d\tFica %d \n",nDia,nHora,loca.horario[nDia-1][nHora]);
                  loca.Eventos[nDia-1][nHora][0]=cod;//add cod de evento da matriz

                  fwrite(&loca,sizeof(SLOCAL),1,fp2);
              }else{
                  fwrite(&loca,sizeof(SLOCAL),1,fp2);
          }
            }//fim do w  
          }


//ss
    //fwrite(&loca,sizeof(SLOCAL),1,fp2);
    fclose(fp);
    fclose(fp2);
    remove("arquivos\\locais.txt");//remove o original
    rename("arquivos\\tempLocais.txt","arquivos\\locais.txt");

}

void listaLocais(int capacidade){
  FILE *fpp;
  SLOCAL loca;//varial de local
  fpp = fopen("arquivos\\locais.txt", "rb");//


int disponiveis[8],i;
  while (fread(&loca, sizeof(SLOCAL), 1,fpp)){//enquanto leitura for verdadeira
              puts("ENTRA EM WHILE DE ESCOLHEWR LOCAL");
              for(i=1;i<=8;i++){
                  if(loca.lugar==i && loca.capacidade==capacidade){//capacidade de 150 pq é palestra
                      if(i==1){
                        printf("%d-Auditório 1\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==2){
                        printf("%d-Auditório 2\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==3){
                        printf("%d-Auditório 3\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==4){
                        printf("%d-Sala 1\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==5){
                        printf("%d-Sala 2\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==6){
                        printf("%d-Sala 3\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==7){
                        printf("%d-Laboratório 1\n",i);
                        disponiveis[i-1]=1;
                      }
                      if(i==8){
                        printf("%d-Laboratório 2\n",i);
                        disponiveis[i-1]=1;
                      }
                  }
              }

  }
    fclose(fpp);
}

void listaHorarios(int dia, int cod,int local){

  FILE *fpp;
  SLOCAL loca;//varial de local
  fpp = fopen("arquivos\\locais.txt", "rb");//
  int i;
      if(cod>=100 && cod<200){
        while (fread(&loca, sizeof(SLOCAL), 1,fpp)){//enquanto leitura for verdadeira
          if(loca.lugar==local){
            for(i=1;i<=3;i++){//palestras só podem pela manha
                if((loca.horario[dia-1][i])!=0){//lista só os horarios disponiveis
                  if(i==1){
                    puts("1- Primeiro horário (Das 7h às 9h)");
                  }
                  if(i==2){
                    puts("2- Segundo horário (Das 9h às 11h) ");
                  }
                  if(i==3){
                    puts("3- Terceiro horário horário (Das 11h às 13h) ");
                  }
                  
                }
            }
          }
        }
      }else{
        while (fread(&loca, sizeof(SLOCAL), 1,fpp)){//enquanto leitura for verdadeira
          if(loca.lugar==local){
            for(i=1;i<=6;i++){
                if((loca.horario[dia-1][i])!=0){//lista só os horarios disponiveis
                  if(i==1){
                    puts("1- Primeiro horário (Das 7h às 9h)");
                  }
                  if(i==2){
                    puts("2- Segundo horário (Das 9h às 11h) ");
                  }
                  if(i==3){
                    puts("3- Terceiro horário horário (Das 11h às 13h) ");
                  }
                  if(i==4){
                    puts("4- Quarto horário (Das 13h às 15h) ");
                  }
                  if(i==5){
                    puts("5- Quinto horário (Das 15h às 17h) ");
                  }
                  if(i==6){
                    puts("6- Sexto horário (Das 17h às 19h) ");
                  }
                }
              }
          }
        }
      }
  

  fclose(fpp);
}