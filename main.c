/*
FALTA


*FAZER A LIMPEZA DAS FUNÇÕES

*COMENTARIO E ORGANIZAÇÃO NO .H



--FUNÇÃO PARA ESPERAR UM TEMPO OU PARAR






-----------------------------------------------------------
BUGS

-----------------------------DUVIDAS------------------------


-----------------------------IDEIAS---------------------------


-----------------------------PROBLEMAS---------------------


-------------------------------------------------------------
*/


#include <stdio.h>
#include "funcions.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include "aparencia.h"



int main(){

  //criar a pasta de arquivos
    if(!CreateDirectory("arquivos", NULL)) {
            if(GetLastError()==183){
                printf("\n");
            }else{
        fprintf(stderr, "ERRO: %d\n", GetLastError());
            }
    }
    //hablitar portugues
    setlocale(LC_ALL, "Portuguese");

  
  
int j;
//cria os locais
  FILE *arq=NULL;
  if ((arq = fopen("arquivos\\locais.txt", "r")) == NULL){
    for(j=1;j<=8;j++){
      criarLocais(j);
    }
  }
mostra();
calma();


//MENU

int op,op2,op3;
do{
  

 limpaTela();
 fundo_tela();
     gotoxy(50,13); puts("MENU PRINCIPAL");
     gotoxy(40,15); puts("|1|OGANIZADORES");
     gotoxy(58,15); puts("|2|CONGRESSISTAS");
     gotoxy(40,16); puts("|3|PALESTRANTES");
     gotoxy(58,16); puts("|4|EVENTOS");
     gotoxy(52,17); puts("|5|SAIR");


      /*
      printf("");
      printf("");
      printf("");
      printf("");
      */



  printf("Escolha uma opcao>>");
  scanf("%d",&op);
  switch(op){ 
    case 1:{//OGANIZADORES
      puts("OGANIZADORES");
      puts("1-CADASTRAR\t2-EDITAR\t3-LISTAR\t4-REMOVER\t5-VOLTAR");
      printf("Escolha uma opcao>>");
      scanf("%d",&op2);
      switch(op2){
        case 1:criaOrganizador(); break;//-CADASTRAR
        case 2:editaOrganizador(); break;//-EDITAR
        case 3:listaOrganizador(); break;//-LISTAR
        case 4:removeOrganizador(); break;//-REMOVER
        case 5: break;//voltar
        default:break;
      }
    }break;
    
    case 2:{//-CONGRESSISTAS
      puts("CONGRESSISTAS");
      puts("1-CADASTRAR\t2-EDITAR\t3-LISTAR\n4-REMOVER\n5-CADASTRAR EM EVENTO\t6-EVENTOS\t7-SAIR DE EVENTOS\n8-VOLTAR");
      printf("Escolha uma opcao>>");
      scanf("%d",&op2);
      switch(op2){
        case 1:
          if((numCongressistas())<300){
            NovoCongressista(); break;//-CADASTRAR CONGRESSISTA
          }else{
            puts("\n!Numero maximo de congressistas cadastrados!\n");break;
          }
        case 2:editaAluno(); break;//-EDITAR
        case 3:listarAlunos(); break;//-LISTAR
        case 4:removerAluno(); break;//-REMOVER
        case 5:cadastrarAlunoemEvento(); break;//-CADASTRAR EM EVENTO 
        case 6:listaEventosdeAlunos(); break;//-EVENTOS  DO CONGRESSISTA
        case 7:deixarEvento(); break;//-SAIR DE EVENTOS
        case 8: break;//voltar
        default:break;
      }break;
    }break;

    case 3:{//-PALESTRANTES
      puts("PALESTRANTES");
      puts("1-CADASTRAR\t2-EDITAR\t3-LISTAR\n4-REMOVER\t5-EVENTOS\t6-VOLTAR");
      printf("Escolha uma opcao>>");
      scanf("%d",&op2);
      switch(op2){
        case 1:cadastroPalestrante(); break;//-CADASTRAR
        case 2:editaPalestrante(); break;//-EDITAR
        case 3:listarPalestrantes(); break;//-LISTAR
        case 4:removerPalestrantes(); break;//-REMOVER
        case 5:listaEventosdoPalestrante(); break;//-EVENTOS  DO PALESTRANTE
        case 6: break;//voltar
        default:break;
      }break;
    }break;

    case 4:{//-EVENTOs
      puts("EVENTOS");
      puts("1-PALESTRAS\t2-GRUPOD DE DISCUSSÕES\n3-CURSOS\t4-OFICINAS");
      printf("Escolha uma opcao>>");
      scanf("%d",&op2);
      switch(op2){
        case 1:{ //PALESTRAS
          puts("PALESTRAS");
          puts("1-CADASTRAR\t2-EDITAR\n3-LISTAR\t4-REMOVER\n5-LISTAR POR PALESTRAS\t6-VOLTAR");
          printf("Escolha uma opcao>>");
          scanf("%d",&op3);
          switch(op3){
            case 1:criaPalestra(); break;//-CADASTRAR
            case 2:editaPalestra(); break;//-EDITAR
            case 3:listaPalestras(); break;//-LISTAR
            case 4:removerPalestra(); break;//-REMOVER
            case 5:listarAlunosdaPalestra(); break;//-LISTAR ALUNOS DA PALESTRA 
            case 6: break;//voltar
            default:break;
          }
        }break;
        
        case 2:{//GRUPOD DE DISCUSSÕES
          puts("GRUPOS DE DISCUSSÕES");
          puts("1-CADASTRAR\t2-EDITAR\n3-LISTAR\t4-REMOVER\n5-LISTAR POR GRUPOS\t6-VOLTAR");
          printf("Escolha uma opcao>>");
          scanf("%d",&op3);
          switch(op3){
            case 1:criaGrupo(); break;//-CADASTRAR
            case 2:editaGrupo(); break;//-EDITAR
            case 3:listaGrupos(); break;//-LISTAR
            case 4:removeGrupo(); break;//-REMOVER
            case 5:listaAlunosdoGrupo(); break;//-LISTAR ALUNOS DO GRUPOD
            case 6: break;//voltar
            default:break;
          }
        }break;
        case 3:{ //CURSOS
          puts("CURSOS");
          puts("1-CADASTRAR\t2-EDITAR\n3-LISTAR\t4-REMOVER\n5-LISTAR POR CURSOS\t6-VOLTAR");
          printf("Escolha uma opcao>>");
          scanf("%d",&op3);
          switch(op3){
            case 1:criaCurso(); break;//-CADASTRAR
            case 2:editaCurso(); break;//-EDITAR
            case 3:listaCursos(); break;//-LISTAR
            case 4:removerCurso(); break;//-REMOVER
            case 5:listarAlunosdoCurso(); break;//-LISTAR ALUNOS DO CURSO 
            case 6: break;//voltar
            default:break;
          }
        }break;
        case 4:{ //OFICINAS
          puts("OFICINAS");
          puts("1-CADASTRAR\t2-EDITAR\n3-LISTAR\t4-REMOVER\n5-LISTAR POR OFICINAS\t6-VOLTAR");
          printf("Escolha uma opcao>>");
          scanf("%d",&op3);
          switch(op3){
            case 1:criaOficina(); break;//-CADASTRAR
            case 2:editaOficinas(); break;//-EDITAR
            case 3:listaOficinas(); break;//-LISTAR
            case 4:removerOficinas(); break;//-REMOVER
            case 5:listaAlunosdaOficina(); break;//-LISTAR ALUNOS DA PALESTRA 
            case 6: break;//voltar
            default:break;
          }
        }break;
      }break;
    }
    case 5:{
      puts("Fim do programa");break;
    }
    default: puts("opcao INVÁLIDA");
  }
}while(op!=5);


  getchar();
  return 0 ;
}
