

#include "funcions.h"


void mostra(){
  puts("\n============ENIC===========\n");
  
}


//FUNÇÃO PARA LISTAR EVENTOS
void listarEventos(int cod){

  if(cod>=100 && cod<200){//cod de palestra
      puts("\n\tPalestra----------");
      FILE *fp;
      PALESTRAS pale;
      fp = fopen("arquivos\\palestras.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&pale, sizeof(PALESTRAS), 1,fp)){//enquanto leitura for verdadeira
        if(cod==pale.cod){
          printf("CODIGO: %d\nTEMA: %s\n",pale.cod,pale.tema);
          mostraPalestrante(pale.palestrante);
          //LISTAR HORÁRIO E LOCAL
          listaHorariodoEvento(pale.cod);
          puts("\n----------------------------\n");
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
        listaHorariodoEvento(ofi.cod);
        puts("\n----------------------------\n");
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
          listaHorariodoEvento(curse.cod);
          puts("\n----------------------------\n");
        }
      }
      fclose(fp);
      //fim
  }
  if(cod>=200 && cod<300){//cod de GRUPO_DE_DISCUSSOES
      int i;
      FILE *fp;
      GRUPO_DE_DISCUSSOES grup;
      fp = fopen("arquivos\\grupos.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&grup, sizeof(GRUPO_DE_DISCUSSOES), 1,fp)){//enquanto leitura for verdadeira
        if(cod==grup.cod){
          printf("CODIGO: %d\nTEMA: %s\n",grup.cod,grup.Tema);
        for(i=0;i<grup.numPalestrante;i++){
          mostraPalestrante(grup.Membros_da_mesa[i][0]);//pega o id do palestrante para exibir nome
        }  
          //LISTAR HORÁRIO E LOCAL
          listaHorariodoEvento(grup.cod);
          puts("\n----------------------------\n");
        }
      }
      fclose(fp);
      //fim
    
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
        if((pale.numCadastrados+1)<150){//numero max de alunos 
          pale.cadastrados[pale.numCadastrados][0]=mat;//add matricula do aluno no array de cadastradas
          pale.numCadastrados++;//incrementa num de cadastradas
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
        int i;
        FILE *fpp;
        FILE *fpp2;
        GRUPO_DE_DISCUSSOES grup;

    fpp = fopen("arquivos\\grupos.txt", "rb");//abre arquivo no modo de leitura
    fpp2 = fopen("arquivos\\tempGrup.txt", "ab");//abre arquivo no modo de acesso

    while (fread(&grup, sizeof(GRUPO_DE_DISCUSSOES), 1,fpp)){
      if(cod==grup.cod){
        //num de cadastradas não pode ser maior que a capacidade
        if((grup.numCadastrados+1)<50){//numero max de alunos 
          grup.cadastrados[grup.numCadastrados][0]=mat;//add matricula do aluno no array de cadastradas
          grup.numCadastrados++;//incrementa num de cadastradas
        }else{
          puts("Numero de cadastrados atingiu o max disponivel");
        }
        fwrite(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fpp2);
      }else{
        fwrite(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fpp2);
      }
    }
    fclose(fpp);
    fclose(fpp2);
    remove("arquivos\\grupos.txt");//remove o original
    rename("arquivos\\tempGrup.txt","arquivos\\grupos.txt");//renomeia o aux com nome do original
    //fim
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
       if((curse.numCadastrados+1)<40){//numero max de alunos   
        curse.numCadastrados++;//incrementa num de cadastradas
        curse.cadastrados[curse.numCadastrados][0]=mat;//add matricula do aluno no array de cadastradas
        fwrite(&curse,sizeof(CURSO),1,fpp2);
       }else{
          puts("Numero de cadastrados atingiu o max disponivel");
       }
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
       if((ofi.numCadastrados+1)<50){//numero max de alunos   
        ofi.numCadastrados++;//incrementa num de cadastradas
        ofi.cadastrados[ofi.numCadastrados][0]=mat;//add matricula do aluno no array de cadastradas
        fwrite(&ofi,sizeof(OFICINAS),1,fpp2);
        }else{
          puts("Numero de cadastrados atingiu o max disponivel");
       }
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
   int i;
    FILE *fpp;
    FILE *fpp2;
    GRUPO_DE_DISCUSSOES grup;

    fpp = fopen("arquivos\\grupos.txt", "rb");//abre arquivo no modo de leitura
    fpp2 = fopen("arquivos\\tempGrup.txt", "ab");//abre arquivo no modo de acesso

    while (fread(&grup, sizeof(GRUPO_DE_DISCUSSOES), 1,fpp)){
      if(cod==grup.cod){
        //num de cadastradas não pode ser maior que a capacidade
        for(i=0;i<grup.numCadastrados;i++){
          if(grup.cadastrados[i][0]==mat){
            grup.cadastrados[i][0]=0;//add matricula do aluno no array de cadastradas
          }
        }
        grup.numCadastrados--;//decrementa num de cadastradas
        fwrite(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fpp2);
      }else{
        fwrite(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fpp2);
      }
    }
    fclose(fpp);
    fclose(fpp2);
    remove("arquivos\\grupos.txt");//remove o original
    rename("arquivos\\tempGrup.txt","arquivos\\grupos.txt");//renomeia o aux com nome do original
    //fim
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
  if ((fp = fopen("arquivos\\alunos.txt", "rb"))==NULL){
      return 1;
  }
  while(fread(&aluno,sizeof(CONGRE),1,fp)){
    cont++;
  }
  return cont;
}
//contador de palestrantes 
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

//====================================================================

//FUNÇÕES DOS ORGANIZADORES--------------------------------------
//CRIAR ORGANIZADORES
void criaOrganizador(){
  
  printf("\nCADASTRO DE ORGANIZADORES\n");
    //abre arquivo e verifica
    FILE *fp;
    ORGANIZADORES org;//
    //teste de entrada de arquivo
    if ((fp = fopen("arquivos\\organizadores.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }

    //ID
      srand(time(NULL));
      org.ID = 700+(rand()% 99);//gerar num entre 700 e 799
      printf("\nID: %d\n",org.ID);
    //nome
      puts("Insira o nome do Organizador");
      setbuf(stdin, NULL);
      fgets(org.nome,TAM,stdin);
      strtok(org.nome,"\n");
    //cpf ou curso
      puts("Insira seu CPF");
      scanf("%d",&org.cpf);

    puts("Cadastro concluído");

    fwrite(&org,sizeof(ORGANIZADORES),1,fp);
    fclose(fp);
}

//EDITAR ORGANIZADORES
void editaOrganizador(){
  
  printf("\nALTERAR ORGANIZADORES\n");
    int id,op2;
    char novoNome[TAM];
    
    FILE *fp;
    FILE *fp2;
    ORGANIZADORES org;//
    
    fp = fopen("arquivos\\organizadores.txt", "rb");
    fp2 = fopen("arquivos\\tempOrg.txt", "ab");

    listaOrganizador();
    putchar('\n');
    printf("Insira o ID do organizador que deseja alterar>>");
    scanf("%d",&id);

    while(fread(&org,sizeof(ORGANIZADORES),1,fp)){
        if(org.ID==id){
            puts("1-Nome\t2-CPF\t3-NENHUM");
            printf("Qual dado deseja alterar?>> ");
            scanf("%d",&op2);
            switch(op2){
              case 1:{
                puts("Insira novo nome");
                  setbuf(stdin,NULL);
                  fgets(novoNome,TAM,stdin);
                  strtok(novoNome,"\n");
                  strcpy(org.nome,novoNome);
                break;
              }
              case 2:{
                puts("Insira novo CPF");
                scanf("%d",&org.cpf);
                break;
              }
              case 3:break;
              default:break;
            }
            fwrite(&org,sizeof(ORGANIZADORES),1,fp2);
        }else{
          fwrite(&org,sizeof(ORGANIZADORES),1,fp2);
        }
    }
    fclose(fp);
    fclose(fp2);
    remove("arquivos\\organizadores.txt");
    rename("arquivos\\tempOrg.txt", "arquivos\\organizadores.txt");

}
//LISTAR ORGANIZADORES
void listaOrganizador(){
  puts("\n===Lista de Organizadores===\n");
  FILE *fp;
    ORGANIZADORES org;
    fp = fopen("arquivos\\organizadores.txt", "rb");
    while(fread(&org,sizeof(ORGANIZADORES),1,fp)){
      printf("-------------------------------------------\n");
      printf(" ID: %d\nNome: %s\nCPF: %d\n",org.ID,org.nome,org.cpf);
      printf("-------------------------------------------\n");
    }
    fclose(fp);
}

//REMOVER ORGANIZADORES
void removeOrganizador(){
  int id;
  
  puts("\nREMOVER ORGANIZADOR\n");
  //abre arquivo e verifica
    FILE *fp;
    FILE *fp2;
    ORGANIZADORES org;//
    
    fp = fopen("arquivos\\organizadores.txt", "rb");
    fp2 = fopen("arquivos\\tempOrg.txt", "ab");
    
    listaOrganizador();
    putchar('\n');
    printf("Insira o ID do organizador que deseja remover>>");
    scanf("%d",&id);

    while(fread(&org,sizeof(ORGANIZADORES),1,fp)){
        if(org.ID!=id){
          fwrite(&org,sizeof(ORGANIZADORES),1,fp2);
        }else{
          printf("Removendo...\n");
        }
    }


    fclose(fp);
    fclose(fp2);
    remove("arquivos\\organizadores.txt");
    rename("arquivos\\tempOrg.txt", "arquivos\\organizadores.txt");

}


//==================================================================
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
  puts("\nLista de palestrantes\n");
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
    int i;
  
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
          /*for(i=0;i<profs.numEventos;i++){
            if(profs.eventos[i][0]!=cod){//listar palestrantes que não estão no grupo
              printf("\nID:%d\nNome: %s\n",profs.ID, profs.nome);
            }
          }*/
        }
      }
      fclose(fpp);
    //fim
}
//LISTAR EVENTOS DO PALESTRANTE 
void listaEventosdoPalestrante(){
 
  puts("\nLista de Eventos de um palestrante\n");
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
  
 
  int i;
  FILE *fpp;
  FILE *fpp2;
      PROFS profs;
      fpp = fopen("arquivos\\palestrantes.txt", "rb");//abre arquivo no modo de LEITURA
      fpp2 = fopen("arquivos\\tempProfI.txt","ab");
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
          fwrite(&profs,sizeof(PROFS),1,fpp2);
        }else{
          fwrite(&profs,sizeof(PROFS),1,fpp2);
        }
      }
      
      
      fclose(fpp);
      fclose(fpp2);
      
      remove("arquivos\\palestrantes.txt");//remove o original
      rename("arquivos\\tempProfI.txt","arquivos\\palestrantes.txt");//renomeia o aux com nome do orinial
    //fim 
    
    //fim
}
//DECREMENTAR PALESTRANTES
void decrementarPale(int cod,int ID){
 
      
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
            
          }
          if(cod>=300 && cod<400){//se for curso
            aluno.nCursos=1;
           
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
           
          }
          if(cod>=300 && cod<400){//se for curso
            aluno.nCursos=0;
           
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
      listaGrupos();
      putchar('\n');
      printf("\nInsira o codigo do grupo desejado>>");
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
    case 3:{//Curso
      
      
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
    puts("LOCAL:");
    //ESCOLHE LOCAL(COD DO EVENTO)
      escolheLocal(pale.cod);
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
           puts("1-Tema\t2-Palestrante\t3-Local e Horário");
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
                  puts("Alterar local e horario\n");
                  alteraHorario(pale.cod);
                  puts("\nDados alterados");
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
      for(i=0;i<1;i++){
        //codigos=pale.cadastrados
        //printf("%d NUM DE CADASTRADOS\n",pale.numCadastrados);
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
      escolheLocal(curse.cod);
    
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
        listaHorariodoEvento(curse.cod);
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
    escolheLocal(ofi.cod);
    
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
        listaHorariodoEvento(ofi.cod);
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
  int i,j,qntd,id;
  printf("\n\n------------------------------------------\n\n");
    //cria arquivo
    FILE *fp;
    FILE *fpp;
    GRUPO_DE_DISCUSSOES grup;
    //teste de entrada de arquivo
    
    fp = fopen("arquivos\\grupos.txt", "ab");
    

  
    //zerar cadastrados
    for(i=0;i<50;i++){
        for(j=0;j<5;j++){
          grup.cadastrados[i][j]=0;
        }
      }

      //zerar palestrantes
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
          grup.Membros_da_mesa[i][j]=0;
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
      //puts("\nLista de palestrantes\n");
      //listarPalestrantes2(grup.cod);//
      putchar('\n');
      printf("Quantos palestrantes deseja adicionar no grupo?(MAX 5)>> ");
      scanf("%d",&qntd);
      if(qntd>numPalestrantes()){
        puts("Numero desejado de palestrantes é maior que o numero de palestrantes disponiveis\nO numero de palestrantes cadastrados será o mesmo dos palestrantes disponiveis");
        listarPalestrantes();
        for(i=0;i<numPalestrantes();i++){
          printf("\nInsira o ID do palestrante desejado>>");
          //insere palestrantes
          //escolhe palestrantes da lista baseado no id
          scanf("%d",&id);
          grup.Membros_da_mesa[grup.numPalestrante][0]=id;
          //verifica se o ID escolhido corresponde ao palestrante existente!!
          //abre arquivo de palestrante para incrementar o num de palestrar e colocar o COD da palestras no array
          incrementarPale(grup.cod, grup.Membros_da_mesa[grup.numPalestrante][0]);
          grup.numPalestrante++;
        }
      }else{
        for(i=0;i<qntd;i++){
          listarPalestrantes();
          printf("\nInsira o ID do palestrante desejado>>");
          //insere palestrantes
          //escolhe palestrantes da lista baseado no id
          scanf("%d",&id);
          grup.Membros_da_mesa[grup.numPalestrante][0]=id;
          //verifica se o ID escolhido corresponde ao palestrante existente!!
          //abre arquivo de palestrante para incrementar o num de palestrar e colocar o COD da palestras no array
          incrementarPale(grup.cod, grup.Membros_da_mesa[grup.numPalestrante][0]);
          grup.numPalestrante++;
        }
      }
/*
printf("\n\n------------------------------------------\n\n");
printf("id:%d\n",id);
printf("ID 1 %d e ID 2 %d\n",grup.Membros_da_mesa[grup.numPalestrante][0],grup.Membros_da_mesa[grup.numPalestrante-1][0]);
printf("TEMA %s\n",grup.Tema);
printf("CODIGO %d\n",grup.cod);
printf("\n\n------------------------------------------\n\n");
      */
      
    //função para colocar local/hora/capacidade/cargahoraria
      escolheLocal(grup.cod);
    
      puts("Cadastro de GRUPO concluido");

    //escreve tudo no arquivo
      fwrite(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fp);
    //fecha o arquivo
      fclose(fp);
     // fclose(fpp);
     // remove("arquivos\\grupos.txt");
     // rename("arquivos\\grupos2.txt","arquivos\\grupos.txt");
    //fim
}

//LISTAR TODOS OS GRUPOS
void listaGrupos(){
  
  puts("\nLista de grupos");
  int i;
  FILE *fpp;
      GRUPO_DE_DISCUSSOES grup;
      fpp = fopen("arquivos\\grupos.txt", "rb");//abre arquivo no modo de leitura
      while (fread(&grup, sizeof(GRUPO_DE_DISCUSSOES), 1,fpp)){//enquanto leitura for verdadeira
        printf("CODIGO: %d\nTEMA: %s\n",grup.cod,grup.Tema);
        for(i=0;i<grup.numPalestrante;i++){
          mostraPalestrante(grup.Membros_da_mesa[i][0]);//pega o id do palestrante para exibir nome
          putchar('\n');
        }
        //LISTAR HORÁRIO E LOCAL
        listaHorariodoEvento(grup.cod);
      }
      fclose(fpp);
      //fim
}

//ALTERAR GRUPO
void editaGrupo(){
      int codigo,op2,op3,IDvelho,IDnovo,i;
      char novoTema[TAM];

      FILE *fp;
      FILE *fpp;
      GRUPO_DE_DISCUSSOES grup;
      fp = fopen("arquivos\\grupos.txt", "rb");//abre arquivo no modo de leitura
      fpp = fopen("arquivos\\tempGrupos.txt", "ab");//

      listaGrupos();
      puts("\n\nInsira o CODIGO do grupo que deseja alterar");
        scanf("%d",&codigo);

      while(fread(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fp)){//le arquivo principal
        if(grup.cod==codigo){//se a matricula for a que eu quero editar
           puts("1-Tema\t2-Palestrante\t3-Local\t4-Horário\t5-Sair");
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
                  strcpy(grup.Tema,novoTema);
                  break;
                }
                case 2:{
                  puts("\n1-Trocar palestrante\t2-Adicionar novo palestrante\t3-Remover Palestrante\t4-Sair");
                  printf("Escolha uma opção>> ");
                  scanf("%d",&op3);
                  switch(op3){
                    case 1:{
                      listaPalesdoGrupo(grup.cod);
                      putchar('\n');
                      printf("Insira o ID do palestrante que quer substituir>> ");
                      scanf("%d",&IDvelho);

                      listarPalestrantes2(grup.cod);
                      putchar('\n');
                      printf("Insira o ID do novo palestrante>> ");
                      scanf("%d",&IDnovo);

                      trocaPalestrante(grup.cod, IDvelho, IDnovo);//talvez dê problemas por estar alterando o grupo que está sendo alterado já

                      puts("Palestrante substituido");
                      break;
                    }
                    case 2:{
                      if((grup.numPalestrante+1)<=5){
                        listarPalestrantes2(grup.cod);
                        putchar('\n');
                        printf("Insira o ID do palestrante que quer adicionar>> ");
                        scanf("%d",&IDnovo);
                        incrementarPale(grup.cod, IDnovo);

                        grup.numPalestrante++;
                        grup.Membros_da_mesa[grup.numPalestrante][0]=IDnovo;
                        
                        break;
                      }else{
                        puts("Numero de palestrantes do grupo já atingiu o maximo disponível");
                        break;
                      }
                        
                    }
                    case 3:{
                      if((grup.numPalestrante-1)>0){
                        listaPalesdoGrupo(grup.cod);
                        putchar('\n');
                        printf("Insira o ID do palestrante que deseja remover>> ");
                        scanf("%d",&IDvelho);
                        decrementarPale(grup.cod, IDvelho);

                        for(i=0;i<grup.numPalestrante;i++){
                          if(grup.Membros_da_mesa[i][0]==IDvelho){
                              grup.Membros_da_mesa[i][0]=0;
                              grup.numPalestrante--;
                          }
                        }
                        puts("Palestrante removido");
                        break;
                      }else{
                        puts("É preciso haver ao menos um palestrante na mesa, insira um novo antes de remover o atual");
                        break;
                      }
                    }
                    case 4: break;
                    default: break;

                  }
                  break;
                }
                case 3:{
                  puts("\nAlterar o local e horario\n");
                  alteraHorario(grup.cod);
                  break;
                }
                
                case 4: break;

                default: break;
            }
            fwrite(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fpp);
        }else{
          fwrite(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fpp);
        }
      }


      fclose(fp);
      fclose(fpp);
      remove("arquivos\\grupos.txt");
      rename("arquivos\\tempGrupos.txt", "arquivos\\grupos.txt");
}

//REMOVER GRUPO
void removeGrupo(){
  puts("\nRemover Grupo\n");
      int codigo;//pegar codigo
      int i;

      listaGrupos();
      puts("Insira o codigo do grupo que deseja remover");
        scanf("%d",&codigo);

      FILE *fp=NULL;
      FILE *fp_aux=NULL;//arquivo auxiliar
      GRUPO_DE_DISCUSSOES grup;

      fp=fopen("arquivos\\grupos.txt","rb");//abre arquivos principais no modo de leitura
      fp_aux=fopen("arquivos\\tempGrupos.txt","ab");//abre arquivos temporarios no modo de acesso

      
      //remover a oficina
      while(fread(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fp)){//le arquivo principal
        if(grup.cod!=codigo){//
          fwrite(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fp_aux);
        }else{
            //remover o cod da palestra dos arquivos dos palestrantes
            for(i=0;i<grup.numPalestrante;i++){
              decrementarPale(grup.cod,grup.Membros_da_mesa[i][0]);
            }
            //remover o cod da palestra dos arquivos dos alunos
            for(i=0;i<grup.numCadastrados;i++){
              decrementarAluno(codigo,grup.cadastrados[i][0]);
            }
        }
      }
    fclose(fp);//fecha arquivo principal
    fclose(fp_aux);//fecha novo arquivo
    remove("arquivos\\grupos.txt");//remove o original
    rename("arquivos\\tempGrupos.txt","arquivos\\grupos.txt");//renomeia o aux com nome do orinial
    //fim
}

//LISTAR CONGRESSISTAS DE GRUPO_DE_DISCUSSOES
void listaAlunosdoGrupo(){
  puts(" \nListar alunos do grupo\n");
  int codigo;//codigo d
  int i;

  listaGrupos();
   puts("Insira o codigo do grupo");
        scanf("%d",&codigo);

  FILE *fp=NULL;
  GRUPO_DE_DISCUSSOES grup;

  fp=fopen("arquivos\\grupos.txt","rb");//abre arquivos principais no modo de leitura

  while(fread(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fp)){//le arquivo principal
    if(grup.cod==codigo){
      for(i=0;i<grup.numCadastrados;i++){
        listarAlunosdeEventos(grup.cod,grup.cadastrados[i][0]);//envia o ID do array de acordo que o for passar por ele
      }
    }
  }

   fclose(fp);//fecha arquivo principal
   //fim
}
//LISTAR PALESTRANTES DO GRUPO
void listaPalesdoGrupo(int cod){
      int i;
      FILE *fp2;
      GRUPO_DE_DISCUSSOES grup;
      fp2 = fopen("arquivos\\grupos.txt", "rb");//abre arquivo no modo de leitura
      while(fread(&grup,sizeof(GRUPO_DE_DISCUSSOES),1,fp2)){
        if(grup.cod==cod){
          for(i=0;i<=grup.numPalestrante;i++){
            mostraPalestrante(grup.Membros_da_mesa[i][0]);
          }
        }
      }

  fclose(fp2);
}





//************************************************************************************************


//FUNÇÕES DE LOCAIS*****************************************************
//CRIA TODOS OS LOCAIS ZERADOS 
void criarLocais(int i){
  
  printf("I eh %d\n",i);
  //TESTA SE O ARQUIVO JA EXISTE
  int j,x,y;
  //abre arquivo e verifica
    FILE *fp=NULL;
    SLOCAL loca;//varial de local
    //teste de entrada de arquivo
    
        
      fp = fopen("arquivos\\locais.txt", "ab");
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
            listaLocais(50);//função paralistar locais com capacidade de ate 150 
            
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
                puts("\nEscolha o local do seu Curso\n");
            puts("Locais disponíveis:");
            listaLocais(50);//função paralistar locais com capacidade de ate 50 
            
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


          //===================================================================================
          if(cod>=400 && cod<500){//cod de oficina
             puts("\nEscolha o local de sua Oficina\n");
            puts("Locais disponíveis:");
            listaLocais(20);//função paralistar locais com capacidade de ate 50 
            
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

          
  //}
    fclose(fp);
    fclose(fp2);
    remove("arquivos\\locais.txt");//remove o original
    rename("arquivos\\tempLocais.txt","arquivos\\locais.txt");
}
//LISTAR OS HORARIOS(int dia, int cod, int lugar)//recebe o dia, cod do evento, e o local escolhido
  //abre arquivos de locais
    //abre cod de locais
    //if cod de local {aparece determinados horarios compativeis}
    //while cods de locais
      //abre o array de horarios
        //lista os horarios diferentes de zero
        

//ALTERAR HORARIO
void alteraHorario(int cod){
  removerHorario(cod);
  printf("\nEscolher novo local e horário:\n");
  escolheLocal(cod);
}

void removerHorario(int cod){
      int i,j;//contador
      int x,y;
 
      FILE *fp;
      FILE *fp2;
      SLOCAL loca;//varial de local
        fp = fopen("arquivos\\locais.txt", "rb");
        fp2 = fopen("arquivos\\tempLocais.txt", "ab");
    while (fread(&loca, sizeof(SLOCAL), 1,fp)){
     for(i=0;i<2;i++){
       for(j=1;j<=6;j++){
         if(loca.Eventos[i][j][0]==cod){
              x=i;
              y=j;
         }
       }
     }
     if(loca.Eventos[x][y][0]==cod){
       printf("\n**dia %d\thora %d\t = %d",i,j,loca.Eventos[x][y][0]);
            loca.horario[x][y]=y;
            printf("\n**dia %d\thora %d\t = %d",i,j,j);
            loca.Eventos[x][y][0]=0;
             fwrite(&loca,sizeof(SLOCAL),1,fp2);
     }else{
       fwrite(&loca,sizeof(SLOCAL),1,fp2);
     }

    }

    fclose(fp);
    fclose(fp2);
    remove("arquivos\\locais.txt");//remove o original
    rename("arquivos\\tempLocais.txt","arquivos\\locais.txt");
}




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
            printf("Local: ");
            switch (loca.lugar){
              case 1:{
                puts("Auditório 1");
              break;
              }
              case 2:{
                puts("Auditório 2");
              break;
              }
            case 3:{
                puts("Auditório 3");
              break;
              }
              case 4:{
                puts("Sala 1");
              break;
              }
              case 5:{
                puts("Sala 2");
              break;
              }
              case 6:{
                puts("Sala 3");
              break;
              }
              case 7:{
                puts("Laboratório 1");
              break;
              }
              case 8:{
                puts("Laboratório 2");
              break;
              }
            default:
              break;
            }
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


//LISTA LOCAIS COMPATIVEIS DE ACORDO COM A capacidade
void listaLocais(int capacidade){
  FILE *fpp;
  SLOCAL loca;//varial de local
  fpp = fopen("arquivos\\locais.txt", "rb");//


  int disponiveis[8],i;
  while (fread(&loca, sizeof(SLOCAL), 1,fpp)){//enquanto leitura for verdadeira
  
              puts("ENTRA EM WHILE DE ESCOLHEWR LOCAllllllllllllllL");

              for(i=1;i<=8;i++){
                printf("\n\ncapacidade %d capacidade do local %d\n",capacidade,loca.capacidade);
                  if(loca.lugar==i && loca.capacidade==capacidade){//capacidade de 150 pq é palestra
                      if(i==1){
                        printf("%d-Auditório 1\n",i);

                        
                      }
                      if(i==2){
                        printf("%d-Auditório 2\n",i);
                        
                      }
                      if(i==3){
                        printf("%d-Auditório 3\n",i);
                        
                      }
                      if(i==4){
                        printf("%d-Sala 1\n",i);
                        
                      }
                      if(i==5){
                        printf("%d-Sala 2\n",i);
                        
                      }
                      if(i==6){
                        printf("%d-Sala 3\n",i);
                        
                      }
                      if(i==7){
                        printf("%d-Laboratório 1\n",i);
                        
                      }
                      if(i==8){
                        printf("%d-Laboratório 2\n",i);
                        
                      }
                  }
              }

  }
    fclose(fpp);
}


//LISTA HORARIOS DISPONIVEIS PARA CERTOS LOCAIS
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